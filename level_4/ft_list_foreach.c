/*
Assignment name  : ft_list_foreach
Expected files   : ft_list_foreach.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a list and a function pointer, and applies this
function to each element of the list.

It must be declared as follows:

void    ft_list_foreach(t_list *begin_list, void (*f)(void *));

The function pointed to by f will be used as follows:

(*f)(list_ptr->data);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
*/

#include <stdlib.h>
#include <stdio.h>
#include "ft_list_foreach.h"

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *temp;

	temp = begin_list;
	while (temp)
	{
		(*f)(temp->data);
		temp = temp->next;
	}
}

void add_one(void *data)
{
	int *data_int = (int *)data;
	*data_int += 1;
}

//int main()
//{
//	t_list *lst = malloc(sizeof(t_list));
//	int ptr = 1;
//	int ptr2 = 2;
//	lst->data = &ptr;
//	t_list *lst2 = malloc(sizeof(t_list));
//	lst2->data = &ptr2;
//	lst->next = lst2;
//	lst2->next = NULL;

//	t_list *temp;
//	temp = lst;
//	ft_list_foreach(lst, add_one);
//	printf("%d %d\n", *(int *)lst2->data, *(int *)lst->data);
//}