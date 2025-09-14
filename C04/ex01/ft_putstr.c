/*
 ******************************************************
 Create a function that prints a string of characters to the standard output.
 The function should be prototyped as follows:
 void ft_putstr(char *str);
 ******************************************************
 * to compile it : gcc ft_putstr.c
 * to run it : ./a.out
 ******************************************************
 */

#include <unistd.h>

/**********************
 * ft_strlen - Calculates and returns the length of a string
 * 
 * Description:
 * This function counts the number of characters in a null-terminated
 * string by iterating through each character until it encounters
 * the null terminator ('\0'). It returns the total count as an integer.
 * The function handles empty strings and normal strings correctly.
 * 
 * Algorithm:
 * 1. Initialize a counter variable to 0
 * 2. Iterate through the string character by character
 * 3. Increment counter for each non-null character
 * 4. Stop when null terminator is encountered
 * 5. Return the final count
 * 
 * Parameters:
 * @str: Pointer to the null-terminated string to measure
 * 
 * Return:
 * int - The number of characters in the string (excluding null terminator)
 * 
 * Examples:
 * ft_strlen("Hello") returns 5
 * ft_strlen("") returns 0
 * ft_strlen("42") returns 2
 **********************/
int	ft_strlen(char *str)
{
	int len;					/* Counter variable to track string length */
	
	len = 0;					/* Initialize length counter to zero */
	while (str[len] != '\0')	/* Loop until null terminator is found */
	{
		len++;					/* Increment counter for each character */
	}
	return (len);				/* Return the total character count */
}

/**********************
 * ft_putstr - Prints a string of characters to standard output
 * 
 * Description:
 * This function takes a null-terminated string and outputs each
 * character to standard output using the write system call.
 * It safely handles empty strings and null pointers by checking
 * for null before processing. The function outputs the entire
 * string character by character until it reaches the null terminator.
 * 
 * Algorithm:
 * 1. Check if the string pointer is not null
 * 2. Calculate the length of the string using ft_strlen
 * 3. Use write system call to output the entire string at once
 * 4. Alternative: iterate through each character and output individually
 * 
 * Parameters:
 * @str: Pointer to the null-terminated string to be printed
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_putstr("Hello") outputs "Hello"
 * ft_putstr("") outputs nothing (empty string)
 * ft_putstr("42 School") outputs "42 School"
 **********************/
void	ft_putstr(char *str)
{
	if (str == 0)				/* Check if string pointer is null */
		return;					/* Exit early if null pointer */
	
	write(1, str, ft_strlen(str));	/* Write entire string to standard output */
}

/**********************
 * main - Entry point for string printing demonstration program
 * 
 * Description:
 * This program demonstrates the ft_putstr function by testing it with
 * various string inputs including normal strings, empty strings,
 * and strings with different content types. It shows how the function
 * correctly handles different scenarios and outputs strings properly.
 * 
 * Algorithm:
 * 1. Create test strings with different content and lengths
 * 2. Call ft_putstr for each test string
 * 3. Add newlines between outputs for clarity
 * 4. Test edge cases like empty strings
 * 5. Verify output is displayed correctly
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_putstr outputs various test strings with proper formatting
 **********************/
int main(void)
{
	char *str1 = "Hello World!";		/* Test string with punctuation */
	char *str2 = "";					/* Empty string test case */
	char *str3 = "42 School";			/* String with numbers and letters */
	char *str4 = "Testing ft_putstr function with a longer string";	/* Long string test */
	
	write(1, "Test 1: ", 8);			/* Display test label */
	ft_putstr(str1);					/* Print first test string */
	write(1, "\n", 1);					/* Add newline for clarity */
	
	write(1, "Test 2: ", 8);			/* Display test label for empty string */
	ft_putstr(str2);					/* Print empty string (outputs nothing) */
	write(1, "[empty string]\n", 15);	/* Indicate empty string was tested */
	
	write(1, "Test 3: ", 8);			/* Display test label */
	ft_putstr(str3);					/* Print third test string */
	write(1, "\n", 1);					/* Add newline for clarity */
	
	write(1, "Test 4: ", 8);			/* Display test label */
	ft_putstr(str4);					/* Print long test string */
	write(1, "\n", 1);					/* Add newline for clarity */
	
	return (0);					/* Return success status to the operating system */
}