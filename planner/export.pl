#! perl

use strict;
use warnings;

load_module("Dist::Build::XS::Export");

export_headers(dir => 'include');
