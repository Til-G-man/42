/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:18:26 by tilman            #+#    #+#             */
/*   Updated: 2024/08/22 14:40:06 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists.h"

t_list	*list_start(t_list *list)
{
	while(list)
	{
		if (!list->before)
			break;
		list = list->before;
	}
	return (list);
}

t_list	*list_end(t_list *list)
{
	while(list)
	{
		if (!list->next)
			break;
		list = list->next;
	}
	return (list);
}

//array[x, y, z, colour]
t_list	*init_list(int array[])
{
	t_list *new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
	{
		free(array);
		return (NULL);
	}
	new_node->before = NULL;
	new_node->x = array[0];
	new_node->y = array[1];
	new_node->z = array[2];
	new_node->colour_r = array[3];
	new_node->colour_g = array[4];
	new_node->colour_b = array[5];
	new_node->next = NULL;
	return (new_node);
}

//array[x, y, z, colour]
t_list *append(t_list *listelement, int array[])
{
	t_list *new_node;

	if (listelement == NULL)
		return (init_list(array));
	//printf("try to append to list\n");
	while (listelement->next != NULL)
		listelement = listelement->next;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
	{
		free(array);
		return (NULL);
	}
	new_node->before = listelement;
	new_node->x = array[0];
	new_node->y = array[1];
	new_node->z = array[2];
	new_node->colour_r = array[3];
	new_node->colour_g = array[4];
	new_node->colour_b = array[5];
	new_node->next = NULL;
	listelement->next = new_node;
	//printf("append done\n");
	//if (array[3] > 1)
		//print_node(new_node);
	return new_node;
}

int	delete_node(t_list *node)
{
	if (node == NULL)
		return (0);
	if (node->before != NULL)
		node->before->next = node->next;
	if (node->next != NULL)
		node->next->before = node->before;
	if (node)
	{
		free(node);
		node = NULL;
	}
	return (0);
}