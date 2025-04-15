# SimHits
This is the SimHits version tailored for geometry change studies
## Getting started

SimHits depends on [e1039-core](https://github.com/Xinlong12580/e1039-core/tree/testori_muon_gun) for displaced tracking and [e1039-core]( https://github.com/Xinlong12580/e1039-core/tree/SpinQuest_upgrade_sagitta) for standard tracking.


To compile the analysis code under `SimAna` (after `setup_mye1039.sh`):
```
mkdir work
cd work
cmake ../src/ 
make clean
make
make install
cd ../
```

Later if you have made changes, do the recompile:
```
cd work
make clean
make
make install
```

### Paths needed to run

The main script is `RecoE1039Sim.C`.
It has different input options depending on the type of simulation to run.
For displaced A' signals, the macro depends on the location of signal files that lives on `HepMC_DIR`, which has been setup in the source script.

### To test
```
cd macro
root -b -q RecoE1039Sim.C
```


<details><summary>The following information are outdated and are not guaranteed to work. Need to update.</summary>


### Available input files (HepMC)

For our signal (Aprime):
- A' to Muons (z vertex between 5-6m): `/pnfs/e1039/persistent/users/yfeng/displaced_Aprime_Muons/`
- Trimuon signal: `/seaquest/users/cmantill/DarkQuest/lhe/output/trimuon/`

### Available options for simulation:

Some options are available in `macro/run_sim.py`. Here are examples of the most commonly used ones:

- A prime:
  ```
  mkdir output/

  python ./run_sim.py -n 10 --sim aprime-muon --zvertex 500 --displaced --inputfile Brem_0.750000_z500_600_eps_-6 --inputpath /seaquest/users/cmantill/DarkQuest/lhe/output/displaced_Aprime_Muons_z500-600/ --outfile aprime_to_muons_brem_0p75_eps-6.root --outpath output/

  python ./run_sim.py -n 10 --sim aprime-electron --zvertex 500 --displaced --inputfile Brem_0.163460_z500_600_eps_-6  --inputpath /seaquest/users/cmantill/DarkQuest/lhe/output/displaced_Aprime_Electrons_z500-600/ --outfile aprime_to_electrons_brem_0p16_eps-6.root --outpath output/
  ```

- Particle gun:
  ```
  # for electrons
  python ./run_sim.py -n 10 --sim gun --gun electron --zvertex 520 --displaced --outfile electron_gun_z520.root --outpath output/

  # for positrons
  python ./run_sim.py -n 10 --sim gun --gun positron --zvertex 520 --displaced --outfile positron_gun_z520.root --outpath output/

  # for photons	      
  python ./run_sim.py -n 10 --sim gun --gun gamma --zvertex 520 --displaced --outfile photon_gun_z520.root --outpath output/
  ```

- Trimuon:
  ```
  python ./run_sim.py -n 10 --sim trimuon --zvertex 490.0 --displaced --inputfile trimuon_0.5MS0gS1 --inputpath /seaquest/users/cmantill/DarkQuest/lhe/output/trimuon/ --outpath output/
  ```

### Add Hit Embedding

Currently the procedure to embed with e906 data hits and run the reco is the following:

1. run the usual workflow to produce the usual ntuple and the dst file

2. run the `RunEmbedding.C` script, change the `fn_sig` file to the dst file produced in the previous step. This is produce a dst file and a new ntuple reconstructed with the data embeded hits. The full list of e906 data files that can be embedded is placed under `/pnfs/e1039/persistent/users/kenichi/data_emb_e906/`.

### Adding pileup:

(To be updated.)

Currently, the procedure to mix pileup events is the following:

1. We use a sample of proton events (already generated for us). The sample can be generated with a proton gun or with pythia proton-nuclei interactions. The sample will contain G4 particles (muons only for now), their position and momentum).
The current sample that we use is stored in:
```
/pnfs/e1039/persistent/users/apun/bkg_study/e1039pythiaGen_26Oct21/
```

2. We take a file from this directory ( randomly chosen) and mix in a given number of particles in our simulated events. The number of particles is currently given by a beam intensity profile function.

Practically, you can obtain the command to mix pileup by adding the `--pileup` option, e.g.:
```
python ./run_sim.py -n 10 --sim gun --gun electron --zvertex 520 --displaced --outfile electron_gun_z520.root --outpath output/ --pileup 
```

</details>

