/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japostad <japostad@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:12:18 by japostad          #+#    #+#             */
/*   Updated: 2024/10/28 16:20:23 by japostad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!*base)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			++j;
		}
		++i;
	}
	if (i < 2)
		return (1);
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	n;
	int			base_len;

	n = nbr;
	base_len = ft_strlen(base);
	if (check_base(base))
	{
		if (n < 0)
		{	
			ft_putchar('-');
			n = -n;
		}
		if (n < base_len)
			ft_putchar(base[n]);
		else
		{
			ft_putnbr_base(n / base_len, base);
			ft_putchar(base[n % base_len]);
		}
	}
}
/*
int main()
{
    ft_putnbr_base(10,"0123456789abcdef");
	ft_putchar('\n');
    ft_putnbr_base(4,"01");
	ft_putchar('\n');
    ft_putnbr_base(4,"01234567");
	ft_putchar('\n');
    ft_putnbr_base(4,"0123456789");
}
*/
