#! /usr/local/bin/perl -w

$start=0;

# read in label file
while ($line=<>) {
    chomp($line);
    if ($start) {
	$fc=0;
	for $field ( split ' ', $line, 9999) {
	    
	    if ($field =~ /\d\.\d/ and $fc==0) {
		$start = $field;
		$new_start=$start*1000;
		
		$new_start=`round $new_start`;
		if ($new_start%5<3) {
		    $new_start=$new_start-$new_start%5;
		} else {
		    $new_start=$new_start+(5-$new_start%5);
		}
		$new_start=$new_start/1000;

		printf("%.3f ", $new_start);
	    } else {
		print "$field ";
	    }
	}
	print "\n";
    } else {
	print "$line\n";
    }
    if ($line =~ /^#/) {
	$start = 1;
    }
}
