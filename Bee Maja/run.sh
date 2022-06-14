mkdir -p bin
gcc src/main.c src/BeeMaja.c src/BeeMaja.h -o bin/BeeMaja
mkdir -p data/output
./bin/BeeMaja < ./data/input/example.in > ./data/output/example.out
