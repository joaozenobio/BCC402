gcc src/main.c src/StackemUp.c src/StackemUp.h -o StackemUp
mkdir -p data/output
./StackemUp < ./data/input/example.in > ./data/output/example.out
