///////////////////////////////////////////////////////////////////////////////////////
//Copyright (C) 2017-2019 Yang Zhang Lab, University of Michigan - All Rights Reserved
//Unauthorized copying of this file, via any medium is strictly prohibited
//Written by Xiaoqiang Huang <xiaoqiah@umich.edu>,2017 Winter
//////////////////////////////////////////////////////////////////////////////////////

#ifndef ENERGY_FUNCTION_H
#define ENERGY_FUNCTION_H
#include "Residue.h"

#define ENERGY_DEBUG_MODE_VDW_ATT           0
#define ENERGY_DEBUG_MODE_VDW_REP           0
#define ENERGY_DEBUG_MODE_HBOND             0
#define ENERGY_DEBUG_MODE_ELEC              0
#define ENERGY_DEBUG_MODE_DESOLV            0


// a maximum of energy weights
#define MAX_EVOEF_ENERGY_TERM_NUM          100

// scale for 1-2, 1-3, 1-4 and >=1-5 interactions
#define ENERGY_SCALE_FACTOR_BOND_123       0.0
#define ENERGY_SCALE_FACTOR_BOND_14        0.2
#define ENERGY_SCALE_FACTOR_BOND_15        1.0
// VDW interactions
#define RADIUS_SCALE_FOR_VDW              0.95
#define VDW_DISTANCE_CUTOFF                6.0

// HBond interactions
#define HBOND_DISTANCE_CUTOFF_MAX          3.0
#define HBOND_WELL_DEPTH                   1.0
#define HBOND_OPTIMAL_DISTANCE             1.9
// Electrostatics interactions
#define ELEC_DISTANCE_CUTOFF               6.0
#define COULOMB_CONSTANT                 332.0
#define DIELECTRIC_CONST_PROTEIN           8.0
#define DIELECTRIC_CONSTANT_WATER         80.0
#define DIELECTRIC_CONST_PROTEIN_AVE      20.0
#define IONIC_STRENGTH                     0.05 // (unit: M)
#define PROTEIN_DESIGN_TEMPERATURE         298  // (unit: K)
// LK solvation interaction
#define LK_SOLV_DISTANCE_CUTOFF            6.0
#define RADIUS_SCALE_FOR_DESOLV           0.80
// FOLDEF parameter
#define FOLDEF_CLASH_TOLERANCE             0.20

int EnergyTermWeighting(double energyTerms[MAX_EVOEF_ENERGY_TERM_NUM]);

double CalcResidueBuriedRatio(Residue* pResi1);
double CalcAverageBuriedRatio(double ratio1, double ratio2);

BOOL ResidueIntraBond12Check(char *atom1,char *atom2, BondSet* pBondSet);
BOOL ResidueIntraBond13Check(char *atom1,char *atom2, BondSet* pBondSet);
BOOL ResidueIntraBond14Check(char *atom1,char *atom2, BondSet* pBondSet);
int ResidueIntraBondConnectionCheck(char *atom1,char *atom2, BondSet* pBondSet);
int ResidueAndNextResidueInterBondConnectionCheck_charmm19(char *atomOnPreResi, char *atomOnNextResi, Residue *pPreResi, Residue *pNextResi);

int VdwAttEnergyAtomAndAtom(Residue* pResi1, Residue* pResi2, Atom *pAtom1, Atom *pAtom2, double *vdwAtt, double distance, int bondType);
int VdwRepEnergyAtomAndAtom(Residue* pResi1, Residue* pResi2, Atom *pAtom1, Atom *pAtom2, double *vdwRep, double distance,int bondType);
int HBondEnergyAtomAndAtom(Residue *pDonor, Residue *pAcceptor,Atom *atomH, Atom *atomA, double *hbond, double distanceHA,double ratio12,int bondType);
int HBondEnergyAtomAndAtomKortemmeModel(Residue *pDonor, Residue *pAcceptor,Atom *atomH, Atom *atomA, double *hbond, double distanceHA,double ratio12,int bondType);
int HBondEnergyAtomAndAtomNewFunction(Residue *pDonor, Residue *pAcceptor,Atom *atomH, Atom *atomA, double *etotal, double *edist, double *etheta, double *ephi,double distanceHA,double ratio12,int bondType);
int ElecEnergyAtomAndAtom(Residue *pResi1, Residue *pResi2,Atom *pAtom1, Atom *pAtom2, double *elec, double distance12,double ratio12,int bondType);
int LKDesolvationEnergyAtomAndAtom(Residue *pResi1, Residue *pResi2, Atom *pAtom1, Atom *pAtom2, double *energyP, double *energyH, double distance,int bondType);
int ResidueReferenceEnergy(Residue *pResidue, double energyTerm[MAX_EVOEF_ENERGY_TERM_NUM]);

int EVOEF_EnergyResidueSelfEnergy(Residue* pThis, double ratio12,double energyTerm[MAX_EVOEF_ENERGY_TERM_NUM]);
int EVOEF_EnergyResidueAndNextResidue(Residue* pThis, Residue* pOther, double ratio12,double energyTerm[MAX_EVOEF_ENERGY_TERM_NUM]);
int EVOEF_EnergyResidueAndOtherResidueSameChain(Residue* pThis, Residue* pOther, double ratio12,double energyTerm[MAX_EVOEF_ENERGY_TERM_NUM]);
int EVOEF_EnergyResidueAndOtherResidueDifferentChain(Residue* pThis, Residue* pOther, double ratio12,double energyTerm[MAX_EVOEF_ENERGY_TERM_NUM]);


double FOLDEF_calculate_atom_occupancy_atom_and_atom(Residue *pResi1, Residue *pResi2, Atom *pAtom1, Atom *pAtom2, double distance);
double FOLDFF_ElecEnergyAtomAndAtom(Atom *pAtom1, Atom *pAtom2, double distance);
double FOLDEF_HBondEnergyAtomAndAtom(Residue *pDonor, Residue *pAcceptor, Atom *atomH, Atom *atomA, double distanceHA);
int FOLDEF_SummationOfDifferentEnergyTermAtomAndAtom(double energyterms[MAX_EVOEF_ENERGY_TERM_NUM], Residue *pResi1, Residue *pResi2,Atom *pAtom1, Atom *pAtom2,double distance,double scaleByconnectivity,double averageBuriedRatio12);
double FOLDEF_VdwRepEnergyAtomAndAtom(Atom *pThis, Atom *pOther, double distance);

int CLASHCHECK_EnergyResidueSelfEnergy(Residue* pThis, double ratio1, double energyTerm[MAX_EVOEF_ENERGY_TERM_NUM]);
int CLASHCHECK_EnergyResidueAndNextResidue(Residue* pThis, Residue* pOther, double ratio12,double energyTerm[MAX_EVOEF_ENERGY_TERM_NUM]);
int CLASHCHECK_EnergyResidueAndOtherResidue(Residue* pThis, Residue* pOther, double ratio12,double energyTerm[MAX_EVOEF_ENERGY_TERM_NUM]);
double CLASHCHECK_ElecEnergyAtomAndAtom(Residue *pResi1, Residue *pResi2,Atom *pAtom1, Atom *pAtom2, double distance,double ratio12,int bondType);
double CLASHCHECK_VdwRepEnergyAtomAndAtom(Atom *pAtom1, Atom *pAtom2, double distance,int bondType);
#endif // ENERGY_FUNCTION_H


