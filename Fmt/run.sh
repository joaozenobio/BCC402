gcc src/main.c src/Fmt.c src/Fmt.h -o Fmt
mkdir -p data/output
./Fmt < ./data/input/example.in > ./data/output/example.out
