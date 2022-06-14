mkdir -p bin
gcc src/main.c src/AustralianVoting.c src/AustralianVoting.h -o bin/AustralianVoting
mkdir -p data/output
./bin/AustralianVoting < ./data/input/example.in > ./data/output/example.out
