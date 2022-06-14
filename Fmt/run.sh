mkdir -p bin
gcc src/main.c src/Fmt.c src/Fmt.h -o bin/Fmt
mkdir -p data/output
./bin/Fmt < ./data/input/example.in > ./data/output/example.out
