#ifndef SLLIST_H
#define SLLIST_H

struct Node
{
	char *value;
	struct Node *next;
};

struct SLList
{
	struct Node *head;
	int size;
};

void sll_init(struct SLList*);
void sll_terminate(struct SLList*);

void  sll_push(struct SLList*, char*);
char* sll_pop (struct SLList*);

int sll_is_empty(struct SLList*);
int sll_size(struct SLList*);

#endif // SLLIST_H
