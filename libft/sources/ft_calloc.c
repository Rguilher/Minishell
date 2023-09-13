/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguilher <rguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:45:35 by rguilher          #+#    #+#             */
/*   Updated: 2023/09/12 16:46:23 by rguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*t;

	if (size == 0 || nmemb == 0 || nmemb >= 2147483647 / size)
		return (NULL);
	i = nmemb * size;
	t = malloc(i);
	ft_bzero(t, i);
	return (t);
}
