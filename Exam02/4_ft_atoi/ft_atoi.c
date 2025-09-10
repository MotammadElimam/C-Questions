//******************************************************
// Assignment name  : ft_atoi
// Expected files   : ft_atoi.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that converts the string argument str to an integer (type int)
// and returns it.

// It works much like the standard atoi(const char *str) function, see the man.

// Your function must be declared as follows:

// int	ft_atoi(const char *str);

//******************************************************
// to compile it : gcc ft_atoi.c
// to run it : ./a.out
//******************************************************

#include <unistd.h>

/**********************
 * ft_atoi - Converts a string to an integer
 * 
 * Description:
 * This function mimics the behavior of the standard atoi function.
 * It converts the initial portion of a string to an integer,
 * handling leading whitespace and an optional sign (+ or -).
 * The conversion stops at the first non-digit character.
 * 
 * Algorithm:
 * 1. Skip leading whitespace characters
 * 2. Handle optional sign (+ or -)
 * 3. Convert digit characters to integer value
 * 4. Apply sign and return the result
 * 
 * Parameters:
 * @str: The string to convert to integer
 * 
 * Return:
 * The converted integer value, or 0 if no valid conversion
 * 
 * Examples:
 * ft_atoi("123") returns 123
 * ft_atoi("-456") returns -456
 * ft_atoi("  +789") returns 789
 * ft_atoi("42abc") returns 42
 **********************/
int	ft_atoi(const char *str)
{
	int i = 0;							/* Index to traverse the string */
	int sign = 1;						/* Sign of the number (1 for positive, -1 for negative) */
	int result = 0;						/* Result accumulator */
	
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
		   str[i] == '\r' || str[i] == '\f' || str[i] == '\v')	/* Skip whitespace */
		i++;							/* Move to next character */
	
	if (str[i] == '-' || str[i] == '+')		/* Handle optional sign */
	{
		if (str[i] == '-')				/* Check if negative */
			sign = -1;					/* Set sign to negative */
		i++;							/* Move past the sign character */
	}
	
	while (str[i] >= '0' && str[i] <= '9')	/* Convert digits to integer */
	{
		result = result * 10 + (str[i] - '0');	/* Multiply by 10 and add digit */
		i++;							/* Move to next character */
	}
	
	return (result * sign);				/* Return result with proper sign */
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
 * ft_putnbr - Writes an integer to standard output
 * 
 * Description:
 * This helper function converts an integer to its string representation
 * and writes it to standard output using the write system call.
 * It handles negative numbers by outputting the minus sign first.
 * 
 * Algorithm:
 * 1. Handle negative numbers by outputting '-' and making positive
 * 2. Handle zero as special case
 * 3. Recursively output digits from most significant to least
 * 4. Convert each digit to character and write it
 * 
 * Parameters:
 * @n: The integer to write to stdout
 * 
 * Return:
 * void - No return value
 * 
 * Examples:
 * ft_putnbr(42); // Outputs "42" to stdout
 * ft_putnbr(-123); // Outputs "-123" to stdout
 * ft_putnbr(0); // Outputs "0" to stdout
 **********************/
void	ft_putnbr(int n)
{
	char digit;								/* Character to output */
	
	if (n == -2147483648)					/* Handle INT_MIN special case */
	{
		write(1, "-2147483648", 11);		/* Write INT_MIN directly */
		return;									/* Exit after handling special case */
	}
	
	if (n < 0)								/* Handle negative numbers */
	{
		write(1, "-", 1);						/* Write minus sign */
		n = -n;									/* Make number positive */
	}
	
	if (n >= 10)								/* Recursive case for multi-digit */
		ft_putnbr(n / 10);						/* Output higher order digits */
	
	digit = (n % 10) + '0';					/* Convert digit to character */
	write(1, &digit, 1);						/* Write single digit */
}

/**********************
 * main - Entry point for ft_atoi testing program
 * 
 * Description:
 * This program tests the ft_atoi function with various
 * string inputs to demonstrate proper integer conversion
 * including edge cases like whitespace, signs, and mixed content.
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Test Cases:
 * - Basic positive number ("123")
 * - Negative number ("-456")
 * - Number with leading whitespace ("  789")
 * - Number with sign ("+42")
 * - String with trailing non-digits ("99bottles")
 **********************/
int main(void)
{
	ft_putstr("ft_atoi(\"123\") = ");			/* Test basic positive */
	ft_putnbr(ft_atoi("123"));				/* Print result */
	ft_putstr("\n");							/* Print newline */
	ft_putstr("ft_atoi(\"-456\") = ");			/* Test negative */
	ft_putnbr(ft_atoi("-456"));				/* Print result */
	ft_putstr("\n");							/* Print newline */
	ft_putstr("ft_atoi(\"  789\") = ");			/* Test with whitespace */
	ft_putnbr(ft_atoi("  789"));				/* Print result */
	ft_putstr("\n");							/* Print newline */
	ft_putstr("ft_atoi(\"+42\") = ");			/* Test with positive sign */
	ft_putnbr(ft_atoi("+42"));					/* Print result */
	ft_putstr("\n");							/* Print newline */
	ft_putstr("ft_atoi(\"99bottles\") = ");	/* Test with trailing text */
	ft_putnbr(ft_atoi("99bottles"));			/* Print result */
	ft_putstr("\n");							/* Print newline */
	ft_putstr("ft_atoi(\"   -2147483648\") = ");	/* Test large negative */
	ft_putnbr(ft_atoi("   -2147483648"));		/* Print result */
	ft_putstr("\n");							/* Print newline */
	return (0);													/* Return success */
}