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

#include "checker.h"

int	good_instruction(char *str)
{
	if (!compare(str, "ra"))
		return (1);
	else if (!compare(str, "rb"))
		return (1);
	else if (!compare(str, "rr"))
		return (1);
	else if (!compare(str, "rra"))
		return (1);
	else if (!compare(str, "rrb"))
		return (1);
	else if (!compare(str, "rrr"))
		return (1);
	else if (!compare(str, "sa"))
		return (1);
	else if (!compare(str, "sb"))
		return (1);
	else if (!compare(str, "ss"))
		return (1);
	else if (!compare(str, "pa"))
		return (1);
	else if (!compare(str, "pb"))
		return (1);
	return (0);
}

char	*gnl(void)
{
	char	*res;
	int		i;
	char	c;

	i = 0;
	res = malloc(sizeof(char) * 4);
	while ((read(0, &c, 1)))
	{
		res[i++] = c;
		if (c == '\n')
		{
			res[i - 1] = 0;
			return (res);
		}
	}
	free (res);
	return (NULL);
}

t_cmd	*get_instructions(void)
{
	t_cmd	*prev;
	t_cmd	*current;
	t_cmd	*head;
	char	*str;

	prev = NULL;
	head = NULL;
	str = gnl ();
	while (str)
	{
		if (!good_instruction(str))
			clear_and_exit(str, head);
		current = malloc(sizeof(t_cmd));
		if (!head)
			head = current;
		if (prev)
			prev->next = current;
		current->str = str;
		current->next = NULL;
		prev = current;
		str = gnl ();
	}
	return (head);
}

void	do_instruction(char *instruction, t_stack *stx)
{
	if (!compare(instruction, "ra"))
		ra(stx);
	else if (!compare(instruction, "rb"))
		rb(stx);
	else if (!compare(instruction, "rr"))
		rr(stx);
	else if (!compare(instruction, "rra"))
		rra(stx);
	else if (!compare(instruction, "rrb"))
		rrb(stx);
	else if (!compare(instruction, "rrr"))
		rrr(stx);
	else if (!compare(instruction, "sa"))
		sa(stx);
	else if (!compare(instruction, "sb"))
		sb(stx);
	else if (!compare(instruction, "ss"))
		ss(stx);
	else if (!compare(instruction, "pa"))
		pa(stx);
	else if (!compare(instruction, "pb"))
		pb(stx);
}

void	check_result(t_stack *stx)
{
	t_cmd	*next;

	while (stx->list)
	{
		do_instruction(stx->list->str, stx);
		free (stx->list->str);
		next = stx->list->next;
		free (stx->list);
		stx->list = next;
	}
}
