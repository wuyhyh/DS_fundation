//
// Created by wuyuhang on 23-6-4.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int elemtype;
typedef struct {
	elemtype *data;
	int top;
	int max_cell_cnt;
} stack;

stack *create_stack(int size)
{
	stack *s = (stack *)malloc(sizeof(stack));
	s->data = (elemtype *)malloc(size * sizeof(elemtype));
	s->top = -1;
	s->max_cell_cnt = size;
	return s;
}

int main()
{
	stack * stack_foo= create_stack(10);

	return 0;
}
