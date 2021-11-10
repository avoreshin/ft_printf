/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.42.fr> >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:54:45 by jlamonic          #+#    #+#             */
/*   Updated: 2021/11/10 23:11:41 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_putnbr(void *nn, void *base, unsigned long cap, t_struct *c)
{
	long long int	num;

	num = 0;
	if (c->flag == 'd' || c->flag == 'i')
		num = (long long int)(int)nn;
	else if (c->flag == 'p')
		num = (long long)nn;
	else
		num = (long long int)(unsigned int)nn;
	if ((c->flag == 'd' || c->flag == 'i') && (num < 0))
	{
		c->count += write(1, "-", 1);
		num *= -1;
	}
	if ((unsigned long)num >= cap)
	{
		ft_putnbr((void *)(num / cap), base, cap, c);
		ft_putnbr((void *)(num % cap), base, cap, c);
	}
	else
		c->count += write (1, &base[num], 1);
	return (0);
}

int	ft_print(va_list ap, t_struct *f)
{
	f->flag = f->string[f->i + 1];
	f->arg = va_arg(ap, void *);
	if (f->flag == 'c')
		f->count += ft_putchar((f->arg));
	else if (f->flag == 's')
		f->count += ft_putstr(f->arg);
	else if (f->flag == 'p' || f->flag == 'x')
	{
		if (f->flag == 'p' )
			f->count += write(1, "0x", 2);
		ft_putnbr(f->arg, BASE16_LOW, 16, f);
	}
	else if (f->flag == 'X')
		ft_putnbr(f->arg, BASE16_HIGH, 16, f);
	else if (f->flag == 'd' || f->flag == 'i' || f->flag == 'u')
		ft_putnbr(f->arg, BASE10, 10, f);
	return (0);
}

void	ft_printf_cont(t_struct *f, va_list ap)
{
	if (f->string[f->i + 1] == '%')
	{
		f->i += write(1, "%", 1);
		f->count++;
	}
	else if (ft_check_flags(f->string[f->i + 1]))
	{
		f->count += ft_print(ap, f);
		f->i++;
	}
	else
	{
		f->i += write(1, f->string, 1);
		f->count++;
	}
}

int	ft_printf(const char *str, ...)
{
	t_struct	f;
	va_list		ap;

	va_start (ap, str);
	f.string = (char *)str;
	f.count = 0;
	f.i = 0;
	while (f.string[f.i])
	{
		if (f.string[f.i] != '%')
			f.count += write(1, &f.string[f.i], 1);
		if (str[f.i] == '%')
			ft_printf_cont(&f, ap);
		f.i++;
	}
	va_end(ap);
	return (f.count);
}
