gcc src/main.c src/BeeMaja.c src/BeeMaja.h -o BeeMaja
mkdir -p data/output
./BeeMaja < ./data/input/example.in > ./data/output/example.out
