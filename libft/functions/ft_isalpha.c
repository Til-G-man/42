/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:09:02 by tgluckli          #+#    #+#             */
/*   Updated: 2024/04/16 12:56:54 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(char c)
{
	if (64 < c && c < 91)
		return (1024);
	else if (96 < c && c < 123)
		return (1024);
	else
		return (0);
}
