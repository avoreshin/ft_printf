#include "ft_headers.h"
#include <string.h>

int main(void) {

//	int n;
//	printf("Please enter an integer: ");
//	while(scanf("%i",&n) != 1)
//	{
//		printf("Please enter an integer: ");
//		while(getchar() != '\n');
//	}
//	printf("You entered: %i\n",n);
	/*PRINT HEX*/
//		printf("ORIGINAL %i\n", 's');
//		ft_printf("ORIGINAL %i\n", 's');
//		scanf("%i", a);

/*PRINT D */

//printf("ORIGINAL %d\n",214748364458);
//ft_printf("ORIGINAL %d",21474454538364548);



	/* PRINT POINTER */
	int	a;
	int *b;
//
	a = -1;
	b = &a;
//
//	printf("ORIGINAL %p\n",b);
//	ft_printf("NO ORIGINAL %p\n",b);

	printf("%s %c %p %X %x \n",  "string", 'c', b, 5546, 45345);
	ft_printf("%s %c %p %X %x \n",  "string", 'c', b, 5546, 45345);

	/* PRINT STRING*/
//	printf("%s  %c %x %s %c %c%c %s %s %s \n","huawei", 'f', 253679,"aaaaa", 'f', 'f', 'f', "retert", "fertertb", "fertertertb");
//
//	ft_printf("%s  %c  %x %s %c %c%c %s %s %s \n","huawei", 'f',253679 ,"aaaaa", 'b', 'm', 'f', "retert", "fertertb", "fertertertb");

/* PRINT CHAR*/
//	printf("custom%%c%c%%%%c%ccccc%c\n",'d', 'f', 'g');
//	ft_printf("custom%%c%c%%%%c%ccccc%c\n",'d', 'f', 'g');

	return 0;
}


