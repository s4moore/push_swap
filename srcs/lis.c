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

int	check_minus(int i, t_stack *stx)
{
	if (i == -1)
		i = stx->a_len - 1;
	return (i);
}

void	build_lis(t_stack *stx, int ***lis, int ***res, int k)
{
	int	j;
	int	i;

	i = k - 1;
	i = check_minus(i, stx);
	while (i != k)
	{
		j = k;
		while (j != i)
		{
			if (stx->a[i] > stx->a[j])
				(*lis)[k][i] = max((*lis)[k][i], (*lis)[k][j] + 1);
			if ((*lis)[k][i] > (*res)[k][0])
			{
				(*res)[k][0] = (*lis)[k][i];
				(*res)[k][1] = i;
			}
			j--;
			j = check_minus(j, stx);
		}
		i--;
		i = check_minus(i, stx);
	}
}

int	find_best_result(t_stack *stx, int **res)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stx->a_len)
	{
		if (res[i][0] > res[j][0])
			j = i;
		i++;
	}
	return (j);
}

void	take_best_lis(t_stack *stx, int **res, int **lis)
{
	int	i;
	int	j;
	int	k;

	j = find_best_result(stx, res);
	stx->lis = ft_calloc(sizeof(int), max(1, (res[j][0] + 1)));
	stx->lis_len = res[j][0] + 1;
	i = res[j][1];
	k = 0;
	while (k < stx->lis_len)
	{
		if (i == stx->a_len)
			i = 0;
		if (lis[j][i] == stx->lis_len - k - 1)
		{
			stx->lis[k++] = stx->a[i];
		}
		i++;
	}
	if (stx->lis_len < 2)
	{
		stx->lis_len = 2;
		stx->lis[0] = stx->sorted[0];
		stx->lis[1] = stx->sorted[1];
	}
}

void	get_lis(t_stack *stx)
{
	int	k;
	int	**lis;
	int	**res;

	res = ft_calloc(sizeof(int *), stx->a_len);
	lis = ft_calloc(sizeof(int *), stx->a_len);
	k = 0;
	while (k < stx->a_len)
	{
		lis[k] = ft_calloc(sizeof(int), stx->a_len);
		res[k] = ft_calloc(sizeof(int), 2);
		build_lis(stx, &lis, &res, k);
		k++;
	}
	take_best_lis(stx, res, lis);
	free_helpers(stx, res, lis);
}
