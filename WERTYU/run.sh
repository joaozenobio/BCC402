mkdir -p bin
gcc src/main.c src/WERTYU.c src/WERTYU.h -o bin/WERTYU
mkdir -p data/output
./bin/WERTYU < ./data/input/example.in > ./data/output/example.out