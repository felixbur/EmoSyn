#! /usr/bin/perl -w

 # segmentDiphon.pl
 #
 # part of emoSyn
 #
 # Copyright (C) 2000  Felix Burkhardt
 #
 # This program is free software; you can redistribute it and/or
 # modify it under the terms of the GNU General Public License
 # as published by the Free Software Foundation; version 2 of the License.
 # 
 # This program is distributed in the hope that it will be useful,
 # but WITHOUT ANY WARRANTY; without even the implied warranty of
 # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 # GNU General Public License for more details.
 # 
 # You should have received a copy of the GNU General Public License
 # along with this program; if not, write to the Free Software
 # Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 #
 # author's contact: felixbur@gmx.de


$skipFrames=1;

sub log10  
{
    if ($_[0] <= 0) {
	return 0;
    } else {
	$returnVal = 0.4342944819 * log ($_[0]);
	if ($returnVal < 0) {
	    return 0;
	} else {
	    return  $returnVal;
	}
    }
}

if (scalar @ARGV < 4 ) {
    die "\nusage: segmentDiphon.pl diphonLabelFile formantFile f0File diphonDir\n\n";
}

$analyseStep=0.005; # analyse framelength in msek


$labFile = $ARGV[0];
chomp($labFile);
$forFile = $ARGV[1];
chomp($forFile);
$f0File = $ARGV[2];
chomp($f0File);

$diphonDir = $ARGV[3];

`pplain $forFile > tmpForFile.plain`;
`pplain $f0File > tmpF0File.plain`;


open(FOR_FILE, "tmpForFile.plain") or die "Can't open formant-file: $!\n";
open(F0_FILE, "tmpF0File.plain") or die "Can't open F0-file: $!\n";
open(LAB_FILE, $labFile) or die "Can't open label-file: $!\n";

# read in label file
$inField = 0;
print "reading entry  ";
LINE: while ($line=<LAB_FILE>) {
    last LINE if $line eq "\n";
    chomp($line);
    if ($inField) {
	
	$fc = 1;
	for $field (split ' ', $line, 9999) {
	    if ($fc == 1) {
		$time = $field;
	    }
	    if ($fc==3) {
		$entry = $field;
	    }
	    $fc++;
	}
	print "$entry ";
	if($entry =~ /-/) { # diphone names
	    $rec = ();
	    $rec->{name} = $entry; 
	    $rec->{start} = $time;
	} elsif ($entry =~ /^\.$/) {
	    $rec->{end} = $time;    
	    push @phonList, $rec;
	    print "\n";
	} else {
	    $rec->{$entry} = $time; 
	} 
	$inField++;
    }
    if ($line =~ /^#/) {
	$inField = 1;
    }
    
}
print "\n";
# calculate durance  and number of f0Vals
print "calculating startVals for diphone ";

for $i (0 .. $#phonList) {
    $name = $phonList[$i]{name};
    	print "$name ";
    $dur = $phonList[$i]{end}-$phonList[$i]{start};
    $valNum = $dur/$analyseStep;
    $valNum = `round $valNum`;

    $phonList[$i]{valNum} = $valNum;

    $t1 = $phonList[$i]{t1}-$phonList[$i]{start};
    $t1 = $t1/$analyseStep;
    $t1 = `round $t1`;
    $phonList[$i]{t1} = $t1;
    $brd = $phonList[$i]{brd}-$phonList[$i]{start};
    $brd = $brd/$analyseStep;
    $brd = `round $brd`;
    $phonList[$i]{brd} = $brd;
    $t2 = $phonList[$i]{t2}-$phonList[$i]{start};
    $t2 = $t2/$analyseStep;
    $t2 = `round $t2`;
    $phonList[$i]{t2} = $t2;
}
 
print "\n";
 
# read in formant and f0-values and rms-values
$i=0;
$rmsMax = 0;

while (defined($forLine = <FOR_FILE>) and defined($f0Line = <F0_FILE>)) {
    @forLine = split /\s/, $forLine;
    @f0Line = split /\s/, $f0Line;	
    
    $valArray[$i][0]=int($f0Line[0]*10);
    $valArray[$i][1]=int($forLine[0]);
    $valArray[$i][2]=int($forLine[1]);
    $valArray[$i][3]=int($forLine[2]);
    $valArray[$i][4]=int($f0Line[2]); # rms-value 
    $rmsMax = int($f0Line[2]) if $rmsMax < int($f0Line[2]); # find rms-max for scaling
    $valArray[$i][5]=int($forLine[3]);
    $valArray[$i][6]=int($forLine[4]);
    $i++;
}
$rmsRef = $rmsMax*0.001;  # choose Refval for dB, so that maxVal in dB = 60

for ($j=0; $j<$i; $j++) {
    $dBVal =  int(20 * log10( $valArray[$j][4]/$rmsRef));
    if ($dBVal<0) {
	print $dBVal."\n";
    }
    $valArray[$j][4]= $dBVal;
}

#$startOffset = $phonList[0]{start};
#$skipFrames = $startOffset/$analyseStep;
#$skipFrames = `round $skipFrames` - 2;

# assign formantVals to phones
for $i (0 .. $#phonList) {
    $valCounter =  $phonList[$i]{start}/$analyseStep;
    $valCounter =  `round $valCounter` - $skipFrames;
    $valNum = $phonList[$i]{valNum};
    for ($j=0; $j<$valNum; $j++) {
	$tmpF0[$j] = $valArray[$valCounter][0]; # f0 and formant freqs
	$tmpF1[$j] = $valArray[$valCounter][1];
	$tmpF2[$j] = $valArray[$valCounter][2];
	$tmpF3[$j] = $valArray[$valCounter][3];
	$tmpAmpVals[$j] = $valArray[$valCounter][4];
	$tmpF4[$j] = $valArray[$valCounter][5];
	$tmpF5[$j] = $valArray[$valCounter][6];
	$valCounter++; 
    }
    $phonList[$i]{F0Vals} = [@tmpF0] ;
    $phonList[$i]{F1Vals} = [@tmpF1] ;
    $phonList[$i]{F2Vals} = [@tmpF2] ;
    $phonList[$i]{F3Vals} = [@tmpF3] ;
    $phonList[$i]{AmpVals} = [@tmpAmpVals] ;  
    $phonList[$i]{F4Vals} = [@tmpF4] ;
    $phonList[$i]{F5Vals} = [@tmpF5] ;
}
for $i (0 .. $#phonList) {
    $name = $phonList[$i]{name};
    $fileName = "$diphonDir/$name.dip";
    open(DIPHON_FILE, "> $fileName") or die "Can't open output file: $!\n";
    print "writing Diphon $fileName\n";
    $valNum = $phonList[$i]{valNum};
    print DIPHON_FILE "name $name\n";
    print DIPHON_FILE "frameNumber $valNum\n";

    $t1 = $phonList[$i]{t1};
    print DIPHON_FILE "t1 $t1\n";
    $brd = $phonList[$i]{brd};
    print DIPHON_FILE "border $brd\n";
    $t2 = $phonList[$i]{t2};
    print DIPHON_FILE "t2 $t2\n";
    
    @F0Vals = @{$phonList[$i]{F0Vals}};
    @F1Vals = @{$phonList[$i]{F1Vals}};
    @F2Vals = @{$phonList[$i]{F2Vals}};
    @F3Vals = @{$phonList[$i]{F3Vals}};
    @AmpVals = @{$phonList[$i]{AmpVals}};
    @F4Vals = @{$phonList[$i]{F4Vals}};
    @F5Vals = @{$phonList[$i]{F5Vals}};
 
    for ($j=0; $j<$valNum; $j++) {
	print DIPHON_FILE "$F0Vals[$j] $AmpVals[$j] $F1Vals[$j] $F2Vals[$j] $F3Vals[$j] $F4Vals[$j] $F5Vals[$j]\n";
    }
    close(DIPHON_FILE);
}
