mkdir -p bin
gcc src/main.c src/CDVII.c src/CDVII.h -o bin/CDVII
mkdir -p data/output
./bin/CDVII < ./data/input/example.in > ./data/output/example.out
