load R0,10
load R2,3
load R1,3
load R3,0xff
load R4,0x1
xor R2,R2,R3
addi R2,R2,R4
loop:addi R0,R0,R2
jmpLE R1<=R0,loop
move RF,R0
halt