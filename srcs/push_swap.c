/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:38:45 by samoore           #+#    #+#             */
/*   Updated: 2023/12/19 16:17:08 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

int	top(t_stack *stx)
{
	return (stx->a[stx->a_len - 1]);
}

int	find_sorted_pos(t_stack *stx, int num)
{
	int	i;

	i = 0;
	while (stx->sorted[i] != num)
		i++;
	return (i);
}

void	push_to_a(t_stack *stx)
{
	if (stx->a_up_down == UP && stx->b_up_down == UP)
		up_up(stx);
	if (stx->a_up_down == DOWN && stx->b_up_down == DOWN)
		down_down(stx);
	while (stx->move_a > 0)
	{
		if (stx->a_up_down == UP)
			ra(stx);
		else if (stx->a_up_down == DOWN)
			rra(stx);
		stx->move_a -= 1;
	}
	while (stx->move_b > 0)
	{
		if (stx->b_up_down == UP)
			rb(stx);
		else if (stx->b_up_down == DOWN)
			rrb(stx);
		stx->move_b -= 1;
	}
	pa(stx);
}

void	ft_sort(t_stack *stx)
{
	t_move	mov;
	
	while (stx->b_len > 0)
	{
		find_best(stx, &mov);
		push_to_a(stx);
	}
}

char *gnl(int fd)
{
	char	*res;
	int		i;
	char	c;

	i = 0;
	res = malloc(sizeof(char) * 5);
	while ((read(0, &c, 1)))
	{
		res[i++] = c;
		// printf("%c", c);
		if (i == 4 && c != '\n')
		{
			res[0] = 1;
			return (res);
		}
		if (c == '\n')
		{
			if (i == 1)
			{
				free (res);
				return (NULL);
			}
			res[i] = 0;
			// printf("%s", res);
			return (res);
		}
	}
	return (NULL);
}

t_cmd	*get_instructions (void)
{
	t_cmd	*prev;
	t_cmd	*current;
	t_cmd	*head;
	char	*str;
	int		bytes;

	prev = NULL;
	head = NULL;
	while ((str = gnl(0)))
	{
		// printf("%s", str);
		current = malloc(sizeof(t_cmd));
		if (!head)
			head = current;
		if (prev)
			prev->next = current;
		current->str = str;
		current->next = NULL;
		prev = current;
		// printf("%s", str);
	}
	return (head);
}

void	check_result(t_stack *stx)
{
	
}

int	main(int argc, char **argv)
{
	t_stack	stx;
	int		i;
	int		low;
	t_cmd	*list;

	stx.list = get_instructions ();
	get_nums(argc, argv, &stx);
	check_result(&stx);
	// if (ft_sorted(&stx))
	// 	exit (0);
	// stx.moves = 0;
	// ft_pre_sort(&stx, 3);
	// ft_sort(&stx);
	// i = find_low(&stx);
	// low = stx.a[i];
	// if (i < stx.a_len / 2)
	// 	while (top(&stx) != low)
	// 		rra(&stx);
	// else
	// 	while (top(&stx) != low)
	// 		ra(&stx);
	// free_stack(&stx);
}
