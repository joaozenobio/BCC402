gcc src/main.c src/TheStern-BrocotNumberSystem.c src/TheStern-BrocotNumberSystem.h -o TheStern-BrocotNumberSystem
mkdir -p data/output
./TheStern-BrocotNumberSystem < ./data/input/example.in > ./data/output/example.out
