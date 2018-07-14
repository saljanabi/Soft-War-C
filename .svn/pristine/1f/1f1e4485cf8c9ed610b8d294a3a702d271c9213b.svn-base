use strict;
use warnings;
use v5.10;

use ZMQ::FFI;
use ZMQ::FFI::Constants qw(ZMQ_REQ ZMQ_SUB);
my $type= "tcp";
my $port= "4242";
my $ip= "localhost";

say "Connecting to server…";
my $context = ZMQ::FFI->new();
my $requestor = $context->socket(ZMQ_REQ);
my $subscriber = $context->socket(ZMQ_SUB);
$requestor->connect("$type://$ip:$port");
$subscriber->connect("$type://$ip:4243");
$subscriber->subscribe('A');
while (1) {
    $requestor->send("/left");
    $requestor->recv();
    my ($address, $contents) = $subscriber->recv_multipart();
    print "[$address] $contents\n";
    sleep 10;
}
