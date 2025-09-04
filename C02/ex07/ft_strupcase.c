/*
 ******************************************************
 Create a function that converts every letter to uppercase.
 char *ft_strupcase(char *str);
 It should return str.
 ******************************************************
 * to compile it : gcc ft_strupcase.c
 * to run it : ./a.out
 ******************************************************
 */

#include <unistd.h>

/**********************
 * ft_strupcase - Converts every lowercase letter in string to uppercase
 * 
 * Description:
 * This function modifies the given string by converting all lowercase
 * alphabetical characters (a-z) to their uppercase equivalents (A-Z).
 * Non-alphabetical characters remain unchanged. The function modifies
 * the original string in place and returns a pointer to it.
 * 
 * Algorithm:
 * 1. Initialize index counter to 0
 * 2. Iterate through each character in the string
 * 3. For each character, check if it's a lowercase letter (a-z)
 * 4. If lowercase, convert to uppercase by subtracting 32 from ASCII value
 * 5. Continue until null terminator is reached
 * 6. Return pointer to the modified string
 * 
 * Parameters:
 * @str: Pointer to null-terminated string to be modified
 * 
 * Return:
 * char* - Pointer to the modified string (same as input parameter)
 * 
 * Examples:
 * ft_strupcase("hello") modifies string to "HELLO" and returns pointer
 * ft_strupcase("Hello123!") modifies string to "HELLO123!" and returns pointer
 **********************/
char *ft_strupcase(char *str)
{
	int i;							/* Index counter for iterating through string */
	
	i = 0;							/* Initialize index to start from first character */
	while (str[i] != '\0')			/* Continue until null terminator is reached */
	{
		if (str[i] >= 'a' && str[i] <= 'z')	/* Check if character is lowercase */
		{
			str[i] = str[i] - 32;	/* Convert to uppercase by subtracting 32 */
		}
		i++;						/* Move to next character */
	}
	return (str);					/* Return pointer to modified string */
}

/**********************
 * ft_putstr - Writes a string to standard output
 * 
 * Description:
 * This function outputs a null-terminated string to standard output
 * using the write system call. It calculates the string length by
 * iterating through characters until the null terminator is found.
 * 
 * Algorithm:
 * 1. Initialize length counter to 0
 * 2. Iterate through string until null terminator is found
 * 3. Count each character to determine total string length
 * 4. Use write system call to output the entire string at once
 * 
 * Parameters:
 * @str: Pointer to null-terminated string to be written
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_putstr("Hello") outputs "Hello"
 * ft_putstr("World\n") outputs "World" followed by newline
 **********************/
void	ft_putstr(char *str)
{
	int len = 0;					/* Length counter for string measurement */
	
	while (str[len])				/* Count characters until null terminator */
		len++;					/* Increment length for each character */
	write(1, str, len);			/* Write entire string to standard output */
}

/**********************
 * main - Entry point for string uppercase conversion demonstration
 * 
 * Description:
 * This program demonstrates the ft_strupcase function by testing it
 * with various strings containing lowercase letters, mixed case,
 * and non-alphabetical characters. It shows the original and
 * converted strings to verify the function works correctly.
 * 
 * Algorithm:
 * 1. Create test strings with different character combinations
 * 2. Display original string content
 * 3. Apply ft_strupcase conversion
 * 4. Display converted string result
 * 5. Test multiple scenarios to show function behavior
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_strupcase shows various string conversion demonstrations
 **********************/
int main(void)
{
	char test1[] = "hello world!";					/* Test string with lowercase letters */
	char test2[] = "Hello World 123!";				/* Test string with mixed case */
	char test3[] = "ALREADY UPPERCASE";				/* Test string already uppercase */
	char test4[] = "123!@# symbols";				/* Test string with numbers and symbols */
	
	ft_putstr("Testing ft_strupcase function:\n\n");	/* Display program header */
	
	/* Test case 1: All lowercase letters */
	ft_putstr("Test 1 - Original: \"");				/* Display test header */
	ft_putstr("hello world!");						/* Display original string */
	ft_putstr("\"\n");								/* Close quote and newline */
	ft_strupcase(test1);							/* Convert to uppercase */
	ft_putstr("Test 1 - Uppercase: \"");				/* Display result header */
	ft_putstr(test1);								/* Display converted string */
	ft_putstr("\"\n\n");							/* Close quote and spacing */
	
	/* Test case 2: Mixed case letters */
	ft_putstr("Test 2 - Original: \"");				/* Display test header */
	ft_putstr("Hello World 123!");					/* Display original string */
	ft_putstr("\"\n");								/* Close quote and newline */
	ft_strupcase(test2);							/* Convert to uppercase */
	ft_putstr("Test 2 - Uppercase: \"");				/* Display result header */
	ft_putstr(test2);								/* Display converted string */
	ft_putstr("\"\n\n");							/* Close quote and spacing */
	
	/* Test case 3: Already uppercase */
	ft_putstr("Test 3 - Original: \"");				/* Display test header */
	ft_putstr("ALREADY UPPERCASE");					/* Display original string */
	ft_putstr("\"\n");								/* Close quote and newline */
	ft_strupcase(test3);							/* Convert to uppercase */
	ft_putstr("Test 3 - Uppercase: \"");				/* Display result header */
	ft_putstr(test3);								/* Display converted string */
	ft_putstr("\"\n\n");							/* Close quote and spacing */
	
	/* Test case 4: Numbers and symbols */
	ft_putstr("Test 4 - Original: \"");				/* Display test header */
	ft_putstr("123!@# symbols");					/* Display original string */
	ft_putstr("\"\n");								/* Close quote and newline */
	ft_strupcase(test4);							/* Convert to uppercase */
	ft_putstr("Test 4 - Uppercase: \"");				/* Display result header */
	ft_putstr(test4);								/* Display converted string */
	ft_putstr("\"\n");								/* Close quote and newline */
	
	return (0);									/* Return success status */
}