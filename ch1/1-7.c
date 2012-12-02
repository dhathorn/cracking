#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void zeroer(int **matrix, int M, int N) {
	int *rows = malloc(sizeof(int) * M);
	int *cols = malloc(sizeof(int) * N);
	memset(rows, 0, M * sizeof(int));
	memset(cols, 0, N * sizeof(int));
	

	int i, j;
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			if(matrix[i][j] == 0) {
				rows[i] = 1;
				cols[j] = 1;
			}
		}
	}
	//zero out rows
	for(i = 0; i < M; i++) {
		if(rows[i] == 1) {
			memset(matrix[i], 0, N * sizeof(int));
		}
	}
	for(j = 0; j < N; j++) {
		if(cols[j] == 1) {
			for(i = 0; i < M; i++) {
				matrix[i][j] = 0;
			}
		}
	}
}

void printmatrix(int **matrix, int M, int N) {
	int i,j;
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}


int main() {
	int M = 10;
	int N = 5;
	int **testmatrix = malloc(sizeof(int*) * M);
	int i;
	for( i = 0; i < M; i++) {
		testmatrix[i] = malloc(sizeof(int) * N);
		int j;
		for(j = 0; j < N; j++) {
			testmatrix[i][j] = i * 10 + j;
		}
	}
	testmatrix[7][4] = 0;
	printmatrix(testmatrix, M, N);
	zeroer(testmatrix, M, N);
	printf("-----------------\n");
	printmatrix(testmatrix, M, N);
}
