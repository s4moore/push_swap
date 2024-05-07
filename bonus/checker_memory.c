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

void	free_list(t_cmd *list)
{
	t_cmd	*tmp;

	while (list)
	{
		tmp = list->next;
		free (list->str);
		free (list);
		list = tmp;
	}
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

void	clear_and_exit(char *str, t_cmd *head)
{
	free (str);
	free_list(head);
	putstr("Error\n");
	exit(1);
}
