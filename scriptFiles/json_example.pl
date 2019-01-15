#!/usr/bin/perl

# JSON read / write example in perl

use warnings;

use JSON;
use Data::Dumper;

my $data = [1, 2, 4];
my $json = JSON::encode_json [1, 2, 4];

$Data::Dumper::Varname = "DATA";
print "\$DATA1 = JSON code\n\$DATA2 = Data\n";
print "Data: " . Dumper($data, $json);