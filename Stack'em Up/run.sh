mkdir -p bin
gcc src/main.c src/StackemUp.c src/StackemUp.h -o bin/StackemUp
mkdir -p data/output
./bin/StackemUp < ./data/input/example.in > ./data/output/example.out
