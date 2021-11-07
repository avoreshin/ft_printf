#include "ft_headers.h"

int	ft_putchar(void *c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(void *ss)
{
	int count;
	char *s;

	count = 0;
	s = ss;
	while (*s)
	{
		write (1, s, 1);
		s++;
		count++;
	}
	return (count);
}

void	ft_putnbr(void *nn, void *base, unsigned long cap)
{
	unsigned long	num;
	unsigned long	n;

	n = (unsigned long)nn;
	num = n;
	if (num >= cap)
	{
		ft_putnbr((void *)(num / cap), base, cap);
		ft_putnbr((void *)(num % cap), base, cap);
	}
	else
		write (1, &base[num], 1);
}

int ft_check_flags(char q)
{
	if (q == 'c' || q == 's' || q == 'd' || q == 'i' ||q == 'p' || q == 'X' || \
		q == 'x' || q == 'u')
		return (1);
	return(0);
}

int ft_print (va_list ap, char *symbol, int i)
{
	void *ss;

	va_list aq;
	va_copy(aq, ap);
	ss = va_arg(ap, void *);
	if (symbol[i] == 'c')
		return (ft_putchar((ss)));
	else if (symbol[i] == 's')
		return (ft_putstr(ss));
	else if (symbol[i] == 'p' || symbol[i] == 'x')
	{
		if (symbol[i] == 'p' )
			write(1, "0x", 2);
		ft_putnbr(ss, BASE16_LOW, 16);
	}
	else if (symbol[i] == 'X')
		ft_putnbr(ss, BASE16_HIGH, 16);
	else if (symbol[i] == 'd' || symbol[i] == 'i' || symbol[i] == 'u')
		ft_putnbr(ss, BASE10, 10);
	return (0);
}

int ft_printf(const char *str, ...)
{
	va_list ap;
	va_start(ap, str);
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] != '%')
			write(1,&str[i],1);
		if (str[i] == '%')
		{
			if(str[i + 1] == '%')
				i += write(1,"%",1);
			else if (ft_check_flags(str[i + 1]))
			{
				ft_print(ap, (char *)str, i + 1);
				i++;
			}
			else
				i += write (1, str, 1);
		}
		i++;
	}
	va_end(ap);
	return (0);
}