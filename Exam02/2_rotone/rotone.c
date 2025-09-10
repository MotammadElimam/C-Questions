//******************************************************
// Assignment name  : rotone
// Expected files   : rotone.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays it, replacing each of its
// letters by the next one in alphabetical order.

// 'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

// The output will be followed by a \n.

// If the number of arguments is not 1, the program displays \n.

// Example:

// $>./rotone "abc"
// bcd
// $>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
// Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
// $>./rotone "AkjhZ zLKIJz , 23y " | cat -e
// BlkiA aMLJKa , 23z $
// $>./rotone | cat -e
// $
// $>
// $>./rotone "" | cat -e
// $
// $>

//******************************************************
// to compile it : gcc -Wall -Wextra -Werror rotone.c -o rotone
// to run it : ./rotone "abc"
// to run it : ./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
// to run it : ./rotone "AkjhZ zLKIJz , 23y " | cat -e
// to run it : ./rotone | cat -e
// to run it : ./rotone "" | cat -e
//******************************************************

#include <unistd.h>

/**********************
 * ft_rotone - Applies ROT1 cipher to a string and prints it
 * 
 * Description:
 * This function processes each character of a string and applies
 * the ROT1 cipher transformation. ROT1 shifts each alphabetic
 * character by 1 position in the alphabet. Non-alphabetic
 * characters remain unchanged. The case of letters is preserved.
 * Special handling for 'z' and 'Z' which wrap to 'a' and 'A'.
 * 
 * Algorithm:
 * 1. Iterate through each character in the string
 * 2. For lowercase 'z': change to 'a'
 * 3. For uppercase 'Z': change to 'A'
 * 4. For other lowercase letters: shift by 1
 * 5. For other uppercase letters: shift by 1
 * 6. For non-alphabetic characters: output unchanged
 * 7. Write each transformed character to stdout
 * 
 * Parameters:
 * @str: The input string to transform with ROT1 cipher
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_rotone("abc") outputs "bcd"
 * ft_rotone("xyz") outputs "yza"
 * ft_rotone("ABC") outputs "BCD"
 * ft_rotone("XYZ") outputs "YZA"
 **********************/
void	ft_rotone(char *str)
{
	int i = 0;							/* Index to traverse the string */
	char c;								/* Current character being processed */
	
	while (str[i])						/* Process each character until null terminator */
	{
		c = str[i];						/* Get current character */
		
		if (c == 'z')					/* Special case: lowercase 'z' */
		{
			c = 'a';					/* Wrap around to 'a' */
			write(1, &c, 1);			/* Write transformed character */
		}
		else if (c == 'Z')				/* Special case: uppercase 'Z' */
		{
			c = 'A';					/* Wrap around to 'A' */
			write(1, &c, 1);			/* Write transformed character */
		}
		else if (c >= 'a' && c <= 'y')	/* Check if lowercase letter (not z) */
		{
			c = c + 1;					/* Shift by 1 position */
			write(1, &c, 1);			/* Write transformed character */
		}
		else if (c >= 'A' && c <= 'Y')	/* Check if uppercase letter (not Z) */
		{
			c = c + 1;					/* Shift by 1 position */
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
 * main - Entry point for ROT1 cipher program
 * 
 * Description:
 * This program takes a string as command line argument and
 * displays it transformed using the ROT1 cipher (each letter
 * shifted by one position in the alphabet). If incorrect
 * number of arguments provided, it only prints a newline.
 * 
 * Usage:
 * ./rotone "string to encode"
 * 
 * Parameters:
 * @argc: Number of command line arguments
 * @argv: Array of command line argument strings
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./rotone "Hello World!" -> outputs "Ifmmp Xpsme!\n"
 * ./rotone "xyz" -> outputs "yza\n"
 **********************/
int main(int argc, char **argv)
{
	if (argc == 2)						/* Check if exactly one argument provided */
		ft_rotone(argv[1]);				/* Call function to apply ROT1 cipher */
	write(1, "\n", 1);					/* Always write a newline at the end */
	return (0);							/* Return success */
}