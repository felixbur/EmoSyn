if [ $# == 0 ] ; then
    echo -e "\nusage: testSenSyn.sh <N | W | F | T | A> [modFile] [database]\n";
else
    
    if [ $# == 1 ] ; then
	echo -e "\nrunning emoSyn ...\n";
	emoSyn -i $1 -so tmp.doc -db diphonDB -ko tmp.par -vb -lo tmp.ll; 
    elif [ $# == 2 ] ; then
	echo -e "\nrunning emoSyn ...\n";
	emoSyn -i $1 -so tmp.doc -db diphonDB  -ko tmp.par -vb -mf $2 -lo tmp.ll;
    elif [ $# == 3 ] ; then
	echo -e "\nrunning emoSyn ...\n";
	emoSyn -i $1 -so tmp.doc  -ko tmp.par -vb -mf $2 -db $3 -lo tmp.ll;
    elif [ $# == 4 ] ; then
	echo -e "\nrunning emoSyn ...\n";
	emoSyn -i $1 -so tmp.doc  -ko tmp.par -vb -mf $2 -db $3 -kd $4 -lo tmp.ll;
    fi

    echo "running sensyn ...";
    sensyn -b tmp.doc > /dev/null; 
    echo "running conversions ...";
    sox  -r 10000 sensOut.sw tmp.wav;
    wav2sd10kHz tmp.wav;
    echo -e "playing tmp.wav ...\n";
    play tmp.wav;
fi
