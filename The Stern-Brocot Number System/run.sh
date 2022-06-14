mkdir -p bin
gcc src/main.c src/TheStern-BrocotNumberSystem.c src/TheStern-BrocotNumberSystem.h -o bin/TheStern-BrocotNumberSystem
mkdir -p data/output
./bin/TheStern-BrocotNumberSystem < ./data/input/example.in > ./data/output/example.out
