all:
	g++ ./src/IC_main.cpp -I. -o ./src/IC_main
	./src/IC_main

complete:
	g++ ./src/NAND_data.cpp -o ./src/NAND_data.out && ./src/NAND_data.out > ./src/nand.txt
	g++ ./src/IC_main.cpp -I. -o ./src/IC_main && ./src/IC_main
