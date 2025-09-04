/*
 ******************************************************
 Create a function that displays a string of characters on the standard output.
 The function should be prototyped as follows:
 void ft_putstr(char *str);
 ******************************************************
 * to compile it : gcc ft_putstr.c
 * to run it : ./a.out
 ******************************************************
 */

#include <unistd.h>

/**********************
 * ft_putstr - Displays a string of characters to standard output
 * 
 * Description:
 * This function takes a pointer to a string (null-terminated character array)
 * and outputs each character to standard output using the write system call.
 * It iterates through the string until it encounters the null terminator,
 * writing each character individually to produce the complete string output.
 * 
 * Algorithm:
 * 1. Initialize an index counter to 0
 * 2. Iterate through the string while current character is not null terminator
 * 3. For each character, write it to standard output using write()
 * 4. Increment the index to move to the next character
 * 5. Continue until the entire string has been displayed
 * 
 * Parameters:
 * @str: Pointer to the null-terminated string to be displayed
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_putstr("Hello") outputs "Hello"
 * ft_putstr("42 School") outputs "42 School"
 * ft_putstr("") outputs nothing (empty string)
 **********************/
void	ft_putstr(char *str)
{
	int i = 0;					/* Index counter to iterate through the string */
	
	while (str[i] != '\0')		/* Continue loop until null terminator is reached */
	{
		write(1, &str[i], 1);	/* Write current character to standard output */
		i++;					/* Move to next character in the string */
	}
}

/**********************
 * main - Entry point for string display demonstration program
 * 
 * Description:
 * This program demonstrates the ft_putstr function by testing it with
 * various string literals and character arrays. It shows how the function
 * can display different types of strings including regular text, special
 * characters, and empty strings, proving the function works correctly.
 * 
 * Algorithm:
 * 1. Test with various string literals of different lengths
 * 2. Test with strings containing special characters and spaces
 * 3. Test with empty string to verify edge case handling
 * 4. Add newlines between tests for better output formatting
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_putstr outputs multiple test strings demonstrating function capability
 **********************/
int main(void)
{
	ft_putstr("Hello, World!");				/* Test with common greeting string */
	write(1, "\n", 1);							/* Write newline for better formatting */
	
	ft_putstr("Harvard School is awesome!");		/* Test with string containing numbers and spaces */
	write(1, "\n", 1);							/* Write newline for better formatting */
	
	ft_putstr("Testing special chars: @#$%");	/* Test with special characters */
	write(1, "\n", 1);							/* Write newline for better formatting */
	
	ft_putstr("");								/* Test with empty string (edge case) */
	write(1, "(Empty string above)\n", 22);	/* Indicate that empty string was tested */
	
	ft_putstr("Multi-line test:");				/* Test header for multi-line demonstration */
	write(1, "\n", 1);							/* Write newline */
	ft_putstr("Line 1");						/* First line */
	write(1, "\n", 1);							/* Write newline */
	ft_putstr("Line 2");						/* Second line */
	write(1, "\n", 1);							/* Write newline */
	ft_putstr("Line 3");						/* Third line */
	write(1, "\n", 1);							/* Write newline for final formatting */
	
	return (0);					/* Return success status to the operating system */
}