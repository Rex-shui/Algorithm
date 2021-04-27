#include "algorithm.h"

static int STACKLENGTH = 128;

typedef struct stack{
	void **base;
	int top;
}Stack;

void S_setLength(int length)
{
	STACKLENGTH = length;
}

Stack *S_get(void)
{
	Stack *s;
	s = malloc(sizeof(Stack));
	s->base = malloc(sizeof(int) * STACKLENGTH);
	s->top = -1;

	return s;
}

void S_free(Stack *s)
{
	free(s->base);
	free(s);
}

int S_isEmpty(Stack *s)
{
	if(s->top == -1){
		return 1;
	}

	return 0;
}

int S_isFull(Stack *s)
{
	if(s->top == STACKLENGTH-1){
		return 1;
	}

	return 0;
}

void *pop(Stack *s)
{
	if(S_isEmpty(s)){
		return NULL;
	}

	void *ret;
	ret = s->base[s->top];
	s->base[s->top] = NULL;
	s->top --;

	return ret;
}

void *push(Stack *s, void *data)
{
	if(S_isFull(s)){
                return NULL;
        }

	s->top++;
	s->base[s->top] = data;

	return data;
}
