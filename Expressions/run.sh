gcc src/main.c src/Expressions.c src/Expressions.h -o Expressions
mkdir -p data/output
./Expressions < ./data/input/example.in > ./data/output/example.out
