#include <stdio.h>

int permutation(char *strone, char *strtwo){
	int chars[256] = { 0 };
	while(*strone) {
		chars[*strone++]++;
	
	}
	while(*strtwo) {
		chars[*strtwo++]--;
	}
	int i;
	for(i = 0; i < 256; i++) {
		if(chars[i] != 0) {
			return 1;
		}
	}
	return 0;
}

int main() {
	printf("%d\n", permutation("rabbit", "dog"));
	printf("%d\n", permutation("panama", "amapna"));
}
