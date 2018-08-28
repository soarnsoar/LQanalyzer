cp ISR_genreco_muons2016.h ISR_genreco_muons2016_tautau.h
find . -name 'ISR_genreco_muons2016_tautau.h' -type f -exec sed -i s/ISR_genreco_muons2016/ISR_genreco_muons2016_tautau/g {} +

cp ISR_genreco_muons2016.h ISR_genreco_muons2016_DATA.h
find . -name 'ISR_genreco_muons2016_DATA.h' -type f -exec sed -i s/ISR_genreco_muons2016/ISR_genreco_muons2016_DATA/g {} +

cp ISR_genreco_muons2016.h ISR_genreco_muons2016_BKG.h
find . -name 'ISR_genreco_muons2016_BKG.h' -type f -exec sed -i s/ISR_genreco_muons2016/ISR_genreco_muons2016_BKG/g {} +
