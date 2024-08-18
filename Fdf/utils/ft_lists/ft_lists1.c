/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:18:26 by tilman            #+#    #+#             */
/*   Updated: 2024/08/08 10:59:45 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists.h"

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
	if (array[3])
		new_node->colour = array[3];
	new_node->next = NULL;
	free(array);
	return (new_node);
}

//array[x, y, z, colour]
t_list *append(t_list *listelement, int array[])
{
	t_list *new_node;

	if (listelement == NULL)
		return (init_list(array));
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
	if (array[3])
		new_node->colour = array[3];
	new_node->next = NULL;
	listelement->next = new_node;
	free(array);
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