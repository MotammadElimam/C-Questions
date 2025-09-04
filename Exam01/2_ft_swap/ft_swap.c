// Assignment name  : ft_swap
// Expected files   : ft_swap.c
// Allowed functions: 
// --------------------------------------------------------------------------------

// Write a function that swaps the contents of two integers the adresses of which
// are passed as parameters.

// Your function must be declared as follows:

// void	ft_swap(int *a, int *b);

#include <unistd.h>

/**********************
 * ft_swap - Exchanges the values of two integers
 * 
 * Description:
 * This function swaps the values stored at two memory addresses.
 * It uses a temporary variable to perform the swap safely without
 * losing any data.
 * 
 * Algorithm:
 * 1. Store first value in temporary variable
 * 2. Assign second value to first location
 * 3. Assign temporary (original first) to second location
 * 
 * Parameters:
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 * 
 * Return:
 * void - No return value (swap done in-place)
 * 
 * Example:
 * int x = 5, y = 10;
 * ft_swap(&x, &y);  // Now x = 10, y = 5
 **********************/
void	ft_swap(int *a, int *b)
{
	int tmp = *a;       /* Store value of a in temporary variable */
	*a = *b;            /* Assign value of b to a */
	*b = tmp;           /* Assign original value of a (stored in tmp) to b */
}

/**********************
 * ft_putnbr - Outputs an integer to standard output
 * 
 * Description:
 * Converts and prints an integer digit by digit using write().
 * Handles negative numbers and the INT_MIN edge case.
 * 
 * Algorithm:
 * 1. Check for INT_MIN special case
 * 2. Handle negative numbers (print minus, negate)
 * 3. Use recursion for multi-digit numbers
 * 4. Convert each digit to ASCII character
 * 
 * Parameters:
 * @n: The integer to display
 * 
 * Return:
 * void - No return value
 **********************/
void	ft_putnbr(int n)
{
	char c;                                    /* Character to hold single digit */
	
	if (n == -2147483648)                     /* Special case for INT_MIN */
	{
		write(1, "-2147483648", 11);      /* Write the string directly */
		return;                            /* Exit function */
	}
	if (n < 0)                                 /* If number is negative */
	{
		write(1, "-", 1);                 /* Print minus sign */
		n = -n;                            /* Make number positive */
	}
	if (n >= 10)                               /* If number has more than one digit */
		ft_putnbr(n / 10);                 /* Recursively print all digits except last */
	c = n % 10 + '0';                          /* Convert last digit to character */
	write(1, &c, 1);                           /* Print the digit */
}

/**********************
 * main - Demonstration program for ft_swap function
 * 
 * Description:
 * This program tests the ft_swap function by swapping two
 * integers and displaying the before/after results.
 * 
 * Test scenario:
 * - Initial values: a = 42, b = 21
 * - After swap: a = 21, b = 42
 * 
 * Output:
 * Displays the values before and after swapping
 * 
 * Return:
 * 0 on successful execution
 **********************/
int main(void)
{
	int a = 42;                                /* Initialize first integer */
	int b = 21;                                /* Initialize second integer */
	
	write(1, "Before swap: a=", 15);           /* Print label */
	ft_putnbr(a);                              /* Print value of a */
	write(1, " b=", 3);                        /* Print label for b */
	ft_putnbr(b);                              /* Print value of b */
	write(1, "\n", 1);                         /* Print newline */
	
	ft_swap(&a, &b);                           /* Call swap function with addresses of a and b */
	
	write(1, "After swap: a=", 14);            /* Print label */
	ft_putnbr(a);                              /* Print new value of a */
	write(1, " b=", 3);                        /* Print label for b */
	ft_putnbr(b);                              /* Print new value of b */
	write(1, "\n", 1);                         /* Print newline */
	
	return (0);                                 /* Return success */
}