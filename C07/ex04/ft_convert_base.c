/*
 ******************************************************
 Files to turn in: ft_convert_base.c, ft_convert_base2.c
 Allowed functions: malloc, free
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
 ******************************************************
 * to compile it : gcc ft_convert_base.c
 * to run it : ./a.out
 ******************************************************
 */

#include <stdlib.h>

/**********************
 * ft_strlen - Calculates the length of a string
 * 
 * Description:
 * Counts characters in a string until the null terminator.
 * Used to determine base lengths.
 * 
 * Algorithm:
 * 1. Initialize counter to 0
 * 2. Loop until null terminator
 * 3. Increment counter for each character
 * 4. Return the count
 * 
 * Parameters:
 * @str: The string to measure
 * 
 * Return:
 * Length of the string
 * 
 * Examples:
 * ft_strlen("01") returns 2 (binary base)
 * ft_strlen("0123456789") returns 10 (decimal base)
 **********************/
int	ft_strlen(char *str)
{
	int	len;					/* Length counter */
	
	len = 0;					/* Initialize counter */
	while (str[len])			/* Loop until null terminator */
		len++;					/* Count each character */
	return (len);				/* Return the length */
}

/**********************
 * ft_check_base - Validates a base string
 * 
 * Description:
 * Checks if a base is valid: no duplicates, no '+' or '-',
 * no whitespace, and must have at least 2 characters.
 * 
 * Algorithm:
 * 1. Check if base has at least 2 characters
 * 2. Check each character for invalid symbols
 * 3. Check for duplicate characters
 * 4. Return 1 if valid, 0 if invalid
 * 
 * Parameters:
 * @base: The base string to validate
 * 
 * Return:
 * 1 if base is valid, 0 if invalid
 * 
 * Examples:
 * ft_check_base("01") returns 1 (valid binary)
 * ft_check_base("0123456789") returns 1 (valid decimal)
 * ft_check_base("011") returns 0 (duplicate '1')
 **********************/
int	ft_check_base(char *base)
{
	int	i;						/* First loop counter */
	int	j;						/* Second loop counter */
	
	if (ft_strlen(base) < 2)	/* Base must have at least 2 chars */
		return (0);
	i = 0;
	while (base[i])				/* Check each character */
	{
		/* Check for invalid characters */
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] == 127)
			return (0);
		j = i + 1;
		while (base[j])			/* Check for duplicates */
		{
			if (base[i] == base[j])
				return (0);		/* Duplicate found */
			j++;
		}
		i++;
	}
	return (1);					/* Base is valid */
}

/**********************
 * ft_atoi_base - Converts string to integer in given base
 * 
 * Description:
 * Converts a string representation of a number in a specified
 * base to an integer. Handles signs and whitespace.
 * 
 * Algorithm:
 * 1. Skip whitespace characters
 * 2. Process sign characters
 * 3. Convert digits according to base
 * 4. Return the result with correct sign
 * 
 * Parameters:
 * @str: String to convert
 * @base: Base string for conversion
 * 
 * Return:
 * Integer value of the string
 * 
 * Examples:
 * ft_atoi_base("101010", "01") returns 42
 * ft_atoi_base("-2A", "0123456789ABCDEF") returns -42
 **********************/
int	ft_atoi_base(char *str, char *base)
{
	int	result;					/* Accumulator for result */
	int	sign;					/* Sign of the number */
	int	base_len;				/* Length of the base */
	int	i;						/* String index */
	int	j;						/* Base search index */
	
	result = 0;					/* Initialize result */
	sign = 1;					/* Default positive */
	base_len = ft_strlen(base);	/* Get base length */
	i = 0;
	
	/* Skip whitespace */
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	
	/* Handle signs */
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;			/* Flip sign for each minus */
		i++;
	}
	
	/* Convert number */
	while (str[i])
	{
		j = 0;
		while (base[j] && base[j] != str[i])	/* Find digit in base */
			j++;
		if (!base[j])			/* Character not in base */
			break;
		result = result * base_len + j;		/* Add digit value */
		i++;
	}
	return (result * sign);		/* Return with sign */
}

/**********************
 * ft_putnbr_base - Converts integer to string in given base
 * 
 * Description:
 * Recursively converts an integer to its string representation
 * in the specified base, storing it in the buffer.
 * 
 * Algorithm:
 * 1. Handle negative numbers
 * 2. Recursively divide by base length
 * 3. Store digits in reverse order
 * 4. Return position in buffer
 * 
 * Parameters:
 * @nbr: Number to convert
 * @base: Target base string
 * @buffer: Buffer to store result
 * @pos: Current position in buffer
 * 
 * Return:
 * Updated position in buffer
 **********************/
int	ft_putnbr_base(long nbr, char *base, char *buffer, int pos)
{
	int		base_len;			/* Length of the base */
	
	base_len = ft_strlen(base);
	if (nbr < 0)				/* Handle negative */
	{
		buffer[pos++] = '-';
		nbr = -nbr;
	}
	if (nbr >= base_len)		/* Recursive case */
		pos = ft_putnbr_base(nbr / base_len, base, buffer, pos);
	buffer[pos++] = base[nbr % base_len];	/* Add digit */
	return (pos);				/* Return new position */
}

/**********************
 * ft_convert_base - Converts number from one base to another
 * 
 * Description:
 * Main function that converts a number string from one base
 * to another. Validates bases, converts to integer, then
 * converts to target base.
 * 
 * Algorithm:
 * 1. Validate both bases
 * 2. Convert string to integer using source base
 * 3. Convert integer to string using target base
 * 4. Allocate and return result
 * 
 * Parameters:
 * @nbr: Number string in base_from
 * @base_from: Source base
 * @base_to: Target base
 * 
 * Return:
 * Newly allocated string in target base
 * NULL if bases are invalid or allocation fails
 * 
 * Examples:
 * ft_convert_base("42", "0123456789", "01") returns "101010"
 * ft_convert_base("2A", "0123456789ABCDEF", "0123456789") returns "42"
 **********************/
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;				/* Integer value */
	char	buffer[100];		/* Temporary buffer */
	char	*result;			/* Result string */
	int		len;				/* Length of result */
	int		i;					/* Copy index */
	
	/* Validate bases */
	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (NULL);
	
	/* Convert to integer */
	num = ft_atoi_base(nbr, base_from);
	
	/* Handle zero special case */
	if (num == 0)
	{
		result = malloc(2);
		if (result)
		{
			result[0] = base_to[0];
			result[1] = '\0';
		}
		return (result);
	}
	
	/* Convert to target base */
	len = ft_putnbr_base(num, base_to, buffer, 0);
	
	/* Allocate and copy result */
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = buffer[i];
		i++;
	}
	result[i] = '\0';
	
	return (result);
}

/**********************
 * main - Test program for ft_convert_base
 * 
 * Description:
 * Tests base conversion with various bases including
 * binary, decimal, and hexadecimal.
 * 
 * Return:
 * 0 on successful execution
 **********************/
#include <stdio.h>

int	main(void)
{
	char	*result;			/* Result string */
	
	/* Test 1: Decimal to Binary */
	printf("Test 1 - Decimal to Binary:\n");
	result = ft_convert_base("42", "0123456789", "01");
	if (result)
	{
		printf("42 (decimal) = %s (binary)\n", result);
		free(result);
	}
	
	/* Test 2: Binary to Decimal */
	printf("\nTest 2 - Binary to Decimal:\n");
	result = ft_convert_base("101010", "01", "0123456789");
	if (result)
	{
		printf("101010 (binary) = %s (decimal)\n", result);
		free(result);
	}
	
	/* Test 3: Decimal to Hexadecimal */
	printf("\nTest 3 - Decimal to Hexadecimal:\n");
	result = ft_convert_base("255", "0123456789", "0123456789ABCDEF");
	if (result)
	{
		printf("255 (decimal) = %s (hex)\n", result);
		free(result);
	}
	
	/* Test 4: Hexadecimal to Binary */
	printf("\nTest 4 - Hexadecimal to Binary:\n");
	result = ft_convert_base("FF", "0123456789ABCDEF", "01");
	if (result)
	{
		printf("FF (hex) = %s (binary)\n", result);
		free(result);
	}
	
	/* Test 5: Negative number */
	printf("\nTest 5 - Negative decimal to binary:\n");
	result = ft_convert_base("-42", "0123456789", "01");
	if (result)
	{
		printf("-42 (decimal) = %s (binary)\n", result);
		free(result);
	}
	
	return (0);				/* Return success */
}