/*
Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:

$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
$>
*/

#include <stdlib.h>
#include "ft_list.h"
#include <stdio.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *temp;
	t_list *temp2;

	temp = *begin_list;
	if (!cmp(temp->data, data_ref))
	{
		*begin_list = temp->next;
		free(temp);
		temp = *begin_list;
	}
	temp2 = temp->next;
	while (temp && temp2)
	{
		
		if (!cmp(data_ref, temp2->data))
		{
			temp->next = temp2->next;
			free(temp);
		}
		temp = temp->next;
		temp2 = temp->next;
	}
}

int int_cmp(void *data_ref, void *data)
{
	if ((int *)data_ref == (int *)data)
		return (0);
	return (1);
}

int main()
{
	t_list *lst = malloc(sizeof(t_list));
	int ptr = 1;
	int ptr2 = 2;
	int ptr3 = 3;
	lst->data = &ptr;
	t_list *lst2 = malloc(sizeof(t_list));
	lst2->data = &ptr2;
	t_list *lst3 = malloc(sizeof(t_list));
	lst3->data = &ptr3;
	lst->next = lst2;
	lst2->next = lst3;
	lst3->next = NULL;

	t_list *temp;
	temp = lst;
	ft_list_remove_if(&lst, &ptr2, int_cmp);
	while (temp)
	{
		printf("%d\n", *(int *)temp->data);
		temp = temp->next;
	}
}