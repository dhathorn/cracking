#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotate(int **img, int N) {
	int size = N/2 + N%2;
	int ul, ur, ll, lr, temp;
	int i;
	for(i =0; i < size; i++) {
		int j;
		for(j=0; j < N/2; j++) {
			ul = img[i][j];
			ur = img[j][N - i - 1];
			lr = img[N - i - 1][N - j - 1];
			ll = img[N - j -1][i];

			img[i][j] = ll;
			img[j][N - i - 1] = ul;
			img[N - i - 1][N - j - 1] = ur;
			img[N - j - 1][i] = lr;
		}
	}
}

void printmatrix(int **matrix, int N) {
	int i,j;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}


int main() {
	int N = 5;
	int **testmatrix = malloc(sizeof(int*) * N);
	int i;
	for( i = 0; i < N; i++) {
		testmatrix[i] = malloc(sizeof(int) * N);
		int j;
		for(j = 0; j < N; j++) {
			testmatrix[i][j] = i * 10 + j;
		}
	}
	printmatrix(testmatrix, N);
	rotate(testmatrix, N);
	printf("-----------------\n");
	printmatrix(testmatrix, N);
}
