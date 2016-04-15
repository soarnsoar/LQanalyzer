if [[ $USER == "jalmond" ]];
    then
    if [[ $CATTAG == "" ]];
	then
	echo "This is a new git checkout of the main branch. You need the tag setup to run code" 
	cp $LQANALYZER_DIR/scripts/setup/tag_setup.sh $LQANALYZER_DIR/setup.sh
	export CATTAG=$CATVERSION$tag_numerator
    fi
fi
if [[ $CATTAG == "" ]];
    then
    echo "You are not running from a tag. You are running from Branch CatAnalyzer_13TeV"
    exit 1
fi

if [[ $CATTAG == "v7-6-3.2" ]];
    then
    echo "You are running on a tag with a bug in pileup weighting. update tag"
    exit 1
fi

latest_tag=""
while read line
do
    if [[ $line == "v"* ]];
    then
	latest_tag=$line
    fi
done < /data1/LQAnalyzer_rootfiles_for_analysis/CATTag/LatestTag.txt


if [[ $latest_tag == $CATTAG ]];then
    
    echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
    echo "Using latest tag "$CATTAG
    echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
else
    
    echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
    echo "Newer CATAnalzer tag available: "
    echo "Current tag "$CATTAG
    echo "Latest tag is "$latest_tag
    echo "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
    echo "Changes in this tag are:"
    while read line
    do
	echo $line
    done < /data1/LQAnalyzer_rootfiles_for_analysis/CATTag/TagDiff_${latest_tag}.txt
    
fi