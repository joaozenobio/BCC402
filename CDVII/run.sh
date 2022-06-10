gcc src/main.c src/CDVII.c src/CDVII.h -o CDVII
mkdir -p data/output
./CDVII < ./data/input/example.in > ./data/output/example.out
