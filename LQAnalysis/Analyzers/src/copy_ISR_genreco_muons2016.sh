cp ISR_genreco_muons2016.cc ISR_genreco_muons2016_tautau.cc
find . -name 'ISR_genreco_muons2016_tautau.cc' -type f -exec sed -i s/ISR_genreco_muons2016/ISR_genreco_muons2016_tautau/g {} +

cp ISR_genreco_muons2016.cc ISR_genreco_muons2016_DATA.cc
find . -name 'ISR_genreco_muons2016_DATA.cc' -type f -exec sed -i s/ISR_genreco_muons2016/ISR_genreco_muons2016_DATA/g {} +

cp ISR_genreco_muons2016.cc ISR_genreco_muons2016_BKG.cc
find . -name 'ISR_genreco_muons2016_BKG.cc' -type f -exec sed -i s/ISR_genreco_muons2016/ISR_genreco_muons2016_BKG/g {} +
