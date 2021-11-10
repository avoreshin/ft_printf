/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.42.fr> >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:04:43 by jlamonic          #+#    #+#             */
/*   Updated: 2021/11/10 21:32:03 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

# define BASE16_LOW "0123456789abcdef"
# define BASE16_HIGH "0123456789ABCDEF"
# define BASE10 "0123456789"

typedef struct s_struct
{
	int			count;
	int			i;
	char		flag;
	char		*string;
	void		*arg;
}				t_struct;

int	ft_printf(const char *s, ...);
int	ft_check_flags(char q);
int	ft_putchar(void *c);
int	ft_putstr(void *ss);

#endif