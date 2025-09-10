//******************************************************
// Assignment name  : rot_13
// Expected files   : rot_13.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays it, replacing each of its
// letters by the letter 13 spaces ahead in alphabetical order.

// 'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

// The output will be followed by a newline.

// If the number of arguments is not 1, the program displays a newline.

// Example:

// $>./rot_13 "abc"
// nop
// $>./rot_13 "My horse is Amazing." | cat -e
// Zl ubefr vf Nznmvat.$
// $>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
// NxwuM mYXVWm , 23l $
// $>./rot_13 | cat -e
// $
// $>
// $>./rot_13 "" | cat -e
// $
// $>

//******************************************************
// to compile it : gcc -Wall -Wextra -Werror rot_13.c -o rot_13
// to run it : ./rot_13 "abc"
// to run it : ./rot_13 "My horse is Amazing." | cat -e
// to run it : ./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
// to run it : ./rot_13 | cat -e
// to run it : ./rot_13 "" | cat -e
//******************************************************

#include <unistd.h>

/**********************
 * ft_rot_13 - Applies ROT13 cipher to a string and prints it
 * 
 * Description:
 * This function processes each character of a string and applies
 * the ROT13 cipher transformation. ROT13 shifts each alphabetic
 * character by 13 positions in the alphabet. Non-alphabetic
 * characters remain unchanged. The case of letters is preserved.
 * 
 * Algorithm:
 * 1. Iterate through each character in the string
 * 2. For lowercase letters (a-z): shift by 13, wrap around using modulo
 * 3. For uppercase letters (A-Z): shift by 13, wrap around using modulo
 * 4. For non-alphabetic characters: output unchanged
 * 5. Write each transformed character to stdout
 * 
 * Parameters:
 * @str: The input string to transform with ROT13 cipher
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_rot_13("hello") outputs "uryyb"
 * ft_rot_13("HELLO") outputs "URYYB"
 * ft_rot_13("abc123") outputs "nop123"
 **********************/
void	ft_rot_13(char *str)
{
	int i = 0;							/* Index to traverse the string */
	char c;								/* Current character being processed */
	
	while (str[i])						/* Process each character until null terminator */
	{
		c = str[i];						/* Get current character */
		
		if (c >= 'a' && c <= 'z')		/* Check if lowercase letter */
		{
			c = ((c - 'a' + 13) % 26) + 'a';	/* Apply ROT13 to lowercase */
			write(1, &c, 1);			/* Write transformed character */
		}
		else if (c >= 'A' && c <= 'Z')	/* Check if uppercase letter */
		{
			c = ((c - 'A' + 13) % 26) + 'A';	/* Apply ROT13 to uppercase */
			write(1, &c, 1);			/* Write transformed character */
		}
		else							/* Non-alphabetic character */
		{
			write(1, &c, 1);			/* Write character unchanged */
		}
		i++;							/* Move to next character */
	}
}

/**********************
 * main - Entry point for ROT13 cipher program
 * 
 * Description:
 * This program takes a string as command line argument and
 * displays it transformed using the ROT13 cipher. If incorrect
 * number of arguments provided, it only prints a newline.
 * 
 * Usage:
 * ./rot_13 "string to encode"
 * 
 * Parameters:
 * @argc: Number of command line arguments
 * @argv: Array of command line argument strings
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./rot_13 "Hello World!" -> outputs "Uryyb Jbeyq!\n"
 * ./rot_13 "abc123" -> outputs "nop123\n"
 **********************/
int main(int argc, char **argv)
{
	if (argc == 2)						/* Check if exactly one argument provided */
		ft_rot_13(argv[1]);				/* Call function to apply ROT13 cipher */
	write(1, "\n", 1);					/* Always write a newline at the end */
	return (0);							/* Return success */
}