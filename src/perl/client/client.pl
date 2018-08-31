use strict;
use warnings;
use v5.10;

use ZMQ::FFI;
use ZMQ::FFI::Constants qw(ZMQ_REQ ZMQ_SUB);
use Data::Dumper qw(Dumper);
my $type= "tcp";
my $port= "4242";
my $ip= "localhost";
my @commande = ('identify',"forward","backward","leftwd","rightfwd","right","left","looking","gather","watch","attack","selfid","selfstats","inspect","next","jump");
say "Connecting to server…";
my $context = ZMQ::FFI->new();
my $requestor = $context->socket(ZMQ_REQ);
my $subscriber = $context->socket(ZMQ_SUB);
$requestor->connect("$type://$ip:$port");
$subscriber->connect("$type://$ip:4243");
$subscriber->subscribe('A');
while (1) {
   print Dumper $requestor; 
    print "mapxxxxxx
           \nxxxxxx
           \nxxxxxx\n";
        print "Entrée votre commande :\n";
        my $in = <STDIN>;
        chomp $in;
        print "$in\n";
    foreach my $com (@commande)
    {
        if ($in =~ $com)
        {
            if ($in =~/looking/)
            {
                print "Valeur (0-3) : \n";
                my $val = <STDIN>;
                chomp $val;
                print "$in|$val\n";
                #$requestor->send("$in|$val");
            }
            if ($in =~/looking/)
            {
                print "Valeur (0-3) : \n";
                my $val = <STDIN>;
                chomp $val;
                print "$in|$val\n";
                #$requestor->send("$in|$val");
            }
        }
    }
        #$requestor->send();
        #$requestor->recv();
        #my ($address, $contents) = $subscriber->recv_multipart();
        #print "[$address] $contents\n";
    sleep 10;
}
