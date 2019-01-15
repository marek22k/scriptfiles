package counter;

use strict;
use warnings;

our @EXPORT_OK = ("new");
our $VERSION = 0.01;

sub new {
    my $self = {
        _count => 0
    };
    bless $self, shift;
    return $self;
}

sub count {
    return $_[0]->{_count}++;
}

sub get {
    return $_[0]->{_count};
}