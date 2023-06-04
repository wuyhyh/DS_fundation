//
// Created by wuyuhang on 23-6-4.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int elemtype;

typedef struct list {
	elemtype data;
	struct list *next;
} list;

list *create_list()
{
	list *list_head = (list *)malloc(sizeof(list));
	list_head->next = NULL;
	list_head->data = -1;
	return list_head;
}

bool is_empty_list(list *l)
{
	return l->next == NULL;
}

int len_of_list(list *l)
{
	int node_cnt = 0;
	list *walker = l->next;
	while (walker != NULL) {
		node_cnt++;
		walker = walker->next;
	}
	return node_cnt;
}

list *search_list(list *l, elemtype e)
{
	list *walker = l->next;
	while (walker != NULL) {
		if (walker->data == e)
			return walker;
		else
			walker = walker->next;
	}
	return NULL;
}

list *pred_node(list *l, elemtype e)
{
	list *walker = l->next;
	list *pred = l;
	while (walker != NULL) {
		if (walker->data == e)
			return pred;
		else {
			walker = walker->next;
			pred = pred->next;
		}
	}
	return pred;
}

void insert_list(list *l, elemtype e)
{
	list *new_node = (list *)malloc(sizeof(list));
	new_node->data = e;
	new_node->next = l->next;
	l->next = new_node;
}

void delete_list(list *l, elemtype e)
{
	list *del_target = search_list(l, e);
	list *pred = pred_node(l, e);
	pred->next = del_target->next;
	free(del_target);
}

void print_list(list *l)
{
	list *walker = l->next;
	while (walker != NULL) {
		printf("%d ", walker->data);
		walker = walker->next;
	}
	printf("\n");
}

int main()
{
	printf("---- create list ----\n");
	list *list_foo = create_list();
	if (is_empty_list(list_foo))
		printf("list is empty!\n");

	printf("---- insert ----\n");
	for (int i = 1; i <= 10; i++) {
		insert_list(list_foo, i);
	}
	print_list(list_foo);
	printf("len of list = %d\n", len_of_list(list_foo));

	insert_list(list_foo, 1000); //insert at start
	print_list(list_foo);
	printf("len of list = %d\n", len_of_list(list_foo));

	insert_list(pred_node(list_foo, 5), 2000); //在list的中间插入
	print_list(list_foo);
	printf("len of list = %d\n", len_of_list(list_foo));

	insert_list(search_list(list_foo, 1), 3000); //insert at list end
	print_list(list_foo);
	printf("len of list = %d\n", len_of_list(list_foo));

	printf("---- delete ----\n");
	delete_list(list_foo, 1000); //delete first node
	print_list(list_foo);
	printf("len of list = %d\n", len_of_list(list_foo));

	delete_list(list_foo, 2000); //delete node at middle
	print_list(list_foo);
	printf("len of list = %d\n", len_of_list(list_foo));

	delete_list(list_foo, 3000); //delete last node
	print_list(list_foo);
	printf("len of list = %d\n", len_of_list(list_foo));

	return 0;
}
