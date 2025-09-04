//******************************************************
// Assignment name  : ft_split
// Expected files   : ft_split.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes a string, splits it into words, and returns them as
// a NULL-terminated array of strings.

// A "word" is defined as a part of a string delimited either by spaces/tabs/new
// lines, or by the start/end of the string.

// Your function must be declared as follows:

// char    **ft_split(char *str);

//******************************************************
// to compile it : gcc -Wall -Wextra -Werror ft_split.c -o ft_split
// to run it : ./ft_split "  Hello   World  42  "
// to run it : ./ft_split "\t\tThis\nis\ta\ntest\t\n"
//******************************************************

#include <stdlib.h>
#include <unistd.h>

/**********************
 * ft_split - String tokenization function
 * 
 * Description:
 * Splits an input string into individual words based on whitespace
 * delimiters (spaces, tabs, newlines). Returns a NULL-terminated
 * array of dynamically allocated strings, each containing one word.
 * Performs two passes: first to count words, second to extract them.
 * 
 * Algorithm:
 * 1. First pass: Count words by skipping whitespace and counting
 *    non-whitespace sequences
 * 2. Allocate array of string pointers (word count + 1 for NULL)
 * 3. Second pass: Extract each word:
 *    - Skip leading whitespace
 *    - Find word boundaries
 *    - Allocate memory for word
 *    - Copy characters to word string
 *    - Null-terminate word
 * 4. NULL-terminate the array of pointers
 * 
 * Parameters:
 * @str: Input string to be split into words
 * 
 * Return:
 * NULL-terminated array of dynamically allocated strings,
 * or NULL if allocation fails
 * 
 * Example:
 * ft_split("  Hello World  ") -> ["Hello", "World", NULL]
 * ft_split("a\tb\nc") -> ["a", "b", "c", NULL]
 **********************/
char **ft_split(char *str)
{
	char **result;					// Array of string pointers to hold split words
	int i = 0;						// Index for iterating through input string
	int j;							// Index for marking end of current word
	int k;							// Index for result array
	int wc = 0;						// Word count
	
	while (str[i])					// First pass: count words in the string
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))	// Skip whitespace
			i++;						// Move past whitespace characters
		if (str[i])						// If we found start of a word
			wc++;						// Increment word count
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')	// Skip non-whitespace
			i++;						// Move past word characters
	}
	
	result = malloc(sizeof(char *) * (wc + 1));	// Allocate array for word pointers plus NULL terminator
	if (!result)					// Check if malloc failed
		return (NULL);				// Return NULL if allocation failed
	
	i = 0;							// Reset index for second pass
	k = 0;							// Initialize result array index
	while (str[i])					// Second pass: extract and store words
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))	// Skip whitespace
			i++;						// Move past whitespace characters
		j = i;							// Mark start of current word
		while (str[j] && str[j] != ' ' && str[j] != '\t' && str[j] != '\n')	// Find end of word
			j++;						// Move to end of current word
		if (i < j)						// If we found a word (i.e., word has length > 0)
		{
			result[k] = malloc(sizeof(char) * ((j - i) + 1));	// Allocate memory for current word plus null terminator
			if (!result[k])				// Check if malloc failed
				return (NULL);			// Return NULL if allocation failed
			int m = 0;					// Index for copying characters into word string
			while (i < j)					// Copy characters from original string to word string
			{
				result[k][m] = str[i];		// Copy character from source to destination
				m++;						// Move to next position in word string
				i++;						// Move to next character in source string
			}
			result[k][m] = '\0';			// Null-terminate the word string
			k++;						// Move to next position in result array
		}
	}
	result[k] = NULL;				// NULL-terminate the array of string pointers
	return (result);				// Return pointer to array of word strings
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
 * main - Test function for ft_split implementation
 * 
 * Description:
 * Demonstrates the ft_split function with various test cases
 * including strings with multiple spaces, tabs, and newlines.
 * Tests proper memory allocation, word extraction, and memory
 * deallocation to prevent leaks.
 * 
 * Algorithm:
 * 1. Test string with multiple spaces
 * 2. Test string with tabs and newlines
 * 3. For each test:
 *    - Call ft_split
 *    - Print each extracted word
 *    - Free memory for each word string
 *    - Free memory for array of pointers
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Example:
 * Output:
 * Word: Hello
 * Word: World
 * Word: 42
 * 
 * Word: This
 * Word: is
 * Word: a
 * Word: test
 **********************/
int main(void)
{
	char **words;					// Array of string pointers returned by ft_split
	int i;							// Index for iterating through words array
	
	write(1, "Testing ft_split:\n", 18);	// Print test header
	
	words = ft_split("  Hello   World  42  ");	// Split string with multiple spaces
	i = 0;							// Initialize index
	while (words[i])					// Iterate through array until NULL terminator
	{
		write(1, "Word: ", 6);				// Print word label
		ft_putstr(words[i]);				// Print current word
		write(1, "\n", 1);				// Print newline
		free(words[i]);					// Free memory for current word string
		i++;							// Move to next word
	}
	free(words);						// Free memory for array of pointers
	
	write(1, "\n", 1);				// Print separator newline
	
	words = ft_split("\t\tThis\nis\ta\ntest\t\n");	// Split string with tabs and newlines
	i = 0;							// Reset index
	while (words[i])					// Iterate through array until NULL terminator
	{
		write(1, "Word: ", 6);				// Print word label
		ft_putstr(words[i]);				// Print current word
		write(1, "\n", 1);				// Print newline
		free(words[i]);					// Free memory for current word string
		i++;							// Move to next word
	}
	free(words);						// Free memory for array of pointers
	
	return (0);						// Return 0 to indicate successful execution
}