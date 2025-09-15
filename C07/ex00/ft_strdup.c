/*
 ******************************************************
 // Reproduce the behavior of the function strdup (man strdup).
 // • Here's how it should be prototyped :
 // char *ft_strdup(char *src);
 ******************************************************
 * to compile it : gcc ft_strdup.c
 * to run it : ./a.out
 ******************************************************
 */

#include <stdlib.h>

/**********************
 * ft_strlen - Calculates the length of a string
 * 
 * Description:
 * This function counts the number of characters in a string
 * until it reaches the null terminator. Used to determine
 * how much memory to allocate for the duplicate string.
 * 
 * Algorithm:
 * 1. Initialize counter to 0
 * 2. Loop through string until null terminator
 * 3. Increment counter for each character
 * 4. Return the final count
 * 
 * Parameters:
 * @str: The string to measure
 * 
 * Return:
 * The length of the string (excluding null terminator)
 * 
 * Examples:
 * ft_strlen("hello") returns 5
 * ft_strlen("") returns 0
 * ft_strlen("test") returns 4
 **********************/
int	ft_strlen(char *str)
{
	int	len;					/* Counter for string length */

	len = 0;					/* Initialize length to 0 */
	while (str[len])			/* Loop until null terminator */
		len++;					/* Count each character */
	return (len);				/* Return the length */
}

/**********************
 * ft_strdup - Duplicates a string in allocated memory
 * 
 * Description:
 * This function creates a duplicate of the input string by
 * allocating memory and copying all characters including the
 * null terminator. It reproduces the behavior of the standard
 * strdup function.
 * 
 * Algorithm:
 * 1. Calculate the length of source string
 * 2. Allocate memory for length + 1 (for null terminator)
 * 3. If allocation fails, return NULL
 * 4. Copy each character from source to destination
 * 5. Add null terminator at the end
 * 6. Return pointer to the new string
 * 
 * Parameters:
 * @src: The source string to duplicate
 * 
 * Return:
 * Pointer to the newly allocated duplicate string
 * NULL if memory allocation fails
 * 
 * Examples:
 * ft_strdup("hello") returns pointer to new string "hello"
 * ft_strdup("") returns pointer to new empty string
 * ft_strdup("test 123") returns pointer to "test 123"
 **********************/
char	*ft_strdup(char *src)
{
	char	*dup;				/* Pointer to duplicated string */
	int		i;					/* Index for copying characters */
	int		len;				/* Length of source string */

	len = ft_strlen(src);		/* Get source string length */
	dup = (char *)malloc(sizeof(char) * (len + 1));	/* Allocate memory for duplicate */
	if (!dup)					/* Check if allocation failed */
		return (NULL);			/* Return NULL on failure */
	i = 0;						/* Initialize copy index */
	while (src[i])				/* Copy each character */
	{
		dup[i] = src[i];		/* Copy current character */
		i++;					/* Move to next character */
	}
	dup[i] = '\0';				/* Add null terminator */
	return (dup);				/* Return the duplicate string */
}

/**********************
 * main - Test program for ft_strdup function
 * 
 * Description:
 * This program tests the ft_strdup function with various
 * test cases and demonstrates proper memory management.
 * 
 * Algorithm:
 * 1. Test with normal string
 * 2. Test with empty string
 * 3. Test with string containing spaces
 * 4. Print results
 * 5. Free allocated memory
 * 
 * Return:
 * 0 on successful execution
 **********************/
#include <stdio.h>

int	main(void)
{
	char	*str1 = "Hello, World!";		/* Test string 1 */
	char	*str2 = "";						/* Empty string test */
	char	*str3 = "42 is the answer";		/* String with spaces */
	char	*dup1;							/* Duplicate of str1 */
	char	*dup2;							/* Duplicate of str2 */
	char	*dup3;							/* Duplicate of str3 */

	/* Test normal string duplication */
	dup1 = ft_strdup(str1);
	printf("Original: %s\n", str1);
	printf("Duplicate: %s\n\n", dup1);

	/* Test empty string duplication */
	dup2 = ft_strdup(str2);
	printf("Original (empty): '%s'\n", str2);
	printf("Duplicate (empty): '%s'\n\n", dup2);

	/* Test string with spaces */
	dup3 = ft_strdup(str3);
	printf("Original: %s\n", str3);
	printf("Duplicate: %s\n", dup3);

	/* Free allocated memory */
	free(dup1);
	free(dup2);
	free(dup3);

	return (0);					/* Return success */
}