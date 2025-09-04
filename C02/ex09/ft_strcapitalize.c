/*
 ******************************************************
 Create a function that capitalizes the first letter of each word and converts all other letters to lowercase.
 A word is a sequence of alphanumeric characters.
 Here is how it should be prototyped:
 char *ft_strcapitalize(char *str);
 It should return str.
 For example:
 hi, how are you? 42words forty-two; fifty+and+one
 Becomes:
 Hi, How Are You? 42words Forty-Two; Fifty+And+One
 ******************************************************
 * to compile it : gcc ft_strcapitalize.c
 * to run it : ./a.out
 ******************************************************
 */

#include <unistd.h>

/**********************
 * is_alphanumeric - Checks if character is alphanumeric
 * 
 * Description:
 * This helper function determines if a character is alphanumeric
 * (a letter or digit). It checks for lowercase letters (a-z),
 * uppercase letters (A-Z), and digits (0-9).
 * 
 * Algorithm:
 * 1. Check if character is between 'a' and 'z'
 * 2. Check if character is between 'A' and 'Z'
 * 3. Check if character is between '0' and '9'
 * 4. Return 1 if any condition is true, 0 otherwise
 * 
 * Parameters:
 * @c: Character to be checked
 * 
 * Return:
 * int - 1 if character is alphanumeric, 0 otherwise
 * 
 * Examples:
 * is_alphanumeric('a') returns 1
 * is_alphanumeric('5') returns 1
 * is_alphanumeric(' ') returns 0
 **********************/
int	is_alphanumeric(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}

/**********************
 * ft_strcapitalize - Capitalizes first letter of each word and lowercases others
 * 
 * Description:
 * This function modifies the given string by capitalizing the first letter
 * of each word and converting all other letters to lowercase. A word is
 * defined as a sequence of alphanumeric characters. Non-alphabetical
 * characters are left unchanged and serve as word separators.
 * 
 * Algorithm:
 * 1. Initialize index counter and word_start flag
 * 2. Iterate through each character in the string
 * 3. If character is alphanumeric:
 *    a. If it's the start of a word and lowercase, capitalize it
 *    b. If it's not the start of a word and uppercase, lowercase it
 *    c. Mark that we're no longer at word start
 * 4. If character is not alphanumeric, mark next alphanumeric as word start
 * 5. Return pointer to the modified string
 * 
 * Parameters:
 * @str: Pointer to null-terminated string to be modified
 * 
 * Return:
 * char* - Pointer to the modified string (same as input parameter)
 * 
 * Examples:
 * ft_strcapitalize("hello world") returns "Hello World"
 * ft_strcapitalize("42words forty-two") returns "42words Forty-Two"
 **********************/
char *ft_strcapitalize(char *str)
{
	int i;							/* Index counter for iterating through string */
	int word_start;					/* Flag to track if we're at the start of a word */
	
	i = 0;							/* Initialize index to start from first character */
	word_start = 1;					/* First character is considered start of word */
	while (str[i] != '\0')			/* Continue until null terminator is reached */
	{
		if (is_alphanumeric(str[i]))	/* Check if character is alphanumeric */
		{
			if (word_start)			/* If at the start of a word */
			{
				if (str[i] >= 'a' && str[i] <= 'z')	/* If lowercase letter */
					str[i] = str[i] - 32;	/* Convert to uppercase */
			}
			else					/* If not at start of word */
			{
				if (str[i] >= 'A' && str[i] <= 'Z')	/* If uppercase letter */
					str[i] = str[i] + 32;	/* Convert to lowercase */
			}
			word_start = 0;			/* No longer at start of word */
		}
		else						/* If character is not alphanumeric */
		{
			word_start = 1;			/* Next alphanumeric character starts new word */
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
 * main - Entry point for string capitalization demonstration
 * 
 * Description:
 * This program demonstrates the ft_strcapitalize function by testing it
 * with various strings containing different word patterns, mixed case,
 * numbers, and special characters. It shows the original and converted
 * strings to verify the function works correctly.
 * 
 * Algorithm:
 * 1. Create test strings with different character combinations
 * 2. Display original string content
 * 3. Apply ft_strcapitalize conversion
 * 4. Display converted string result
 * 5. Test multiple scenarios including the provided example
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_strcapitalize shows various string capitalization demonstrations
 **********************/
int main(void)
{
	char test1[] = "hi, how are you? 42words forty-two; fifty+and+one";	/* Example from problem */
	char test2[] = "hello world! this is a TEST.";						/* Mixed case test */
	char test3[] = "123abc DEF456 ghi-jkl";							/* Alphanumeric mix */
	char test4[] = "one+two=three four*five six/seven";				/* Mathematical operators */
	
	ft_putstr("Testing ft_strcapitalize function:\n\n");	/* Display program header */
	
	/* Test case 1: Example from problem statement */
	ft_putstr("Test 1 - Original:\n\"");					/* Display test header */
	ft_putstr("hi, how are you? 42words forty-two; fifty+and+one");	/* Display original */
	ft_putstr("\"\n");									/* Close quote and newline */
	ft_strcapitalize(test1);							/* Apply capitalization */
	ft_putstr("Test 1 - Capitalized:\n\"");				/* Display result header */
	ft_putstr(test1);									/* Display converted string */
	ft_putstr("\"\n\n");								/* Close quote and spacing */
	
	/* Test case 2: Mixed case with punctuation */
	ft_putstr("Test 2 - Original:\n\"");					/* Display test header */
	ft_putstr("hello world! this is a TEST.");			/* Display original string */
	ft_putstr("\"\n");									/* Close quote and newline */
	ft_strcapitalize(test2);							/* Apply capitalization */
	ft_putstr("Test 2 - Capitalized:\n\"");				/* Display result header */
	ft_putstr(test2);									/* Display converted string */
	ft_putstr("\"\n\n");								/* Close quote and spacing */
	
	/* Test case 3: Alphanumeric combinations */
	ft_putstr("Test 3 - Original:\n\"");					/* Display test header */
	ft_putstr("123abc DEF456 ghi-jkl");					/* Display original string */
	ft_putstr("\"\n");									/* Close quote and newline */
	ft_strcapitalize(test3);							/* Apply capitalization */
	ft_putstr("Test 3 - Capitalized:\n\"");				/* Display result header */
	ft_putstr(test3);									/* Display converted string */
	ft_putstr("\"\n\n");								/* Close quote and spacing */
	
	/* Test case 4: Mathematical operators as separators */
	ft_putstr("Test 4 - Original:\n\"");					/* Display test header */
	ft_putstr("one+two=three four*five six/seven");		/* Display original string */
	ft_putstr("\"\n");									/* Close quote and newline */
	ft_strcapitalize(test4);							/* Apply capitalization */
	ft_putstr("Test 4 - Capitalized:\n\"");				/* Display result header */
	ft_putstr(test4);									/* Display converted string */
	ft_putstr("\"\n");									/* Close quote and newline */
	
	return (0);										/* Return success status */
}