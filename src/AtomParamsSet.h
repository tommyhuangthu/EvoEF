///////////////////////////////////////////////////////////////////////////////////////
//Copyright (C) 2017-2019 Yang Zhang Lab, University of Michigan - All Rights Reserved
//Unauthorized copying of this file, via any medium is strictly prohibited
//Written by Xiaoqiang Huang <xiaoqiah@umich.edu>,2017 Winter
//////////////////////////////////////////////////////////////////////////////////////

#ifndef ATOMPARAMSSET_H
#define ATOMPARAMSSET_H

#include "Atom.h"

typedef struct _AtomParamsSet{
  StringArray residueNames;  //12 bytes at least
  Atom** atoms;              //4-8 bytes
  int*   atomCount;          //4-8 bytes
} AtomParamsSet;

int AtomParamsSetCreate(AtomParamsSet* pThis);
int AtomParamsSetDestroy(AtomParamsSet* pThis);
int AtomParamsSetAdd(AtomParamsSet* pThis, char* residueName, Atom* pNewAtom);
int AtomParamsSetAddFromFile(AtomParamsSet* pThis, char* filepath);
int AtomParamsSetGetResidueCount(AtomParamsSet* pThis);
int AtomParamsSetGetResidueName(AtomParamsSet* pThis, int index, char* residueName);
int AtomParamsSetGetAtomCount(AtomParamsSet* pThis, char* residueName, int* pCount);
int AtomParamsSetGetAtomParam(AtomParamsSet* pThis, char* residueName, int index, Atom* pDestAtom);
int AtomParamsSetGetAtomParamByName(AtomParamsSet* pThis, char* residueName, char* atomName, Atom* pDestAtom);
int AtomParameterRead(AtomParamsSet* pAtomParam, char* filePath);

int AtomparamsSetAssignEEF1Parameters(AtomParamsSet* pThis);
int AtomparamsSetAssignFOLDEFParameters(AtomParamsSet* pThis);
#endif