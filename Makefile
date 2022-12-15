all:
	g++ ./src/IC_main.cpp -I. -o ./src/IC_main --std=c++11
	./src/IC_main

saveEpoch:
	g++ ./src/IC_main.cpp -I. -o ./src/IC_main --std=c++11
	./src/IC_main saveEpoch

complete:
	g++ ./src/NAND_data.cpp -o ./src/NAND_data.out && ./src/NAND_data.out > ./src/nand.txt
	g++ ./src/IC_main.cpp -I. -o ./src/IC_main && ./src/IC_main

test_util:
	g++ ./src/IC_util.cpp -I. -emaintest -o ./src/IC_util --std=c++11
	./src/IC_util
