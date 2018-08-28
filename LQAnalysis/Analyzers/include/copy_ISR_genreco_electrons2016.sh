cp ISR_genreco_electrons2016.h ISR_genreco_electrons2016_tau.h
find . -name 'ISR_genreco_electrons2016_tau.h' -type f -exec sed -i s/ISR_genreco_electrons2016/ISR_genreco_electrons2016_tau/g {} +

cp ISR_genreco_electrons2016.h ISR_genreco_electrons2016_DATA.h
find . -name 'ISR_genreco_electrons2016_DATA.h' -type f -exec sed -i s/ISR_genreco_electrons2016/ISR_genreco_electrons2016_DATA/g {} +

cp ISR_genreco_electrons2016.h ISR_genreco_electrons2016_BKG.h
find . -name 'ISR_genreco_electrons2016_BKG.h' -type f -exec sed -i s/ISR_genreco_electrons2016/ISR_genreco_electrons2016_BKG/g {} +
