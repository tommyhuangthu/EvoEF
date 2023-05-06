# INTRODUCTION
EvoEF (**Evo**Design physcical **E**nergy **F**unction) is the physical energy function component of EvoDesign, an approach developed for de novo protein sequence design given a protein backbone scaffold. EvoDesign uses a composite score function that combines the position-specific scoring matrix (PSSM, derived from structure-based evolutionary analysis) and EvoEF for sequence/structure decoy evaluation in the Monte Carlo-based sequence design simulations. In the earlier versions of EvoDesign, FoldX was used to compute the physical energy, which is, however, rather slow. To improve the scoring accuracy and speed, we developed EvoEF to replace FoldX. Users can read the REFERENCE paper below for more details.

# INSTALLATION
We recommend users to download the EvoEF source-code package to your computer and build the EvoEF executable on your own. After downloading and unzipping the package, change into the $path/EvoEF/ directory and run "<b>g++ -O3 --fast-math -o EvoEF src/*.cpp</b>" or "<b>./build.sh</b>" if you are working on UNIX, Linux or Mac. If you are working on the Windows system, you need to install the g++ compiler first.

# USAGE
EvoEF can do the following calculations given a protein structure in the PDB format. <b>Note that EvoEF works with amino acids/proteins only; it cannot deal with nucleotides, DNA, RNA, water, and/or other molecules</b>.

## 1. ComputeStability

**ComputeStability** computes the stability (or total energy) of a protein or protein complex.

$path/EvoEF --command=ComputeStability  --pdb=protein.pdb

## 2. ComputeBinding

**ComputeBinding** computes the binding interaction energy of a protein-protein complex.

$path/EvoEF --command=ComputeBinding --pdb=complex.pdb

$path/EvoEF --command=ComputeBinding --split=A,BC --pdb=complex.pdb

User should specify how to split chains into two parts for "ComputeBinding". Otherwise, EvoEF will compute the interaction energy between any pair of chains.

## 3. RepairStructure

**RepairStructure** repairs incomplete side chains of a protein. The side chains will be optimized to reduce steric clashes at the best. The hydroxyl hydrogens of Ser, Thr, and Tyr are optimized. Side-chain groups of His, Asn, and Gln may be flipped for optimizing hydrogen-bonding networks.

$path/EvoEF --command=RepairStructure --pdb=your.pdb --num_of_runs=3

Running this command will create a new structure model named "your_Repair.pdb" in the current directory. The option "--number_of_runs" specify the number of repeated times of repairing/optimizing the structure sequentially (default: 3).

## 4. BuildMutant

**BuildMutant** builds mutant model.

$path/EvoEF --command=BuildMutant --pdb=your.pdb --mutant_file=individual_list.txt  --num_of_runs=10 

Here, the "individual_list.txt" file shows the mutants that you want to build. It has the following format:

CA171A,DB180E;

Each mutant is written in one line ending with “;”, and multiple mutations in a mutant are divided by “,”. Note that there is no gap or space character between single mutations. For each single mutation, the first letter is the reference amino acid, the second letter is the chain identifier of the amino acid followed by its position in the chain, and the last letter is the amino acid after mutation. Running the command successfully should generate a new structure file named “your_Model_1.pdb”. The option "--number_of_runs" specify the number of repeated times of optimizing the rotamers of the mutated and surrounding residues sequentially (default: 10). 

## 5. OptimizeHydrogen

**OptimizeHydrogen** optimizes hydroxyl hydrogens for Ser, Thr, and Tyr.

$path/EvoEF --command=OptimizeHydrogen --pdb=your.pdb --num_of_runs=3

Running this command successfully will create a file named "your_OptH.pdb" in the current directory. The option "--number_of_runs" specify the number of repeated times of optimizing the locations of Ser/Thr/Tyr hydroxyl hydrogens (default: 3).

## 6. To show EvoEF usage:

$path/EvoEF --help

# ABOUT ΔΔ<i>G</i> CALCULATION
EvoEF is most widely used to calculate the thermodynamic change (ΔΔ<i>G</i><sub>bind</sub> and ΔΔ<i>G</i><sub>stability</sub>) caused by amino acid mutations. ΔΔ<i>G</i><sub>stability</sub> is an indicator of measures protein stability change upon mutation(s), and ΔΔ<i>G</i><sub>bind</sub> is an indicator of the binding affinity change of protein-protein interaction upon mutation(s), where a negative Δ<i>G</i> value indicates favorable energy change.

The following steps are suggested for calculating ΔΔ<i>G</i>:

## 1. Repair your structure

$path/EvoEF --command=RepairStructure --pdb=your.pdb
  
Running this command successfully will generate a model named "your_Repair.pdb".

## 2. Build mutant

$path/EvoEF --command=BuildMutant --pdb=your_Repair.pdb --mutant_file=individual_list.txt
  
Running this command will generate a panel of models named as your_Repair_Model_dddd.pdb, where dddd is a four digit number from 0001 to 9999, depending on the number of mutants to be generated that are listed in the mutant file.

## 3. Calculate ΔΔ<i>G</i>

### 3.1 Calculate ΔΔ<i>G</i><sub>stability</sub>

First, calculate the stability score for the reference protein (Δ<i>G</i><sub>stability,ref</sub>):
  
$path/EvoEF --command=ComputeStability --pdb=your_Repair.pdb
  
Then, calculate the stability score for the mutant protein (Δ<i>G</i><sub>stability,mut</sub>), e.g.:
  
$path/EvoEF --command=ComputeStability --pdb=your_Repair_Model_0001.pdb
  
ΔΔ<i>G</i><sub>stability</sub> = Δ<i>G</i><sub>stability,mut</sub> - Δ<i>G</i><sub>stability,ref</sub>

### 3.2 Calculate ΔΔ<i>G</i><sub>bind</sub>
  
First, calculate the binding interaction score for the reference protein-protein complex (Δ<i>G</i><sub>bind,ref</sub>):

$path/EvoEF --command=ComputeBinding --pdb=your_Repair.pdb

Then, calculate the binding interaction score for the mutant complex (Δ<i>G</i><sub>bind,mut</sub>), e.g.:

$path/EvoEF --command=ComputeBinding --pdb=your_Repair_Model_0001.pdb

ΔΔ<i>G</i><sub>bind</sub> = Δ<i>G</i><sub>bind,mut</sub> - Δ<i>G</i><sub>bind,ref</sub>

If the protein complex has more than chains, you can use the "split" option to divide it into two parts before calculating the binding energy (see below).

# COPYRIGHT & CONTACT
Copyright (c) Xiaoqiang Huang. EvoEF is free to academic users. For suggestions, please contact xiaoqiah@umich.edu or xiaoqiah@outlook.com.

# REFERENCE
Pearce R, Huang X, Setiawan D, Zhang Y. EvoDesign: Designing Protein–Protein Binding Interactions Using Evolutionary Interface Profiles in Conjunction with an Optimized Physical Energy Function. Journal of Molecular Biology (2019) 431: 2467-2476.
