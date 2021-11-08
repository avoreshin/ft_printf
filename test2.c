#include "ft_printf.h"

int	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int count;

	count = 0;
	while (*s)
	{
		ft_putchar(*s++);
		count++;
	}
	return (count);
}

void	ft_putnbr(unsigned long num, char *base, int cap)
{
	if (num >= (unsigned  int)cap)
	{
		ft_putnbr(num / cap, base, cap);
		ft_putnbr(num % cap, base, cap);
	}
	else
		ft_putchar(base[num]);
}

int ft_check_flags(char q)
{
	if(q == 'c' || q == 's' || q == 'd' || q == 'i' ||q == 'p' || q == 'X' || \
	q == 'x' || q == 'u')
	return (1);
	return(0);
}

int ft_print (va_list ap, char *symbol, int i)
{
	unsigned long long c;
	char *str;
	unsigned int h;
//	int d;

	if (symbol[i] == 'c')
	{
		c = va_arg(ap, int);
		return (ft_putchar(c));
	}
	else if (symbol[i] == 's')
	{
		str = va_arg(ap, char *);
		return (ft_putstr(str));
	}
	else if (symbol[i] == 'p')
	{
		write(1, "0x", 2);
		c = va_arg(ap, unsigned long long);
		ft_putnbr((unsigned long long)c, BASE16_LOW, 16);
	}
	else if (symbol[i] == 'x')
	{
		h = va_arg(ap, unsigned int);
		ft_putnbr((unsigned int)h, BASE16_LOW, 16);
	}
	else if (symbol[i] == 'X')
	{
		h = va_arg(ap, unsigned long);
		ft_putnbr((unsigned int)h, BASE16_HIGH, 16);
	}
	//TO_DO
//	else if (symbol[i] == 'd' || symbol[i] == 'i')
//	{
//		d = va_arg(ap, int);
//		ft_putnbr((int)d,BASE10, 10);
//	}
//			else if (symbol[i] == 'u')
//			{
//				d = va_arg(ap, int);
//				ft_putnbr((unsigned long)d, BASE10, 10);
//			}

		return (0);
}

int ft_printf(const char *s, ...)
{
	va_list ap;
	va_start(ap, s);
	int	i;

	i = 0;
	while(s[i])
	{
		if (s[i] != '%')
			write(1,&s[i],1);
		if (s[i] == '%')
		{
			if(s[i + 1] == '%')
				i += write(1,"%",1);
			else if (ft_check_flags(s[i + 1]))
			{
				ft_print(ap, (char *)s, i + 1);
				i++;
			}
			else
				i += write (1, s, 1);
		}
		i++;
	}
	va_end(ap);
	return (0);
}