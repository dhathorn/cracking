#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	struct element *next;
	int data;
} element ;

void insert(element **ll, int value) {
	element *newHead = malloc(sizeof(element));
	newHead->data = value;
	newHead->next = *ll;
	*ll = newHead;
}
void movetohead(element **head, element *node) {
    node->next = *head;
    *head = node;
}

void partition(element **head, int x) {
    if(*head == NULL) {
        return;
    }
    element *iter = *head;
    while(iter->next != NULL) {
        if(iter->next->value < x) {
            element *newhead = iter->next;
            iter->next = newhead->next;
            movetohead(**head, iter->next);
        }
        iter = iter->next;
    }
}

int main() {
    element *head = NULL;
	element **ll = &head;
	int i;
	for(i = 0; i < 10; i++) {
		insert(ll, i);
	}
    partition(ll, 7);
	element *iter = *ll;
	while(iter) {
		printf("%d\n", iter->data);
		iter = iter->next;
	}
}
