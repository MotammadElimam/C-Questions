/*
 ******************************************************
 Create a function that returns 1 if the given string contains only digits and 0 if it contains any other character.
 Here is how it should be prototyped:
 int ft_str_is_numeric(char *str);
 ******************************************************
 * to compile it : gcc ft_str_is_numeric.c
 * to run it : ./a.out
 ******************************************************
 */

#include <unistd.h>

/**********************
 * ft_str_is_numeric - Checks if string contains only numeric characters
 * 
 * Description:
 * This function examines each character in the given string to determine
 * if all characters are digits (0-9). It returns 1 if the string contains
 * only numeric characters, and 0 if it contains any non-numeric characters.
 * An empty string returns 1.
 * 
 * Algorithm:
 * 1. Initialize index counter to 0
 * 2. Iterate through each character in the string
 * 3. For each character, check if it's between '0' and '9'
 * 4. If any character is not numeric, return 0 immediately
 * 5. If all characters are numeric (or string is empty), return 1
 * 
 * Parameters:
 * @str: Pointer to null-terminated string to be checked
 * 
 * Return:
 * int - 1 if string contains only numeric characters, 0 otherwise
 * 
 * Examples:
 * ft_str_is_numeric("12345") returns 1
 * ft_str_is_numeric("123abc") returns 0
 * ft_str_is_numeric("") returns 1
 **********************/
int	ft_str_is_numeric(char *str)
{
	int i;							/* Index counter for iterating through string */
	
	i = 0;							/* Initialize index to start from first character */
	while (str[i] != '\0')			/* Continue until null terminator is reached */
	{
		if (!(str[i] >= '0' && str[i] <= '9'))	/* Check if character is not numeric */
		{
			return (0);				/* Return 0 if non-numeric character found */
		}
		i++;						/* Move to next character */
	}
	return (1);						/* Return 1 if all characters are numeric */
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
 * main - Entry point for numeric string checker demonstration
 * 
 * Description:
 * This program demonstrates the ft_str_is_numeric function by testing it
 * with various strings including numeric-only strings, mixed strings,
 * and edge cases. It displays the test results to show how the function
 * behaves with different inputs.
 * 
 * Algorithm:
 * 1. Test with purely numeric strings
 * 2. Test with mixed alphanumeric strings
 * 3. Test with strings containing special characters
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
 * ./ft_str_is_numeric shows various string validation demonstrations
 **********************/
int main(void)
{
	ft_putstr("Testing ft_str_is_numeric function:\n\n");	/* Display program header */
	
	/* Test case 1: Pure numeric string */
	ft_putstr("Test 1 - \"12345\": ");						/* Test description */
	if (ft_str_is_numeric("12345"))						/* Check if string is numeric */
		ft_putstr("is numeric\n");						/* Display positive result */
	else
		ft_putstr("is not numeric\n");					/* Display negative result */
	
	/* Test case 2: Mixed alphanumeric string */
	ft_putstr("Test 2 - \"123abc\": ");					/* Test description */
	if (ft_str_is_numeric("123abc"))						/* Check if string is numeric */
		ft_putstr("is numeric\n");						/* Display positive result */
	else
		ft_putstr("is not numeric\n");					/* Display negative result */
	
	/* Test case 3: String with special characters */
	ft_putstr("Test 3 - \"123-456\": ");					/* Test description */
	if (ft_str_is_numeric("123-456"))					/* Check if string is numeric */
		ft_putstr("is numeric\n");						/* Display positive result */
	else
		ft_putstr("is not numeric\n");					/* Display negative result */
	
	/* Test case 4: Empty string */
	ft_putstr("Test 4 - \"\" (empty): ");					/* Test description */
	if (ft_str_is_numeric(""))							/* Check if empty string is numeric */
		ft_putstr("is numeric\n");						/* Display positive result */
	else
		ft_putstr("is not numeric\n");					/* Display negative result */
	
	return (0);										/* Return success status */
}
