/*
 ******************************************************
 Create a function that sorts an array of integers in ascending order.
 The function takes two arguments: a pointer to an int and the number of elements
 in the array.
 The function should be prototyped as follows:
 void ft_sort_int_tab(int *tab, int size);
 ******************************************************
 * to compile it : gcc ft_sort_int_tab.c
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
 * ft_sort_int_tab - Sorts an array of integers in ascending order using bubble sort
 * 
 * Description:
 * This function takes an array of integers and sorts its elements in
 * ascending order using the bubble sort algorithm. It modifies the
 * original array in place, repeatedly comparing adjacent elements
 * and swapping them if they are in the wrong order.
 * 
 * Algorithm:
 * 1. Use nested loops for bubble sort implementation
 * 2. Outer loop: iterate through all elements (n-1 passes)
 * 3. Inner loop: compare adjacent pairs and swap if needed
 * 4. After each pass, the largest unsorted element "bubbles" to its position
 * 5. Continue until no more swaps are needed
 * 
 * Parameters:
 * @tab: Pointer to the integer array to be sorted
 * @size: Number of elements in the array
 * 
 * Return:
 * void - No return value (modifies array in place)
 * 
 * Examples:
 * int arr[] = {3, 1, 4, 2}; ft_sort_int_tab(arr, 4); // arr becomes {1, 2, 3, 4}
 * int arr[] = {5, -2, 8}; ft_sort_int_tab(arr, 3); // arr becomes {-2, 5, 8}
 **********************/
void	ft_sort_int_tab(int *tab, int size)
{
	int i;						/* Outer loop counter for number of passes */
	int j;						/* Inner loop counter for comparing adjacent elements */
	int temp;					/* Temporary variable for swapping elements */
	
	i = 0;						/* Initialize outer loop counter */
	while (i < size - 1)		/* Outer loop: perform size-1 passes */
	{
		j = 0;					/* Initialize inner loop counter for each pass */
		while (j < size - 1 - i)	/* Inner loop: compare elements, reducing range each pass */
		{
			if (tab[j] > tab[j + 1])	/* Check if current element is greater than next */
			{
				temp = tab[j];			/* Store current element in temporary variable */
				tab[j] = tab[j + 1];	/* Move smaller element to current position */
				tab[j + 1] = temp;		/* Move larger element to next position */
			}
			j++;				/* Move to next pair of adjacent elements */
		}
		i++;					/* Move to next pass */
	}
}

/**********************
 * print_array - Helper function to display an integer array
 * 
 * Description:
 * This helper function displays all elements of an integer array
 * in a formatted way, with elements separated by spaces and enclosed
 * in square brackets. It's used to show the array contents before
 * and after the sorting operation.
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
 * main - Entry point for integer array sorting demonstration
 * 
 * Description:
 * This program demonstrates the ft_sort_int_tab function by testing
 * it with various integer arrays containing different patterns of
 * unsorted data. It shows the array contents before and after
 * sorting to verify the function works correctly.
 * 
 * Algorithm:
 * 1. Create test arrays with different sorting challenges
 * 2. For each test array:
 *    a. Display original unsorted array contents
 *    b. Call ft_sort_int_tab to sort the array
 *    c. Display sorted array contents
 * 3. Test various cases: random order, reverse order, duplicates, negatives
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_sort_int_tab shows before/after arrays demonstrating sorting
 **********************/
int main(void)
{
	write(1, "Testing ft_sort_int_tab function:\n\n", 35);	/* Display program header */
	
	/* Test case 1: Random unsorted array */
	int array1[] = {3, 1, 4, 1, 5, 9, 2, 6};				/* Create unsorted test array */
	int size1 = 8;											/* Set array size */
	write(1, "Test 1 - Original array: ", 26);				/* Display test header */
	print_array(array1, size1);							/* Display original array */
	ft_sort_int_tab(array1, size1);						/* Sort the array */
	write(1, "Test 1 - Sorted array:   ", 26);				/* Display result header */
	print_array(array1, size1);							/* Display sorted array */
	write(1, "\n", 1);										/* Write newline for spacing */
	
	/* Test case 2: Reverse sorted array (worst case for bubble sort) */
	int array2[] = {9, 8, 7, 6, 5};						/* Create reverse-sorted array */
	int size2 = 5;											/* Set array size */
	write(1, "Test 2 - Original array: ", 26);				/* Display test header */
	print_array(array2, size2);							/* Display original array */
	ft_sort_int_tab(array2, size2);						/* Sort the array */
	write(1, "Test 2 - Sorted array:   ", 26);				/* Display result header */
	print_array(array2, size2);							/* Display sorted array */
	write(1, "\n", 1);										/* Write newline for spacing */
	
	/* Test case 3: Array with negative numbers */
	int array3[] = {-3, 5, -1, 0, 2, -4};					/* Create array with negative numbers */
	int size3 = 6;											/* Set array size */
	write(1, "Test 3 - Original array: ", 26);				/* Display test header */
	print_array(array3, size3);							/* Display original array */
	write(1, "Test 3 - Sorted array:   ", 26);				/* Display result header */
	ft_sort_int_tab(array3, size3);						/* Sort the array */
	print_array(array3, size3);							/* Display sorted array */
	write(1, "\n", 1);										/* Write newline for spacing */
	
	/* Test case 4: Array with duplicate values */
	int array4[] = {4, 2, 4, 1, 2, 1, 4};					/* Create array with duplicates */
	int size4 = 7;											/* Set array size */
	write(1, "Test 4 - Original array: ", 26);				/* Display test header */
	print_array(array4, size4);							/* Display original array */
	ft_sort_int_tab(array4, size4);						/* Sort the array */
	write(1, "Test 4 - Sorted array:   ", 26);				/* Display result header */
	print_array(array4, size4);							/* Display sorted array */
	write(1, "\n", 1);										/* Write newline for spacing */
	
	/* Test case 5: Single element array (edge case) */
	int array5[] = {42};									/* Create single element array */
	int size5 = 1;											/* Set array size */
	write(1, "Test 5 - Original array: ", 26);				/* Display test header */
	print_array(array5, size5);							/* Display original array */
	ft_sort_int_tab(array5, size5);						/* Sort the array */
	write(1, "Test 5 - Sorted array:   ", 26);				/* Display result header */
	print_array(array5, size5);							/* Display sorted array */
	write(1, "\n", 1);										/* Write newline for spacing */
	
	/* Test case 6: Already sorted array (best case) */
	int array6[] = {1, 2, 3, 4, 5};						/* Create already sorted array */
	int size6 = 5;											/* Set array size */
	write(1, "Test 6 - Original array: ", 26);				/* Display test header */
	print_array(array6, size6);							/* Display original array */
	ft_sort_int_tab(array6, size6);						/* Sort the array */
	write(1, "Test 6 - Sorted array:   ", 26);				/* Display result header */
	print_array(array6, size6);							/* Display sorted array */
	
	return (0);					/* Return success status to the operating system */
}