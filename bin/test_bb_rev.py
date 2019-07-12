'''
Run barnase-barstar reversals

Created on July 11, 2019

@author: lvotapka
'''

import seekr
from seekr import amber
import sys, os, math
from simtk.unit import *
import mdtraj
from simtk.openmm.app import AmberInpcrdFile

print "Parse arguments"
which = None
if len(sys.argv) < 2: # then assume all
  which = 'all'
elif sys.argv[1] == 'all':
  which = 'all'
else:
  which = int(sys.argv[1])

if len(sys.argv) == 3:
  launches_per_config = int(sys.argv[2])
else:
  launches_per_config = 1
  
print "which:", which

print "Loading SEEKR calculation."

##################################################################
# VARIABLES WITHIN SECTION BELOW SHOULD BE MODIFIED TO YOUR SYSTEM
##################################################################

picklename = '/home/lvotapka/barnasebarstar/seekr_calc.pickle'

me = seekr.openSeekrCalc(picklename)

#lig_selection = [3221, 3222, 3223, 3224, 3225, 3226, 3227, 3228, 3229]
#rec_selection = [2478, 2489, 2499, 2535, 2718, 2745, 2769, 2787, 2794, 2867, 2926]

barnase_indices = [833, 549] # ARG 59, SER 36
barstar_indices = [2266, 2388] # ASP 35, TRP 44 [2268, 2387]

me.fwd_rev_stage.steps = 1000 # in 2*fs
me.fwd_rev_stage.energy_freq = 1000
me.fwd_rev_stage.traj_freq = 1000
me.fwd_rev_stage.launches_per_config = launches_per_config
me.fwd_rev_stage.barostat = False # leave barostat off
umbrella_glob = 'umbrella*.dcd'
reversal_frames = (10, 100, 1)
pos_vel_chunk_size = 400
save_crossing_states = True
#reversal_frames = (1010, 10010, 1)
#pos_vel_chunk_size = 5

##################################################################
# DON'T MODIFY THE SECTION BELOW UNLESS YOU KNOW WHAT YOU'RE DOING
##################################################################

if which == 'all': # then run all milestones
  all_milestones = me.milestones
else:
  all_milestones = [me.milestones[which]]
  
for milestone in all_milestones:
  if milestone.md:
    if not milestone.openmm.prmtop_filename: 
      prmtop_path = os.path.join(me.project.rootdir, milestone.directory, 'md', 'building', 'holo.parm7')
      inpcrd_path = os.path.join(me.project.rootdir, milestone.directory, 'md', 'building', 'holo.rst7')
      if os.path.exists(prmtop_path) and os.path.exists(inpcrd_path):
        milestone.openmm.prmtop_filename = prmtop_path
        milestone.openmm.inpcrd_filename = inpcrd_path
        inpcrd = AmberInpcrdFile(inpcrd_path)
        milestone.box_vectors = inpcrd.boxVectors
        print "box_vectors:", milestone.box_vectors
      else:
        print "prmtop or inpcrd file not found for milestone %d. Skipping..." % milestone.index
        continue
    print "launching constant energy reverse stage for milestone:", which
    if milestone.box_vectors:
      print "Using milestone.box_vectors:", milestone.box_vectors
      box_vectors = milestone.box_vectors
    else:
      inpcrd_path = os.path.join(me.project.rootdir, milestone.directory, 'md', 'building', 'holo.rst7')
      inpcrd = AmberInpcrdFile(inpcrd_path)
      milestone.box_vectors = inpcrd.boxVectors
      box_vectors = milestone.box_vectors
    milestone.atom_selection_1 = barnase_indices
    milestone.atom_selection_2 = barstar_indices
    fwd_rev_path = os.path.join(me.project.rootdir, milestone.directory, 'md', 'fwd_rev')
    umbrella_traj = os.path.join(me.project.rootdir, milestone.directory, 'md', 'umbrella', umbrella_glob)
    parm_file_name = os.path.join(me.project.rootdir, milestone.directory, 'md', 'building', 'holo.parm7')
    trajout = os.path.join(me.project.rootdir, milestone.directory, 'md', 'umbrella', 'imaged.dcd')
    cpptraj_script_location = os.path.join(me.project.rootdir, milestone.directory, 'md', 'umbrella', 'image_umbrella.cpptraj')
    if save_crossing_states == True:
      reversal_state_name = os.path.join(me.project.rootdir, milestone.directory, 'md', 'fwd_rev', 'reversal')
    else:
      reversal_state_name = ''
    box_info = seekr.make_box_info(box_vectors)
    if os.path.exists(trajout):
      print "Imaged trajectories already generated. Skipping autoimaging."
    else:
      seekr.autoimage_traj(parm_file_name, umbrella_traj, trajout, box_info, cpptraj_script_location=cpptraj_script_location, writing_frames=reversal_frames)
    dcd = mdtraj.iterload(trajout, top=parm_file_name, chunk=1)
    traj_base = "reverse"
    print "running reversals"

    #num_frames = launches_per_config*(reversal_frames[1] - reversal_frames[0]) / reversal_frames[2]
    #print "num_frames:", num_frames
    #print "pos_vel_chunk_size:", pos_vel_chunk_size
    #print "math.ceil((1.0*num_frames) / pos_vel_chunk_size):", math.ceil((1.0*num_frames) / pos_vel_chunk_size)
    
    # TODO: PROBLEM! What do to about the existing transitions.dat file???
    
    #for i in range(int(math.ceil((1.0*num_frames) / pos_vel_chunk_size))):
    complete = False
    i = 0
    save_fwd_rev = False
    while not complete:
      print "Running chunk %d" % i
      success_positions, success_velocities, data_file_name, indices_list, complete = seekr.launch_fwd_rev_stage(me, milestone, traj_base, True, dcd, pos_vel_chunk_size, box_vectors=box_vectors, suffix='_%d' % i, save_fwd_rev=save_fwd_rev, save_state_filename=reversal_state_name)
      save_fwd_rev = True
      if len(success_positions) == 0:
        print "Reversal stage failed for this chunk: No successful reversal trajectories completed."
      else:
        print "saving coordinates and velocities for the reversal stage. len(success_positions)", len(success_positions), "len(success_velocities):", len(success_velocities)
        seekr.pickle_coords_vels(me, milestone, success_positions, success_velocities, index=i)
      i += 1
    
me.save()
    