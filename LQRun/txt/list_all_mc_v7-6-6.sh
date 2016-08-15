#!/bin/sh

########################
### SAMPLE LIST ########## 
#######################


source ${LQANALYZER_DIR}/LQRun/txt/list_user_mc.sh


 declare -a input_samples=('WZ_pythia8')

 declare -a all_mc=('HN150_mumumu' 'HN40_mumumu' 'HN60_mumumu' 'HN700_mumumu' 'DY10to50_MCatNLO' 'DY50plus_MCatNLO' 'DY50plus_madgraph' 'DY5to50_madgraph' 'GJet_20to40_pythia8' 'GJet_40plus_pythia8' 'ggHtomm_Powheg' 'HN_EmEm_Schannel_100' 'HN_EmEm_Schannel_1100' 'HN_EmEm_Schannel_200' 'HN_EmEm_Schannel_500' 'HN_EmEm_Tchannel_100' 'HN_EmEm_Tchannel_1100' 'HN_EmEm_Tchannel_200' 'HN_EmEm_Tchannel_500' 'HN_EmMum_Schannel_100' 'HN_EmMum_Schannel_1100' 'HN_EmMum_Schannel_200' 'HN_EmMum_Schannel_500' 'HN_EpEp_Schannel_100' 'HN_EpEp_Schannel_1100' 'HN_EpEp_Schannel_200' 'HN_EpEp_Schannel_500' 'HN_EpEp_Tchannel_100' 'HN_EpEp_Tchannel_1100' 'HN_EpEp_Tchannel_200' 'HN_EpEp_Tchannel_500' 'HN_EpMup_Schannel_100' 'HN_EpMup_Schannel_1100' 'HN_EpMup_Schannel_200' 'HN_EpMup_Schannel_500' 'HN_MumEm_Schannel_100' 'HN_MumEm_Schannel_1100' 'HN_MumEm_Schannel_200' 'HN_MumEm_Schannel_500' 'HN_MumMum_Schannel_100' 'HN_MumMum_Schannel_1100' 'HN_MumMum_Schannel_200' 'HN_MumMum_Schannel_500' 'HN_MumMum_Tchannel_100' 'HN_MumMum_Tchannel_1100' 'HN_MumMum_Tchannel_200' 'HN_MumMum_Tchannel_500' 'HN_MupMup_Schannel_100' 'HN_MupMup_Schannel_1100' 'HN_MupMup_Schannel_200' 'HN_MupMup_Schannel_500' 'HN_EpMup_Schannel_100' 'HN_EpMup_Schannel_1100' 'HN_EpMup_Schannel_200' 'HN_EpMup_Schannel_500' 'HN_MupMup_Tchannel_100' 'HN_MupMup_Tchannel_1100' 'HN_MupMup_Tchannel_200' 'HN_MupMup_Tchannel_500' 'QCD_mu1000toINF_pythia8' 'QCD_em120to170_pythia8' 'QCD_mu120to170_pythia8' 'QCD_em15to20_pythia8' 'QCD_mu15to20_pythia8' 'QCD_em170to300_pythia8' 'QCD_mu170to300_pythia8' 'QCD_em20to30_pythia8' 'QCD_mu20to30_pythia8' 'QCD_mu300to470_pythia8' 'QCD_em300toINF_pythia8' 'QCD_DoubleEM_30to40_pythia8' 'QCD_em30to50_pythia8' 'QCD_mu30to50_pythia8' 'QCD_DoubleEM_30toInf_pythia8' 'QCD_DoubleEM_40toInf_pythia8' 'QCD_mu470to600_pythia8' 'QCD_em50to80_pythia8' 'QCD_mu50to80_pythia8' 'QCD_mu600to800_pythia8' 'QCD_mu800to1000_pythia8' 'QCD_em80to120_pythia8' 'QCD_mu80to120_pythia8' 'QCD_15to20_bcToE_pythia8' 'QCD_170to250_bcToE_pythia8' 'QCD_20to30_bcToE_pythia8' 'QCD_250toInf_bcToE_pythia8' 'QCD_30to80_bcToE_pythia8' 'QCD_80to170_bcToE_pythia8' 'singletop_s_MCatNLO' 'singletop_tbar_Powheg' 'singletop_t_Powheg' 'singletop_tbarW_Powheg' 'singletop_tW_Powheg' 'TTG_MCatNLO' 'TT_MCatNLO' 'TT_MG5' 'TTToHcToWA_3l4j_3mu_Mhc130MA3' 'TTToHcToWA_3l4j_3mu_Mhc130MA5' 'TTToHcToWA_3l4j_3mu_Mhc155MA30' 'TTToHcToWA_3l4j_3mu_Mhc90MA5' 'TTToHcToWA_3l4j_emu_Mhc130MA30' 'TTToHcToWA_3l4j_emu_Mhc130MA5' 'TTToHcToWA_3l4j_emu_Mhc155MA30' 'TTToHcToWA_3l4j_emu_Mhc90MA5' 'TTToHcToWZp_3l4j_1e2mu_Mhc155MZp5' 'TTToHcToWZp_3l4j_3mu_Mhc155MZp5' 'ttWJetsToLNu_MCatNLO' 'ttWJetsToQQ_MCatNLO' 'ttZToLLNuNu_MCatNLO' 'ttZToQQ_MCatNLO' 'TT_powheg' 'vhf_Htomm_Powheg' 'WG_lnuG_madgraph' 'WJets_MCatNLO' 'WW_llnn_powheg' 'WWZ_MCatNLO' 'WW_doublescattering' 'WW_pythia8' 'WZ_lllnu_MCatNLO' 'WZ_llqq_MCatNLO' 'WZ_lllnu_powheg' 'WZZ_MCatNLO' 'WZ_pythia8' 'WpWp_madgraph' 'WpWp_qcd_madgraph' 'ZG_llG_MCatNLO' 'ZZ_llnunu_powheg' 'ZZ_llqq_MCatNLO' 'ZZ_llll_MCatNLO' 'ZZ_llll_powheg' 'ZZZ_MCatNLO' 'ZZ_pythia8' 'ttHnobb_Powheg' 'ttHtobb_Powheg') 

 declare -a mc_noqcd=('HN150_mumumu' 'HN40_mumumu' 'HN60_mumumu' 'HN700_mumumu' 'DY10to50_MCatNLO' 'DY50plus_MCatNLO' 'DY50plus_madgraph' 'DY5to50_madgraph' 'GJet_20to40_pythia8' 'GJet_40plus_pythia8' 'ggHtomm_Powheg' 'HN_EmEm_Schannel_100' 'HN_EmEm_Schannel_1100' 'HN_EmEm_Schannel_200' 'HN_EmEm_Schannel_500' 'HN_EmEm_Tchannel_100' 'HN_EmEm_Tchannel_1100' 'HN_EmEm_Tchannel_200' 'HN_EmEm_Tchannel_500' 'HN_EmMum_Schannel_100' 'HN_EmMum_Schannel_1100' 'HN_EmMum_Schannel_200' 'HN_EmMum_Schannel_500' 'HN_EpEp_Schannel_100' 'HN_EpEp_Schannel_1100' 'HN_EpEp_Schannel_200' 'HN_EpEp_Schannel_500' 'HN_EpEp_Tchannel_100' 'HN_EpEp_Tchannel_1100' 'HN_EpEp_Tchannel_200' 'HN_EpEp_Tchannel_500' 'HN_EpMup_Schannel_100' 'HN_EpMup_Schannel_1100' 'HN_EpMup_Schannel_200' 'HN_EpMup_Schannel_500' 'HN_MumEm_Schannel_100' 'HN_MumEm_Schannel_1100' 'HN_MumEm_Schannel_200' 'HN_MumEm_Schannel_500' 'HN_MumMum_Schannel_100' 'HN_MumMum_Schannel_1100' 'HN_MumMum_Schannel_200' 'HN_MumMum_Schannel_500' 'HN_MumMum_Tchannel_100' 'HN_MumMum_Tchannel_1100' 'HN_MumMum_Tchannel_200' 'HN_MumMum_Tchannel_500' 'HN_MupMup_Schannel_100' 'HN_MupMup_Schannel_1100' 'HN_MupMup_Schannel_200' 'HN_MupMup_Schannel_500' 'HN_EpMup_Schannel_100' 'HN_EpMup_Schannel_1100' 'HN_EpMup_Schannel_200' 'HN_EpMup_Schannel_500' 'HN_MupMup_Tchannel_100' 'HN_MupMup_Tchannel_1100' 'HN_MupMup_Tchannel_200' 'HN_MupMup_Tchannel_500' 'singletop_s_MCatNLO' 'singletop_tbar_Powheg' 'singletop_t_Powheg' 'singletop_tbarW_Powheg' 'singletop_tW_Powheg' 'TTG_MCatNLO' 'TT_MCatNLO' 'TT_MG5' 'TTToHcToWA_3l4j_3mu_Mhc130MA3' 'TTToHcToWA_3l4j_3mu_Mhc130MA5' 'TTToHcToWA_3l4j_3mu_Mhc155MA30' 'TTToHcToWA_3l4j_3mu_Mhc90MA5' 'TTToHcToWA_3l4j_emu_Mhc130MA30' 'TTToHcToWA_3l4j_emu_Mhc130MA5' 'TTToHcToWA_3l4j_emu_Mhc155MA30' 'TTToHcToWA_3l4j_emu_Mhc90MA5' 'TTToHcToWZp_3l4j_1e2mu_Mhc155MZp5' 'TTToHcToWZp_3l4j_3mu_Mhc155MZp5' 'ttWJetsToLNu_MCatNLO' 'ttWJetsToQQ_MCatNLO' 'ttZToLLNuNu_MCatNLO' 'ttZToQQ_MCatNLO' 'TT_powheg' 'vhf_Htomm_Powheg' 'WG_lnuG_madgraph' 'WJets_MCatNLO' 'WW_llnn_powheg' 'WWZ_MCatNLO' 'WW_doublescattering' 'WW_pythia8' 'WZ_lllnu_MCatNLO' 'WZ_llqq_MCatNLO' 'WZ_lllnu_powheg' 'WZZ_MCatNLO' 'WZ_pythia8' 'WpWp_madgraph' 'WpWp_qcd_madgraph' 'ZG_llG_MCatNLO' 'ZZ_llnunu_powheg' 'ZZ_llqq_MCatNLO' 'ZZ_llll_MCatNLO' 'ZZ_llll_powheg' 'ZZZ_MCatNLO' 'ZZ_pythia8' 'ttHnobb_Powheg' 'ttHtobb_Powheg') 

 declare -a ch_wa=('TTToHcToWA_3l4j_3mu_Mhc130MA3' 'TTToHcToWA_3l4j_3mu_Mhc130MA5' 'TTToHcToWA_3l4j_3mu_Mhc155MA30' 'TTToHcToWA_3l4j_3mu_Mhc90MA5' 'TTToHcToWA_3l4j_emu_Mhc130MA30' 'TTToHcToWA_3l4j_emu_Mhc130MA5' 'TTToHcToWA_3l4j_emu_Mhc155MA30' 'TTToHcToWA_3l4j_emu_Mhc90MA5' '') 


 declare -a ch_wz=('TTToHcToWZp_3l4j_1e2mu_Mhc155MZp5' 'TTToHcToWZp_3l4j_3mu_Mhc155MZp5' '') 

 declare -a hn_ll_ee=('HN_EmEm_Schannel_100' 'HN_EmEm_Schannel_1100' 'HN_EmEm_Schannel_200' 'HN_EmEm_Schannel_500' 'HN_EpEp_Schannel_100' 'HN_EpEp_Schannel_1100' 'HN_EpEp_Schannel_200' 'HN_EpEp_Schannel_500' '') 

 declare -a hn_ll_mm=('HN_MumEm_Schannel_100' 'HN_MumEm_Schannel_1100' 'HN_MumEm_Schannel_200' 'HN_MumEm_Schannel_500' 'HN_MumMum_Schannel_100' 'HN_MumMum_Schannel_1100' 'HN_MumMum_Schannel_200' 'HN_MumMum_Schannel_500' 'HN_MupMup_Schannel_100' 'HN_MupMup_Schannel_1100' 'HN_MupMup_Schannel_200' 'HN_MupMup_Schannel_500' '') 

 declare -a hn_ll_em=('HN_EmMum_Schannel_100' 'HN_EmMum_Schannel_1100' 'HN_EmMum_Schannel_200' 'HN_EmMum_Schannel_500' 'HN_EpMup_Schannel_100' 'HN_EpMup_Schannel_1100' 'HN_EpMup_Schannel_200' 'HN_EpMup_Schannel_500' 'HN_EpMup_Schannel_100' 'HN_EpMup_Schannel_1100' 'HN_EpMup_Schannel_200' 'HN_EpMup_Schannel_500' '') 

 declare -a hn_mmm=('') 

 declare -a hn_ll_tchann_ee=('HN_EmEm_Tchannel_100' 'HN_EmEm_Tchannel_1100' 'HN_EmEm_Tchannel_200' 'HN_EmEm_Tchannel_500' 'HN_EpEp_Tchannel_100' 'HN_EpEp_Tchannel_1100' 'HN_EpEp_Tchannel_200' 'HN_EpEp_Tchannel_500' '') 

 declare -a hn_ll_tchann_mm=('HN_MumMum_Tchannel_100' 'HN_MumMum_Tchannel_1100' 'HN_MumMum_Tchannel_200' 'HN_MumMum_Tchannel_500' 'HN_MupMup_Tchannel_100' 'HN_MupMup_Tchannel_1100' 'HN_MupMup_Tchannel_200' 'HN_MupMup_Tchannel_500' '') 


declare -a diboson_pythia=('WZ_pythia8' 'ZZ_pythia8' 'WW_pythia8')

declare -a dy_mcatnlo=('DY10to50_MCatNLO' 'DY50plus_MCatNLO') 

declare -a dilepton_list=('DY10to50_MCatNLO' 'DY50plus_MCatNLO' 'WJets_MCatNLO' 'WZ_pythia8' 'ZZ_pythia8' 'WW_pythia8'  'TT_MG5' 'singletop_s_MCatNLO' 'singletop_tbar_Powheg' 'singletop_t_Powheg' 'singletop_tbarW_Powheg' 'singletop_tW_Powheg' 'ttWJetsToLNu_MCatNLO' 'ttWJetsToQQ_MCatNLO' 'ttZToQQ_MCatNLO' 'TTG_MCatNLO' 'ttZToLLNuNu_MCatNLO' 'WpWp_madgraph' 'WpWp_qcd_madgraph' 'ttHnobb_Powheg' 'ttHtobb_Powheg' 'ZZZ_MCatNLO' 'WZZ_MCatNLO')
declare -a trilepton_list=('DY10to50_MCatNLO' 'DY50plus_MCatNLO' 'WJets_MCatNLO' 'WZ_pythia8' 'ZZ_pythia8' 'WW_pythia8'  'TT_MG5' 'singletop_s_MCatNLO' 'singletop_tbar_Powheg' 'singletop_t_Powheg' 'singletop_tbarW_Powheg' 'singletop_tW_Powheg' 'ZZ_llnunu_powheg' 'ZZ_llqq_MCatNLO' 'ZZ_llll_MCatNLO' 'ZZ_llll_powheg' 'WJets_MCatNLO' 'WW_llnn_powheg' 'WZ_lllnu_powheg' 'WZ_lllnu_MCatNLO' 'WZ_llqq_MCatNLO' 'WN_lllnu_powheg' 'WZZ_MCatNLO' 'ZZZ_MCatNLO')

declare -a qcd=('QCD_mu1000toINF_pythia8' 'QCD_em120to170_pythia8' 'QCD_mu120to170_pythia8' 'QCD_em15to20_pythia8' 'QCD_mu15to20_pythia8' 'QCD_em170to300_pythia8' 'QCD_mu170to300_pythia8' 'QCD_em20to30_pythia8' 'QCD_mu20to30_pythia8' 'QCD_mu300to470_pythia8' 'QCD_em300toINF_pythia8' 'QCD_DoubleEM_30to40_pythia8' 'QCD_em30to50_pythia8' 'QCD_mu30to50_pythia8' 'QCD_DoubleEM_30toInf_pythia8' 'QCD_DoubleEM_40toInf_pythia8' 'QCD_mu470to600_pythia8' 'QCD_em50to80_pythia8' 'QCD_mu50to80_pythia8' 'QCD_mu600to800_pythia8' 'QCD_mu800to1000_pythia8' 'QCD_em80to120_pythia8' 'QCD_mu80to120_pythia8' 'QCD_15to20_bcToE_pythia8' 'QCD_170to250_bcToE_pythia8' 'QCD_20to30_bcToE_pythia8' 'QCD_250toInf_bcToE_pythia8' 'QCD_30to80_bcToE_pythia8' 'QCD_80to170_bcToE_pythia8') 

declare -a qcd_mu=('QCD_mu1000toINF_pythia8' 'QCD_mu120to170_pythia8' 'QCD_mu15to20_pythia8' 'QCD_mu170to300_pythia8' 'QCD_mu20to30_pythia8' 'QCD_mu300to470_pythia8' 'QCD_mu30to50_pythia8' 'QCD_mu470to600_pythia8' 'QCD_mu50to80_pythia8' 'QCD_mu600to800_pythia8' 'QCD_mu800to1000_pythia8' 'QCD_mu80to120_pythia8') 

declare -a qcd_eg=('QCD_em120to170_pythia8' 'QCD_em15to20_pythia8' 'QCD_em170to300_pythia8' 'QCD_em20to30_pythia8' 'QCD_em300toINF_pythia8' 'QCD_DoubleEM_30to40_pythia8' 'QCD_em30to50_pythia8' 'QCD_DoubleEM_30toInf_pythia8' 'QCD_DoubleEM_40toInf_pythia8' 'QCD_em50to80_pythia8' 'QCD_em80to120_pythia8' 'QCD_15to20_bcToE_pythia8' 'QCD_170to250_bcToE_pythia8' 'QCD_20to30_bcToE_pythia8' 'QCD_250toInf_bcToE_pythia8' 'QCD_30to80_bcToE_pythia8' 'QCD_80to170_bcToE_pythia8') 


declare -a hn_mm=('WZ_pythia8' 'ZZ_pythia8' 'WpWp_madgraph' 'WpWp_qcd_madgraph'  'ttWJetsToLNu_MCatNLO' 'ttWJetsToQQ_MCatNLO' 'ttZToLLNuNu_MCatNLO' 'ttZToQQ_MCatNLO' 'ttHtobb_Powheg' 'ttHnobb_Powheg' 'WZZ_MCatNLO' 'vhf_Htomm_Powheg' 'ttZToLLNuNu_MCatNLO' 'ggHtomm_Powheg') 

declare -a hn_ee=('WZ_pythia8' 'ZZ_pythia8' 'WpWp_madgraph' 'WpWp_qcd_madgraph'  'ttWJetsToLNu_MCatNLO' 'ttWJetsToQQ_MCatNLO' 'ttZToLLNuNu_MCatNLO' 'ttZToQQ_MCatNLO' 'DY10to50_MCatNLO' 'DY50plus_MCatNLO' 'ttHtobb_Powheg' 'ttHnobb_Powheg' 'WZZ_MCatNLO' 'vhf_Htomm_Powheg' 'ttZToLLNuNu_MCatNLO' 'ggHtomm_Powheg') 

declare -a hn_fakeee=('DY10to50_MCatNLO' 'DY50plus_MCatNLO' 'WJets_MCatNLO'  'TT_MG5')


declare -a singletop=('singletop_s_MCatNLO' 'singletop_tbar_Powheg' 'singletop_t_Powheg' 'singletop_tbarW_Powheg' 'singletop_tW_Powheg') 