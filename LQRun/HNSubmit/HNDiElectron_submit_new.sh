sktree -a HNDiElectron  -S DoubleEG -s FLATCAT  -n 311
sktree -a HNDiElectron -list hn_ee  -s FLATCAT -n 311
#sktree -a HNDiElectron-list qcd_eg -s SKTree_TriLepSkim -n 311
sktree -a HNDiElectron -S DoubleEG -fake True -s FLATCAT  -n 311
sktree -a HNDiElectron -i HN_EE_M40 -s SKTree_NoSkim -n 311
sktree -a HNDiElectron -i HN_EE_M100 -s SKTree_NoSkim -n 311
sktree -a HNDiElectron -i HN_EE_M500 -s SKTree_NoSkim -n 311
sktree -a HNDiElectron -i HN_EE_M1500 -s SKTree_NoSkim -n 311