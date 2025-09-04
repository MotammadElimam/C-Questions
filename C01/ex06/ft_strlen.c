/*
 ******************************************************
 Create a function that counts and returns the number of characters in a string.
 The function should be prototyped as follows:
 int ft_strlen(char *str);
 ******************************************************
 * to compile it : gcc ft_strlen.c
 * to run it : ./a.out
 ******************************************************
 */

#include <unistd.h>

/**********************
 * ft_putnbr - Displays an integer number to standard output
 * 
 * Description:
 * This function converts an integer to its string representation
 * and outputs it character by character using the write system call.
 * It handles all possible int values including negative numbers,
 * zero, and the special case of INT_MIN (-2147483648).
 * 
 * Algorithm:
 * 1. Handle INT_MIN special case directly (cannot be negated)
 * 2. If number is negative, print '-' and make number positive
 * 3. If number >= 10, recursively print higher digits first
 * 4. Convert last digit to character and print it
 * 
 * Parameters:
 * @nb: The integer number to be displayed
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_putnbr(42) outputs "42"
 * ft_putnbr(-123) outputs "-123"
 **********************/
void	ft_putnbr(int nb)
{
	char c;						/* Character variable to hold digit for output */
	
	if (nb == -2147483648)		/* Handle INT_MIN edge case (cannot be negated) */
	{
		write(1, "-2147483648", 11);	/* Write the literal value directly */
		return;					/* Exit function early */
	}
	if (nb < 0)					/* Check if number is negative */
	{
		write(1, "-", 1);		/* Write minus sign for negative numbers */
		nb = -nb;				/* Make number positive for processing */
	}
	if (nb >= 10)				/* Check if number has more than one digit */
		ft_putnbr(nb / 10);		/* Recursively print higher digits first */
	c = nb % 10 + '0';			/* Convert last digit to character */
	write(1, &c, 1);			/* Write the digit character to output */
}

/**********************
 * ft_strlen - Counts and returns the number of characters in a string
 * 
 * Description:
 * This function takes a pointer to a null-terminated string and counts
 * the number of characters in it, excluding the null terminator. It
 * iterates through the string character by character until it reaches
 * the null terminator, maintaining a counter of the characters encountered.
 * 
 * Algorithm:
 * 1. Initialize a counter variable to 0
 * 2. Iterate through the string while current character is not null terminator
 * 3. For each character encountered, increment the counter
 * 4. Move to the next character in the string
 * 5. Return the final counter value as the string length
 * 
 * Parameters:
 * @str: Pointer to the null-terminated string to be measured
 * 
 * Return:
 * int - The number of characters in the string (excluding null terminator)
 * 
 * Examples:
 * ft_strlen("Hello") returns 5
 * ft_strlen("42") returns 2
 * ft_strlen("") returns 0 (empty string)
 **********************/
int	ft_strlen(char *str)
{
	int length = 0;				/* Counter to store the number of characters */
	
	while (str[length] != '\0')	/* Continue loop until null terminator is reached */
	{
		length++;				/* Increment counter for each character found */
	}
	return (length);			/* Return the total character count */
}

/**********************
 * main - Entry point for string length calculation demonstration
 * 
 * Description:
 * This program demonstrates the ft_strlen function by testing it with
 * various string literals and displaying both the strings and their
 * calculated lengths. It shows how the function handles different
 * types of strings including regular text, special characters, and
 * empty strings.
 * 
 * Algorithm:
 * 1. Test with various string literals of different lengths
 * 2. Display each test string followed by its calculated length
 * 3. Test edge cases like empty strings and single characters
 * 4. Show results in a clear, formatted output
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_strlen outputs strings with their corresponding lengths
 **********************/
int main(void)
{
	char *test_strings[] = {		/* Array of test strings for demonstration */
		"Hello, World!",
		"Harvard School",
		"C programming",
		"",
		"A",
		"This is a longer string with spaces and numbers 123",
		"Special chars: @#$%^&*()"
	};
	int num_tests = 7;				/* Number of test strings in the array */
	int i = 0;						/* Index counter for iterating through tests */
	int length;						/* Variable to store calculated string length */
	
	write(1, "Testing ft_strlen function:\n\n", 29);		/* Display program header */
	
	while (i < num_tests)			/* Iterate through all test strings */
	{
		write(1, "String: \"", 9);						/* Display string label */
		write(1, test_strings[i], ft_strlen(test_strings[i]));	/* Display the test string */
		write(1, "\" -> Length: ", 13);					/* Display arrow and length label */
		length = ft_strlen(test_strings[i]);			/* Calculate string length */
		ft_putnbr(length);								/* Display the calculated length */
		write(1, "\n", 1);								/* Write newline */
		i++;											/* Move to next test string */
	}
	
	write(1, "\nAdditional edge case tests:\n", 29);	/* Display additional tests header */
	
	/* Test with dynamically created string */
	char dynamic_string[] = "Dynamic";					/* Create a character array */
	write(1, "Dynamic array: \"", 16);					/* Display label */
	write(1, dynamic_string, ft_strlen(dynamic_string));	/* Display the string */
	write(1, "\" -> Length: ", 13);						/* Display arrow and length label */
	ft_putnbr(ft_strlen(dynamic_string));				/* Display calculated length */
	write(1, "\n", 1);									/* Write newline */
	
	return (0);					/* Return success status to the operating system */
}