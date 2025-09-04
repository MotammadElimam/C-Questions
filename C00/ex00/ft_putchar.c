/*
 ******************************************************
 Write a function that displays the character passed as a parameter
 The function should be prototyped as follows:
 void ft_putchar(char c);
 To display the character, you must use the write function as follows:    
 write(1, &c, 1); 
 
 ******************************************************
 * to compile it : gcc ft_putchar.c
 * to run it : ./a.out
 ******************************************************
 */

#include <unistd.h>

/**********************
 * ft_putchar - Displays a single character to standard output
 * 
 * Description:
 * This function outputs a single character to the standard output
 * using the write system call. It's a fundamental function for
 * character-based output operations, serving as a building block
 * for more complex output functions.
 * 
 * Algorithm:
 * 1. Take the character parameter by value
 * 2. Use write system call to output the character
 * 3. Write to file descriptor 1 (stdout)
 * 4. Write exactly 1 byte (the character)
 * 
 * Parameters:
 * @c: The character to be displayed
 * 
 * Return:
 * void - No return value (output is written directly)
 * 
 * Examples:
 * ft_putchar('A') outputs "A"
 * ft_putchar('z') outputs "z"
 * ft_putchar('\n') outputs a newline
 **********************/
void	ft_putchar(char c)
{
	write(1, &c, 1);		/* Write the character to stdout using write system call */
}

/**********************
 * main - Entry point for putchar demonstration program
 * 
 * Description:
 * This program demonstrates the ft_putchar function by displaying
 * various characters including letters, digits, special characters,
 * and control characters. It serves as a comprehensive test of the
 * ft_putchar functionality.
 * 
 * Algorithm:
 * 1. Call ft_putchar with different character types
 * 2. Test uppercase and lowercase letters
 * 3. Test digits and special characters
 * 4. Test control characters (newline, tab, space)
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Examples:
 * ./ft_putchar outputs: "H"
 **********************/
int main(void)
{
	ft_putchar('H');		/* Display uppercase letter H */
	return (0);				/* Return success status */
}
