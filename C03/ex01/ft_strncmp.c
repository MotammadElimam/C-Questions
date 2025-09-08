/*
 ******************************************************
 Reproduce the behavior of the function strncmp (man strncmp).
 The function should be prototyped as follows:
 int ft_strncmp(char *s1, char *s2, unsigned int n);
 ******************************************************
 * to compile it : gcc ft_strncmp.c
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
 * ft_strncmp - Compares two strings up to n characters
 * 
 * Description:
 * This function reproduces the behavior of the standard strncmp function.
 * It compares at most n characters of two strings and returns an integer
 * indicating their relative ordering. The comparison stops at the first
 * difference found or when n characters have been compared.
 * 
 * Algorithm:
 * 1. Check if n is 0, return 0 immediately
 * 2. Iterate through both strings up to n characters
 * 3. Compare characters at each position
 * 4. If characters differ, return their difference
 * 5. Stop if either string ends or n characters compared
 * 6. Return difference of current characters
 * 
 * Parameters:
 * @s1: First string to compare
 * @s2: Second string to compare
 * @n: Maximum number of characters to compare
 * 
 * Return:
 * 0 if strings are equal up to n characters
 * Negative value if s1 < s2 within n characters
 * Positive value if s1 > s2 within n characters
 * 
 * Examples:
 * ft_strncmp("abc", "abc", 3) returns 0
 * ft_strncmp("abc", "abd", 2) returns 0
 * ft_strncmp("abc", "abd", 3) returns negative
 **********************/
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;				/* Index for iterating through strings */
	
	if (n == 0)					/* If n is 0, no comparison needed */
		return (0);				/* Return 0 indicating equality */
	
	i = 0;						/* Initialize index to start of strings */
	while (i < n - 1 && s1[i] != '\0' && s2[i] != '\0')	/* Loop while within limit and both have chars */
	{
		if (s1[i] != s2[i])		/* Check if characters differ at current position */
			return (s1[i] - s2[i]);		/* Return difference in ASCII values */
		i++;					/* Move to next character position */
	}
	if (i < n)					/* If we haven't compared n characters yet */
		return (s1[i] - s2[i]);		/* Return difference of current characters */
	return (0);					/* All n characters are equal */
}

/**********************
 * main - Entry point for limited string comparison demonstration program
 * 
 * Description:
 * This program demonstrates the ft_strncmp function by testing it with
 * various string pairs and different values of n. It shows how the
 * function compares only up to n characters and how this affects the
 * comparison results.
 * 
 * Algorithm:
 * 1. Create test string pairs covering different scenarios
 * 2. Call ft_strncmp with various n values
 * 3. Display the comparison results
 * 4. Show how n parameter affects the comparison outcome
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_strncmp outputs comparison results with different n values
 **********************/
int main(void)
{
	char *str1 = "Hello";		/* First test string */
	char *str2 = "Hello";		/* Second test string (equal to first) */
	char *str3 = "Hell";		/* Shorter string */
	char *str4 = "Helicopter";	/* String with same prefix */
	char *str5 = "";			/* Empty string */
	int result;					/* Variable to store comparison result */
	
	/* Test 1: Equal strings, compare all */
	result = ft_strncmp(str1, str2, 5);		/* Compare full strings */
	write(1, "Test 1 - Equal strings (n=5):\n", 31);		/* Display test description */
	write(1, "ft_strncmp(\"Hello\", \"Hello\", 5) = ", 35);		/* Show input */
	ft_putnbr(result);			/* Display result (should be 0) */
	write(1, "\n\n", 2);		/* Write newlines for formatting */
	
	/* Test 2: Different strings, but same first 3 chars */
	result = ft_strncmp(str1, str4, 3);		/* Compare only first 3 characters */
	write(1, "Test 2 - Same prefix (n=3):\n", 29);		/* Display test description */
	write(1, "ft_strncmp(\"Hello\", \"Helicopter\", 3) = ", 40);		/* Show input */
	ft_putnbr(result);			/* Display result (should be 0) */
	write(1, "\n\n", 2);		/* Write newlines for formatting */
	
	/* Test 3: Same test but compare more characters */
	result = ft_strncmp(str1, str4, 5);		/* Compare 5 characters */
	write(1, "Test 3 - Different after prefix (n=5):\n", 40);		/* Display test description */
	write(1, "ft_strncmp(\"Hello\", \"Helicopter\", 5) = ", 40);		/* Show input */
	ft_putnbr(result);			/* Display result (should be positive: 'o' > 'i') */
	write(1, "\n\n", 2);		/* Write newlines for formatting */
	
	/* Test 4: First string longer, compare beyond shorter string */
	result = ft_strncmp(str1, str3, 5);		/* Compare beyond length of str3 */
	write(1, "Test 4 - Beyond shorter string (n=5):\n", 39);		/* Display test description */
	write(1, "ft_strncmp(\"Hello\", \"Hell\", 5) = ", 34);		/* Show input */
	ft_putnbr(result);			/* Display result (should be positive) */
	write(1, "\n\n", 2);		/* Write newlines for formatting */
	
	/* Test 5: n = 0 case */
	result = ft_strncmp(str1, str4, 0);		/* Compare 0 characters */
	write(1, "Test 5 - n = 0:\n", 16);		/* Display test description */
	write(1, "ft_strncmp(\"Hello\", \"Helicopter\", 0) = ", 40);		/* Show input */
	ft_putnbr(result);			/* Display result (should be 0) */
	write(1, "\n\n", 2);		/* Write newlines for formatting */
	
	/* Test 6: Empty string comparison */
	result = ft_strncmp(str5, str1, 3);		/* Compare empty with non-empty */
	write(1, "Test 6 - Empty vs non-empty (n=3):\n", 36);		/* Display test description */
	write(1, "ft_strncmp(\"\", \"Hello\", 3) = ", 30);		/* Show input */
	ft_putnbr(result);			/* Display result (negative: empty < non-empty) */
	write(1, "\n", 1);			/* Write newline */
	
	return (0);					/* Return success status to the operating system */
}