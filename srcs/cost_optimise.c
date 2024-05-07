/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:37:12 by samoore           #+#    #+#             */
/*   Updated: 2023/12/20 14:00:27 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	up_a_up_b_down(t_move *m, int b_len)
{
	if (b_len < 2)
		return (0);
	if (m->a_up_down == DOWN)
		return (0);
	if (m->b_up_down == UP)
		return (0);
	if (b_len - m->j - 1 < m->move_a + m->move_b)
		return (0);
	return (1);
}

int	up_b_up_a_down(t_move *m, int a_len, int b_len)
{
	if (b_len < 2)
		return (0);
	if (m->b_up_down == DOWN)
		return (0);
	if (m->a_up_down == UP)
		return (0);
	if (a_len - m->i - 1 < m->move_a + m->move_b)
		return (0);
	return (1);
}

int	down_a_down_b_up(t_move *m, int b_len)
{
	if (b_len < 2)
		return (0);
	if (m->b_up_down == DOWN)
		return (0);
	if (m->a_up_down == UP)
		return (0);
	if (m->j + 1 < m->move_a + m->move_b)
		return (0);
	return (1);
}

int	down_a_up_b_down(t_move *m, int b_len)
{
	if (b_len < 2)
		return (0);
	if (m->a_up_down == DOWN)
		return (0);
	if (m->b_up_down == UP)
		return (0);
	if (m->i + 1 < m->move_a + m->move_b)
		return (0);
	return (1);
}

void	set_m(t_move *m, char a_or_b, int up_down, int moves)
{
	if (a_or_b == 'a')
	{
		m->a_up_down = up_down;
		m->move_a = moves;
	}
	else
	{
		m->b_up_down = up_down;
		m->move_b = moves;
	}
	m->moves = max(m->move_a, m->move_b);
}
