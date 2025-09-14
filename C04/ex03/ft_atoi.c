/*
 ******************************************************
 • Write a function that converts the initial portion of the string pointed to by str into its integer representation.
 • The string may begin with an arbitrary amount of whitespace (as determined by isspace(3)).
 • The string may be preceded by an arbitrary number of '+' and '-' signs. A '-' sign will invert the result depending on whether the number of '-' signs is odd or even.
 • The function should then process any consecutive digits in base 10.
 • The function reads the string until a non-conforming character is encountered and returns the number obtained so far.
 • Overflow and underflow do not need to be handled; the function's return value is undefined in such cases.
 The function should be prototyped as follows:
 int ft_atoi(char *str);
 Example Program Output:
 $>./a.out " ---+--+1234ab567"
 -1234
 ******************************************************
 * to compile it : gcc ft_atoi.c
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
 * ft_atoi - Converts string to integer following atoi rules
 * 
 * Description:
 * This function mimics the behavior of the standard atoi function.
 * It parses a string to extract an integer value, handling whitespace,
 * sign characters, and numeric digits. The function skips leading
 * whitespace, processes multiple +/- signs (odd number of minus signs
 * makes result negative), and converts consecutive digits to integer.
 * 
 * Algorithm:
 * 1. Skip leading whitespace characters (space, tab, newline, etc.)
 * 2. Count and process sign characters (+/-) to determine final sign
 * 3. Convert consecutive digit characters to integer value
 * 4. Stop at first non-digit character and return result
 * 5. Apply sign based on odd/even count of minus signs
 * 
 * Parameters:
 * @str: Pointer to null-terminated string to convert
 * 
 * Return:
 * int - The integer representation of the string
 * 
 * Examples:
 * ft_atoi("123") returns 123
 * ft_atoi(" -42") returns -42
 * ft_atoi("  ---+--+1234ab567") returns -1234
 **********************/
int	ft_atoi(char *str)
{
	int i;						/* Index for iterating through string */
	int sign;					/* Sign multiplier (1 for positive, -1 for negative) */
	int result;					/* Accumulated result value */
	
	i = 0;						/* Initialize string index */
	sign = 1;					/* Initialize sign as positive */
	result = 0;					/* Initialize result accumulator */
	
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || 
		   str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
	{
		i++;					/* Skip whitespace characters */
	}
	
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')		/* Count minus signs to determine final sign */
			sign = -sign;		/* Flip sign for each minus sign */
		i++;					/* Move to next character */
	}
	
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');	/* Convert digit and add to result */
		i++;					/* Move to next character */
	}
	
	return (result * sign);		/* Return result with appropriate sign */
}

/**********************
 * main - Entry point for string to integer conversion demonstration program
 * 
 * Description:
 * This program demonstrates the ft_atoi function by testing it with
 * various string inputs including the example from the problem statement.
 * It shows how the function handles whitespace, multiple signs, digits,
 * and stops at non-digit characters. Each test case displays the input
 * string and its converted integer value.
 * 
 * Algorithm:
 * 1. Create test strings with different formats and edge cases
 * 2. Call ft_atoi for each test string
 * 3. Display input string and converted result
 * 4. Test the specific example from problem statement
 * 5. Verify all conversions work correctly
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_atoi outputs various string conversions and their integer results
 **********************/
int main(void)
{
	char *test1 = "123";					/* Simple positive number */
	char *test2 = " -42";					/* Negative with whitespace */
	char *test3 = "  ---+--+1234ab567";	/* Example from problem statement */
	char *test4 = " \t\n +456xyz";			/* Multiple whitespace and signs */
	char *test5 = "0";						/* Zero test case */
	char *test6 = " +-+-789";				/* Alternating signs */
	
	write(1, "Testing ft_atoi:\n", 17);		/* Program header */
	
	write(1, "\"123\" -> ", 9);				/* Test simple positive */
	ft_putnbr(ft_atoi(test1));
	write(1, "\n", 1);
	
	write(1, "\" -42\" -> ", 10);			/* Test negative with space */
	ft_putnbr(ft_atoi(test2));
	write(1, "\n", 1);
	
	write(1, "\"  ---+--+1234ab567\" -> ", 24);	/* Test problem example */
	ft_putnbr(ft_atoi(test3));
	write(1, "\n", 1);
	
	write(1, "\" \\t\\n +456xyz\" -> ", 18);	/* Test multiple whitespace */
	ft_putnbr(ft_atoi(test4));
	write(1, "\n", 1);
	
	write(1, "\"0\" -> ", 7);					/* Test zero */
	ft_putnbr(ft_atoi(test5));
	write(1, "\n", 1);
	
	write(1, "\" +-+-789\" -> ", 14);			/* Test alternating signs */
	ft_putnbr(ft_atoi(test6));
	write(1, "\n", 1);
	
	return (0);					/* Return success status to the operating system */
}