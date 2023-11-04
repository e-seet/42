/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:37:15 by eseet             #+#    #+#             */
/*   Updated: 2023/10/05 18:37:16 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdarg.h>
// #include "libft/libft.h"
#include <stdio.h>
#include <limits.h> // for LONG_MIN, LONG_MAX, INT_MIN, INT_MAX, ULONG_MAX
#include "ft_printf.h"
#include <unistd.h> // for write
#include "libft/libft.h"

// %c Prints a single character.
// • %s Prints a string (as defined by the common C convention).
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number.
// • %i Prints an integer in base 10.
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.
// • %% Prints a percent sign

// how it works:
// When calling the function
// ft_printf("this item costs %d dollars and that is %d", 10, 50);
// it wil ltake it string and (10, 15) in ...

// void	ft_printfarg(const char *str, int i, int *num, va_list args)
// {
// 	if (str[i + 1] == 'c')
// 		ft_putchar(va_arg(args, int), num);
// 	else if (str[i + 1] == 's')
// 		ft_putstr(va_arg(args, char *), num);
// 	else if (str[i + 1] == 'p')
// 		ft_putptr(va_arg(args, void *), num);
// 	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
// 		ft_putnbr_fd(va_arg(args, int), num);
// 	else if (str[i + 1] == 'u')
// 		ft_putunbr(va_arg(args, unsigned int), num);
// 	else if (str[i + 1] == 'x')
// 		ft_puthex(va_arg(args, unsigned int), num);
// 	else if (str[i + 1] == 'X')
// 		ft_puthexup(va_arg(args, unsigned int), num);
// 	// else if (str[i + 1] == 'x' || str[i + 1] == 'X')
// 	// 	ft_printfarg2(str, i, num, args);
// 	else if (str[i + 1] == '%')
// 		ft_putchar('%', num);
// }

// void	ft_printfarg2(const char *str, int i, int *num, va_list args)
// {
// 	if (str[i + 1] == 'x')
// 		ft_puthex(va_arg(args, unsigned int), num);
// 	else if (str[i + 1] == 'X')
// 		ft_puthexup(va_arg(args, unsigned int), num);
// }

void	ft_printfhelper(const char *str, int i, int *num, va_list args)
{
	while (str[i] != '\0' && *num != -1)
	{
		if (str[i] == '%' && str[i + 1] == 'c')
			ft_putchar(va_arg(args, int), num);
		else if (str[i] == '%' && str[i + 1] == 's')
			ft_putstr(va_arg(args, char *), num);
		else if (str[i] == '%' && str[i + 1] == 'p')
			ft_putptr(va_arg(args, void *), num);
		else if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
			ft_putnbr_fd(va_arg(args, int), num);
		else if (str[i] == '%' && str[i + 1] == 'u')
			ft_putunbr(va_arg(args, unsigned int), num);
		else if (str[i] == '%' && str[i + 1] == 'x')
			ft_puthex(va_arg(args, unsigned int), num);
		else if (str[i] == '%' && str[i + 1] == 'X')
			ft_puthexup(va_arg(args, unsigned int), num);
		else if (str[i] == '%' && str[i + 1] == '%')
			ft_putchar('%', num);
		else
		{
			ft_helper(write(1, &str[i], 1), 1, num);
			i--;
		}
		i = i + 2;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		num;

	va_start(args, str);
	i = 0;
	num = 0;
	ft_printfhelper(str, i, &num, args);
	va_end(args);
	return (num);
}

/*
int main(void)
{
	char s2[] = "Mussum Ipsum, cacilds vidis litro abertis.
	 Posuere libero varius. Nullam a nisl ut ante blandit hendrerit.
	  Aenean sit amet nisi. Atirei o pau no gatis, per gatis
	   num morreus.";
	int val;

	val = ft_printf(" %s ", "-"); //3
	printf("val: %d\n", val);
	// ft_printf(" %s %s ", "", "-"); //4
	// printf("\n");
	// ft_printf(" %s %s ", " - ", "");
	// printf("\n");
	// ft_printf(" %s %s %s %s %s", " - ", "", "4", "", s2);
	// printf("\n");
	// ft_printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
	// printf("\n");
	// ft_printf(" NULL %s NULL ", NULL);
    return 0;
}
*/

// va_copy:
// Function: va_copy(dest, src)
// Purpose: Copies the va_list object src to dest.
// Parameters:
// dest: The destination va_list.
// src: The source va_list to be copied.
// Usage: va_copy is used when you need to create a copy of a va_list
// so that you can iterate through the arguments
// independently without affecting the original list.

// void print_strargs(char *s, ...)
// {
// 	va_list args;
//     va_start(args, s);

//     // char *str = s; // Start with the first string argument

//     while (s != NULL) {
// 		int i = 0;
// 		while (s[i] != '\0') {
// 			printf("%c", s[i]);
// 			i += 1;
// 		}
// 		printf("\n");
//         s = va_arg(args, char*); // Move to the next string argument
//     }

//     va_end(args);

// }

/* void print_strargs(char *s, ...)
{
	va_list args;
    va_start(args, s);

    // char *str = s;
	// Start with the first string argument

    while (s != NULL) {
		int i = 0;
		while (s[i] != '\0') {
			printf("%c", s[i]);
			i += 1;
		}
		printf("\n");
        s = va_arg(args, char*); 
		// Move to the next string argument
    }

    va_end(args);

}

void print_args(int count, ...) {
	// A variable argument list.
    va_list args;
    // Initializes a va_list to point to the first
	// variable argument in the function.
	va_start(args, count);

	int i = 0;
	printf("Printing original arguments:\n");
    while (i < count) {
        // Retrieves the next argument from the variable argument list.
        int value = va_arg(args, int);
        printf("Argument %d: %d\n", i + 1, value);
        i++;
    }
	printf("Printing arguments:\n");
	printf("Argument : %d\n", va_arg(args, int));

	// Purpose: Cleans up the va_list object when you're done using it.
	// Parameters:
	// ap: The va_list to be cleaned up.
	// Usage: You should call va_end when you're finished 
	//processing variable
	// arguments to release any resources associated with the va_list.
    va_end(args);
} */

/*int main() {
	// The first argument is the number of arguments that follow.
	// Afterwards are the ... arguments.
    // print_args(3, 10, 20, 30);
    // print_strargs("hello", "world");
    // print_strargs("hello", "world");
    
	char character = 'A';
    char* string = "Hello, World!";
    void* pointer = (void*)0x12345678;
    int decimalNumber = 42;
    unsigned int unsignedNumber = 12345;
    int hexNumber = 0xABCD;

	// %c Prints a single character.
	printf("Character: %c\n", character);
	ft_printf("Character: %c\n\n", character);

	// %s Prints a string.
	printf("Character: %s\n", string);
	ft_printf("String: %s\n\n", string);

	// %p Prints a pointer in hexadecimal format.
	printf("Pointer: %p\n", pointer);
	ft_printf("Pointer: %p\n\n", pointer);

	printf("original number: %d\n", decimalNumber);
	// %d Prints a decimal number.
	ft_printf("Decimal: %d\n", decimalNumber);
	// %i Prints an integer in base 10.
	ft_printf("Integer: %i\n", decimalNumber);

	// %u Prints an unsigned decimal number.
	printf("unsigned number: %u\n", unsignedNumber);
	ft_printf("Unsigned: %u\n\n", unsignedNumber);

	// %x Prints a number in hexadecimal lowercase format.
	printf("Hexadecimal (lowercase): %x\n", hexNumber);
	ft_printf("Hexadecimal (lowercase): %x\n", hexNumber);

	// %X Prints a number in hexadecimal uppercase format.
	printf("Hexadecimal (uppercase): %X\n", hexNumber);
	ft_printf("Hexadecimal (uppercase): %X\n\n", hexNumber);

	// %% Prints a percent sign.
	printf("Percent sign: %%\n");
	ft_printf("Percent sign: %%\n");

	return 0;
}
*/
