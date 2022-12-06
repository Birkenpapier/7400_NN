all:
	g++ ./src/NAND_data.cpp -o ./src/NAND_data.out && ./src/NAND_data.out > ./src/nand.txt
	g++ ./src/IC_nnet.cpp -I. -o ./src/IC_nnet && ./src/IC_nnet

net:
	g++ ./src/IC_nnet.cpp -I. -o ./src/IC_nnet && ./src/IC_nnet