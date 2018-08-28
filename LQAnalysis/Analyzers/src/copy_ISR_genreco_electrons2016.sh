cp ISR_genreco_electrons2016.cc ISR_genreco_electrons2016_tau.cc
find . -name 'ISR_genreco_electrons2016_tau.cc' -type f -exec sed -i s/ISR_genreco_electrons2016/ISR_genreco_electrons2016_tau/g {} +

cp ISR_genreco_electrons2016.cc ISR_genreco_electrons2016_DATA.cc
find . -name 'ISR_genreco_electrons2016_DATA.cc' -type f -exec sed -i s/ISR_genreco_electrons2016/ISR_genreco_electrons2016_DATA/g {} +

cp ISR_genreco_electrons2016.cc ISR_genreco_electrons2016_BKG.cc
find . -name 'ISR_genreco_electrons2016_BKG.cc' -type f -exec sed -i s/ISR_genreco_electrons2016/ISR_genreco_electrons2016_BKG/g {} +
