/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:24:49 by samoore           #+#    #+#             */
/*   Updated: 2023/12/19 14:47:22 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	ft_sorted(t_stack *stx)
{
	int	i;

	i = 1;
	while (i < stx->a_len)
	{
		if (stx->a[i] > stx->a[i - 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
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

void	free_stack(t_stack *stx)
{
	free (stx->a);
	free (stx->b);
	free (stx->sorted);
}

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}