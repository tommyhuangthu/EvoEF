///////////////////////////////////////////////////////////////////////////////////////
//Copyright (C) 2017-2019 Yang Zhang Lab, University of Michigan - All Rights Reserved
//Unauthorized copying of this file, via any medium is strictly prohibited
//Written by Xiaoqiang Huang <xiaoqiah@umich.edu>,2017 Winter
//////////////////////////////////////////////////////////////////////////////////////

#ifndef STRUCTURE_H
#define STRUCTURE_H

#include "Chain.h"
#include "Rotamer.h"
#include "DesignSite.h"


#define HYDROXYL_ROTAMER_SER  11
#define HYDROXYL_ROTAMER_THR  11
#define HYDROXYL_ROTAMER_TYR  1


typedef struct _Structure{
  char name[MAX_LENGTH_STRUCTURE_NAME+1]; // 11 bytes
  Chain* chains;                          // 4/8 bytes
  DesignSite ***designSites;              // 4/8 bytes
  int chainNum;                           // 4 bytes
  int designSiteCount;                    // 4 bytes
} Structure;

int StructureCreate(Structure* pThis);
int StructureDestroy(Structure* pThis);
char* StructureGetName(Structure* pThis);
int StructureSetName(Structure* pThis, char* newName);
int StructureGetChainCount(Structure* pThis);
Chain* StructureGetChain(Structure* pThis, int index);
Chain* StructureGetChainByName(Structure* pThis, char* chainName);
int StructureFindChain(Structure* pThis, char* chainName, int* index);
int StructureFindSmallMol(Structure* pThis, Residue** ppSmallMol);
int StructureAddChain(Structure* pThis, Chain* newChain);
int StructureDeleteChain(Structure* pThis, char* chainName);
int StructureShowInPDBFormat(Structure* pThis, BOOL showHydrogen, FILE* pFile);
int StructureGetDesignSiteCount(Structure* pThis);
DesignSite* StructureGetDesignSite(Structure* pThis, int chainIndex, int resiIndex);
int StructureShowAtomParameter(Structure* pStructure);

int ProteinSiteBuildAllRotamers(Structure* pThis, int chainIndex, int resiIndex, RotamerLib* rotlib, AtomParamsSet* atomParams, ResiTopoSet* resiTopos);
int ProteinSiteDeleteRotamers(Structure* pThis, int chainIndex, int resiIndex);
int ProteinSiteWriteRotamers(Structure *pStructure, int chainIndex, int resiIndex, const char *rotamerFilePath);
int StructureGenerateProteinRotamers(Structure* pThis, RotamerLib* rotlib, AtomParamsSet* atomParams, ResiTopoSet* resiTopos);
int StructureInitializeDesignSites(Structure* pThis);
int ProteinSiteBuildMutatedRotamers(Structure* pThis, int chainIndex, int resiIndex, RotamerLib* rotlib,AtomParamsSet* atomParams,ResiTopoSet* resiTopos, StringArray *pDesignTypes, StringArray *pPatchTypes);

int ProteinSiteBuildWildtypeRotamers(Structure* pThis, int chainIndex, int resiIndex, RotamerLib* rotlib, AtomParamsSet* atomParams, ResiTopoSet* resiTopos);
int ProteinSiteAddCrystalRotamer(Structure* pStructure, int chainIndex, int resiIndex, ResiTopoSet *pResiTopos);
int ProteinSiteOptimizeRotamer(Structure *pStructure, int chainIndex, int resiIndex);
int StructureShowBondInformation(Structure* pStructure);
int StructureInitialize(Structure* pStructure, char* pdbFile, AtomParamsSet* pAtomParams, ResiTopoSet* pTopos);
int StructureConfig(Structure *pStructure, char* pdbFile, AtomParamsSet* pAtomParams, ResiTopoSet* pResiTopos);
int ChainComputeResiduePosition(Structure *pStructure, int chainIndex);
int StructureComputeResiduePosition(Structure *pStructure);
int StructureGetAminoAcidComposition(Structure* pStructure, int *aas);
int StructureShowDesignSites(Structure* pThis, FILE* pFile);
int StructureComputeResidueInteractionWithFixedSurroundingResidues(Structure *pStructure, int chainIndex, int residueIndex);
int ProteinSiteExpandHydroxylRotamers(Structure *pStructure, int chainIndex, int resiIndex, ResiTopoSet *pTopos);
int ProteinRotamerGenerate(Structure* pStructure, AtomParamsSet* pAtomParams,ResiTopoSet* pResiTopo, char* rotamer_lib_file);


BOOL ProteinSiteCheckClash(Structure *pStructure, int chainIndex, int residueIndex);
int ProteinSiteBuildFlippedCrystalRotamer(Structure* pStructure, int chainIndex, int resiIndex, ResiTopoSet *pResiTopos);
int StructureDeleteRotamers(Structure* pThis);
int ProteinSiteOptimizeRotamerHBondEnergy(Structure *pStructure, int chainIndex, int resiIndex);
int ProteinSiteOptimizeRotamerLocally(Structure *pStructure, int chainIndex, int resiIndex, double rmsdcutoff);
#endif // STRUCTURE_H
