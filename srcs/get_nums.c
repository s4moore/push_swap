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

#include "../includes/push_swap.h"

long int	ft_atoi(char *s)
{
	long long int	res;
	int				i;
	int				neg;

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
	}
	if (neg)
		res *= -1;
	if (res < -2147483648 || res > 2147483647)
		return (ERROR);
	return (res);
}

void	copy_nums(t_stack *stx)
{
	int	i;

	i = 0;
	free (stx->a);
	stx->a = ft_calloc(stx->total_nums, sizeof(int));
	while (i < stx->total_nums)
	{
		stx->a[i] = stx->nums[i];
		i++;
	}
}

void	make_helper_arrays(t_stack *stx)
{
	int	i;

	i = 0;
	ft_make_sorted(stx, &stx->sorted, stx->a_len - 1);
	if (stx->a_len <= 3)
		return ;
	get_lis(stx);
	stx->split_nums_len = 0;
	stx->split_nums = ft_calloc (sizeof(int),
			max(1, (stx->total_nums - stx->lis_len)));
	while (i < stx->total_nums)
	{
		if (!in_set(stx->a[i], stx->lis, stx->lis_len))
			stx->split_nums[stx->split_nums_len++] = stx->a[i];
		i++;
	}
	ft_make_sorted(stx, &stx->split_nums, stx->split_nums_len - 1);
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
			printf("Error\n");
			free_stack(stx);
			exit (2);
		}
		stx->a[argc - i - 1] = (int)t;
		stx->nums[argc - i - 1] = (int)t;
		stx->a_len++;
		stx->sorted[argc - i++ - 1] = (int)t;
	}
	make_helper_arrays(stx);
}
