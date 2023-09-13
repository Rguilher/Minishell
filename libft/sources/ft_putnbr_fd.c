/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguilher <rguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:45:35 by rguilher          #+#    #+#             */
/*   Updated: 2023/09/12 16:46:23 by rguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_is_negative(int n, int fd)
{
	write(fd, "-", 1);
	if (n == -2147483648)
	{	
		write(fd, "2", 1);
		n = n + 2000000000;
	}
	n = -n;
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		a;
	char	c;

	if (n < 0)
		n = nb_is_negative(n, fd);
	a = n % 10;
	c = a + '0';
	if (n <= 9)
	{
		write(fd, &c, 1);
		return ;
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		write(fd, &c, 1);
	}
}
