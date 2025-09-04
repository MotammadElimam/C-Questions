/*
 ******************************************************
 Create a function that returns 1 if the given string contains only printable characters and 0 if it contains any other character.
 Here is how it should be prototyped:
 int ft_str_is_printable(char *str);
 It should return 1 if str is empty
 ******************************************************
 * to compile it : gcc ft_str_is_printable.c
 * to run it : ./a.out
 ******************************************************
 */

#include <unistd.h>

/**********************
 * ft_str_is_printable - Checks if string contains only printable characters
 * 
 * Description:
 * This function examines each character in the given string to determine
 * if all characters are printable (ASCII values 32-126 inclusive). It returns
 * 1 if the string contains only printable characters, and 0 if it contains
 * any non-printable characters. An empty string returns 1 as specified.
 * 
 * Algorithm:
 * 1. Initialize index counter to 0
 * 2. Iterate through each character in the string
 * 3. For each character, check if it's between ASCII 32 (space) and 126 (~)
 * 4. If any character is not printable, return 0 immediately
 * 5. If all characters are printable (or string is empty), return 1
 * 
 * Parameters:
 * @str: Pointer to null-terminated string to be checked
 * 
 * Return:
 * int - 1 if string contains only printable characters, 0 otherwise
 * 
 * Examples:
 * ft_str_is_printable("Hello World!") returns 1
 * ft_str_is_printable("Hello\tWorld") returns 0 (contains tab character)
 * ft_str_is_printable("") returns 1
 **********************/
int	ft_str_is_printable(char *str)
{
	int i;							/* Index counter for iterating through string */
	
	i = 0;							/* Initialize index to start from first character */
	while (str[i] != '\0')			/* Continue until null terminator is reached */
	{
		if (!(str[i] >= 32 && str[i] <= 126))	/* Check if character is not printable */
		{
			return (0);				/* Return 0 if non-printable character found */
		}
		i++;						/* Move to next character */
	}
	return (1);						/* Return 1 if all characters are printable */
}

/**********************
 * ft_putstr - Writes a string to standard output
 * 
 * Description:
 * This function outputs a null-terminated string to standard output
 * using the write system call. It calculates the string length by
 * iterating through characters until the null terminator is found.
 * 
 * Algorithm:
 * 1. Initialize length counter to 0
 * 2. Iterate through string until null terminator is found
 * 3. Count each character to determine total string length
 * 4. Use write system call to output the entire string at once
 * 
 * Parameters:
 * @str: Pointer to null-terminated string to be written
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_putstr("Hello") outputs "Hello"
 * ft_putstr("World\n") outputs "World" followed by newline
 **********************/
void	ft_putstr(char *str)
{
	int len = 0;					/* Length counter for string measurement */
	
	while (str[len])				/* Count characters until null terminator */
		len++;					/* Increment length for each character */
	write(1, str, len);			/* Write entire string to standard output */
}

/**********************
 * main - Entry point for printable string checker demonstration
 * 
 * Description:
 * This program demonstrates the ft_str_is_printable function by testing it
 * with various strings including printable-only strings, strings with
 * non-printable characters, and edge cases. It displays the test results
 * to show how the function behaves with different inputs.
 * 
 * Algorithm:
 * 1. Test with printable strings
 * 2. Test with strings containing control characters
 * 3. Test with strings containing extended ASCII characters
 * 4. Test with empty string edge case
 * 5. Display results for each test case
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_str_is_printable shows various string validation demonstrations
 **********************/
int main(void)
{
	ft_putstr("Testing ft_str_is_printable function:\n\n");	/* Display program header */
	
	/* Test case 1: Printable string with various characters */
	ft_putstr("Test 1 - \"Hello World! 123\": ");				/* Test description */
	if (ft_str_is_printable("Hello World! 123"))				/* Check if string is printable */
		ft_putstr("is printable\n");						/* Display positive result */
	else
		ft_putstr("is not printable\n");					/* Display negative result */
	
	/* Test case 2: String with tab character (non-printable) */
	ft_putstr("Test 2 - \"Hello\\tWorld\" (with tab): ");		/* Test description */
	if (ft_str_is_printable("Hello\tWorld"))					/* Check if string is printable */
		ft_putstr("is printable\n");						/* Display positive result */
	else
		ft_putstr("is not printable\n");					/* Display negative result */
	
	/* Test case 3: String with newline character (non-printable) */
	ft_putstr("Test 3 - \"Hello\\nWorld\" (with newline): ");	/* Test description */
	if (ft_str_is_printable("Hello\nWorld"))					/* Check if string is printable */
		ft_putstr("is printable\n");						/* Display positive result */
	else
		ft_putstr("is not printable\n");					/* Display negative result */
	
	/* Test case 4: Empty string */
	ft_putstr("Test 4 - \"\" (empty): ");					/* Test description */
	if (ft_str_is_printable(""))							/* Check if empty string is printable */
		ft_putstr("is printable\n");						/* Display positive result */
	else
		ft_putstr("is not printable\n");					/* Display negative result */
	
	return (0);											/* Return success status */
}