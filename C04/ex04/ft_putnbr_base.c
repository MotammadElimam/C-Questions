/*
 ******************************************************
 • Create a function that displays a number in a given base system in the terminal.
 • The number is provided as an int, and the base is represented as a string of characters.
 • The base system consists of all the symbols used to represent the number.
 ◦ 0123456789 is the commonly used base system for representing decimal numbers.
 ◦ 01 is a binary base system.
 ◦ 0123456789ABCDEF is a hexadecimal base system.
 ◦ poneyvif is an octal base system.
 • The function must handle negative numbers.
 • If an invalid argument is provided, nothing should be displayed.
 Examples of invalid arguments:
 ◦ The base is empty or has only one character.
 ◦ The base contains duplicate characters.
 ◦ The base contains '+' or '-'.
 The function should be prototyped as follows:
 void ft_putnbr_base(int nbr, char *base);
 ******************************************************
 * to compile it : gcc -Wall -Wextra -Werror ft_putnbr_base.c -o ft_putnbr_base
 * to run it : /a.out " ---+--+1234ab567"
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
 * check_base - Validates if a base string is valid for number conversion
 * 
 * Description:
 * This function checks if a given base string meets all the requirements
 * for a valid number base system. It verifies the base has at least 2
 * characters, contains no duplicate characters, and excludes forbidden
 * characters like '+' and '-' signs which are reserved for number signs.
 * 
 * Algorithm:
 * 1. Check if base length is at least 2 characters
 * 2. Iterate through each character in the base string
 * 3. Check if current character is '+' or '-' (invalid)
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
		if (base[i] == '+' || base[i] == '-')	/* Check for forbidden characters */
			return (0);			/* Invalid: contains sign characters */
		
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
 * ft_putnbr_base - Displays a number in the specified base system
 * 
 * Description:
 * This function converts and displays an integer in any given base system.
 * It validates the base string first, then handles negative numbers by
 * printing a minus sign and converting to positive. The conversion uses
 * recursive division by the base length, printing digits from most to
 * least significant using the characters from the base string.
 * 
 * Algorithm:
 * 1. Validate the base string using check_base function
 * 2. Handle INT_MIN special case (cannot be negated safely)
 * 3. If number is negative, print '-' and make positive
 * 4. If number >= base_len, recursively print higher digits
 * 5. Print current digit using base[number % base_len]
 * 
 * Parameters:
 * @nbr: The integer number to display in the given base
 * @base: String representing the base system characters
 * 
 * Return:
 * void - No return value (output written directly or nothing if invalid base)
 * 
 * Examples:
 * ft_putnbr_base(42, "0123456789") outputs "42" (decimal)
 * ft_putnbr_base(42, "01") outputs "101010" (binary)
 * ft_putnbr_base(255, "0123456789ABCDEF") outputs "FF" (hexadecimal)
 **********************/
void	ft_putnbr_base(int nbr, char *base)
{
	int base_len;				/* Length of the base string */
	long long nb;				/* Long version to handle INT_MIN safely */
	
	if (!check_base(base))		/* Validate base before processing */
		return;					/* Exit if base is invalid */
	
	base_len = ft_strlen(base);	/* Get the base system length */
	nb = nbr;					/* Convert to long long for safe negation */
	
	if (nb < 0)					/* Handle negative numbers */
	{
		write(1, "-", 1);		/* Write minus sign */
		nb = -nb;				/* Make number positive */
	}
	
	if (nb >= base_len)			/* If number has multiple digits in this base */
		ft_putnbr_base(nb / base_len, base);	/* Recursively print higher digits */
	
	write(1, &base[nb % base_len], 1);	/* Write current digit using base character */
}

/**********************
 * main - Entry point for base conversion demonstration program
 * 
 * Description:
 * This program demonstrates the ft_putnbr_base function by testing it
 * with various numbers and different base systems. It shows conversions
 * to binary, octal, decimal, hexadecimal, and custom base systems.
 * Each test displays the number, base system, and resulting output.
 * 
 * Algorithm:
 * 1. Create test numbers and various base system strings
 * 2. Test each number with different base systems
 * 3. Display labels and call ft_putnbr_base for each test
 * 4. Test invalid base systems to verify error handling
 * 5. Show edge cases like negative numbers and zero
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_putnbr_base outputs various numbers in different base systems
 **********************/
int main(void)
{
	int test_num = 42;			/* Test number for conversions */
	int negative_num = -255;	/* Test negative number */
	int zero = 0;				/* Test zero value */
	
	write(1, "Testing ft_putnbr_base:\n", 24);	/* Program header */
	
	write(1, "42 in binary (01): ", 19);			/* Binary conversion test */
	ft_putnbr_base(test_num, "01");
	write(1, "\n", 1);
	
	write(1, "42 in octal (01234567): ", 24);		/* Octal conversion test */
	ft_putnbr_base(test_num, "01234567");
	write(1, "\n", 1);
	
	write(1, "42 in decimal (0123456789): ", 28);	/* Decimal conversion test */
	ft_putnbr_base(test_num, "0123456789");
	write(1, "\n", 1);
	
	write(1, "42 in hex (0123456789ABCDEF): ", 30);	/* Hexadecimal test */
	ft_putnbr_base(test_num, "0123456789ABCDEF");
	write(1, "\n", 1);
	
	write(1, "42 in custom (poneyvif): ", 25);		/* Custom base test */
	ft_putnbr_base(test_num, "poneyvif");
	write(1, "\n", 1);
	
	write(1, "-255 in hex: ", 13);					/* Negative number test */
	ft_putnbr_base(negative_num, "0123456789ABCDEF");
	write(1, "\n", 1);
	
	write(1, "0 in binary: ", 13);					/* Zero test */
	ft_putnbr_base(zero, "01");
	write(1, "\n", 1);
	
	write(1, "Invalid base test (nothing printed): ", 38);	/* Invalid base test */
	ft_putnbr_base(42, "0");							/* Should print nothing */
	write(1, "[end]\n", 6);
	
	write(1, "Duplicate base test (nothing printed): ", 39);	/* Duplicate test */
	ft_putnbr_base(42, "0123456700");					/* Should print nothing */
	write(1, "[end]\n", 6);
	
	return (0);					/* Return success status to the operating system */
}