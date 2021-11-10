/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.42.fr> >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 21:43:53 by jlamonic          #+#    #+#             */
/*   Updated: 2021/11/10 23:21:08 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_check_flags(char q)
{
	if (q == 'c' || q == 's' || q == 'd' || q == 'i' || q == 'p' || \
		q == 'X' || q == 'x' || q == 'u')
		return (1);
	return (0);
}

int	ft_putchar(void *c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(void *ss)
{
	int		count;
	char	*s;

	count = 0;
	s = ss;
	if (!s)
		return (count += write(1, "(null)", 6));
	while (*s)
	{
		write (1, s, 1);
		s++;
		count++;
	}
	return (count);
}
