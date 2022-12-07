# 7400_NN
predicting the output of the 7400 IC using a neural network

## create training data
```
g++ NAND_data.cpp -o NAND_data.out && ./NAND_data.out > nand.txt
```

## train and test the neural network
```
make
```

### Attribution/Thanks
- This project could not have happened without the tutorial and explanations given by [David Miller](https://vimeo.com/19569529). 