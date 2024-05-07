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

void	init_stack(t_stack *stx, int argc)
{
	stx->a_len = 0;
	stx->b_len = 0;
	stx->moves = 0;
	stx->a = ft_calloc(sizeof(int), (argc));
	stx->b = ft_calloc(sizeof(int), (argc));
	stx->sorted = ft_calloc(sizeof(int), argc);
	stx->total_nums = argc - 1;
	stx->lis = NULL;
	stx->nums_to_split = NULL;
}

void	free_stack(t_stack *stx)
{
	if (stx->a)
		free (stx->a);
	if (stx->b)
		free (stx->b);
	if (stx->sorted)
		free (stx->sorted);
	if (stx->lis)
		free (stx->lis);
	if (stx->nums_to_split)
		free (stx->nums_to_split);
}

void	ft_bzero(void *dst, int n)
{
	unsigned char	*d;
	int				i;

	i = 0;
	d = (unsigned char *)dst;
	while (i < n)
	{
		d[i] = 0;
		i++;
	}
}

void	*ft_calloc(int nmemb, int size)
{
	void	*buf;
	int		t_size;

	t_size = nmemb * size;
	if (nmemb == 0 || size == 0)
	{
		buf = malloc(0);
		return (buf);
	}
	if (INT_MAX / nmemb < size)
	{
		return (0);
	}
	buf = malloc(t_size);
	if (!buf)
		return (NULL);
	ft_bzero(buf, t_size);
	return (buf);
}

void	free_helpers(t_stack *stx, int **res, int **lis)
{
	int	i;

	i = 0;
	while (i < stx->a_len)
	{
		free (res[i]);
		free (lis[i++]);
	}
	free (res);
	free (lis);
}
