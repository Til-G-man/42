/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:29:37 by tgluckli          #+#    #+#             */
/*   Updated: 2024/05/06 17:42:38 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	space(char s)
{
	if (s == ' ' || s == ' ' || (9 <= s && s <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	out;
	int	sign_count;

	sign_count = 0;
	sign = 1;
	i = 0;
	while (space(str[i]) == 1)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		if (sign_count > 0)
			return (0);
		i++;
		sign_count++;
	}
	out = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		out = (out * 10) + (str[i++] - '0');
	}
	return (sign * out);
}
