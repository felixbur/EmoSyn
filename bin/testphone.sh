if [ $# == 1 ] ; then
./emoSyn -testSensyn $1;  
sensyn -b klattTest.doc; 
sox -r 10000 sensOut.sw tmp.wav; 
wav2sd10kHz tmp.wav; 
play tmp.wav
else
    echo "usage testphone.sh testKlattParams"
fi