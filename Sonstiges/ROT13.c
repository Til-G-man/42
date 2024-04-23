/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgluckli <tgluckli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:50:04 by tgluckli          #+#    #+#             */
/*   Updated: 2024/04/23 14:20:24 by tgluckli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
/*
char	*strdup(const char *s)
{

}
*/


char	*ft_rot13(const char *s)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *)malloc(strlen(s) + 1); // Allocate memory for the result string
	if (!result)
		return (NULL); // Return NULL if memory allocation fails
	while (s[i] != '\0') // Iterate through each character of the input string
	{
		if ((s[i] >= 'a' && s[i] <= 'm') || (s[i] >= 'A' && s[i] <= 'M'))
			result[i] = s[i] + 13; // Shift character 13 places forward if it's in the first half of the alphabet
		else if ((s[i] >= 'n' && s[i] <= 'z') || (s[i] >= 'N' && s[i] <= 'Z'))
			result[i] = s[i] - 13; // Shift character 13 places backward if it's in the second half of the alphabet
		else
			result[i] = s[i]; // Keep the character as is if it's not a letter
		i++;
	}
	result[i] = '\0'; // Null-terminate the result string
	return (result); // Return the encrypted string
}

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h> // Include for strlen

// Your ft_rot13 function here...

int	main(void)
{
    char    *s = "Rnpu cebwrpg bs gur 97 Pbzzba Pber pbagnvaf na rapbqrq uvag. Sbe "
"rnpu pvepyr, bayl bar cebwrpg cebivqrf gur pbeerpg uvag arrqrq sbe "
"gur arkg pvepyr. Guvf punyyratr vf vaqvivqhny, gurer vf bayl n "
"cevmr sbe bar fghqrag jvaare cebivqvat nyy qrpbqrq zrffntrf. Nal "
"nqinagntrq crbcyr pna cynl, yvxr pheerag be sbezre fgnss, ohg gur "
"cevmr jvyy erznva flzobyvp. Gur uvag sbe guvf svefg cebwrpg vf: "
"Ynetr pbjf trarebfvgl pbzrf jvgu punegf naq sbhe oybaqr ungf gb qrsl "
"hccre tenivgl ureb";
    char   *result = ft_rot13(s);

    printf("%s\n", result);
}
