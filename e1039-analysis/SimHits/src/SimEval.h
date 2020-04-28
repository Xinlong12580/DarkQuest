#ifndef _H_SimEval_H_
#define _H_SimEval_H_

// ROOT
#include <TSQLServer.h>
#include <TSQLResult.h>
#include <TSQLRow.h>

// Fun4All includes
#include <fun4all/SubsysReco.h>

// STL includes
#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <map>
//#include <algorithm>

class SQRun;
class SQSpillMap;

class SQEvent;
class SQHitMap;
class SQHitVector;

class PHG4TruthInfoContainer;

class SRecEvent;

class GeomSvc;

class TFile;
class TTree;

class SimEval: public SubsysReco {

public:

  SimEval(const std::string &name = "SimEval");
  virtual ~SimEval() {
  }
  
  int Init(PHCompositeNode *topNode);
  int InitRun(PHCompositeNode *topNode);
  int process_event(PHCompositeNode *topNode);
  int End(PHCompositeNode *topNode);
  
  int InitEvalTree();
  int ResetEvalVars();
  
  const std::string& get_hit_container_choice() const {
    return _hit_container_type;
  }
  
  void set_hit_container_choice(const std::string& hitContainerChoice) {
    _hit_container_type = hitContainerChoice;
  }
  
  const std::string& get_out_name() const {
    return _out_name;
  }
  
  void set_out_name(const std::string& outName) {
    _out_name = outName;
  }
  
private:

  int GetNodes(PHCompositeNode *topNode);
  
  int TruthEval(PHCompositeNode *topNode);
  
  std::string _hit_container_type;

  size_t _event;
  
  SQRun* _run_header;
  SQEvent * _event_header;
  SQHitMap *_hit_map;
  SQHitVector *_hit_vector;

  PHG4TruthInfoContainer* _truth;
  
  std::string _out_name;
  TTree* _tout_truth;
  
  int run_id;
  int event_id;
  
  // These are SQHits, info per hit
  int n_hits;
  int hit_detid[10000];
  int hit_elmid[10000];
  float hit_driftdis[10000];
  float hit_pos[10000];
  float hit_detz[10000];
  
  float hit_truthx[10000];
  float hit_truthy[10000];
  float hit_truthz[10000];
  float hit_truthpos[10000];
  
  int n_tracks;
  int gparid[1000];
  int gpid[1000];
  float gvx[1000];
  float gvy[1000];
  float gvz[1000];
  float gpx[1000];
  float gpy[1000];
  float gpz[1000];
  float gpt[1000];
  float geta[1000];
  float gphi[1000];

  float gx_st1[1000];
  float gy_st1[1000];
  float gz_st1[1000];
  float gpx_st1[1000];
  float gpy_st1[1000];
  float gpz_st1[1000];
  float gx_st2[1000];
  float gy_st2[1000];
  float gz_st2[1000];
  float gpx_st2[1000];
  float gpy_st2[1000];
  float gpz_st2[1000];
  float gx_st3[1000];
  float gy_st3[1000];
  float gz_st3[1000];
  float gpx_st3[1000];
  float gpy_st3[1000];
  float gpz_st3[1000];

  float gx_dp1[1000];
  float gy_dp1[1000];
  float gz_dp1[1000];

  float gx_dp2[1000];
  float gy_dp2[1000];
  float gz_dp2[1000];

  float gbarID_h1[1000];
  float gbarID_h2[1000];
  float gbarID_h4y[1000];
  float gbarID_dp1[1000];
  float gbarID_dp2[1000];

  float gquad_dp1[1000];
  float gquad_dp2[1000];
  float gquad_h4y[1000];

  int gnhits[1000];
  int gndc[1000];
  int gnhodo[1000];
  int gnprop[1000];
  int gnDP[1000];
  int gnH4Y[1000];

  int gelmid[1000][55];
  
  GeomSvc *p_geomSvc;
};


#endif /* _H_SimEval_H_ */
