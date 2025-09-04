/*
 ******************************************************
 Create a function that displays a string of characters on screen. If this string contains non-printable characters, they must be displayed as lowercase hexadecimal values, preceded by a backslash.
 For example:
 Hello\nHow are you?
 The function should display:
 Hello\0aHow are you?
 Here is how it should be prototyped:
 void ft_putstr_non_printable(char *str);
 ******************************************************
 * to compile it : gcc ft_putstr_non_printable.c
 * to run it : ./a.out
 ******************************************************
 */

#include <unistd.h>

/**********************
 * ft_puthex - Displays a byte value as lowercase hexadecimal
 * 
 * Description:
 * This helper function converts a byte value (0-255) to its two-digit
 * lowercase hexadecimal representation and displays it. It always
 * displays exactly two hex digits, padding with a leading zero if
 * necessary. Uses characters '0'-'9' and 'a'-'f'.
 * 
 * Algorithm:
 * 1. Extract high nibble (upper 4 bits) by dividing by 16
 * 2. Convert high nibble to hex character and display
 * 3. Extract low nibble (lower 4 bits) using modulo 16
 * 4. Convert low nibble to hex character and display
 * 
 * Parameters:
 * @byte: The byte value to convert and display as hex
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_puthex(10) outputs "0a"
 * ft_puthex(255) outputs "ff"
 * ft_puthex(0) outputs "00"
 **********************/
void	ft_puthex(unsigned char byte)
{
	char hex_chars[] = "0123456789abcdef";	/* Hexadecimal character lookup table */
	
	write(1, &hex_chars[byte / 16], 1);		/* Write high nibble hex character */
	write(1, &hex_chars[byte % 16], 1);		/* Write low nibble hex character */
}

/**********************
 * ft_putstr_non_printable - Displays string with non-printable chars as hex
 * 
 * Description:
 * This function displays a string character by character. Printable
 * characters (ASCII 32-126) are displayed normally. Non-printable
 * characters are displayed as a backslash followed by their two-digit
 * lowercase hexadecimal value. This allows visualization of control
 * characters and other non-printable bytes in the string.
 * 
 * Algorithm:
 * 1. Initialize index counter to 0
 * 2. Iterate through each character in the string
 * 3. For each character:
 *    a. If printable (ASCII 32-126), write character directly
 *    b. If non-printable, write backslash then hex representation
 * 4. Continue until null terminator is reached
 * 
 * Parameters:
 * @str: Pointer to null-terminated string to be displayed
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_putstr_non_printable("Hello\nWorld") outputs "Hello\0aWorld"
 * ft_putstr_non_printable("Tab\tChar") outputs "Tab\09Char"
 **********************/
void	ft_putstr_non_printable(char *str)
{
	int i;							/* Index counter for iterating through string */
	
	i = 0;							/* Initialize index to start from first character */
	while (str[i] != '\0')			/* Continue until null terminator is reached */
	{
		if (str[i] >= 32 && str[i] <= 126)	/* Check if character is printable */
		{
			write(1, &str[i], 1);	/* Write printable character directly */
		}
		else						/* Character is non-printable */
		{
			write(1, "\\", 1);		/* Write backslash prefix */
			ft_puthex((unsigned char)str[i]);	/* Write hex representation */
		}
		i++;						/* Move to next character */
	}
}

/**********************
 * main - Entry point for non-printable string display demonstration
 * 
 * Description:
 * This program demonstrates the ft_putstr_non_printable function by testing
 * it with various strings containing different combinations of printable
 * and non-printable characters. It shows how control characters, extended
 * ASCII, and other non-printable bytes are displayed as hex escapes.
 * 
 * Algorithm:
 * 1. Test with the example from the problem statement
 * 2. Test with various control characters
 * 3. Test with extended ASCII characters
 * 4. Test with mixed printable and non-printable content
 * 5. Display clear labels for each test case
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_putstr_non_printable shows various non-printable character demonstrations
 **********************/
int main(void)
{
	write(1, "Testing ft_putstr_non_printable function:\n\n", 43);	/* Display program header */
	
	/* Test case 1: Example from problem statement */
	write(1, "Test 1 - Input: \"Hello\\nHow are you?\"\n", 38);		/* Test description */
	write(1, "Output: ", 8);										/* Output label */
	ft_putstr_non_printable("Hello\nHow are you?");				/* Display with newline */
	write(1, "\n\n", 2);											/* Spacing between tests */
	
	/* Test case 2: Various control characters */
	write(1, "Test 2 - Input: \"Tab\\tChar\\rReturn\\0Null\"\n", 41);	/* Test description */
	write(1, "Output: ", 8);										/* Output label */
	ft_putstr_non_printable("Tab\tChar\rReturn\0Null");			/* Display control chars */
	write(1, "\n\n", 2);											/* Spacing between tests */
	
	/* Test case 3: All printable characters */
	write(1, "Test 3 - Input: \"Hello World! 123\"\n", 36);			/* Test description */
	write(1, "Output: ", 8);										/* Output label */
	ft_putstr_non_printable("Hello World! 123");					/* Display printable only */
	write(1, "\n\n", 2);											/* Spacing between tests */
	
	/* Test case 4: Mixed content with various non-printables */
	write(1, "Test 4 - Input: \"Start\\x01\\x1f\\x7f End\"\n", 39);	/* Test description */
	write(1, "Output: ", 8);										/* Output label */
	{
		char test_string[] = {'S', 't', 'a', 'r', 't', 1, 31, 127, ' ', 'E', 'n', 'd', '\0'};
		ft_putstr_non_printable(test_string);						/* Display mixed content */
	}
	write(1, "\n\n", 2);											/* Spacing between tests */
	
	/* Test case 5: Empty string */
	write(1, "Test 5 - Input: \"\"\n", 19);						/* Test description */
	write(1, "Output: ", 8);										/* Output label */
	ft_putstr_non_printable("");									/* Display empty string */
	write(1, "[empty]\n", 8);										/* Indicate empty result */
	
	return (0);													/* Return success status */
}