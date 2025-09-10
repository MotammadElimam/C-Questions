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
// to compile it : gcc ft_split.c
// to run it : ./a.out
//******************************************************

#include <stdlib.h>
#include <unistd.h>

/**********************
 * is_whitespace - Checks if a character is whitespace
 * 
 * Description:
 * This helper function determines if a character is considered
 * whitespace (space, tab, or newline). Used to identify word
 * boundaries when splitting the string.
 * 
 * Parameters:
 * @c: The character to check
 * 
 * Return:
 * 1 if character is whitespace, 0 otherwise
 * 
 * Examples:
 * is_whitespace(' ') returns 1
 * is_whitespace('a') returns 0
 **********************/
int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');	/* Check for space, tab, newline */
}

/**********************
 * count_words - Counts the number of words in a string
 * 
 * Description:
 * This helper function counts the number of words in a string
 * by identifying transitions from whitespace to non-whitespace.
 * This count is used to allocate the correct amount of memory
 * for the array of string pointers.
 * 
 * Algorithm:
 * 1. Iterate through the string
 * 2. When transitioning from whitespace to non-whitespace, increment count
 * 3. Skip consecutive non-whitespace characters
 * 4. Return total word count
 * 
 * Parameters:
 * @str: The string to count words in
 * 
 * Return:
 * The number of words in the string
 * 
 * Examples:
 * count_words("hello world") returns 2
 * count_words("  a  b  c  ") returns 3
 **********************/
int	count_words(char *str)
{
	int count = 0;						/* Word counter */
	int i = 0;							/* String index */
	
	while (str[i])						/* Iterate through string */
	{
		while (str[i] && is_whitespace(str[i]))	/* Skip whitespace */
			i++;						/* Move to next character */
		
		if (str[i])						/* If non-whitespace found */
		{
			count++;					/* Increment word count */
			while (str[i] && !is_whitespace(str[i]))	/* Skip the word */
				i++;					/* Move to next character */
		}
	}
	
	return (count);						/* Return total word count */
}

/**********************
 * extract_word - Extracts a single word from a string
 * 
 * Description:
 * This helper function allocates memory and copies a single word
 * from the source string starting at the given position. It
 * determines the word length and creates a null-terminated copy.
 * 
 * Algorithm:
 * 1. Calculate the length of the word
 * 2. Allocate memory for the word (+1 for null terminator)
 * 3. Copy characters from source to destination
 * 4. Null-terminate the word
 * 5. Return pointer to the new word
 * 
 * Parameters:
 * @str: The source string
 * @start: Starting position of the word
 * 
 * Return:
 * Pointer to allocated word string, or NULL on malloc failure
 * 
 * Examples:
 * extract_word("hello world", 0) returns "hello"
 * extract_word("hello world", 6) returns "world"
 **********************/
char	*extract_word(char *str, int start)
{
	int len = 0;						/* Word length counter */
	char *word;							/* Pointer to new word */
	int i = 0;							/* Copy index */
	
	while (str[start + len] && !is_whitespace(str[start + len]))	/* Calculate word length */
		len++;							/* Increment length counter */
	
	word = (char *)malloc(sizeof(char) * (len + 1));	/* Allocate memory for word */
	if (!word)							/* Check if malloc failed */
		return (NULL);					/* Return NULL on allocation failure */
	
	while (i < len)						/* Copy word characters */
	{
		word[i] = str[start + i];		/* Copy character */
		i++;							/* Move to next character */
	}
	
	word[len] = '\0';					/* Null-terminate the word */
	return (word);						/* Return pointer to word */
}

/**********************
 * ft_split - Splits a string into an array of words
 * 
 * Description:
 * This function takes a string and splits it into individual words,
 * returning them as a NULL-terminated array of strings. Each word
 * is allocated separately, and the array itself is also allocated.
 * Words are separated by whitespace (spaces, tabs, newlines).
 * 
 * Algorithm:
 * 1. Count the number of words in the string
 * 2. Allocate array of string pointers (+1 for NULL terminator)
 * 3. Iterate through string extracting each word
 * 4. Store each word in the array
 * 5. NULL-terminate the array
 * 6. Return the array of words
 * 
 * Parameters:
 * @str: The string to split into words
 * 
 * Return:
 * NULL-terminated array of word strings, or NULL on failure
 * 
 * Examples:
 * ft_split("hello world") returns ["hello", "world", NULL]
 * ft_split("  a  b  ") returns ["a", "b", NULL]
 **********************/
char	**ft_split(char *str)
{
	int word_count = count_words(str);		/* Count total words */
	char **result;						/* Array of string pointers */
	int i = 0;							/* String traversal index */
	int word_index = 0;					/* Current word index in result array */
	
	if (!str)							/* Handle NULL input */
		return (NULL);					/* Return NULL for invalid input */
	
	result = (char **)malloc(sizeof(char *) * (word_count + 1));	/* Allocate array */
	if (!result)						/* Check if malloc failed */
		return (NULL);					/* Return NULL on allocation failure */
	
	while (str[i] && word_index < word_count)	/* Process all words */
	{
		while (str[i] && is_whitespace(str[i]))	/* Skip leading whitespace */
			i++;						/* Move to next character */
		
		if (str[i])						/* If word found */
		{
			result[word_index] = extract_word(str, i);	/* Extract and store word */
			if (!result[word_index])	/* Check if extraction failed */
			{
				/* Free previously allocated words on failure */
				int j = 0;				/* Cleanup index */
				while (j < word_index)	/* Free all previous words */
				{
					free(result[j]);	/* Free current word */
					j++;				/* Move to next word */
				}
				free(result);			/* Free result array */
				return (NULL);			/* Return NULL on failure */
			}
			word_index++;				/* Move to next word slot */
			while (str[i] && !is_whitespace(str[i]))	/* Skip current word */
				i++;					/* Move to next character */
		}
	}
	
	result[word_count] = NULL;			/* NULL-terminate the array */
	return (result);					/* Return array of words */
}

/**********************
 * ft_putstr - Writes a string to standard output
 * 
 * Description:
 * This helper function writes a string to standard output using
 * the write system call. It calculates the string length and
 * outputs the entire string at once.
 * 
 * Parameters:
 * @str: The string to write to stdout
 * 
 * Return:
 * void - No return value
 * 
 * Examples:
 * ft_putstr("Hello"); // Outputs "Hello" to stdout
 * ft_putstr("World\n"); // Outputs "World" followed by newline
 **********************/
void	ft_putstr(char *str)
{
	int len = 0;							/* Length counter for string */
	
	if (!str)								/* Handle NULL pointer */
		return;									/* Exit if string is NULL */
	
	while (str[len])						/* Calculate string length */
		len++;									/* Increment length counter */
	
	write(1, str, len);						/* Write string to stdout */
}

/**********************
 * ft_putnbr - Writes an integer to standard output
 * 
 * Description:
 * This helper function converts an integer to its string representation
 * and writes it to standard output using the write system call.
 * It handles negative numbers by outputting the minus sign first.
 * 
 * Algorithm:
 * 1. Handle negative numbers by outputting '-' and making positive
 * 2. Handle zero as special case
 * 3. Recursively output digits from most significant to least
 * 4. Convert each digit to character and write it
 * 
 * Parameters:
 * @n: The integer to write to stdout
 * 
 * Return:
 * void - No return value
 * 
 * Examples:
 * ft_putnbr(42); // Outputs "42" to stdout
 * ft_putnbr(-123); // Outputs "-123" to stdout
 * ft_putnbr(0); // Outputs "0" to stdout
 **********************/
void	ft_putnbr(int n)
{
	char digit;								/* Character to output */
	
	if (n == -2147483648)					/* Handle INT_MIN special case */
	{
		write(1, "-2147483648", 11);		/* Write INT_MIN directly */
		return;									/* Exit after handling special case */
	}
	
	if (n < 0)								/* Handle negative numbers */
	{
		write(1, "-", 1);						/* Write minus sign */
		n = -n;									/* Make number positive */
	}
	
	if (n >= 10)								/* Recursive case for multi-digit */
		ft_putnbr(n / 10);						/* Output higher order digits */
	
	digit = (n % 10) + '0';					/* Convert digit to character */
	write(1, &digit, 1);						/* Write single digit */
}

/**********************
 * main - Entry point for ft_split testing program
 * 
 * Description:
 * This program tests the ft_split function with various
 * string inputs to demonstrate word splitting functionality
 * including edge cases like multiple spaces and empty strings.
 * 
 * Parameters:
 * None
 * 
 * Return:
 * 0 on successful execution
 * 
 * Test Cases:
 * - Basic sentence with multiple words
 * - String with extra whitespace
 * - Single word
 * - Empty string
 **********************/
int main(void)
{
	char **words;						/* Array of word pointers */
	int i;								/* Loop index */
	
	/* Test case 1: Basic sentence */
	ft_putstr("Test 1: \"hello world test\"\n");	/* Print test description */
	words = ft_split("hello world test");	/* Split the string */
	i = 0;								/* Initialize index */
	while (words && words[i])			/* Print each word */
	{
		ft_putstr("Word ");					/* Print word label */
		ft_putnbr(i);						/* Print word index */
		ft_putstr(": \"");					/* Print separator and quote */
		ft_putstr(words[i]);				/* Print current word */
		ft_putstr("\"\n");					/* Print closing quote and newline */
		free(words[i]);					/* Free word memory */
		i++;							/* Move to next word */
	}
	free(words);						/* Free array memory */
	ft_putstr("\n");						/* Print separator */
	
	/* Test case 2: Extra whitespace */
	ft_putstr("Test 2: \"  hello    world  \"\n");	/* Print test description */
	words = ft_split("  hello    world  ");	/* Split the string */
	i = 0;								/* Initialize index */
	while (words && words[i])			/* Print each word */
	{
		ft_putstr("Word ");					/* Print word label */
		ft_putnbr(i);						/* Print word index */
		ft_putstr(": \"");					/* Print separator and quote */
		ft_putstr(words[i]);				/* Print current word */
		ft_putstr("\"\n");					/* Print closing quote and newline */
		free(words[i]);					/* Free word memory */
		i++;							/* Move to next word */
	}
	free(words);						/* Free array memory */
	ft_putstr("\n");						/* Print separator */
	
	/* Test case 3: Single word */
	ft_putstr("Test 3: \"hello\"\n");		/* Print test description */
	words = ft_split("hello");			/* Split the string */
	i = 0;								/* Initialize index */
	while (words && words[i])			/* Print each word */
	{
		ft_putstr("Word ");					/* Print word label */
		ft_putnbr(i);						/* Print word index */
		ft_putstr(": \"");					/* Print separator and quote */
		ft_putstr(words[i]);				/* Print current word */
		ft_putstr("\"\n");					/* Print closing quote and newline */
		free(words[i]);					/* Free word memory */
		i++;							/* Move to next word */
	}
	free(words);						/* Free array memory */
	
	return (0);							/* Return success */
}