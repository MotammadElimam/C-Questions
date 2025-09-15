/*
 ******************************************************
 // • Since this is a program, your .c file must contain a main function.
 // • Write a program that displays its own name, followed by a new line.
 // • Example:
 // $>./a.out | cat -e
 // ./a.out$
 ******************************************************
 * to compile it : gcc ft_print_program_name.c
 * to run it : ./a.out
 ******************************************************
 */

#include <unistd.h>

/**********************
 * main - Entry point for program name display
 * 
 * Description:
 * This program displays its own name (as invoked) followed by a
 * newline character. The program name is accessed through argv[0],
 * which contains the path used to execute the program.
 * 
 * Algorithm:
 * 1. Initialize index to 0
 * 2. Loop through argv[0] character by character
 * 3. Write each character to stdout using write()
 * 4. After printing the name, write a newline character
 * 5. Return 0 to indicate successful execution
 * 
 * Parameters:
 * @argc: Number of command-line arguments (used to ensure argv exists)
 * @argv: Array of strings containing the arguments
 *        argv[0] is always the program name
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./a.out outputs "./a.out\n"
 * ./ft_print_program_name outputs "./ft_print_program_name\n"
 * /usr/bin/prog outputs "/usr/bin/prog\n"
 **********************/
int	main(int argc, char **argv)
{
	int	i = 0;					/* Index for string traversal */

	while (argv[0][i] != '\0' && argc)		/* Loop through each character of program name */
	{
		write(1, &argv[0][i], 1);		/* Write current character to stdout */
		i++;					/* Move to next character */
	}
	write(1, "\n", 1);				/* Write newline after program name */
	return (0);					/* Return success status */
}