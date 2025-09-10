//******************************************************
// Assignment name  : ft_swap
// Expected files   : ft_swap.c
// Allowed functions: 
// --------------------------------------------------------------------------------

// Write a function that swaps the contents of two integers the adresses of which
// are passed as parameters.

// Your function must be declared as follows:

// void	ft_swap(int *a, int *b);

//******************************************************
// to compile it : gcc ft_swap.c
// to run it : ./a.out
//******************************************************

#include <unistd.h>

/**********************
 * ft_swap - Swaps the contents of two integers
 * 
 * Description:
 * This function swaps the values of two integers by using
 * their memory addresses. It dereferences the pointers to
 * access the actual values and exchanges them using a
 * temporary variable.
 * 
 * Algorithm:
 * 1. Store the value pointed to by 'a' in a temporary variable
 * 2. Assign the value pointed to by 'b' to the location pointed to by 'a'
 * 3. Assign the temporary value to the location pointed to by 'b'
 * 
 * Parameters:
 * @a: Pointer to the first integer to swap
 * @b: Pointer to the second integer to swap
 * 
 * Return:
 * void - No return value (values are modified through pointers)
 * 
 * Examples:
 * int x = 5, y = 10;
 * ft_swap(&x, &y); // After: x = 10, y = 5
 **********************/
void	ft_swap(int *a, int *b)
{
	int temp;							/* Temporary variable to hold one value during swap */
	
	temp = *a;							/* Store value pointed to by 'a' in temp */
	*a = *b;							/* Assign value pointed to by 'b' to location of 'a' */
	*b = temp;							/* Assign temp value to location of 'b' */
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
 * main - Entry point for ft_swap testing program
 * 
 * Description:
 * This program tests the ft_swap function with various
 * integer values to demonstrate that the swap operation
 * works correctly with different scenarios.
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Test Cases:
 * - Basic positive numbers (42, 21)
 * - Negative and positive numbers (-5, 10)
 * - Both negative numbers (-100, -200)
 * - Zero and positive number (0, 99)
 **********************/
int main(void)
{
	int a, b;							/* Variables to test the swap function */
	
	/* Test case 1: Basic positive integers */
	a = 42;								/* Initialize first value */
	b = 21;								/* Initialize second value */
	ft_putstr("Before swap: a = ");		/* Print label before swap */
	ft_putnbr(a);							/* Print first value */
	ft_putstr(", b = ");					/* Print separator */
	ft_putnbr(b);							/* Print second value */
	ft_putstr("\n");						/* Print newline */
	ft_swap(&a, &b);					/* Call swap function with addresses */
	ft_putstr("After swap:  a = ");		/* Print label after swap */
	ft_putnbr(a);							/* Print first value */
	ft_putstr(", b = ");					/* Print separator */
	ft_putnbr(b);							/* Print second value */
	ft_putstr("\n\n");						/* Print newlines */
	
	/* Test case 2: Negative and positive integers */
	a = -5;								/* Initialize first value (negative) */
	b = 10;								/* Initialize second value (positive) */
	ft_putstr("Before swap: a = ");		/* Print label before swap */
	ft_putnbr(a);							/* Print first value */
	ft_putstr(", b = ");					/* Print separator */
	ft_putnbr(b);							/* Print second value */
	ft_putstr("\n");						/* Print newline */
	ft_swap(&a, &b);					/* Call swap function with addresses */
	ft_putstr("After swap:  a = ");		/* Print label after swap */
	ft_putnbr(a);							/* Print first value */
	ft_putstr(", b = ");					/* Print separator */
	ft_putnbr(b);							/* Print second value */
	ft_putstr("\n\n");						/* Print newlines */
	
	/* Test case 3: Both negative integers */
	a = -100;							/* Initialize first value (negative) */
	b = -200;							/* Initialize second value (negative) */
	ft_putstr("Before swap: a = ");		/* Print label before swap */
	ft_putnbr(a);							/* Print first value */
	ft_putstr(", b = ");					/* Print separator */
	ft_putnbr(b);							/* Print second value */
	ft_putstr("\n");						/* Print newline */
	ft_swap(&a, &b);					/* Call swap function with addresses */
	ft_putstr("After swap:  a = ");		/* Print label after swap */
	ft_putnbr(a);							/* Print first value */
	ft_putstr(", b = ");					/* Print separator */
	ft_putnbr(b);							/* Print second value */
	ft_putstr("\n\n");						/* Print newlines */
	
	/* Test case 4: Zero and positive integer */
	a = 0;								/* Initialize first value (zero) */
	b = 99;								/* Initialize second value (positive) */
	ft_putstr("Before swap: a = ");		/* Print label before swap */
	ft_putnbr(a);							/* Print first value */
	ft_putstr(", b = ");					/* Print separator */
	ft_putnbr(b);							/* Print second value */
	ft_putstr("\n");						/* Print newline */
	ft_swap(&a, &b);					/* Call swap function with addresses */
	ft_putstr("After swap:  a = ");		/* Print label after swap */
	ft_putnbr(a);							/* Print first value */
	ft_putstr(", b = ");					/* Print separator */
	ft_putnbr(b);							/* Print second value */
	ft_putstr("\n");						/* Print newline */
	
	return (0);							/* Return success */
}