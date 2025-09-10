//******************************************************
// Assignment name  : ft_range
// Expected files   : ft_range.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write the following function:

// int     *ft_range(int start, int end);

// It must allocate (with malloc()) an array of integers, fill it with consecutive
// values that begin at start and end at end (Including start and end !), then
// return a pointer to the first value of the array.

// Examples:

// - With (1, 3) you will return an array containing 1, 2 and 3.
// - With (-1, 2) you will return an array containing -1, 0, 1 and 2.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing 0, -1, -2 and -3.

//******************************************************
// to compile it : gcc ft_range.c
// to run it : ./a.out
//******************************************************

#include <stdlib.h>
#include <unistd.h>

/**********************
 * ft_abs - Returns absolute value of an integer
 * 
 * Description:
 * This helper function returns the absolute value of an integer,
 * which is needed to calculate the size of the range regardless
 * of whether we're going from start to end in ascending or
 * descending order.
 * 
 * Parameters:
 * @n: The integer to get absolute value of
 * 
 * Return:
 * The absolute value of n
 * 
 * Examples:
 * ft_abs(-5) returns 5
 * ft_abs(3) returns 3
 **********************/
int	ft_abs(int n)
{
	return (n < 0 ? -n : n);			/* Return negative of n if negative, else n */
}

/**********************
 * ft_range - Creates an array with consecutive integers from start to end
 * 
 * Description:
 * This function allocates memory for an array of integers and fills
 * it with consecutive values from start to end (inclusive). It handles
 * both ascending and descending ranges, calculating the appropriate
 * size and direction for filling the array.
 * 
 * Algorithm:
 * 1. Calculate the size of the range (absolute difference + 1)
 * 2. Allocate memory for the array using malloc
 * 3. Determine the direction (increment or decrement)
 * 4. Fill the array with consecutive values
 * 5. Return pointer to the allocated array
 * 
 * Parameters:
 * @start: The starting value of the range (inclusive)
 * @end: The ending value of the range (inclusive)
 * 
 * Return:
 * Pointer to allocated array containing the range, or NULL on malloc failure
 * 
 * Examples:
 * ft_range(1, 3) returns array [1, 2, 3]
 * ft_range(-1, 2) returns array [-1, 0, 1, 2]
 * ft_range(5, 2) returns array [5, 4, 3, 2]
 **********************/
int	*ft_range(int start, int end)
{
	int size;							/* Size of the range array */
	int *array;							/* Pointer to allocated array */
	int i = 0;							/* Index for array filling */
	int step;							/* Direction of increment (1 or -1) */
	
	size = ft_abs(end - start) + 1;			/* Calculate array size (inclusive) */
	array = (int *)malloc(sizeof(int) * size);	/* Allocate memory for array */
	if (!array)							/* Check if malloc failed */
		return (NULL);					/* Return NULL on allocation failure */
	
	step = (start < end) ? 1 : -1;			/* Determine increment direction */
	
	while (i < size)					/* Fill array with consecutive values */
	{
		array[i] = start + (step * i);		/* Calculate current value */
		i++;							/* Move to next array position */
	}
	
	return (array);						/* Return pointer to filled array */
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
 * main - Entry point for ft_range testing program
 * 
 * Description:
 * This program tests the ft_range function with various
 * start and end values to demonstrate range creation
 * in both ascending and descending order, including
 * edge cases like single-element ranges.
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Test Cases:
 * - Ascending range (1, 4)
 * - Descending range (5, 2)
 * - Single element range (7, 7)
 * - Negative to positive range (-2, 2)
 **********************/
int main(void)
{
	int *range;							/* Pointer to range array */
	int i;								/* Loop index */
	int size;							/* Size of current range */
	
	/* Test case 1: Ascending range */
	ft_putstr("Range from 1 to 4: ");		/* Print test description */
	range = ft_range(1, 4);				/* Create range array */
	size = ft_abs(4 - 1) + 1;			/* Calculate size for printing */
	for (i = 0; i < size; i++)			/* Print array elements */
	{
		ft_putnbr(range[i]);				/* Print current element */
		ft_putstr(" ");						/* Print space separator */
	}
	ft_putstr("\n");						/* Print newline */
	free(range);						/* Free allocated memory */
	
	/* Test case 2: Descending range */
	ft_putstr("Range from 5 to 2: ");		/* Print test description */
	range = ft_range(5, 2);				/* Create range array */
	size = ft_abs(2 - 5) + 1;			/* Calculate size for printing */
	for (i = 0; i < size; i++)			/* Print array elements */
	{
		ft_putnbr(range[i]);				/* Print current element */
		ft_putstr(" ");						/* Print space separator */
	}
	ft_putstr("\n");						/* Print newline */
	free(range);						/* Free allocated memory */
	
	/* Test case 3: Single element */
	ft_putstr("Range from 7 to 7: ");		/* Print test description */
	range = ft_range(7, 7);				/* Create range array */
	size = ft_abs(7 - 7) + 1;			/* Calculate size for printing */
	for (i = 0; i < size; i++)			/* Print array elements */
	{
		ft_putnbr(range[i]);				/* Print current element */
		ft_putstr(" ");						/* Print space separator */
	}
	ft_putstr("\n");						/* Print newline */
	free(range);						/* Free allocated memory */
	
	/* Test case 4: Negative to positive */
	ft_putstr("Range from -2 to 2: ");		/* Print test description */
	range = ft_range(-2, 2);			/* Create range array */
	size = ft_abs(2 - (-2)) + 1;		/* Calculate size for printing */
	for (i = 0; i < size; i++)			/* Print array elements */
	{
		ft_putnbr(range[i]);				/* Print current element */
		ft_putstr(" ");						/* Print space separator */
	}
	ft_putstr("\n");						/* Print newline */
	free(range);						/* Free allocated memory */
	
	return (0);							/* Return success */
}