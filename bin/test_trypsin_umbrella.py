'''
A sample script for running umbrella sampling

Created on May 15, 2018

@author: lvotapka
'''

import seekr
from seekr import amber
import sys, os
from simtk.unit import *

print "Parsing arguments"
which = None
try:
  if sys.argv[1].lower() == 'all':
    which = 'all'
  else:
    which = int(sys.argv[1])
  
  if sys.argv[2].lower() == 'npt':
    ensemble = 'npt'
  elif sys.argv[2].lower() == 'nvt':
    ensemble = 'nvt'
  else:
    print "Option for 'ensemble' not allowed:", sys.argv[2]
    
  num_steps = int(sys.argv[3])
  
except:
  print '''Usage: python this_script.py milestone ensemble steps
Argument milestone may be an integer or the word 'all', ensemble may be 'nvt' or
'npt', and steps is an integer representing the number of umbrella steps
to run.'''
  exit()

print "Loading SEEKR calculation for milestone:", which
print "Using", ensemble, "ensemble for", num_steps, "steps."
#rootdir = '/home/lvotapka/tryp_test'

##################################################################
# VARIABLES WITHIN SECTION BELOW SHOULD BE MODIFIED TO YOUR SYSTEM
##################################################################

picklename = '/home/lvotapka/tryp_test/seekr_calc.pickle'
me = seekr.openSeekrCalc(picklename)
me.umbrella_stage.force_constant = 900.0*kilocalories_per_mole/angstroms**2
me.umbrella_stage.steps = num_steps # in 2*fs
me.umbrella_stage.energy_freq = 10000
me.umbrella_stage.traj_freq = 100000
if ensemble == 'npt':
  me.umbrella_stage.barostat = True # turn on barostat, run in NPT
  me.umbrella_stage.barostat_freq = 25
  me.umbrella_stage.barostat_pressure = 1.0*bar
else:
  me.umbrella_stage.barostat = False
  
# Make sure you use a VMD selection by index (not serial) to find these numbers
lig_selection = [3222, 3223, 3224, 3225, 3226, 3227, 3228, 3229, 3230]
rec_selection = [2467, 2479, 2490, 2536, 2746, 2770, 2788]

##################################################################
# DON'T MODIFY THE SECTION BELOW UNLESS YOU KNOW WHAT YOU'RE DOING
##################################################################

if which == 'all': # then run all milestones
  all_milestones = me.milestones
else:
  all_milestones = [me.milestones[which]]
  
for milestone in all_milestones:
  if milestone.md:
    if not milestone.openmm.prmtop_filename: continue
    print "launching constant pressure umbrella sampling for milestone:", which
    if rec_selection:
      milestone.atom_selection_1 = rec_selection
    if lig_selection:
      milestone.atom_selection_2 = lig_selection
      
    new_dcd_filename, new_pdb_filename = seekr.generate_umbrella_filenames(me, milestone)
    box_vectors = milestone.box_vectors
    milestone.box_vectors, umbrella_traj = seekr.launch_umbrella_stage(me, milestone, box_vectors, traj_name=new_dcd_filename)
    #TODO: umbrella_traj not used
    pdb_filename = os.path.join(me.project.rootdir, milestone.directory, 'md', 'umbrella', new_pdb_filename)
    amber.save_restart(me, milestone, pdb_filename)
    milestone.openmm.umbrella_pdb_filename = pdb_filename
    
  print "ending box vectors for milestone %d:" % milestone.index, me.milestones[which].box_vectors
  
me.save()
