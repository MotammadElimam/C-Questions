/*
 ******************************************************
 Reproduce the behavior of the function strcmp (man strcmp).
 The function should be prototyped as follows:
 int ft_strcmp(char *s1, char *s2);
 ******************************************************
 * to compile it : gcc ft_strcmp.c
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
 * ft_strcmp - Compares two strings lexicographically
 * 
 * Description:
 * This function reproduces the behavior of the standard strcmp function.
 * It compares two strings character by character and returns an integer
 * indicating their relative ordering. The comparison is done using
 * ASCII values of the characters.
 * 
 * Algorithm:
 * 1. Iterate through both strings simultaneously
 * 2. Compare characters at each position
 * 3. If characters differ, return their difference
 * 4. Continue until end of either string
 * 5. Return difference of current characters (0 if both ended)
 * 
 * Parameters:
 * @s1: First string to compare
 * @s2: Second string to compare
 * 
 * Return:
 * 0 if strings are equal
 * Negative value if s1 < s2
 * Positive value if s1 > s2
 * 
 * Examples:
 * ft_strcmp("abc", "abc") returns 0
 * ft_strcmp("abc", "abd") returns negative
 * ft_strcmp("abd", "abc") returns positive
 **********************/
int	ft_strcmp(char *s1, char *s2)
{
	int i;						/* Index for iterating through both strings */
	
	i = 0;						/* Initialize index to start of strings */
	while (s1[i] != '\0' && s2[i] != '\0')		/* Loop while both strings have characters */
	{
		if (s1[i] != s2[i])		/* Check if characters differ at current position */
			return (s1[i] - s2[i]);		/* Return difference in ASCII values */
		i++;					/* Move to next character position */
	}
	return (s1[i] - s2[i]);		/* Return difference (0 if both strings ended) */
}

/**********************
 * main - Entry point for string comparison demonstration program
 * 
 * Description:
 * This program demonstrates the ft_strcmp function by testing it with
 * various string pairs including equal strings, different strings,
 * strings of different lengths, and empty strings. It shows how the
 * function correctly determines the lexicographical ordering of strings.
 * 
 * Algorithm:
 * 1. Create test string pairs covering different scenarios
 * 2. Call ft_strcmp with each pair
 * 3. Display the comparison result
 * 4. Interpret results (0 = equal, negative = s1 < s2, positive = s1 > s2)
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_strcmp outputs comparison results for various string pairs
 **********************/
int main(void)
{
	char *str1 = "Hello";		/* First test string */
	char *str2 = "Hello";		/* Second test string (equal to first) */
	char *str3 = "Hell";		/* Shorter string */
	char *str4 = "World";		/* Different string */
	char *str5 = "";			/* Empty string */
	int result;					/* Variable to store comparison result */
	
	/* Test 1: Equal strings */
	result = ft_strcmp(str1, str2);		/* Compare identical strings */
	write(1, "Test 1 - Equal strings:\n", 24);		/* Display test description */
	write(1, "ft_strcmp(\"Hello\", \"Hello\") = ", 31);		/* Show input */
	ft_putnbr(result);			/* Display result (should be 0) */
	write(1, "\n\n", 2);		/* Write newlines for formatting */
	
	/* Test 2: First string longer */
	result = ft_strcmp(str1, str3);		/* Compare longer string with shorter */
	write(1, "Test 2 - First string longer:\n", 31);		/* Display test description */
	write(1, "ft_strcmp(\"Hello\", \"Hell\") = ", 30);		/* Show input */
	ft_putnbr(result);			/* Display result (should be positive) */
	write(1, "\n\n", 2);		/* Write newlines for formatting */
	
	/* Test 3: Different strings */
	result = ft_strcmp(str1, str4);		/* Compare completely different strings */
	write(1, "Test 3 - Different strings:\n", 29);		/* Display test description */
	write(1, "ft_strcmp(\"Hello\", \"World\") = ", 31);		/* Show input */
	ft_putnbr(result);			/* Display result (negative: 'H' < 'W') */
	write(1, "\n\n", 2);		/* Write newlines for formatting */
	
	/* Test 4: Empty string comparison */
	result = ft_strcmp(str5, str1);		/* Compare empty string with non-empty */
	write(1, "Test 4 - Empty vs non-empty:\n", 30);		/* Display test description */
	write(1, "ft_strcmp(\"\", \"Hello\") = ", 26);		/* Show input */
	ft_putnbr(result);			/* Display result (negative: empty < non-empty) */
	write(1, "\n\n", 2);		/* Write newlines for formatting */
	
	/* Test 5: Both empty strings */
	result = ft_strcmp(str5, str5);		/* Compare two empty strings */
	write(1, "Test 5 - Both empty:\n", 21);		/* Display test description */
	write(1, "ft_strcmp(\"\", \"\") = ", 20);		/* Show input */
	ft_putnbr(result);			/* Display result (should be 0) */
	write(1, "\n", 1);			/* Write newline */
	
	return (0);					/* Return success status to the operating system */
}