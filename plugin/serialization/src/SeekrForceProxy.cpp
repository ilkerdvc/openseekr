/*
   Copyright 2019 by Lane Votapka
   All rights reserved
   
   -------------------------------------------------------------------------- *
 *                                   OpenMM                                   *
 * -------------------------------------------------------------------------- *
 * This is part of the OpenMM molecular simulation toolkit originating from   *
 * Simbios, the NIH National Center for Physics-Based Simulation of           *
 * Biological Structures at Stanford, funded under the NIH Roadmap for        *
 * Medical Research, grant U54 GM072970. See https://simtk.org.               *
 *                                                                            *
 * Portions copyright (c) 2014 Stanford University and the Authors.           *
 * Authors: Peter Eastman                                                     *
 * Contributors:                                                              *
 *                                                                            *
 * Permission is hereby granted, free of charge, to any person obtaining a    *
 * copy of this software and associated documentation files (the "Software"), *
 * to deal in the Software without restriction, including without limitation  *
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,   *
 * and/or sell copies of the Software, and to permit persons to whom the      *
 * Software is furnished to do so, subject to the following conditions:       *
 *                                                                            *
 * The above copyright notice and this permission notice shall be included in *
 * all copies or substantial portions of the Software.                        *
 *                                                                            *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   *
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL    *
 * THE AUTHORS, CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,    *
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR      *
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE  *
 * USE OR OTHER DEALINGS IN THE SOFTWARE.                                     *
 * -------------------------------------------------------------------------- */

#include "SeekrForceProxy.h"
#include "SeekrForce.h"
#include "openmm/serialization/SerializationNode.h"
#include <sstream>
#include <iostream>

using namespace SeekrPlugin;
using namespace OpenMM;
using namespace std;


SeekrForceProxy::SeekrForceProxy() : SerializationProxy("SeekrForce") {
}


// This module allows everything to be converted to XML and back again

void SeekrForceProxy::serialize(const void* object, SerializationNode& node) const {
    node.setIntProperty("version", 1);
    const SeekrForce& force = *reinterpret_cast<const SeekrForce*>(object);
    SerializationNode& planarZMilestones = node.createChildNode("PlanarZMilestones");
    

    for (int i = 0; i < force.getNumPlanarZMilestones(); i++) {
        std::vector<int> atomIndices1;
        std::vector<int> atomIndices2;
        SerializationNode& planarZMilestone = planarZMilestones.createChildNode("PlanarZMilestone");
        SerializationNode& atomIndicesNode = planarZMilestone.setIntProperty("numIndices1", force.getPlanarZNumIndices(i,1)).setIntProperty("numIndices2", force.getPlanarZNumIndices(i,2)).setDoubleProperty("offset1", force.getPlanarZOffset(i,1)).setDoubleProperty("offset2", force.getPlanarZOffset(i,2)).setDoubleProperty("offset3", force.getPlanarZOffset(i,3));
        SerializationNode& atomIndicesNode1 = atomIndicesNode.createChildNode("atomIndices1");
        for (int j = 0; j < force.getPlanarZNumIndices(i,1); j++) {; //
            atomIndices1.push_back(0);
            force.getPlanarZMilestoneAtoms(i, j, atomIndices1[j], 1);
            SerializationNode& atomIndexNode1 = atomIndicesNode1.createChildNode("atomIndex1");
            atomIndexNode1.setIntProperty("index", atomIndices1[j]);
        }
        SerializationNode& atomIndicesNode2 = atomIndicesNode.createChildNode("atomIndices2");
        for (int j = 0; j < force.getPlanarZNumIndices(i,2); j++) {
            atomIndices2.push_back(0);
            force.getPlanarZMilestoneAtoms(i, j, atomIndices2[j], 2);
            SerializationNode& atomIndexNode2 = atomIndicesNode2.createChildNode("atomIndex2");
            atomIndexNode2.setIntProperty("index", atomIndices2[j]);
        }
    }
    
    SerializationNode& sphericalMilestones = node.createChildNode("SphericalMilestones");
    
    for (int i = 0; i < force.getNumSphericalMilestones(); i++) {
        std::vector<int> atomIndices1;
        std::vector<int> atomIndices2;
        SerializationNode& sphericalMilestone = sphericalMilestones.createChildNode("SphericalMilestone");
        SerializationNode& atomIndicesNode = sphericalMilestone.setIntProperty("numIndices1", force.getSphericalNumIndices(i,1)).setIntProperty("numIndices2", force.getSphericalNumIndices(i,2)).setDoubleProperty("radius1", force.getSphericalRadius(i,1)).setDoubleProperty("radius2", force.getSphericalRadius(i,2)).setDoubleProperty("radius3", force.getSphericalRadius(i,3));
        SerializationNode& atomIndicesNode1 = atomIndicesNode.createChildNode("atomIndices1");
        for (int j = 0; j < force.getSphericalNumIndices(i,1); j++) {; //
            atomIndices1.push_back(0);
            force.getSphericalMilestoneAtoms(i, j, atomIndices1[j], 1);
            SerializationNode& atomIndexNode1 = atomIndicesNode1.createChildNode("atomIndex1");
            atomIndexNode1.setIntProperty("index", atomIndices1[j]);
        }
        SerializationNode& atomIndicesNode2 = atomIndicesNode.createChildNode("atomIndices2");
        for (int j = 0; j < force.getSphericalNumIndices(i,2); j++) {
            atomIndices2.push_back(0);
            force.getSphericalMilestoneAtoms(i, j, atomIndices2[j], 2);
            SerializationNode& atomIndexNode2 = atomIndicesNode2.createChildNode("atomIndex2");
            atomIndexNode2.setIntProperty("index", atomIndices2[j]);
        }
    }
    
    SerializationNode& rmsdMilestones = node.createChildNode("RmsdMilestones");
    
    for (int i = 0; i < force.getNumRmsdMilestones(); i++) {
        std::vector<int> atomIndices1;
        std::vector<int> atomIndices2;
        SerializationNode& rmsdMilestone = rmsdMilestones.createChildNode("RmsdMilestone");
        SerializationNode& atomIndicesNode = rmsdMilestone.setIntProperty("numIndices1", force.getRmsdNumIndices(i,1)).setIntProperty("numIndices2", force.getRmsdNumIndices(i,2)).setDoubleProperty("radius1", force.getRmsdRadius(i,1)).setDoubleProperty("radius2", force.getRmsdRadius(i,2)).setDoubleProperty("radius3", force.getRmsdRadius(i,3));
        SerializationNode& atomIndicesNode1 = atomIndicesNode.createChildNode("atomIndices1");
        for (int j = 0; j < force.getRmsdNumIndices(i,1); j++) {; //
            atomIndices1.push_back(0);
            force.getRmsdMilestoneAtoms(i, j, atomIndices1[j], 1);
            SerializationNode& atomIndexNode1 = atomIndicesNode1.createChildNode("atomIndex1");
            atomIndexNode1.setIntProperty("index", atomIndices1[j]);
        }
        SerializationNode& atomIndicesNode2 = atomIndicesNode.createChildNode("atomIndices2");
        for (int j = 0; j < force.getRmsdNumIndices(i,2); j++) {
            atomIndices2.push_back(0);
            force.getRmsdMilestoneAtoms(i, j, atomIndices2[j], 2);
            SerializationNode& atomIndexNode2 = atomIndicesNode2.createChildNode("atomIndex2");
            atomIndexNode2.setIntProperty("index", atomIndices2[j]);
        }
    }
    
    SerializationNode& globalParams = node.createChildNode("globalParams");
    //SerializationNode& endOnMiddleCrossing = globalParams.createChildNode("endOnMiddleCrossing");
    globalParams.setBoolProperty("endOnMiddleCrossing", force.getEndOnMiddleCrossing()).setStringProperty("dataFileName", force.getDataFileName()).setStringProperty("saveStateFileName", force.getSaveStateFileName());
    
    //TODO: support addition of global parameters like saveStateFileName
}

void* SeekrForceProxy::deserialize(const SerializationNode& node) const {
    if (node.getIntProperty("version") != 1)
        throw OpenMMException("Unsupported version number");
    SeekrForce* force = new SeekrForce();
    try {
        const SerializationNode& planarZMilestones = node.getChildNode("PlanarZMilestones");
        
        for (int i = 0; i < planarZMilestones.getChildren().size(); i++) {
          const SerializationNode& planarZMilestone = planarZMilestones.getChildNode("PlanarZMilestone");
          int numIndices1 = planarZMilestone.getIntProperty("numIndices1");
          int numIndices2 = planarZMilestone.getIntProperty("numIndices2");
          float offset1 = planarZMilestone.getDoubleProperty("offset1");
          float offset2 = planarZMilestone.getDoubleProperty("offset2");
          float offset3 = planarZMilestone.getDoubleProperty("offset3");
          const SerializationNode& atomIndicesNode1 = planarZMilestone.getChildNode("atomIndices1");
          const SerializationNode& atomIndicesNode2 = planarZMilestone.getChildNode("atomIndices2");
          //bool endOnMiddleCrossing = planarZMilestone.getBoolProperty("endOnMiddleCrossing");
          //TODO: this is a problem
          //std::string dataFileName = "/tmp/test.txt";
          //const std::string dataFileName = planarZMilestone.getStringProperty("dataFileName"); // This might not work, resort to above if necessary
          
          std::vector<int> atomIndices1(atomIndicesNode1.getChildren().size());
          std::vector<int> atomIndices2(atomIndicesNode2.getChildren().size());
          
          for (int j = 0; j < numIndices1; j++) {
            atomIndices1[j] = atomIndicesNode1.getChildren()[j].getIntProperty("index");
          }
          
          for (int j = 0; j < numIndices2; j++) {
            atomIndices2[j] = atomIndicesNode2.getChildren()[j].getIntProperty("index");
          }
          
          force->addPlanarZMilestone(numIndices1, numIndices2, offset1, offset2, offset3, atomIndices1, atomIndices2);

        }
    
        const SerializationNode& sphericalMilestones = node.getChildNode("SphericalMilestones");
        
        for (int i = 0; i < sphericalMilestones.getChildren().size(); i++) {
          const SerializationNode& sphericalMilestone = sphericalMilestones.getChildNode("SphericalMilestone");
          int numIndices1 = sphericalMilestone.getIntProperty("numIndices1");
          int numIndices2 = sphericalMilestone.getIntProperty("numIndices2");
          float radius1 = sphericalMilestone.getDoubleProperty("radius1");
          float radius2 = sphericalMilestone.getDoubleProperty("radius2");
          float radius3 = sphericalMilestone.getDoubleProperty("radius3");
          const SerializationNode& atomIndicesNode1 = sphericalMilestone.getChildNode("atomIndices1");
          const SerializationNode& atomIndicesNode2 = sphericalMilestone.getChildNode("atomIndices2");
          //bool endOnMiddleCrossing = sphericalMilestone.getBoolProperty("endOnMiddleCrossing");
          //TODO: this is a problem
          //std::string dataFileName = "/tmp/test.txt";
          //const std::string dataFileName = sphericalMilestone.getStringProperty("dataFileName"); // This might not work, resort to above if necessary
          
          std::vector<int> atomIndices1(atomIndicesNode1.getChildren().size());
          std::vector<int> atomIndices2(atomIndicesNode2.getChildren().size());
          
          for (int j = 0; j < numIndices1; j++) {
            atomIndices1[j] = atomIndicesNode1.getChildren()[j].getIntProperty("index");
          }
          
          for (int j = 0; j < numIndices2; j++) {
            atomIndices2[j] = atomIndicesNode2.getChildren()[j].getIntProperty("index");
          }
          
          force->addSphericalMilestone(numIndices1, numIndices2, radius1, radius2, radius3, atomIndices1, atomIndices2);
          
        }
        
        const SerializationNode& rmsdMilestones = node.getChildNode("RmsdMilestones");
        
        for (int i = 0; i < rmsdMilestones.getChildren().size(); i++) {
          const SerializationNode& rmsdMilestone = rmsdMilestones.getChildNode("RmsdMilestone");
          int numIndices1 = rmsdMilestone.getIntProperty("numIndices1");
          int numIndices2 = rmsdMilestone.getIntProperty("numIndices2");
          float radius1 = rmsdMilestone.getDoubleProperty("radius1");
          float radius2 = rmsdMilestone.getDoubleProperty("radius2");
          float radius3 = rmsdMilestone.getDoubleProperty("radius3");
          const SerializationNode& atomIndicesNode1 = rmsdMilestone.getChildNode("atomIndices1");
          const SerializationNode& atomIndicesNode2 = rmsdMilestone.getChildNode("atomIndices2");
          //bool endOnMiddleCrossing = sphericalMilestone.getBoolProperty("endOnMiddleCrossing");
          //TODO: this is a problem
          //std::string dataFileName = "/tmp/test.txt";
          //const std::string dataFileName = sphericalMilestone.getStringProperty("dataFileName"); // This might not work, resort to above if necessary
          
          std::vector<int> atomIndices1(atomIndicesNode1.getChildren().size());
          std::vector<int> atomIndices2(atomIndicesNode2.getChildren().size());
          
          for (int j = 0; j < numIndices1; j++) {
            atomIndices1[j] = atomIndicesNode1.getChildren()[j].getIntProperty("index");
          }
          
          for (int j = 0; j < numIndices2; j++) {
            atomIndices2[j] = atomIndicesNode2.getChildren()[j].getIntProperty("index");
          }
          
          force->addSphericalMilestone(numIndices1, numIndices2, radius1, radius2, radius3, atomIndices1, atomIndices2);
          
          
          
        }
        
        const SerializationNode& globalParams = node.getChildNode("globalParams");
        bool endOnMiddleCrossing = globalParams.getBoolProperty("endOnMiddleCrossing");
        force->setEndOnMiddleCrossing(endOnMiddleCrossing);
        std::string dataFileName = globalParams.getStringProperty("dataFileName");
        force->setDataFileName(dataFileName);
        std::string saveStateFileName = globalParams.getStringProperty("saveStateFileName");
        force->setSaveStateFileName(saveStateFileName);
    }
    catch (...) {
        delete force;
        throw;
    }
    return force;
}
