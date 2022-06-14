mkdir -p bin
gcc src/main.c src/TheTrip.c src/TheTrip.h -o bin/TheTrip
mkdir -p data/output
./bin/TheTrip < ./data/input/example.in > ./data/output/example.out