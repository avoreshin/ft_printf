/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_headers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.42.fr> >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:04:43 by jlamonic          #+#    #+#             */
/*   Updated: 2021/11/07 20:30:35 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADERS_H
# define FT_HEADERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

# define BASE16_LOW "0123456789abcdef"
# define BASE16_HIGH "0123456789ABCDEF"
# define BASE10 "0123456789"

typedef	struct		s_struct
{
	int				cnt;

}					t_struct;

int ft_printf(const char *s, ...);

#endif