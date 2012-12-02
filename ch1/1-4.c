#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int replacer(char *str) {
	while(*str){
		if(*str == ' ') {
			char *mover = str + 1;
			while(*mover++);
			mover++;
			while(mover > str) {
				*mover-- = *(mover - 2);
			}
			*str = '%';
			*(str + 1) = '2';
			*(str + 2) = '0';
		}
		str++;
	}
}

int replacer2(char *str) {
	int spacecount = 0;
	while(*str) {
		if(*str++ == ' ') {
			spacecount++;
		}
	}
	char *newend = str + spacecount * 2;
	while(newend > str) {
		if(*str == ' '){
			*newend-- = '0';
			*newend-- = '2';
			*newend-- = '%';
		} else {
			*newend-- = *str;
		}
		str--;
	}
}



int main() {
	char *teststring = malloc(sizeof(char) * 18);
	teststring = strdup("Mr John Smith");
	replacer2(teststring);
	printf("%s\n", teststring);
}
