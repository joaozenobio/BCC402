gcc src/main.c src/AustralianVoting.c src/AustralianVoting.h -o AustralianVoting
mkdir -p data/output
./AustralianVoting < ./data/input/example.in > ./data/output/example.out
