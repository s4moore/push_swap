/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:57:56 by samoore           #+#    #+#             */
/*   Updated: 2023/12/20 14:11:02 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_target_a(t_stack *stx, int j)
{
	int	i;
	int	low;

	i = find_low(stx);
	low = stx->a[i];
	if (stx->b[j] < stx->a[i])
		return (i);
	if (i == 0)
		i = stx->a_len - 1;
	else
		i -= 1;
	while (stx->a[i] != low && stx->a[i] < stx->b[j])
	{
		i--;
		if (i == -1)
			i = stx->a_len - 1;
	}

	return (i);
}

void	get_cost(int *target, int *moves, int *up_down, int len)
{
	if (len == 1)
	{
		*moves = 0;
		*up_down = 0;
		return ;
	}
	if (*target < (len / 2))
	{
		*moves = (*target + 1);
		*up_down = DOWN;
	}
	else
	{
		*moves = (len - *target - 1);
		if (*moves == 0)
			*up_down = 0;
		else
			*up_down = UP;
	}
}

void	optimise_cost(t_move *m, int a_len, int b_len)
{
	if (m->move_a == 0)
		m->moves = m->move_b;
	else if (m->move_b == 0)
		m->moves = m->move_a;
	else if (m->a_up_down == m->b_up_down)
		m->moves = max(m->move_a, m->move_b);
	else if (up_a_up_b_down(m, b_len))
		set_m(m, 'b', UP, b_len - m->j - 1);
	else if (up_b_up_a_down(m, a_len, b_len))
		set_m(m, 'a', UP, a_len - m->i - 1);
	else if (down_a_down_b_up(m, b_len))
		set_m(m, 'b', DOWN, m->j + 1);
	else if (down_a_up_b_down(m, b_len))
		set_m(m, 'a', DOWN, m->i + 1);
}

void	check_cost(t_stack *stx, int j, t_move *mov)
{
	int	i;

	i = find_target_a(stx, j);
	mov->i = i;
	mov->j = j;
	get_cost(&mov->i, &mov->move_a, &mov->a_up_down, stx->a_len);
	get_cost(&mov->j, &mov->move_b, &mov->b_up_down, stx->b_len);
	optimise_cost(mov, stx->a_len, stx->b_len);
}

void	find_best(t_stack *stx, t_move *mov)
{
	int		j;
	int		best;

	j = 0;
	best = INT_MAX;
	while (j < stx->b_len)
	{
		check_cost(stx, j, mov);
		if (mov->moves < best)
		{
			best = mov->moves;
			stx->move_a = mov->move_a;
			stx->move_b = mov->move_b;
			stx->i = mov->i;
			stx->j = mov->j;
			stx->a_up_down = mov->a_up_down;
			stx->b_up_down = mov->b_up_down;
		}
		j++;
	}
}
