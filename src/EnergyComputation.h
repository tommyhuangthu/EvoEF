///////////////////////////////////////////////////////////////////////////////////////
//Copyright (C) 2017-2019 Yang Zhang Lab, University of Michigan - All Rights Reserved
//Unauthorized copying of this file, via any medium is strictly prohibited
//Written by Xiaoqiang Huang <xiaoqiah@umich.edu>,2017 Winter
//////////////////////////////////////////////////////////////////////////////////////

#ifndef ENERGY_COMPUTATION_H
#define ENERGY_COMPUTATION_H

#include "Structure.h"
#include "EnergyFunction.h"


//FOLDX energy functions
int FOLDEF_StructureCalculateAtomOccupancy14(Structure* pStructure);
int FOLDEF_StructureCalculateAtomOccupancy1234(Structure* pStructure);
int FOLDEF_ChainCalculateAtomOccupancy14(Structure* pStructure, int chainIndex);
int FOLDEF_ChainCalculateAtomOccupancy1234(Structure* pStructure, int chainIndex);
int FOLDEF_ComputeChainFoldingFreeEnergy(Structure *pStructure, int chainIndex, double *energyTerms);
int FOLDEF_ComputeStructureFoldingFreeEnergy(Structure *pStructure, double *energyTerms);
int FOLDEF_ComputeStructureBindingEnergy(Structure *pStructure, double *energyTerms);

int EvoEF_ComputeChainStability(Structure *pStructure, int chainIndex, double *energyTerms);
#endif
