#ifndef ISR_genreco_muons2016_h
#define ISR_genreco_muons2016_h

#include "AnalyzerCore.h"
class ISR_genreco_muons2016 : public AnalyzerCore {

 public:
  //// constructors                                                                                                                                                             
  ISR_genreco_muons2016();
  ~ISR_genreco_muons2016();

  /// Functions from core
  virtual void BeginCycle() throw( LQError );
  virtual void BeginEvent()throw( LQError );
  virtual void ExecuteEvents()throw( LQError );
  virtual void EndCycle()throw( LQError );
  virtual void ClearOutputVectors()throw( LQError );
  
  void InitialiseAnalysis() throw( LQError );
  void MakeHistograms();
 private:
  
  //
  // The output variables 
  //
  /// Vectors for output objetcs
  std::vector<snu::KMuon> out_muons;
  std::vector<snu::KElectron> out_electrons;


  ClassDef ( ISR_genreco_muons2016, 1);
};
#endif
