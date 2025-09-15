/*
 ******************************************************
 • Since this is a program, your .c file must contain a main function.
 • Write a program that displays its given arguments.
 • Eachargumentshouldbeprintedonanewline,inthesameorderasinthecommand line.
 • The program should display all arguments except argv[0].
 • Example:
 $>./a.out test1 test2 test3 | cat -e
 test1$
 test2$
 test3$
 $>
 ******************************************************
 * to compile it : gcc ft_print_params.c
 * to run it : ./a.out
 ******************************************************
 */

#include <unistd.h>

/**********************
 * ft_putstr - Displays a string to standard output
 * 
 * Description:
 * This function outputs a null-terminated string to the standard
 * output by writing each character directly. It iterates
 * through the string until it reaches the null terminator.
 * 
 * Algorithm:
 * 1. Initialize index counter to 0
 * 2. Loop while current character is not null terminator
 * 3. Write each character directly using write system call
 * 4. Increment index to move to next character
 * 5. Stop when null terminator is reached
 * 
 * Parameters:
 * @str: Pointer to the null-terminated string to display
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_putstr("test1") outputs "test1"
 * ft_putstr("hello") outputs "hello"
 * ft_putstr("") outputs nothing (empty string)
 **********************/
void	ft_putstr(char *str)
{
	int	i;						/* Index for string traversal */

	i = 0;						/* Initialize index to start of string */
	while (str[i] != '\0')		/* Continue until null terminator */
	{
		write(1, &str[i], 1);	/* Write current character to stdout */
		i++;					/* Move to next character */
	}
}

/**********************
 * main - Entry point for parameter display program
 * 
 * Description:
 * This program displays all command-line arguments passed to it,
 * excluding the program name (argv[0]). Each argument is printed
 * on a separate line. This demonstrates how to access and process
 * command-line arguments in C programs.
 * 
 * Algorithm:
 * 1. Initialize counter to 1 (skip argv[0])
 * 2. Loop through all arguments from argv[1] to argv[argc-1]
 * 3. For each argument, call ft_putstr to display it
 * 4. Add a newline after each argument
 * 5. Continue until all arguments are processed
 * 6. Return 0 to indicate successful execution
 * 
 * Parameters:
 * @argc: Number of command-line arguments including program name
 * @argv: Array of strings containing the arguments
 *        argv[0] is the program name (skipped)
 *        argv[1] through argv[argc-1] are the actual arguments
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./a.out test1 test2 outputs "test1\ntest2\n"
 * ./a.out hello world foo outputs "hello\nworld\nfoo\n"
 * ./a.out outputs nothing (no arguments to display)
 **********************/
int	main(int argc, char **argv)
{
	int	i = 1;						/* Counter for iterating through arguments */						/* Start from argv[1], skipping program name */
	while (i < argc)			/* Loop through all remaining arguments */
	{
		ft_putstr(argv[i]);		/* Display current argument */
		write(1, "\n", 1);		/* Add newline after each argument */
		i++;					/* Move to next argument */
	}
	return (0);					/* Return success status */
}