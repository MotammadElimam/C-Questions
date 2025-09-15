/*
 ******************************************************
 Create a function that returns the result of converting the string nbr from base
 base_from to base base_to.
 • nbr, base_from, and base_to may be read-only.
 • nbr will follow the same rules as ft_atoi_base (from another module). Beware of
 the characters '+', '-', and whitespaces.
 • The number represented by nbr must fit inside an int.
 • If a base is invalid, NULL should be returned.
 • The returned number must be prefixed only by a single and unique '-' if necessary;
 no whitespaces, no '+'.
 • Here is how it should be prototyped:
 char *ft_convert_base(char *nbr, char *base_from, char *base_to);
 Files to turn in: ft_convert_base.c, ft_convert_base2.c
 Allowed functions: malloc, free
 ******************************************************
 * to compile it : gcc ft_ultimate_range.c
 * to run it : ./a.out
 ******************************************************
 */

#include <stdlib.h>

/**********************
 * ft_ultimate_range - Creates an array of integers via pointer
 * 
 * Description:
 * This function allocates memory for an array of integers containing
 * all values from min (inclusive) to max (exclusive) and assigns it
 * to the pointer pointed to by range. It returns the size of the
 * created array or 0 if min >= max.
 * 
 * Algorithm:
 * 1. Check if min >= max, set *range to NULL and return 0
 * 2. Calculate the size of the range (max - min)
 * 3. Allocate memory for the array
 * 4. If allocation fails, set *range to NULL and return -1
 * 5. Fill array with values from min to max-1
 * 6. Assign array to *range
 * 7. Return the size of the array
 * 
 * Parameters:
 * @range: Pointer to pointer that will hold the array
 * @min: The minimum value (inclusive)
 * @max: The maximum value (exclusive)
 * 
 * Return:
 * Size of the created array
 * 0 if min >= max
 * -1 if memory allocation fails
 * 
 * Examples:
 * int *arr; ft_ultimate_range(&arr, 1, 5) returns 4, arr = [1,2,3,4]
 * int *arr; ft_ultimate_range(&arr, 5, 3) returns 0, arr = NULL
 * int *arr; ft_ultimate_range(&arr, -2, 2) returns 4, arr = [-2,-1,0,1]
 **********************/
int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;						/* Index for array filling */
	int	size;					/* Size of the range */

	if (min >= max)				/* Check for invalid range */
	{
		*range = NULL;			/* Set pointer to NULL */
		return (0);				/* Return 0 for invalid range */
	}
	size = max - min;			/* Calculate range size */
	*range = (int *)malloc(sizeof(int) * size);	/* Allocate memory */
	if (!*range)				/* Check if allocation failed */
		return (-1);			/* Return -1 on allocation failure */
	i = 0;						/* Initialize array index */
	while (i < size)			/* Fill the array with range values */
	{
		(*range)[i] = min + i;	/* Set current element to min + offset */
		i++;					/* Move to next element */
	}
	return (size);				/* Return the size of the array */
}

/**********************
 * main - Test program for ft_ultimate_range function
 * 
 * Description:
 * This program tests the ft_ultimate_range function with various
 * test cases including normal ranges, negative numbers, edge cases,
 * and proper memory management.
 * 
 * Algorithm:
 * 1. Test normal positive range
 * 2. Test range with negative numbers
 * 3. Test invalid range (min >= max)
 * 4. Test single element range
 * 5. Print results and free memory
 * 
 * Return:
 * 0 on successful execution
 **********************/
#include <stdio.h>

int	main(void)
{
	int	*range1;				/* Test array 1 */
	int	*range2;				/* Test array 2 */
	int	*range3;				/* Test array 3 */
	int	*range4;				/* Test array 4 */
	int	size;					/* Size returned by function */
	int	i;						/* Loop counter */

	/* Test 1: Normal positive range */
	printf("Test 1 - Range(1, 5): ");
	size = ft_ultimate_range(&range1, 1, 5);
	printf("Size = %d, Values = ", size);
	if (range1)
	{
		for (i = 0; i < size; i++)
			printf("%d ", range1[i]);
		printf("\n");
		free(range1);
	}
	else
		printf("NULL\n");

	/* Test 2: Range with negative numbers */
	printf("Test 2 - Range(-3, 3): ");
	size = ft_ultimate_range(&range2, -3, 3);
	printf("Size = %d, Values = ", size);
	if (range2)
	{
		for (i = 0; i < size; i++)
			printf("%d ", range2[i]);
		printf("\n");
		free(range2);
	}
	else
		printf("NULL\n");

	/* Test 3: Invalid range (min >= max) */
	printf("Test 3 - Range(5, 3): ");
	size = ft_ultimate_range(&range3, 5, 3);
	printf("Size = %d, Values = ", size);
	if (range3)
		printf("Error: Should be NULL\n");
	else
		printf("NULL (correct)\n");

	/* Test 4: Single element range */
	printf("Test 4 - Range(42, 43): ");
	size = ft_ultimate_range(&range4, 42, 43);
	printf("Size = %d, Values = ", size);
	if (range4)
	{
		for (i = 0; i < size; i++)
			printf("%d ", range4[i]);
		printf("\n");
		free(range4);
	}
	else
		printf("NULL\n");

	return (0);					/* Return success */
}