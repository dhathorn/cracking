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

int k_last(element **stack, int k) {
	element *slow = *stack;
	element *fast = *stack;
	while(k--) {
		if(!fast) {
			return 0;
		}
		fast = fast->next;
	}
	while(fast->next) {
		fast = fast->next;
		slow = slow->next;
	}
	element *delete = slow->next;
	slow->next = slow->next->next;
	free(delete);
	return 1;
}




int main() {
	element *head = NULL;
	element **stack = &head;
	int i;
	for(i = 0; i < 10; i++) {
		insert(stack, i);
	}
	k_last(stack, 3);
	element *iter = *stack;
	while(iter) {
		printf("%d\n", iter->data);
		iter = iter->next;
	}
}

