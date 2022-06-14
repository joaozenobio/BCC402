mkdir -p bin
gcc src/main.c src/Expressions.c src/Expressions.h -o bin/Expressions
mkdir -p data/output
./bin/Expressions < ./data/input/example.in > ./data/output/example.out
