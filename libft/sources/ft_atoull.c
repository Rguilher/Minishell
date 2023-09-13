/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguilher <rguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:45:35 by rguilher          #+#    #+#             */
/*   Updated: 2023/09/12 16:46:23 by rguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_atoull(const char *nptr)
{
	int					flag;
	unsigned long long	nb;

	flag = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+')
		flag = 1;
	else if (*nptr == '-')
		flag = -1;
	if (flag)
		nptr++;
	nb = 0;
	while (ft_isdigit(*nptr))
	{
		nb = nb * 10 + (*nptr - 48);
		if ((flag != -1 && nb > LL_MAX) || nb > (unsigned long long)LL_MAX + 1)
			return ((unsigned long long)LL_MAX + 2);
		nptr++;
	}
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr && !ft_isdigit(*nptr))
		return ((unsigned long long)LL_MAX + 2);
	return (nb);
}
