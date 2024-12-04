#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

typedef int Type;
struct List
{
	Type data;
	struct List *prev;
	struct List *next;
};
typedef struct List List;

List* list_create_element(void)
{
	List *list = malloc(sizeof(List));
	return list;
}

void list_delete_element(List* list)
{
	free(list);
}

List* list_init(void)
{
	List *list = list_create_element();
	list->prev = list;
	list->next = list;
	return list;
}

void list_insert(List *prev, Type data)
{
	List *next = prev->next;
	List *curr = list_create_element();
	curr->data = data;
	curr->prev = prev;
	curr->next = next;
	prev->next = curr;
	next->prev = curr;
}

void list_remove(List *curr)
{
	List *prev = curr->prev;
	List *next = curr->next;
	list_delete_element(curr);
	prev->next = next;
	next->prev = prev;
}

List* list_search(List *list, Type data)
{
	for(List *curr = list->next; curr != list; curr = curr->next)
	{
		if(data == curr->data)
		{
			return curr;
		}
	}
	return NULL;
}

void list_free(List *list)
{
	while(list != list->next)
	{
		list_remove(list->next);
	}
	list_delete_element(list);
}

void list_dump(List *list)
{
	int flag = 0;
	for(List *curr = list->next; curr != list; curr = curr->next)
	{
		if(flag) { printf(" "); }
		flag = 1;
		printf("%d", curr->data);
	}
	printf("\n");
}

int main()
{
	int n, x;
	char command[16];
	List *list;
	List *temp;

	list = list_init();
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%s", command);

		if(strcmp(command, "insert") == 0)
		{
			scanf("%d", &x);
			list_insert(list, x);
		}
		if(strcmp(command, "delete") == 0)
		{
			scanf("%d", &x);
			temp = list_search(list, x);
			if(temp)
			{
				list_remove(temp);
			}
		}
		if(strcmp(command, "deleteFirst") == 0)
		{
			list_remove(list->next);
		}
		if(strcmp(command, "deleteLast") == 0)
		{
			list_remove(list->prev);
		}
	}	
	list_dump(list);
	list_free(list);

	return 0;
}

