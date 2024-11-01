/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japostad <japostad@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:11:18 by japostad          #+#    #+#             */
/*   Updated: 2024/10/28 17:11:00 by japostad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char *c)
{
	if (*c == '\t' || *c == '\r' || *c == '\n' || *c == '\v'
		|| *c == ' ' || *c == '\f' || *c == '\b' || *c == '\a')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(&str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	res *= sign;
	return (res);
}
/*
#include <stdio.h>

int main()
{

		printf("ft_atoi result =>%d \n",ft_atoi("321321321973621936122173"));
		printf("ft_atoi result =>%d \n",ft_atoi("-321321321973621936122173"));
		printf("ft_atoi result =>%d \n",ft_atoi("0"));
		printf("ft_atoi result =>%d \n",ft_atoi(" ----+++1234ab567"));
}
*/
