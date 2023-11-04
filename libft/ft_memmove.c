/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:48:42 by eseet             #+#    #+#             */
/*   Updated: 2023/09/07 16:48:42 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The  memmove()  function copies n bytes from memory area src
//to memory area dest.
//The memory areas may overlap: copying takes place as
// though the bytes in src are first copied into a temporary array that does not
// overlap src or dest, and the bytes are then  copied  from
// the temporary array to dest.
// The memmove() function returns a pointer to dest.
#include "libft.h"

void	*copyfromback(unsigned char *destptr, unsigned char *srcptr, size_t n)
{
	while (n)
	{
		destptr[n - 1] = srcptr[n - 1];
		n--;
	}
	return (destptr);
}

void	*copyfromfront(unsigned char *destptr, unsigned char *srcptr, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		destptr[i] = srcptr[i];
		i++;
	}
	return (destptr);
}

// void *memmove(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*srcptr;
	unsigned char	*destptr;

	if (!dest && !src)
		return (dest);
	srcptr = (unsigned char *) src;
	destptr = (unsigned char *) dest;
	if (dest > src)
		copyfromback(destptr, srcptr, n);
	else
		copyfromfront(destptr, srcptr, n);
	return (dest);
}

/*
void printer(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		printf("pos:%d char:%c\n", i, str[i]);
		i++;
	}
}

int main() {
    char str1[] = "Hello, World!";
    char str2[20];

    // Test Case 1: Copying from str1 to str2 without overlap  Hello, World!
    //result: Hello, World!
    ft_memmove(str2, str1, strlen(str1) + 1);
    printf("Test Case 1:%s\n", str2);
	printer(str2);

    char str3[] = "Hello, World!";
    char str4[20];

    // Test Case 2: Copying from str3 to str4 with overlap. o, World!
    // result:  o, World!
    ft_memmove(str4, str3 + 4, strlen(str3) - 4 + 1);
    printf("\n\nTest Case 2:%s\n", str4);
	printer(str4);

    char str5[] = "Hello, World!";
    char str6[20];

    // Test Case 3: Copying from str5 to str6 with overlap and different sizes
    //result: ""
    ft_memmove(str6 + 4, str5, strlen(str5) - 4 + 1);
    printf("\n\nTest Case 3:%s\n", str6);
	printer(str6);
	printf("\n|\n");
	printer(str6 + 4); //Hello, Wor

	 // Test Case 4: Copying a substring from str7 to str8
    //result: "test."
	char str7[] = "This is a test.";
    char str8[] = "test.";
    char str9[] = "a";
    ft_memmove(str8, str7 + 10, 5);
    printf("\n\nTest Case 4:%s\n", str8);
	printer(str8);

    // Test Case 5: Copying a single character from str7 to str9
    //result: "i"
    ft_memmove(str9, str7 + 5, 1);
    printf("\nTest Case 5:%s\n", str9);
	printer(str9);

	//Test Case 6:
	//result: "Destinllo, Woata"
	char str[] = "Hello, World!";
    char destination[20];

    strcpy(destination, "Destination Data");
    printf("\n\nBefore memmove: destination = %s\n", destination);

    // Use memmove to copy a portion of str to destination with overlap
    ft_memmove(destination + 6, str + 2, 7);
    // Print the result after memmove
    printf("After memmove: destination = %s\n", destination);

    return 0;
	
}*/
