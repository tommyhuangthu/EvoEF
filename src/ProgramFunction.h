///////////////////////////////////////////////////////////////////////////////////////
//Copyright (C) 2017-2019 Yang Zhang Lab, University of Michigan - All Rights Reserved
//Unauthorized copying of this file, via any medium is strictly prohibited
//Written by Xiaoqiang Huang <xiaoqiah@umich.edu>,2017 Winter
//////////////////////////////////////////////////////////////////////////////////////

#ifndef PROGRAM_FUNCTION_H
#define PROGRAM_FUNCTION_H

#include "Structure.h"
#include "EnergyFunction.h"
#include "EnergyComputation.h"


int EvoEF_help();
int EvoEF_version();
int EvoEF_interface();
BOOL CheckCommandName(char* queryname);

int EvoEF_ComputeStability(Structure *pStructure, double *energyTerms);
int EvoEF_ComputeBinding(Structure *pStructure, double *energyTerms);
int EvoEF_BuildMutant(Structure* pStructure, char* mutantfile, RotamerLib* rotlib, AtomParamsSet* atomParams,ResiTopoSet* resiTopos, char* pdbid);
int EvoEF_RepairStructure(Structure* pStructure, RotamerLib* rotlib, AtomParamsSet* atomParams,ResiTopoSet* resiTopos, char* pdbid);
int EvoEF_WriteStructureToFile(Structure* pStructure, char* pdbfile);
int EvoEF_AddHydrogen(Structure* pStructure, char* pdbid);
int EvoEF_OptimizeHydrogen(Structure* pStructure, AtomParamsSet* atomParams,ResiTopoSet* resiTopos, char* pdbid);
int EvoEF_ComputeBindingWithSplitting(Structure *pStructure, double *energyTerms,char split1[], char split2[]);
int EvoEF_ComputeBindingWithSplittingNew(Structure *pStructure, double *energyTerms,char split1[], char split2[]);
#endif //PROGRAM_FUNCTION_H