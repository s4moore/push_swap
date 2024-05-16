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

int	compare(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	if (s1[i] == s2[i])
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	stx;

	if (argc == 1)
		exit (0);
	get_nums(argc, argv, &stx);
	stx.list = get_instructions ();
	check_result(&stx);
	if (ft_sorted(&stx))
	{
		putstr("OK\n");
		free_stack(&stx);
		exit (0);
	}
	putstr("KO\n");
	free_stack(&stx);
	return (1);
}
