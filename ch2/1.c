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

void dedup(element **linked_list) {
	element *current = *linked_list;
	while(current) {
		element *runner = current;
		while(runner->next) {
			if(runner->next->data == current->data) {
				element *delete = runner->next;
				runner->next = runner->next->next;
				free(delete);
			} else {
				runner = runner->next;
			}
		}
		current = current->next;
	}
}

int main() {
	element *head = NULL;
	element **stack = &head;
	int i;
	for(i = 0; i < 10; i++) {
		insert(stack, i);
	}
	insert(stack, 3);
	insert(stack, 4);
	insert(stack, 5);
	dedup(stack);
	element *iter = *stack;
	while(iter) {
		printf("%d\n", iter->data);
		iter = iter->next;
	}
}

