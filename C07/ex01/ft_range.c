/*
 ******************************************************
 Create a function ft_range which returns an array of ints. This int array should
 contain all values between min and max.
 contain all values between min and max.
 • Min included - max excluded.
 • Min included - max excluded.
 • Here is how it should be prototyped :
 • Here is how it should be prototyped :
 int *ft_range(int min, int max);
 ******************************************************
 * to compile it : gcc ft_range.c
 * to run it : ./a.out
 ******************************************************
 */

#include <stdlib.h>

/**********************
 * ft_range - Creates an array of integers in a range
 * 
 * Description:
 * This function creates a dynamically allocated array containing
 * all integers from min (inclusive) to max (exclusive). If min
 * is greater than or equal to max, it returns NULL.
 * 
 * Algorithm:
 * 1. Check if min >= max, return NULL if true
 * 2. Calculate the size of the range (max - min)
 * 3. Allocate memory for the array
 * 4. If allocation fails, return NULL
 * 5. Fill array with values from min to max-1
 * 6. Return pointer to the array
 * 
 * Parameters:
 * @min: The minimum value (inclusive)
 * @max: The maximum value (exclusive)
 * 
 * Return:
 * Pointer to allocated array containing the range
 * NULL if min >= max or if allocation fails
 * 
 * Examples:
 * ft_range(1, 5) returns [1, 2, 3, 4]
 * ft_range(0, 3) returns [0, 1, 2]
 * ft_range(5, 3) returns NULL
 * ft_range(-2, 2) returns [-2, -1, 0, 1]
 **********************/
int	*ft_range(int min, int max)
{
	int	*range;					/* Pointer to the result array */
	int	i;						/* Index for array filling */
	int	size;					/* Size of the range */

	if (min >= max)				/* Check for invalid range */
		return (NULL);			/* Return NULL for invalid range */
	size = max - min;			/* Calculate range size */
	range = (int *)malloc(sizeof(int) * size);		/* Allocate memory for array */
	if (!range)					/* Check if allocation failed */
		return (NULL);			/* Return NULL on allocation failure */
	i = 0;						/* Initialize array index */
	while (i < size)			/* Fill the array with range values */
	{
		range[i] = min + i;		/* Set current element to min + offset */
		i++;					/* Move to next element */
	}
	return (range);				/* Return the filled array */
}

/**********************
 * main - Test program for ft_range function
 * 
 * Description:
 * This program tests the ft_range function with various
 * test cases including normal ranges, negative numbers,
 * and edge cases.
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
	int	i;						/* Loop counter */

	/* Test 1: Normal positive range */
	printf("Test 1 - Range(1, 5): ");
	range1 = ft_range(1, 5);
	if (range1)
	{
		for (i = 0; i < 4; i++)
			printf("%d ", range1[i]);
		printf("\n");
		free(range1);
	}
	else
		printf("NULL\n");

	/* Test 2: Range with negative numbers */
	printf("Test 2 - Range(-3, 3): ");
	range2 = ft_range(-3, 3);
	if (range2)
	{
		for (i = 0; i < 6; i++)
			printf("%d ", range2[i]);
		printf("\n");
		free(range2);
	}
	else
		printf("NULL\n");

	/* Test 3: Invalid range (min >= max) */
	printf("Test 3 - Range(5, 3): ");
	range3 = ft_range(5, 3);
	if (range3)
	{
		printf("Error: Should be NULL\n");
		free(range3);
	}
	else
		printf("NULL (correct)\n");

	/* Test 4: Single element range */
	printf("Test 4 - Range(42, 43): ");
	range4 = ft_range(42, 43);
	if (range4)
	{
		printf("%d\n", range4[0]);
		free(range4);
	}
	else
		printf("NULL\n");

	return (0);					/* Return success */
}