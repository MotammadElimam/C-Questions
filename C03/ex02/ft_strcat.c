/*
 ******************************************************
 Reproduce the behavior of the function strcat (man strcat).
 The function should be prototyped as follows:
 char *ft_strcat(char *dest, char *src);
 ******************************************************
 * to compile it : gcc ft_strcat.c
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
 * ft_strcat - Concatenates two strings
 * 
 * Description:
 * This function reproduces the behavior of the standard strcat function.
 * It appends the src string to the dest string, overwriting the null
 * terminator at the end of dest, and then adds a terminating null
 * character. The destination string must have enough space to hold
 * the result.
 * 
 * Algorithm:
 * 1. Find the end of the destination string
 * 2. Copy each character from source to destination
 * 3. Add null terminator at the end
 * 4. Return pointer to destination string
 * 
 * Parameters:
 * @dest: Destination string (must have enough space)
 * @src: Source string to append
 * 
 * Return:
 * Pointer to the destination string
 * 
 * Examples:
 * char dest[20] = "Hello";
 * ft_strcat(dest, " World") returns "Hello World"
 **********************/
char	*ft_strcat(char *dest, char *src)
{
	int i;						/* Index for destination string */
	int j;						/* Index for source string */
	
	i = 0;						/* Initialize destination index */
	while (dest[i] != '\0')	/* Find the end of destination string */
		i++;					/* Move to next character */
	
	j = 0;						/* Initialize source index */
	while (src[j] != '\0')		/* Copy source string to destination */
	{
		dest[i] = src[j];		/* Copy character from source to destination */
		i++;					/* Move to next position in destination */
		j++;					/* Move to next character in source */
	}
	dest[i] = '\0';				/* Add null terminator at the end */
	
	return (dest);				/* Return pointer to destination string */
}

/**********************
 * main - Entry point for string concatenation demonstration program
 * 
 * Description:
 * This program demonstrates the ft_strcat function by testing it with
 * various string combinations including normal strings, empty strings,
 * and multiple concatenations. It shows how the function appends
 * strings and modifies the destination buffer.
 * 
 * Algorithm:
 * 1. Create destination buffers with sufficient space
 * 2. Initialize test strings
 * 3. Perform various concatenation operations
 * 4. Display results after each concatenation
 * 5. Demonstrate chaining of concatenations
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_strcat outputs concatenated strings for various test cases
 **********************/
int main(void)
{
	char dest1[50] = "Hello";	/* Destination buffer with initial string */
	char dest2[50] = "";		/* Empty destination buffer */
	char dest3[50] = "The";	/* Destination for multiple concatenations */
	char *src1 = " World";		/* Source string to append */
	char *src2 = "!";			/* Short source string */
	char *src3 = "Start";		/* Source for empty destination test */
	
	/* Test 1: Normal concatenation */
	write(1, "Test 1 - Normal concatenation:\n", 32);		/* Display test description */
	write(1, "Before: \"", 9);		/* Show label */
	ft_putstr(dest1);				/* Display original destination */
	write(1, "\"\n", 2);			/* Close quote and newline */
	ft_strcat(dest1, src1);		/* Concatenate strings */
	write(1, "After:  \"", 9);		/* Show label */
	ft_putstr(dest1);				/* Display concatenated result */
	write(1, "\"\n\n", 3);			/* Close quote and newlines */
	
	/* Test 2: Empty destination */
	write(1, "Test 2 - Empty destination:\n", 29);		/* Display test description */
	write(1, "Before: \"", 9);		/* Show label */
	ft_putstr(dest2);				/* Display empty destination */
	write(1, "\"\n", 2);			/* Close quote and newline */
	ft_strcat(dest2, src3);		/* Concatenate to empty string */
	write(1, "After:  \"", 9);		/* Show label */
	ft_putstr(dest2);				/* Display result */
	write(1, "\"\n\n", 3);			/* Close quote and newlines */
	
	/* Test 3: Multiple concatenations */
	write(1, "Test 3 - Multiple concatenations:\n", 35);		/* Display test description */
	write(1, "Initial: \"", 10);	/* Show label */
	ft_putstr(dest3);				/* Display initial string */
	write(1, "\"\n", 2);			/* Close quote and newline */
	
	ft_strcat(dest3, " quick");	/* First concatenation */
	write(1, "After 1st: \"", 12);	/* Show label */
	ft_putstr(dest3);				/* Display after first concat */
	write(1, "\"\n", 2);			/* Close quote and newline */
	
	ft_strcat(dest3, " brown");	/* Second concatenation */
	write(1, "After 2nd: \"", 12);	/* Show label */
	ft_putstr(dest3);				/* Display after second concat */
	write(1, "\"\n", 2);			/* Close quote and newline */
	
	ft_strcat(dest3, " fox");		/* Third concatenation */
	write(1, "After 3rd: \"", 12);	/* Show label */
	ft_putstr(dest3);				/* Display final result */
	write(1, "\"\n\n", 3);			/* Close quote and newlines */
	
	/* Test 4: Append single character string */
	ft_strcat(dest1, src2);		/* Append "!" to "Hello World" */
	write(1, "Test 4 - Single char append:\n", 30);		/* Display test description */
	write(1, "Result: \"", 9);		/* Show label */
	ft_putstr(dest1);				/* Display result */
	write(1, "\"\n", 2);			/* Close quote and newline */
	
	return (0);					/* Return success status to the operating system */
}