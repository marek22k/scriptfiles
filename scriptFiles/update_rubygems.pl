#!/usr/bin/perl

# Author: Marek K.

# They will be updated by Rubygems when calling this script.
# If Windows is used, the "pause" command is used so that
# the script can be called and the result displayed.

use strict;
use warnings;

print "";

if(!(system "gem update --system") && !(system "gem update"))
{
    print "Success!\n";
} else {
    print "Failed!\n";
}

system "pause" if $^O eq "MSWin32";