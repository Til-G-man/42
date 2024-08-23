/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:16:40 by tilman            #+#    #+#             */
/*   Updated: 2024/08/22 14:40:12 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LISTS_H
# define FT_LISTS_H

# include "../utils.h"

t_list	*init_list(int array[]);
t_list	*append(t_list *listelement, int array[]);
int		delete_node(t_list *node);
void	*delete_list(t_list *listelement);
void	print_node(t_list *element);
int		print_list(t_list *element);
int		count_list(t_list *list);
t_list	*list_start(t_list *list);
t_list	*list_end(t_list *list);

#endif
