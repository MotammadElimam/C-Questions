/*
 ******************************************************
 Create a function that reverses a given array of integers (the first element becomes
 the last, and so on).
 The function takes two arguments: a pointer to an int and the number of elements
 in the array.
 The function should be prototyped as follows:
 void ft_rev_int_tab(int *tab, int size);
 ******************************************************
 * to compile it : gcc ft_rev_int_tab.c
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
 * ft_rev_int_tab - Reverses an array of integers in place
 * 
 * Description:
 * This function takes an array of integers and reverses its elements
 * in place, meaning it modifies the original array. The first element
 * becomes the last, the second becomes second-to-last, and so on.
 * It uses a swapping technique with two pointers approaching from
 * opposite ends of the array.
 * 
 * Algorithm:
 * 1. Initialize two indices: start at 0, end at size-1
 * 2. While start index is less than end index:
 *    a. Swap elements at start and end positions
 *    b. Increment start index, decrement end index
 * 3. Continue until pointers meet in the middle
 * 4. Array is now reversed in place
 * 
 * Parameters:
 * @tab: Pointer to the integer array to be reversed
 * @size: Number of elements in the array
 * 
 * Return:
 * void - No return value (modifies array in place)
 * 
 * Examples:
 * int arr[] = {1, 2, 3, 4}; ft_rev_int_tab(arr, 4); // arr becomes {4, 3, 2, 1}
 * int arr[] = {5, 10}; ft_rev_int_tab(arr, 2); // arr becomes {10, 5}
 **********************/
void	ft_rev_int_tab(int *tab, int size)
{
	int start = 0;				/* Index pointer starting from the beginning of array */
	int end = size - 1;			/* Index pointer starting from the end of array */
	int temp;					/* Temporary variable for swapping elements */
	
	while (start < end)			/* Continue while pointers haven't met in the middle */
	{
		temp = tab[start];		/* Store the element at start position in temporary variable */
		tab[start] = tab[end];	/* Copy element from end position to start position */
		tab[end] = temp;		/* Copy temporary value (original start) to end position */
		start++;				/* Move start pointer towards the center */
		end--;					/* Move end pointer towards the center */
	}
}

/**********************
 * print_array - Helper function to display an integer array
 * 
 * Description:
 * This helper function displays all elements of an integer array
 * in a formatted way, with elements separated by spaces and enclosed
 * in square brackets. It's used to show the array contents before
 * and after the reversal operation.
 * 
 * Algorithm:
 * 1. Print opening bracket
 * 2. Iterate through all array elements
 * 3. For each element: print the number followed by a space
 * 4. Print closing bracket and newline
 * 
 * Parameters:
 * @tab: Pointer to the integer array to display
 * @size: Number of elements in the array
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * print_array({1, 2, 3}, 3) outputs "[1 2 3 ]\n"
 **********************/
void	print_array(int *tab, int size)
{
	int i = 0;					/* Index counter for iterating through array */
	
	write(1, "[", 1);			/* Write opening bracket */
	while (i < size)			/* Iterate through all array elements */
	{
		ft_putnbr(tab[i]);		/* Display current array element */
		write(1, " ", 1);		/* Write space separator after each element */
		i++;					/* Move to next array element */
	}
	write(1, "]\n", 2);			/* Write closing bracket and newline */
}

/**********************
 * main - Entry point for integer array reversal demonstration
 * 
 * Description:
 * This program demonstrates the ft_rev_int_tab function by testing
 * it with various integer arrays of different sizes. It shows the
 * array contents before and after reversal to verify the function
 * works correctly with different array configurations.
 * 
 * Algorithm:
 * 1. Create test arrays of various sizes and contents
 * 2. For each test array:
 *    a. Display original array contents
 *    b. Call ft_rev_int_tab to reverse the array
 *    c. Display reversed array contents
 * 3. Test edge cases like single element and two element arrays
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_rev_int_tab shows before/after arrays demonstrating reversal
 **********************/
int main(void)
{
	write(1, "Testing ft_rev_int_tab function:\n\n", 34);		/* Display program header */
	
	/* Test case 1: Array with 5 elements */
	int array1[] = {1, 2, 3, 4, 5};							/* Create test array */
	int size1 = 5;											/* Set array size */
	write(1, "Test 1 - Original array: ", 26);				/* Display test header */
	print_array(array1, size1);							/* Display original array */
	ft_rev_int_tab(array1, size1);							/* Reverse the array */
	write(1, "Test 1 - Reversed array: ", 26);				/* Display result header */
	print_array(array1, size1);							/* Display reversed array */
	write(1, "\n", 1);										/* Write newline for spacing */
	
	/* Test case 2: Array with 4 elements (even number) */
	int array2[] = {10, 20, 30, 40};						/* Create test array */
	int size2 = 4;											/* Set array size */
	write(1, "Test 2 - Original array: ", 26);				/* Display test header */
	print_array(array2, size2);							/* Display original array */
	ft_rev_int_tab(array2, size2);							/* Reverse the array */
	write(1, "Test 2 - Reversed array: ", 26);				/* Display result header */
	print_array(array2, size2);							/* Display reversed array */
	write(1, "\n", 1);										/* Write newline for spacing */
	
	/* Test case 3: Array with 2 elements (minimal case) */
	int array3[] = {100, 200};								/* Create test array */
	int size3 = 2;											/* Set array size */
	write(1, "Test 3 - Original array: ", 26);				/* Display test header */
	print_array(array3, size3);							/* Display original array */
	ft_rev_int_tab(array3, size3);							/* Reverse the array */
	write(1, "Test 3 - Reversed array: ", 26);				/* Display result header */
	print_array(array3, size3);							/* Display reversed array */
	write(1, "\n", 1);										/* Write newline for spacing */
	
	/* Test case 4: Array with 1 element (edge case) */
	int array4[] = {42};									/* Create single element array */
	int size4 = 1;											/* Set array size */
	write(1, "Test 4 - Original array: ", 26);				/* Display test header */
	print_array(array4, size4);							/* Display original array */
	ft_rev_int_tab(array4, size4);							/* Reverse the array */
	write(1, "Test 4 - Reversed array: ", 26);				/* Display result header */
	print_array(array4, size4);							/* Display reversed array */
	write(1, "\n", 1);										/* Write newline for spacing */
	
	/* Test case 5: Array with negative numbers */
	int array5[] = {-1, -2, 3, -4, 5};						/* Create array with negative numbers */
	int size5 = 5;											/* Set array size */
	write(1, "Test 5 - Original array: ", 26);				/* Display test header */
	print_array(array5, size5);							/* Display original array */
	ft_rev_int_tab(array5, size5);							/* Reverse the array */
	write(1, "Test 5 - Reversed array: ", 26);				/* Display result header */
	print_array(array5, size5);							/* Display reversed array */
	
	return (0);					/* Return success status to the operating system */
}