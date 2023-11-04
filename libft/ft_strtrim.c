/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:29:01 by eseet             #+#    #+#             */
/*   Updated: 2023/09/13 15:29:02 by eseet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// parameter
// s1: The string to be trimmed.
// set: The reference set of characters to trim.

// return
// The trimmed string.
// NULL if the allocation fails.

//basically anything that is in set, remove it from s1
// remove the from front and back only
#include "libft.h"

int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i++])
			return (1);
	}
	return (0);
}

// using memory address to subtract start and end
// for malloc, there is a need to allocate + 2
// reason:
// 1. Start character needs a char. That is to be acc.
// 2. null terminator to end the array of char
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*finalstr;

	if (!s1 || !set)
		return (0);
	start = (char *) s1;
	while (*start && is_set(*start, set))
		start++;
	end = (char *) s1 + ft_strlen(s1) - 1;
	while (end > start && is_set(*end, set))
		end--;
	finalstr = malloc(end - start + 2);
	if (!finalstr)
		return (0);
	ft_strlcpy(finalstr, start, end - start +2);
	finalstr[end - start + 1] = '\0';
	return (finalstr);
}

/*
int main() {
    // // Test Case 1: Trim leading and trailing spaces
    // const char *s1 = "  Hello, World!  ";
    // const char *set = " ";
    // char *trimmed1 = ft_strtrim(s1, set);
    // if (trimmed1 != NULL) {
    //     printf("Trimmed string 1: \"%s\"\n", trimmed1);
    //     free(trimmed1);
    // } else {
    //     printf("Memory allocation failed for Test Case 1!\n");
    // }

    // // Test Case 2: Trim specific characters
    // const char *s2 = "###TrimThisString###";
    // const char *set2 = "#";
    // char *trimmed2 = ft_strtrim(s2, set2);
    // if (trimmed2 != NULL) {
    //     printf("Trimmed string 2: \"%s\"\n", trimmed2);
    //     free(trimmed2);
    // } else {
    //     printf("Memory allocation failed for Test Case 2!\n");
    // }

    // Test Case 3: Trim specific characters
    // const char *s3 = "#!##!TrimThisString##!#";
    // const char *set3 = "#!";
    // char *trimmed3 = ft_strtrim(s3, set3);
    // if (trimmed3 != NULL) {
    //     printf("Trimmed string 3: \"%s\"\n", trimmed3);
    //     free(trimmed3);
    // } else {
    //     printf("Memory allocation failed for Test Case 3!\n");
    // }

	// Test 1:
	char *strtrim;
    char s1[] = "lorem \n ipsum \t dolor \n sit \t amet";
    if (!(strtrim = ft_strtrim(s1, "te")))
        printf("NULL\n");
    else
		printf("result:\n%s\n",strtrim);
    if (strtrim == s1)
		printf("\nA new string was not returned\n");
	// Expected (cat -e test01.output):
	// lorem $
	// ipsum   dolor $
	// sit     amet

	printf("\n\n");
	// Test 2:
    char s2[] = "lorem ipsum dolor sit amet";
	if (!(strtrim = ft_strtrim(s2, "te")))
        printf("NULL\n");
    else
		printf("result:\n%s\n",strtrim);
    if (strtrim == s2)
		printf("\nA new string was not returned\n");
	// Expected (cat -e test02.output):
	// lorem ipsum dolor sit am
	
	printf("\n\n");
	// Test 3:
    char s3[] = " lorem ipsum dolor sit amet";
	if (!(strtrim = ft_strtrim(s3, "l")))
        printf("NULL\n");
    else
		printf("result:\n%s\n",strtrim);
    if (strtrim == s3)
		printf("\nA new string was not returned\n");
	// Expected (cat -e test03.output):
	// orem ipsum dolor sit amet

	printf("\n\n");
	// Test 4:
    char s4[] = "lorem ipsum dolor sit amet";
    if (!(strtrim = ft_strtrim(s4, "tel")))
        printf("NULL\n");
    else
		printf("result:\n%s\n",strtrim);
    if (strtrim == s4)
		printf("\nA new string was not returned\n");
	// Expected (cat -e test04.output):
	// ...

    return 0;
}
*/