/*
 ******************************************************
 • Write a function that converts the initial portion of the string pointed to by str into an integer representation.
 • str is in a specific base, given as a second parameter.
 • Except for the base rule, the function should behave exactly like ft_atoi.
 • If an invalid argument is provided, the function should return 0.
 Examples of invalid arguments:
 ◦ 0123456789ABCDEF is a hexadecimal base system.
 ◦ poneyvif is an octal base system.
 • The function must handle negative numbers.
 • If an invalid argument is provided, nothing should be displayed.
 Examples of invalid arguments:
 ◦ The base is empty or has only one character.
 ◦ The base contains duplicate characters.
 ◦ The base contains '+', '-', or whitespace characters.
 • The function should be prototyped as follows:
 int ft_atoi_base(char *str, char *base);
 ******************************************************
 * to compile it : gcc ft_atoi_base.c
 * to run it : /a.out
 ******************************************************
 */

#include <unistd.h>

/**********************
 * ft_strlen - Calculates and returns the length of a string
 * 
 * Description:
 * This function counts the number of characters in a null-terminated
 * string by iterating through each character until it encounters
 * the null terminator ('\0'). It returns the total count as an integer.
 * The function handles empty strings and normal strings correctly.
 * 
 * Algorithm:
 * 1. Initialize a counter variable to 0
 * 2. Iterate through the string character by character
 * 3. Increment counter for each non-null character
 * 4. Stop when null terminator is encountered
 * 5. Return the final count
 * 
 * Parameters:
 * @str: Pointer to the null-terminated string to measure
 * 
 * Return:
 * int - The number of characters in the string (excluding null terminator)
 * 
 * Examples:
 * ft_strlen("Hello") returns 5
 * ft_strlen("") returns 0
 * ft_strlen("42") returns 2
 **********************/
int	ft_strlen(char *str)
{
	int len;					/* Counter variable to track string length */
	
	len = 0;					/* Initialize length counter to zero */
	while (str[len] != '\0')	/* Loop until null terminator is found */
	{
		len++;					/* Increment counter for each character */
	}
	return (len);				/* Return the total character count */
}

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
 * check_base - Validates if a base string is valid for number conversion
 * 
 * Description:
 * This function checks if a given base string meets all requirements
 * for a valid number base system. It verifies the base has at least 2
 * characters, contains no duplicate characters, and excludes forbidden
 * characters like '+', '-', and whitespace which could interfere with parsing.
 * 
 * Algorithm:
 * 1. Check if base length is at least 2 characters
 * 2. Iterate through each character in the base string
 * 3. Check if current character is forbidden ('+', '-', whitespace)
 * 4. Check if current character appears later in the string (duplicate)
 * 5. Return 0 if any validation fails, 1 if all checks pass
 * 
 * Parameters:
 * @base: Pointer to the base string to validate
 * 
 * Return:
 * int - 1 if base is valid, 0 if base is invalid
 * 
 * Examples:
 * check_base("01") returns 1 (valid binary)
 * check_base("0123456789ABCDEF") returns 1 (valid hex)
 * check_base("0") returns 0 (too short)
 * check_base("01+") returns 0 (contains '+')
 * check_base("01 ") returns 0 (contains whitespace)
 **********************/
int	check_base(char *base)
{
	int i;						/* Index for main iteration */
	int j;						/* Index for duplicate checking */
	int base_len;				/* Length of the base string */
	
	base_len = ft_strlen(base);	/* Get base string length */
	if (base_len < 2)			/* Base must have at least 2 characters */
		return (0);				/* Invalid: too short */
	
	i = 0;						/* Initialize main loop index */
	while (base[i] != '\0')		/* Check each character in base */
	{
		/* Check for forbidden characters: signs and whitespace */
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ' ||
			base[i] == '\t' || base[i] == '\n' || base[i] == '\r' ||
			base[i] == '\v' || base[i] == '\f')
			return (0);			/* Invalid: contains forbidden characters */
		
		j = i + 1;				/* Initialize duplicate check index */
		while (base[j] != '\0')	/* Check for duplicates after current position */
		{
			if (base[i] == base[j])	/* Found duplicate character */
				return (0);		/* Invalid: duplicate characters */
			j++;				/* Move to next character */
		}
		i++;					/* Move to next character */
	}
	return (1);					/* Valid: all checks passed */
}

/**********************
 * get_digit_value - Finds the value of a character in the given base
 * 
 * Description:
 * This function searches for a character in the base string and returns
 * its position (value) within that base system. If the character is not
 * found in the base string, it returns -1 to indicate it's not a valid
 * digit for this base system.
 * 
 * Algorithm:
 * 1. Initialize index counter to 0
 * 2. Iterate through each character in the base string
 * 3. Compare current base character with the target character
 * 4. If match found, return current index (digit value)
 * 5. If no match found after checking all characters, return -1
 * 
 * Parameters:
 * @c: The character to find in the base system
 * @base: String representing the base system characters
 * 
 * Return:
 * int - The value (position) of the character in base, or -1 if not found
 * 
 * Examples:
 * get_digit_value('5', "0123456789") returns 5
 * get_digit_value('F', "0123456789ABCDEF") returns 15
 * get_digit_value('z', "0123456789") returns -1 (not in base)
 **********************/
int	get_digit_value(char c, char *base)
{
	int i;						/* Index for searching through base string */
	
	i = 0;						/* Initialize search index */
	while (base[i] != '\0')		/* Search through all base characters */
	{
		if (base[i] == c)		/* Found matching character */
			return (i);			/* Return its position (digit value) */
		i++;					/* Move to next character */
	}
	return (-1);				/* Character not found in base */
}

/**********************
 * ft_atoi_base - Converts string to integer in specified base system
 * 
 * Description:
 * This function behaves like ft_atoi but works with any valid base system.
 * It validates the base first, then parses the string following atoi rules:
 * skip whitespace, handle signs, convert valid digits until non-digit found.
 * The conversion uses the specified base instead of decimal (base 10).
 * 
 * Algorithm:
 * 1. Validate base using check_base function
 * 2. Skip leading whitespace characters
 * 3. Process sign characters to determine final sign
 * 4. Convert consecutive valid base digits to integer
 * 5. Stop at first invalid character and return result
 * 6. Apply final sign based on processed signs
 * 
 * Parameters:
 * @str: Pointer to null-terminated string to convert
 * @base: String representing the base system characters
 * 
 * Return:
 * int - The integer representation in base 10, or 0 if invalid base
 * 
 * Examples:
 * ft_atoi_base("FF", "0123456789ABCDEF") returns 255 (hex to decimal)
 * ft_atoi_base("101", "01") returns 5 (binary to decimal)
 * ft_atoi_base("  -nv", "poneyvif") returns -62 (custom base to decimal)
 **********************/
int	ft_atoi_base(char *str, char *base)
{
	int i;						/* Index for string iteration */
	int sign;					/* Sign multiplier (1 positive, -1 negative) */
	int result;					/* Accumulated result value */
	int digit_value;			/* Value of current digit in base system */
	int base_len;				/* Length of base string */
	
	if (!check_base(base))		/* Validate base before processing */
		return (0);				/* Return 0 if base is invalid */
	
	i = 0;						/* Initialize string index */
	sign = 1;					/* Initialize sign as positive */
	result = 0;					/* Initialize result accumulator */
	base_len = ft_strlen(base);	/* Get base system length */
	
	/* Skip leading whitespace characters */
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
		   str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
	{
		i++;					/* Skip whitespace */
	}
	
	/* Process sign characters */
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')		/* Count minus signs for final sign */
			sign = -sign;		/* Flip sign for each minus */
		i++;					/* Move to next character */
	}
	
	/* Convert digits in the specified base */
	while (str[i] != '\0')
	{
		digit_value = get_digit_value(str[i], base);	/* Get digit value in base */
		if (digit_value == -1)	/* Character not valid in this base */
			break;				/* Stop conversion */
		result = result * base_len + digit_value;		/* Add digit to result */
		i++;					/* Move to next character */
	}
	
	return (result * sign);		/* Return result with appropriate sign */
}

/**********************
 * main - Entry point for base conversion demonstration program
 * 
 * Description:
 * This program demonstrates the ft_atoi_base function by testing it
 * with various strings and base systems. It shows conversions from
 * binary, octal, decimal, hexadecimal, and custom bases to decimal
 * integers. Each test displays the input string, base system, and
 * resulting decimal value.
 * 
 * Algorithm:
 * 1. Create test strings in different base representations
 * 2. Create various base system strings
 * 3. Call ft_atoi_base for each combination
 * 4. Display input string, base, and converted decimal result
 * 5. Test edge cases like negative numbers and invalid bases
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_atoi_base outputs various string-to-integer conversions in different bases
 **********************/
int main(void)
{
	char *binary_str = "1010";			/* Binary representation of 10 */
	char *hex_str = "FF";				/* Hexadecimal representation of 255 */
	char *hex_neg = " -1A";				/* Negative hex with whitespace */
	char *custom_str = "  -nv";		/* Custom base representation */
	char *decimal_str = "123";			/* Decimal string */
	
	write(1, "Testing ft_atoi_base:\n", 22);	/* Program header */
	
	write(1, "\"1010\" in binary -> ", 20);	/* Binary conversion test */
	ft_putnbr(ft_atoi_base(binary_str, "01"));
	write(1, "\n", 1);
	
	write(1, "\"FF\" in hex -> ", 15);			/* Hexadecimal test */
	ft_putnbr(ft_atoi_base(hex_str, "0123456789ABCDEF"));
	write(1, "\n", 1);
	
	write(1, "\" -1A\" in hex -> ", 17);		/* Negative hex test */
	ft_putnbr(ft_atoi_base(hex_neg, "0123456789ABCDEF"));
	write(1, "\n", 1);
	
	write(1, "\"  -nv\" in custom base -> ", 27);	/* Custom base test */
	ft_putnbr(ft_atoi_base(custom_str, "poneyvif"));
	write(1, "\n", 1);
	
	write(1, "\"123\" in decimal -> ", 20);	/* Decimal test */
	ft_putnbr(ft_atoi_base(decimal_str, "0123456789"));
	write(1, "\n", 1);
	
	write(1, "Invalid base test -> ", 21);		/* Invalid base test */
	ft_putnbr(ft_atoi_base("123", "0"));		/* Should return 0 */
	write(1, "\n", 1);
	
	write(1, "Duplicate base test -> ", 23);		/* Duplicate base test */
	ft_putnbr(ft_atoi_base("123", "0123456700"));	/* Should return 0 */
	write(1, "\n", 1);
	
	return (0);					/* Return success status to the operating system */
}