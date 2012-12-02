#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*void reverse(char* str){
	char* start;
	char* end;
	char swapTemp;
	end = str + strlen(str) - 1;
	start = str;

	while(start < end) {
		swapTemp = *start;
		*start++ = *end;
		*end-- = swapTemp;
	}
	return;
}*/

void strcat2(char *dst, char *src) {
	while(*dst)dst++;
	while(*dst++ = *src++);
}

int main() {
	char *newstring = malloc(sizeof(char) * 12);
	newstring = strdup("hi");
	char str[] = "literals";
	char test[10];
	strcat2(newstring, str);
	printf("%s\n", newstring);
	return 0;
}
