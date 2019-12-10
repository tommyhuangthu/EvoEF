///////////////////////////////////////////////////////////////////////////////////////
//Copyright (C) 2017-2019 Yang Zhang Lab, University of Michigan - All Rights Reserved
//Unauthorized copying of this file, via any medium is strictly prohibited
//Written by Xiaoqiang Huang <xiaoqiah@umich.edu>,2017 Winter
//////////////////////////////////////////////////////////////////////////////////////

#ifndef DESIGN_SITE_H
#define DESIGN_SITE_H

#include "Rotamer.h"

typedef struct _DesignSite{
  RotamerSet rotamers; //20-24 bytes
  Residue* pResidue;   //4-8 bytes
} DesignSite;

int DesignSiteCreate(DesignSite* pThis);
int DesignSiteDestroy(DesignSite* pThis);
RotamerSet* DesignSiteGetRotamers(DesignSite* pThis);
char* DesignSiteGetChainName(DesignSite* pThis);
char* DesignSiteGetResiName(DesignSite* pThis);
int DesignSiteGetPosInChain(DesignSite* pThis);
int DesignSiteShow(DesignSite* pThis,FILE* pFile);
Residue* DesignSiteGetResidue(DesignSite* pThis);
int DesignSiteShowRepresentativeRotamerAtomParameter(DesignSite* pThis);
int DesignSiteShowRepresentativeRotamerBondInformation(DesignSite* pThis);
#endif

