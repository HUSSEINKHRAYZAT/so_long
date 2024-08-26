/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:34:30 by hkhrayza          #+#    #+#             */
/*   Updated: 2024/07/29 20:34:31 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	size_of_ui(unsigned int n)
{
	if (n / 10 == 0)
		return (1);
	else
		return (1 + size_of_ui(n / 10));
}

void	ft_putnbr_ui(unsigned int n)
{
	char	c;

	if (n / 10 == 0)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		c = n % 10 + '0';
		ft_putnbr_ui(n / 10);
		write(1, &c, 1);
	}
}

int	print_ui(unsigned int n)
{
	ft_putnbr_ui(n);
	return (size_of_ui(n));
}
