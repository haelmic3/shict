C=g++ -O9 -Wall --std=c++11
L=
M=main.o
O=
P=run.exec
.PHONY:all clean run
run:all
	./$P example.sht
all:$P
$P:$M $O
	$C -o $P $M $O $L
%.o:%.cpp
	$C -c $< -o $@
clean:
	rm $M $O $P
