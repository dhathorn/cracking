#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	struct element *next;
	int data;
} element ;

void insert(element **stack, int value) {
	element *newHead = malloc(sizeof(element));
	newHead->data = value;
	newHead->next = *stack;
	*stack = newHead;
}

int mid_delete(element *node) {
	element *next = node->next;
	node->data = next->data;
	node->next = next->next;
	free(next);
}




int main() {
	element *head = NULL;
	element **stack = &head;
	int i;
	for(i = 0; i < 10; i++) {
		insert(stack, i);
	}
	mid_delete(*stack);
	element *iter = *stack;
	while(iter) {
		printf("%d\n", iter->data);
		iter = iter->next;
	}
}

