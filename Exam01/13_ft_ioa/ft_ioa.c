//******************************************************
// Assignment name  : ft_itoa
// Expected files   : ft_itoa.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes an int and converts it to a null-terminated string.
// The function returns the result in a char array that you must allocate.

// Your function must be declared as follows:

// char	*ft_itoa(int nbr);

//******************************************************
// to compile it : gcc -Wall -Wextra -Werror ft_itoa.c -o ft_itoa
// to run it : ./ft_itoa 42
// to run it : ./ft_itoa -42
// to run it : ./ft_itoa 0
// to run it : ./ft_itoa 2147483647
// to run it : ./ft_itoa -2147483648
//******************************************************

#include <stdlib.h>
#include <unistd.h>

/**********************
 * ft_itoa - Integer to ASCII string conversion
 * 
 * Description:
 * Converts an integer to its string representation by calculating
 * the required string length, allocating memory, and filling the
 * string with digits from right to left. Handles negative numbers,
 * zero, and the special case of INT_MIN which cannot be negated.
 * 
 * Algorithm:
 * 1. Handle INT_MIN special case (return string literal)
 * 2. Calculate string length by counting digits and sign
 * 3. Allocate memory for string plus null terminator
 * 4. Handle zero as special case
 * 5. If negative, set minus sign and make number positive
 * 6. Fill string with digits from right to left
 * 7. Return allocated string
 * 
 * Parameters:
 * @nbr: Integer to convert to string
 * 
 * Return:
 * Pointer to newly allocated string containing the integer representation,
 * or NULL if malloc fails
 * 
 * Example:
 * ft_itoa(42) -> "42"
 * ft_itoa(-123) -> "-123"
 * ft_itoa(0) -> "0"
 **********************/
char *ft_itoa(int nbr)
{
	char *str;						// Pointer to hold the resulting string
	int n = nbr;					// Copy of nbr for length calculation
	int len = 0;					// Length of the resulting string
	
	if (nbr == -2147483648)			// Handle INT_MIN edge case
		return ("-2147483648");		// Return string literal for INT_MIN
	
	if (nbr <= 0)					// If number is negative or zero
		len++;							// Add space for minus sign or single '0'
	while (n)						// Count digits in the number
	{
		n /= 10;						// Remove last digit
		len++;						// Increment length counter
	}
	
	str = malloc(sizeof(char) * (len + 1));	// Allocate memory for string plus null terminator
	if (!str)						// Check if malloc failed
		return (NULL);				// Return NULL if allocation failed
	
	str[len] = '\0';				// Set null terminator at end of string
	
	if (nbr == 0)					// Special case for zero
	{
		str[0] = '0';					// Set first character to '0'
		return (str);					// Return the string "0"
	}
	
	if (nbr < 0)					// If number is negative
	{
		str[0] = '-';					// Set first character to minus sign
		nbr = -nbr;						// Make number positive for digit extraction
	}
	
	while (nbr)						// Fill string with digits from right to left
	{
		len--;							// Move backwards in string
		str[len] = nbr % 10 + '0';		// Convert last digit to character and store
		nbr /= 10;						// Remove last digit from number
	}
	
	return (str);					// Return pointer to the allocated string
}

/**********************
 * ft_putstr - Prints a string to standard output
 * 
 * Description:
 * Outputs a null-terminated string character by character using
 * the write system call. Continues until the null terminator
 * is encountered.
 * 
 * Algorithm:
 * 1. Initialize index to 0
 * 2. While current character is not null:
 *    - Write current character to stdout
 *    - Increment index
 * 
 * Parameters:
 * @str: Null-terminated string to print
 * 
 * Return:
 * None (void function)
 * 
 * Example:
 * ft_putstr("Hello") -> prints "Hello"
 **********************/
void ft_putstr(char *str)
{
	int i = 0;						// Initialize index for string iteration
	while (str[i])					// Iterate through string until null terminator
	{
		write(1, &str[i], 1);			// Write current character to stdout
		i++;							// Move to next character
	}
}

/**********************
 * main - Test function for ft_itoa implementation
 * 
 * Description:
 * Demonstrates the ft_itoa function with various test cases
 * including positive numbers, negative numbers, zero, and edge
 * cases like INT_MAX and INT_MIN. Properly frees allocated
 * memory except for the INT_MIN case which returns a string literal.
 * 
 * Algorithm:
 * 1. Test positive number (42)
 * 2. Test negative number (-42)
 * 3. Test zero (0)
 * 4. Test INT_MAX (2147483647)
 * 5. Test INT_MIN (-2147483648)
 * 6. For each test: convert, print, and free (except INT_MIN)
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Example:
 * Output:
 * 42: 42
 * -42: -42
 * 0: 0
 * 2147483647: 2147483647
 * -2147483648: -2147483648
 **********************/
int main(void)
{
	char *str;						// Pointer to hold string returned by ft_itoa
	
	write(1, "Testing ft_itoa:\n", 17);	// Print test header
	
	str = ft_itoa(42);				// Convert 42 to string
	write(1, "42: ", 4);				// Print test label
	ft_putstr(str);					// Print the converted string
	write(1, "\n", 1);				// Print newline
	free(str);						// Free allocated memory
	
	str = ft_itoa(-42);				// Convert -42 to string
	write(1, "-42: ", 5);				// Print test label
	ft_putstr(str);					// Print the converted string
	write(1, "\n", 1);				// Print newline
	free(str);						// Free allocated memory
	
	str = ft_itoa(0);				// Convert 0 to string
	write(1, "0: ", 3);				// Print test label
	ft_putstr(str);					// Print the converted string
	write(1, "\n", 1);				// Print newline
	free(str);						// Free allocated memory
	
	str = ft_itoa(2147483647);			// Convert INT_MAX to string
	write(1, "2147483647: ", 12);		// Print test label
	ft_putstr(str);					// Print the converted string
	write(1, "\n", 1);				// Print newline
	free(str);						// Free allocated memory
	
	str = ft_itoa(-2147483648);			// Convert INT_MIN to string (returns string literal)
	write(1, "-2147483648: ", 13);		// Print test label
	ft_putstr(str);					// Print the converted string (no free needed for literal)
	write(1, "\n", 1);				// Print newline
	
	return (0);						// Return 0 to indicate successful execution
}