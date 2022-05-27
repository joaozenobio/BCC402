#include <stdio.h>
#include <math.h>

typedef struct {
	int x;
	int y;
} P;

P converteCoordenadas(int n) {
	n--;
	int circle = floor(n/6);
	int pos = n - (6 * circle);
	P p = {circle, 1};
	printf("(%d, %d)\n", p.x, p.y);
	for(int i = 1; (i < circle + 1) && pos != 0; i++) {
		(p.x)--;
		(p.y)++;
		pos--;
		printf("(%d, %d)\n", p.x, p.y);
	}
	for(int i = 0; (i < circle + 1) && pos !=0; i++) {
		(p.x)--;
                pos--;
		printf("(%d, %d)\n", p.x, p.y);
	}
	for(int i = 0; (i < circle + 1) && pos !=0; i++) {
                (p.y)--;
                pos--;
		printf("(%d, %d)\n", p.x, p.y);
        }
	for(int i = 0; (i < circle + 1) && pos !=0; i++) {
                (p.x)++;
		(p.y)--;
                pos--;
		printf("(%d, %d)\n", p.x, p.y);
        }
	for(int i = 0; (i < circle + 1) && pos !=0; i++) {
                (p.x)++;
                pos--;
		printf("(%d, %d)\n", p.x, p.y);
        }
	for(int i = 0; (i < circle + 1) && pos !=0; i++) {
                (p.y)++;
                pos--;
		printf("(%d, %d)\n", p.x, p.y);
        }
	printf("(%d, %d)\n", p.x, p.y);
	return p;
}

int main() {
	int n = 1;
	while(n != 0) {
		scanf("%d", &n);
		printf("%d\n", n);
		converteCoordenadas(n);
	}
	return 0;
}
