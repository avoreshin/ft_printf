#include "ft_headers.h"

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
	{
		ft_putchar(*s++);
	}
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
	int c;
	if (symbol[i] == 'c')
	{
		c = va_arg(ap, int);
		ft_putchar(c);
	}
//	else if (symbol == 's')
//		ft_putstr((char *)input);
//	else if (symbol == 'p')
//	{
//		write(1, "0x", 2);
//		ft_putnbr((unsigned long)input, base16, 16);
//	}
//	else if (symbol == 'd' || symbol == 'i')
//		ft_putnbr((unsigned long)input);
//	else if (symbol == 'u')
//		ft_putnbr((unsigned long)input, BASE10, 10);
//	else if (symbol == 'x')
//		ft_putnbr((int)input, base16, 16);
//	else if (symbol == 'X')
//		ft_putnbr((unsigned long)input, BASE16, 16);
		return (0);
}

int ft_printf(const char *s, ...)
{
	va_list ap;
	va_start(ap, s);
	int	i;
	int k;

	i = 0;
	while(s[i])
	{
//		if (s[i] != '%')
//			write(1,&s[i],1);
		if (s[i] == '%')
		{
			if(s[i + 1] == '%')
				write(1,"%",1);
			if(ft_check_flags(s[i + 1]))
				ft_print(ap, s, i + 1);
		}
		i++;
	}
	va_end(ap);
	return (-1);

}

int main(void) {

	ft_printf("%c" "%c" "%c" "%c" "%c" "%c" , '0','5','5','5','5','5','5');
	return 0;
}



//
//double i1 =  va_arg(ap, double );
//int i2 =  va_arg(ap, int);

