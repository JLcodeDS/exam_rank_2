/*
Assignment name  : ft_list_size
Expected files   : ft_list_size.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

*/

#include "ft_list.h"
//#include <stdio.h>
//#include <stdlib.h>

int	ft_list_size(t_list *begin_list)
{
	t_list *temp;
	int size = 0;

	temp = begin_list;
	while (temp)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}

//int main()
//{
//	int val = 20;
//	t_list *lst = malloc(sizeof(t_list));
//	t_list *new = malloc(sizeof(t_list));
//	t_list *new2 = malloc(sizeof(t_list));

//	lst->data = &val;
//	new->data = &val;
//	new2->data = &val;
//	lst->next = new;
//	new->next = new2;
//	new2->next = NULL;
//	printf("%d\n", ft_list_size(lst));
//}