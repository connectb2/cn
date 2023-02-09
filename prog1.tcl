set ns [new Simulator]

#Open trace file and Nam file
set tracefile [open prog1.tr w]
$ns trace-all $tracefile
set namfile [open prog1.nam w]
$ns namtrace-all $namfile

#Create nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]

#Labeling nodes
$n0 label "Source"
$n2 label "Sink"
$ns color 1 "Blue"

#Creating duplex link between nodes
$ns duplex-link $n0 $n1 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 1Mb 10ms DropTail

#Make link Orientation
$ns duplex-link-op $n0 $n1 orient right
$ns duplex-link-op $n1 $n2 orient right

#Set queue size
$ns queue-limit $n0 $n1 10
$ns queue-limit $n1 $n2 10
      
#Setup transport layer connection
set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0
set sink0 [new Agent/TCPSink]
$ns attach-agent $n2 $sink0
$ns connect $tcp0 $sink0

#Setup Application layer traffic (cbr = constant bit rate)
set cbr0 [new Application/Traffic/CBR]
$cbr0 set type_ CBR
$cbr0 set packetSize_ 100
$cbr0 set rate_ 1Mb
$cbr0 set random_ false
$cbr0 attach-agent $tcp0
$tcp0 set class_ 1

proc finish {} {
    global ns tracefile namfile
    #Close the files
    $ns flush-trace
    close $tracefile
    close $namfile
    
    #Show no of packets dropped
    exec nam prog1.nam &
    exec echo "Number of packet drops is: " &
    exec grep -c "^d" prog1.tr &
    exit 0
}

#Schedule events
$ns at 0.0 "$cbr0 start"
$ns at 5.0 "finish"
$ns run
