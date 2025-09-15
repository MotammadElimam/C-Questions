/*
 ******************************************************
 Write a function that concatenates all the strings pointed to by strs, separated by sep.
 • size is the number of strings in strs.
 • If size is 0, you must return an empty string that can be freed using free().
 • Here is how it should be prototyped:
 char *ft_strjoin(int size, char **strs, char *sep);
 
 ******************************************************
 * to compile it : gcc ft_strjoin.c
 * to run it : ./a.out
 ******************************************************
 */

#include <stdlib.h>

/**********************
 * ft_strlen - Calculates the length of a string
 * 
 * Description:
 * This function counts the number of characters in a string
 * until it reaches the null terminator. Used to calculate
 * the total size needed for the joined string.
 * 
 * Algorithm:
 * 1. Initialize counter to 0
 * 2. Loop through string until null terminator
 * 3. Increment counter for each character
 * 4. Return the final count
 * 
 * Parameters:
 * @str: The string to measure
 * 
 * Return:
 * The length of the string (excluding null terminator)
 * 
 * Examples:
 * ft_strlen("hello") returns 5
 * ft_strlen("") returns 0
 **********************/
int	ft_strlen(char *str)
{
	int	len;					/* Counter for string length */

	len = 0;					/* Initialize length to 0 */
	while (str[len])			/* Loop until null terminator */
		len++;					/* Count each character */
	return (len);				/* Return the length */
}

/**********************
 * ft_calculate_total_len - Calculates total length for joined string
 * 
 * Description:
 * This function calculates the total length needed for the final
 * joined string by summing the lengths of all strings and separators.
 * 
 * Algorithm:
 * 1. Initialize total length to 0
 * 2. For each string, add its length to total
 * 3. Add separator length for each separator needed (size - 1)
 * 4. Return total length
 * 
 * Parameters:
 * @size: Number of strings to join
 * @strs: Array of strings to join
 * @sep: Separator string
 * 
 * Return:
 * Total length needed for the joined string
 * 
 * Examples:
 * ["hello", "world"], sep=" " returns 11
 * ["a", "b", "c"], sep="-" returns 5
 **********************/
int	ft_calculate_total_len(int size, char **strs, char *sep)
{
	int	total_len;				/* Total length accumulator */
	int	sep_len;				/* Length of separator */
	int	i;						/* Loop counter */

	total_len = 0;				/* Initialize total length */
	sep_len = ft_strlen(sep);	/* Get separator length once */
	i = 0;						/* Initialize counter */
	while (i < size)			/* Loop through all strings */
	{
		total_len += ft_strlen(strs[i]);	/* Add string length */
		if (i < size - 1)		/* If not last string */
			total_len += sep_len;	/* Add separator length */
		i++;					/* Move to next string */
	}
	return (total_len);			/* Return total length */
}

/**********************
 * ft_strcat_to_dest - Concatenates a string to destination
 * 
 * Description:
 * This function appends a source string to a destination string
 * starting at the specified index and returns the new index.
 * 
 * Algorithm:
 * 1. Loop through each character of source
 * 2. Copy character to destination at current index
 * 3. Increment index
 * 4. Return final index position
 * 
 * Parameters:
 * @dest: Destination string
 * @src: Source string to append
 * @index: Starting index in destination
 * 
 * Return:
 * New index position after concatenation
 * 
 * Examples:
 * dest="hello", src="world", index=5 returns 10
 **********************/
int	ft_strcat_to_dest(char *dest, char *src, int index)
{
	int	i;						/* Source string index */

	i = 0;						/* Initialize source index */
	while (src[i])				/* Loop through source string */
	{
		dest[index] = src[i];	/* Copy character to destination */
		index++;				/* Move destination index */
		i++;					/* Move source index */
	}
	return (index);				/* Return new destination index */
}

/**********************
 * ft_strjoin - Joins multiple strings with a separator
 * 
 * Description:
 * This function concatenates all strings in the array strs,
 * placing the separator string between each pair. Returns a
 * newly allocated string containing the result.
 * 
 * Algorithm:
 * 1. Handle special case of size 0 (return empty string)
 * 2. Calculate total length needed
 * 3. Allocate memory for result string
 * 4. Copy first string
 * 5. For each remaining string:
 *    - Add separator
 *    - Add string
 * 6. Add null terminator
 * 7. Return result
 * 
 * Parameters:
 * @size: Number of strings in strs array
 * @strs: Array of strings to join
 * @sep: Separator string to place between strings
 * 
 * Return:
 * Newly allocated string containing joined strings
 * NULL if memory allocation fails
 * 
 * Examples:
 * ft_strjoin(2, ["hello", "world"], " ") returns "hello world"
 * ft_strjoin(3, ["a", "b", "c"], "-") returns "a-b-c"
 * ft_strjoin(0, [], "x") returns ""
 **********************/
char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;			/* Result string */
	int		total_len;			/* Total length needed */
	int		index;				/* Current index in result */
	int		i;					/* Loop counter */

	if (size == 0)				/* Handle empty case */
	{
		result = (char *)malloc(sizeof(char));	/* Allocate for empty string */
		if (result)
			result[0] = '\0';	/* Create empty string */
		return (result);		/* Return empty string */
	}
	total_len = ft_calculate_total_len(size, strs, sep);	/* Calculate total length */
	result = (char *)malloc(sizeof(char) * (total_len + 1));	/* Allocate memory */
	if (!result)				/* Check allocation */
		return (NULL);			/* Return NULL on failure */
	index = 0;					/* Initialize result index */
	i = 0;						/* Initialize string counter */
	while (i < size)			/* Loop through all strings */
	{
		index = ft_strcat_to_dest(result, strs[i], index);	/* Add current string */
		if (i < size - 1)		/* If not last string */
			index = ft_strcat_to_dest(result, sep, index);	/* Add separator */
		i++;					/* Move to next string */
	}
	result[index] = '\0';		/* Add null terminator */
	return (result);			/* Return joined string */
}

/**********************
 * main - Test program for ft_strjoin function
 * 
 * Description:
 * This program tests the ft_strjoin function with various
 * test cases including normal joins, empty arrays, and
 * different separators.
 * 
 * Algorithm:
 * 1. Test normal string joining
 * 2. Test with empty separator
 * 3. Test with size 0
 * 4. Test with single string
 * 5. Print results and free memory
 * 
 * Return:
 * 0 on successful execution
 **********************/
#include <stdio.h>

int	main(void)
{
	char	*strs1[] = {"Hello", "World", "42"};			/* Test array 1 */
	char	*strs2[] = {"One", "Two", "Three", "Four"};	/* Test array 2 */
	char	*strs3[] = {"Single"};						/* Single string */
	char	*result;										/* Result string */

	/* Test 1: Normal join with space separator */
	printf("Test 1 - Join with space:\n");
	result = ft_strjoin(3, strs1, " ");
	printf("Result: '%s'\n", result);
	free(result);

	/* Test 2: Join with dash separator */
	printf("\nTest 2 - Join with dash:\n");
	result = ft_strjoin(4, strs2, "-");
	printf("Result: '%s'\n", result);
	free(result);

	/* Test 3: Join with empty separator */
	printf("\nTest 3 - Join with empty separator:\n");
	result = ft_strjoin(3, strs1, "");
	printf("Result: '%s'\n", result);
	free(result);

	/* Test 4: Size 0 (empty result) */
	printf("\nTest 4 - Size 0:\n");
	result = ft_strjoin(0, strs1, ", ");
	printf("Result: '%s' (empty)\n", result);
	free(result);

	/* Test 5: Single string (no separator needed) */
	printf("\nTest 5 - Single string:\n");
	result = ft_strjoin(1, strs3, " | ");
	printf("Result: '%s'\n", result);
	free(result);

	return (0);					/* Return success */
}