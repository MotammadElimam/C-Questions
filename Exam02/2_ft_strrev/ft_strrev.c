//******************************************************
// Assignment name  : ft_strrev
// Expected files   : ft_strrev.c
// Allowed functions: 
// --------------------------------------------------------------------------------

// Write a function that reverses (in-place) a string.

// It must return its parameter.

// Your function must be declared as follows:

// char    *ft_strrev(char *str);

//******************************************************
// to compile it : gcc ft_strrev.c
// to run it : ./a.out
//******************************************************

#include <unistd.h>

/**********************
 * ft_strrev - Reverses a string in-place
 * 
 * Description:
 * This function reverses the order of characters in a string
 * by swapping characters from both ends moving toward the center.
 * The reversal is done in-place, meaning the original string
 * memory is modified rather than creating a new string.
 * 
 * Algorithm:
 * 1. Handle null pointer case by returning NULL
 * 2. Find the length of the string
 * 3. Set up two pointers: start (0) and end (length-1)
 * 4. Swap characters at start and end positions
 * 5. Move start forward and end backward until they meet
 * 6. Return the original string pointer
 * 
 * Parameters:
 * @str: The input string to reverse in-place
 * 
 * Return:
 * char* - Returns the same string pointer (now containing reversed string)
 * 
 * Examples:
 * ft_strrev("hello") modifies str to "olleh" and returns it
 * ft_strrev("abc") modifies str to "cba" and returns it
 * ft_strrev(NULL) returns NULL
 **********************/
char	*ft_strrev(char *str)
{
	int i = 0;							/* Length of the string */
	int start = 0;						/* Start index (left pointer) */
	int end;							/* End index (right pointer) */
	char temp;							/* Temporary variable for swapping */
	
	if (!str)							/* Handle null pointer case */
		return (NULL);					/* Return NULL for safety */
	
							/* Initialize length counter */
	while (str[i])					/* Find the length of the string */
		i++;							/* Increment length counter */
	
	end = i - 1;						/* Set end pointer to last character */
	
	while (start < end)					/* Swap characters from both ends */
	{
		temp = str[start];				/* Store start character in temp */
		str[start] = str[end];			/* Copy end character to start position */
		str[end] = temp;				/* Copy temp (original start) to end position */
		start++;						/* Move start pointer forward */
		end--;							/* Move end pointer backward */
	}
	
	return (str);						/* Return the modified string */
}

/**********************
 * ft_putstr - Writes a string to standard output
 * 
 * Description:
 * This helper function writes a string to standard output using
 * the write system call. It calculates the string length and
 * outputs the entire string at once.
 * 
 * Parameters:
 * @str: The string to write to stdout
 * 
 * Return:
 * void - No return value
 * 
 * Examples:
 * ft_putstr("Hello"); // Outputs "Hello" to stdout
 * ft_putstr("World\n"); // Outputs "World" followed by newline
 **********************/
void	ft_putstr(char *str)
{
	int len = 0;							/* Length counter for string */
	
	if (!str)								/* Handle NULL pointer */
		return;									/* Exit if string is NULL */
	
	while (str[len])						/* Calculate string length */
		len++;									/* Increment length counter */
	
	write(1, str, len);						/* Write string to stdout */
}

/**********************
 * main - Entry point for ft_strrev testing program
 * 
 * Description:
 * This program tests the ft_strrev function with various
 * string scenarios to demonstrate that the in-place reversal
 * works correctly with different types of strings.
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Test Cases:
 * - Basic string ("hello")
 * - Single character ("a")
 * - Empty string ("")
 * - String with numbers and special chars ("abc123!@#")
 **********************/
int main(void)
{
	char test1[] = "hello";				/* Test string 1 - basic string */
	char test2[] = "a";					/* Test string 2 - single character */
	char test3[] = "";					/* Test string 3 - empty string */
	char test4[] = "abc123!@#";			/* Test string 4 - mixed characters */
	
	/* Test case 1: Basic string reversal */
	ft_putstr("Original: \"");				/* Print label */
	ft_putstr(test1);						/* Print original string */
	ft_putstr("\"\n");						/* Print closing quote and newline */
	ft_strrev(test1);					/* Reverse the string in-place */
	ft_putstr("Reversed: \"");				/* Print label */
	ft_putstr(test1);						/* Print reversed string */
	ft_putstr("\"\n\n");					/* Print closing quote and newlines */
	
	/* Test case 2: Single character (should remain unchanged) */
	ft_putstr("Original: \"");				/* Print label */
	ft_putstr(test2);						/* Print original string */
	ft_putstr("\"\n");						/* Print closing quote and newline */
	ft_strrev(test2);					/* Reverse the string in-place */
	ft_putstr("Reversed: \"");				/* Print label */
	ft_putstr(test2);						/* Print reversed string */
	ft_putstr("\"\n\n");					/* Print closing quote and newlines */
	
	/* Test case 3: Empty string (should remain empty) */
	ft_putstr("Original: \"");				/* Print label */
	ft_putstr(test3);						/* Print original string */
	ft_putstr("\"\n");						/* Print closing quote and newline */
	ft_strrev(test3);					/* Reverse the string in-place */
	ft_putstr("Reversed: \"");				/* Print label */
	ft_putstr(test3);						/* Print reversed string */
	ft_putstr("\"\n\n");					/* Print closing quote and newlines */
	
	/* Test case 4: String with mixed characters */
	ft_putstr("Original: \"");				/* Print label */
	ft_putstr(test4);						/* Print original string */
	ft_putstr("\"\n");						/* Print closing quote and newline */
	ft_strrev(test4);					/* Reverse the string in-place */
	ft_putstr("Reversed: \"");				/* Print label */
	ft_putstr(test4);						/* Print reversed string */
	ft_putstr("\"\n");						/* Print closing quote and newline */
	
	return (0);							/* Return success */
}