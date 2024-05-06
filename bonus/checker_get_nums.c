/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_get_nums.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 07:29:18 by samoore           #+#    #+#             */
/*   Updated: 2023/12/19 14:46:25 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long int	ft_atoi(char *s)
{
	long int	res;
	int			i;
	int			neg;

	i = 0;
	res = 0;
	neg = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			neg = 1;
		i++;
	}
	if (s[i] < '0' || s[i] > '9')
		return (ERROR);
	while (s[i] && (s[i] >= 0 && s[i] <= '9'))
	{
		res *= 10;
		res += s[i++] - '0';
		if (res > 2147483648)
			return (ERROR);
	}
	if (neg)
		res *= -1;
	if (res < -2147483648 || res > 2147483647)
		return (ERROR);
	return (res);
}

void	init_stack(t_stack *stx, int argc)
{
	stx->a_len = 0;
	stx->b_len = 0;
	stx->a = ft_calloc(sizeof(int), (argc));
	stx->b = ft_calloc(sizeof(int), (argc));
	stx->sorted = ft_calloc(sizeof(int), argc);
	stx->total_nums = argc - 1;
}

int	ft_check_dupes(int *nums, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (nums[i] == nums[i - 1])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	get_nums(int argc, char **argv, t_stack *stx)
{
	long	t;
	int		i;

	init_stack(stx, argc);
	i = 1;
	while (i < argc)
	{
		t = ft_atoi(argv[i]);
		if (t == ERROR)
		{
			putstr("Error\n");
			free_stack(stx);
			exit (2);
		}
		stx->a[argc - i - 1] = (int)t;
		stx->a_len++;
		stx->sorted[argc - i++ - 1] = (int)t;
	}
	ft_make_sorted(stx);
	if (ft_check_dupes(stx->sorted, stx->a_len))
	{
		putstr("Error\n");
		free_stack(stx);
		exit (1);
	}
}
