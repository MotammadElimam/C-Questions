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
// to compile it : gcc -Wall -Wextra -Werror ft_range.c -o ft_range
// to run it : ./ft_range 1 3
// to run it : ./ft_range -1 2
// to run it : ./ft_range 0 -3
// to run it : ./ft_range 0 0
//******************************************************
// The flags mean:
//******************************************************
//   - -Wall: Enable all common warnings
//   - -Wextra: Enable extra warning flags
//   - -Werror: Treat warnings as errors
//   - -o ft_range: Name the output executable "ft_range"
//******************************************************
//******************************************************
#include <stdlib.h>
#include <unistd.h>

/**********************
 * ft_range - Creates an array of consecutive integers
 * 
 * Description:
 * Allocates memory for an array and fills it with consecutive
 * integers from start to end (inclusive). Handles both ascending
 * and descending ranges automatically based on the relationship
 * between start and end values.
 * 
 * Algorithm:
 * 1. Calculate array size based on start and end values
 * 2. Allocate memory using malloc
 * 3. Fill array with consecutive values:
 *    - If start <= end: increment from start to end
 *    - If start > end: decrement from start to end
 * 4. Return pointer to allocated array
 * 
 * Parameters:
 * @start: Starting integer value (inclusive)
 * @end: Ending integer value (inclusive)
 * 
 * Return:
 * Pointer to newly allocated integer array, or NULL if malloc fails
 * 
 * Example:
 * ft_range(1, 3) -> [1, 2, 3]
 * ft_range(0, -3) -> [0, -1, -2, -3]
 * ft_range(5, 5) -> [5]
 **********************/
int *ft_range(int start, int end)
{
	int *range;						// Pointer to hold the allocated array
	int size;						// Size of the array to be allocated
	int i = 0;						// Index for filling the array
	
	if (start <= end)				// If start is less than or equal to end (ascending range)
		size = end - start + 1;		// Calculate size as difference plus 1 (inclusive)
	else							// If start is greater than end (descending range)
		size = start - end + 1;		// Calculate size as difference plus 1 (inclusive)
	
	range = malloc(size * sizeof(int));	// Allocate memory for the array
	if (!range)						// Check if malloc failed
		return (NULL);				// Return NULL if allocation failed
	
	if (start <= end)				// If ascending range
	{
		while (start <= end)			// Fill array from start to end incrementally
		{
			range[i] = start;			// Store current start value in array
			start++;					// Increment start value
			i++;						// Move to next array index
		}
	}
	else							// If descending range
	{
		while (start >= end)			// Fill array from start to end decrementally
		{
			range[i] = start;			// Store current start value in array
			start--;					// Decrement start value
			i++;						// Move to next array index
		}
	}
	return (range);					// Return pointer to the allocated and filled array
}

/**********************
 * ft_putnbr - Prints an integer to standard output
 * 
 * Description:
 * Recursively converts an integer to its string representation
 * and outputs it character by character using the write system call.
 * Handles negative numbers and the special case of INT_MIN which
 * cannot be negated without overflow.
 * 
 * Algorithm:
 * 1. Handle INT_MIN special case directly
 * 2. If negative, print '-' and make number positive
 * 3. If number >= 10, recursively print higher digits
 * 4. Convert last digit to character and print
 * 
 * Parameters:
 * @n: Integer to be printed
 * 
 * Return:
 * None (void function)
 * 
 * Example:
 * ft_putnbr(42) -> prints "42"
 * ft_putnbr(-123) -> prints "-123"
 **********************/
void ft_putnbr(int n)
{
	char c;							// Character to hold digit for output
	
	if (n == -2147483648)			// Handle INT_MIN edge case (can't be negated)
	{
		write(1, "-2147483648", 11);	// Write the literal value directly
		return;						// Exit function early
	}
	if (n < 0)						// If number is negative
	{
		write(1, "-", 1);				// Write minus sign
		n = -n;							// Make number positive
	}
	if (n >= 10)					// If number has more than one digit
		ft_putnbr(n / 10);				// Recursively print higher digits first
	c = n % 10 + '0';				// Convert last digit to character
	write(1, &c, 1);				// Write the digit character
}

/**********************
 * main - Test function for ft_range implementation
 * 
 * Description:
 * Demonstrates the ft_range function with various test cases
 * including ascending ranges, descending ranges, and edge cases.
 * Tests memory allocation and proper array filling, then frees
 * allocated memory to prevent leaks.
 * 
 * Algorithm:
 * 1. Test ascending range (1 to 3)
 * 2. Test range with negative start (-1 to 2)
 * 3. Test descending range (0 to -3)
 * 4. For each test: allocate, print, and free memory
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Example:
 * Output:
 * Range from 1 to 3: 1 2 3
 * Range from -1 to 2: -1 0 1 2
 * Range from 0 to -3: 0 -1 -2 -3
 **********************/
int main(void)
{
	int *arr;						// Pointer to hold array returned by ft_range
	int i;							// Index for iterating through array
	
	write(1, "Range from 1 to 3: ", 19);	// Print test description
	arr = ft_range(1, 3);				// Create array from 1 to 3
	i = 0;							// Initialize index
	while (i < 3)						// Iterate through the 3-element array
	{
		ft_putnbr(arr[i]);				// Print current array element
		write(1, " ", 1);				// Print space separator
		i++;							// Move to next element
	}
	write(1, "\n", 1);				// Print newline
	free(arr);						// Free allocated memory
	
	write(1, "Range from -1 to 2: ", 20);	// Print test description
	arr = ft_range(-1, 2);				// Create array from -1 to 2
	i = 0;							// Reset index
	while (i < 4)						// Iterate through the 4-element array
	{
		ft_putnbr(arr[i]);				// Print current array element
		write(1, " ", 1);				// Print space separator
		i++;							// Move to next element
	}
	write(1, "\n", 1);				// Print newline
	free(arr);						// Free allocated memory
	
	write(1, "Range from 0 to -3: ", 20);	// Print test description
	arr = ft_range(0, -3);				// Create array from 0 to -3 (descending)
	i = 0;							// Reset index
	while (i < 4)						// Iterate through the 4-element array
	{
		ft_putnbr(arr[i]);				// Print current array element
		write(1, " ", 1);				// Print space separator
		i++;							// Move to next element
	}
	write(1, "\n", 1);				// Print newline
	free(arr);						// Free allocated memory
	
	return (0);						// Return 0 to indicate successful execution
}