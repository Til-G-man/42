/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:21:17 by tgluckli          #+#    #+#             */
/*   Updated: 2024/07/18 21:25:25 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_file_info.h"

int	get_num(char *str)
{
	char	**str_arr;

	*str_arr = ft_split(str, ' ');
	printf("str_arr:'%s'\n", str);
	return 0;
}
