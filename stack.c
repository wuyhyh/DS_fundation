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
	s->top = -1; //约定栈顶指针放在小地址
	s->max_cell_cnt = size;
	return s;
}

bool is_empty_stack(stack *s)
{
	return s->top == -1;
}

bool is_full_stack(stack *s)
{
	return s->top == (s->max_cell_cnt - 1); //编址是从0开始的
}

void push(stack *s, elemtype e)
{
	if (is_full_stack(s)) {
		printf("stack is full.\n");
		return;
	}
	s->data[++s->top] = e;
}

#define ERROR_CODE 100000
elemtype pop(stack *s)
{
	if (is_empty_stack(s)) {
		printf("stack is empty.\n");
		return ERROR_CODE;
	}
	return s->data[s->top--];
}

void destory_stack(stack *s)
{
	elemtype *data = s->data;
	if (data != NULL)
		free(data);
	printf("stack is destroyed.\n");
	free(s);
}

int main()
{
	printf("---- create stack ----\n");
	stack *stack_foo = create_stack(10);

	printf("---- push ----\n");
	for (int i = 1; i <= 10; i++)
		push(stack_foo, i);

	push(stack_foo, 100); //测试溢出

	printf("---- pop ----\n");
	printf("last elem last time = %d\n", pop(stack_foo));
	push(stack_foo, 1000);

	//pop所有元素
	while (!is_empty_stack(stack_foo))
		printf("%d ", pop(stack_foo));

	printf("\n");

	pop(stack_foo);

	destory_stack(stack_foo);

	return 0;
}
