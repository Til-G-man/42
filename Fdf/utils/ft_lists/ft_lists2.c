/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:12:24 by tilman            #+#    #+#             */
/*   Updated: 2024/08/07 23:09:40 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists.h"

void	*delete_list(t_list *listelement)
{
	t_list	*next_element;

	if (listelement == NULL)
		return (NULL);
	while (listelement->before != NULL)
	{
		listelement = listelement->before;
	}
	while (listelement->next != NULL)
	{
		next_element = listelement->next;
		delete_node(listelement);
		listelement = next_element;
	}
	if (listelement != NULL)
		delete_node(listelement);
	return (NULL);
}

void	print_listelement(t_list *element)
{
	if (element != NULL)
	{
		printf("x: %d\n"
			"y: %d\n"
			"z: %d\n"
			"colour: %d\n"
			"before: %p\n"
			"next: %p\n"
			"_____________\n",
			element->x, element->y, element->z,
			element->colour, element->before, element->next);
	}
}

int	print_list(t_list *element)
{
	while (element->before != NULL)
		element = element->before;
	while (element->next != NULL)
	{
		print_listelement(element);
		element = element-> next;
	}
	print_listelement(element);
	return (0);
}

int	count_list(t_list *t_list)
{
	int	count;

	count = 0;
	if (!t_list)
		return (0);
	while (t_list->before != NULL)
		t_list = t_list->before;
	while (t_list->next != NULL)
	{
		count++;
		t_list = t_list->next;
	}
	if (t_list != NULL)
		count++;
	return (count);
}
//int *create_array(int x, int y, int z, int colour)
//{
//	int *array = (int *)malloc(4 * sizeof(int));
//	if (array == NULL) {
//		fprintf(stderr, "Memory allocation failed\n");
//		exit(EXIT_FAILURE);
//	}

//	array[0] = x;
//	array[1] = y;
//	array[2] = z;
//	array[3] = colour;

//	return (array);
//}
//cc -Wall -Werror -Wextra  ft_lists1.c ft_lists2.c
//int	main(void)
//{
//	t_list	*new_list;
//	t_list	*test_node;

//	new_list = init_list(create_array(1,2,3,0xFFFFFF));
//	append(new_list, create_array(4,5,6,0x34DA2F));
//	test_node = append(new_list, create_array(7,8,9,0xF1de9A));
//	append(new_list, create_array(10,11,12,0x0000FF));
//	printf("count: %i\n", count_list(new_list));
//	printf("t_list ready\n");
//	print_list(new_list);
//	delete_node(test_node);
//	printf("testnode deleted\n");
//	print_list(new_list);
//	new_list = delete_list(new_list);
//	printf("count: %i\n", count_list(new_list));
//	return (0);
//}
