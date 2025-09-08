/*
 ******************************************************
 Reproduce the behavior of the function strncat (man strncat).
 The function should be prototyped as follows:
 char *ft_strncat(char *dest, char *src, unsigned int nb);
 ******************************************************
 * to compile it : gcc ft_strncat.c
 * to run it : ./a.out
 ******************************************************
 */

#include <unistd.h>

/**********************
 * ft_putstr - Displays a string to standard output
 * 
 * Description:
 * This function outputs a null-terminated string character by character
 * using the write system call. It iterates through the string until
 * reaching the null terminator and writes each character to stdout.
 * 
 * Algorithm:
 * 1. Initialize index to 0
 * 2. Loop through string until null terminator
 * 3. Write each character to standard output
 * 4. Increment index and continue
 * 
 * Parameters:
 * @str: The string to be displayed
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_putstr("Hello") outputs "Hello"
 * ft_putstr("") outputs nothing
 **********************/
void	ft_putstr(char *str)
{
	int i;						/* Index for iterating through the string */
	
	i = 0;						/* Initialize index to start of string */
	while (str[i] != '\0')		/* Loop until null terminator */
	{
		write(1, &str[i], 1);	/* Write current character to stdout */
		i++;					/* Move to next character */
	}
}

/**********************
 * ft_strncat - Concatenates n characters from source to destination
 * 
 * Description:
 * This function reproduces the behavior of the standard strncat function.
 * It appends at most nb characters from src string to dest string,
 * overwriting the null terminator at the end of dest, and then adds
 * a terminating null character. If src contains nb or more characters,
 * only nb characters are appended.
 * 
 * Algorithm:
 * 1. Find the end of the destination string
 * 2. Copy at most nb characters from source to destination
 * 3. Stop if null terminator is reached in source
 * 4. Add null terminator at the end
 * 5. Return pointer to destination string
 * 
 * Parameters:
 * @dest: Destination string (must have enough space)
 * @src: Source string to append
 * @nb: Maximum number of characters to append
 * 
 * Return:
 * Pointer to the destination string
 * 
 * Examples:
 * char dest[20] = "Hello";
 * ft_strncat(dest, " World", 3) returns "Hello Wo"
 **********************/
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;				/* Index for destination string */
	unsigned int j;				/* Index for source string */
	
	i = 0;						/* Initialize destination index */
	while (dest[i] != '\0')	/* Find the end of destination string */
		i++;					/* Move to next character */
	
	j = 0;						/* Initialize source index */
	while (j < nb && src[j] != '\0')	/* Copy up to nb chars from source */
	{
		dest[i] = src[j];		/* Copy character from source to destination */
		i++;					/* Move to next position in destination */
		j++;					/* Move to next character in source */
	}
	dest[i] = '\0';				/* Add null terminator at the end */
	
	return (dest);				/* Return pointer to destination string */
}

/**********************
 * main - Entry point for limited string concatenation demonstration program
 * 
 * Description:
 * This program demonstrates the ft_strncat function by testing it with
 * various string combinations and different values of nb. It shows how
 * the function appends only a limited number of characters and how this
 * affects the resulting concatenated string.
 * 
 * Algorithm:
 * 1. Create destination buffers with sufficient space
 * 2. Initialize test strings
 * 3. Perform various limited concatenation operations
 * 4. Display results showing effect of nb parameter
 * 5. Test edge cases with nb = 0 and nb > source length
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_strncat outputs concatenated strings with limited characters
 **********************/
int main(void)
{
	char dest1[50] = "Hello";	/* Destination buffer with initial string */
	char dest2[50] = "Good";	/* Another destination buffer */
	char dest3[50] = "";		/* Empty destination buffer */
	char dest4[50] = "Test";	/* Destination for nb = 0 test */
	char dest5[50] = "Start";	/* Destination for large nb test */
	char *src1 = " World!";		/* Source string to append */
	char *src2 = " Morning";	/* Another source string */
	
	/* Test 1: Normal strncat with nb < source length */
	write(1, "Test 1 - Append 3 chars:\n", 26);		/* Display test description */
	write(1, "Before: \"", 9);		/* Show label */
	ft_putstr(dest1);				/* Display original destination */
	write(1, "\"\n", 2);			/* Close quote and newline */
	ft_strncat(dest1, src1, 3);	/* Concatenate only 3 characters */
	write(1, "After:  \"", 9);		/* Show label */
	ft_putstr(dest1);				/* Display result (should be "Hello Wo") */
	write(1, "\"\n\n", 3);			/* Close quote and newlines */
	
	/* Test 2: nb equals source length */
	write(1, "Test 2 - Append full string (nb=8):\n", 37);		/* Display test description */
	write(1, "Before: \"", 9);		/* Show label */
	ft_putstr(dest2);				/* Display original destination */
	write(1, "\"\n", 2);			/* Close quote and newline */
	ft_strncat(dest2, src2, 8);	/* Concatenate entire source string */
	write(1, "After:  \"", 9);		/* Show label */
	ft_putstr(dest2);				/* Display result (should be "Good Morning") */
	write(1, "\"\n\n", 3);			/* Close quote and newlines */
	
	/* Test 3: Empty destination with limited append */
	write(1, "Test 3 - Empty dest, append 5 chars:\n", 38);		/* Display test description */
	write(1, "Before: \"", 9);		/* Show label */
	ft_putstr(dest3);				/* Display empty destination */
	write(1, "\"\n", 2);			/* Close quote and newline */
	ft_strncat(dest3, "Hello World", 5);	/* Append 5 chars to empty string */
	write(1, "After:  \"", 9);		/* Show label */
	ft_putstr(dest3);				/* Display result (should be "Hello") */
	write(1, "\"\n\n", 3);			/* Close quote and newlines */
	
	/* Test 4: nb = 0 (no characters appended) */
	write(1, "Test 4 - Append 0 chars (nb=0):\n", 33);		/* Display test description */
	write(1, "Before: \"", 9);		/* Show label */
	ft_putstr(dest4);				/* Display original destination */
	write(1, "\"\n", 2);			/* Close quote and newline */
	ft_strncat(dest4, " ignored", 0);	/* Append 0 characters */
	write(1, "After:  \"", 9);		/* Show label */
	ft_putstr(dest4);				/* Display result (should be unchanged) */
	write(1, "\"\n\n", 3);			/* Close quote and newlines */
	
	/* Test 5: nb > source length (appends entire source) */
	write(1, "Test 5 - nb > source length (nb=20):\n", 38);		/* Display test description */
	write(1, "Before: \"", 9);		/* Show label */
	ft_putstr(dest5);				/* Display original destination */
	write(1, "\"\n", 2);			/* Close quote and newline */
	ft_strncat(dest5, " End", 20);	/* nb is larger than source length */
	write(1, "After:  \"", 9);		/* Show label */
	ft_putstr(dest5);				/* Display result (should be "Start End") */
	write(1, "\"\n", 2);			/* Close quote and newline */
	
	return (0);					/* Return success status to the operating system */
}