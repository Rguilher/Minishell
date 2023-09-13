/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguilher <rguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:36:48 by rguilher          #+#    #+#             */
/*   Updated: 2022/09/18 00:36:50 by rguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*t;

	t = NULL;
	if ((unsigned char)c == '\0')
		return (&((char *)s)[ft_strlen(s)]);
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			t = &s[i];
		i++;
	}
	return ((char *)t);
}
