/*
 ******************************************************
 Allowed functions: malloc
 • Create a function that splits a string of characters based on an additional string of
 characters.
 • You'll have to use each character from the string charset as a separator.
 • The function should return an array where each element of the array contains the
 address of a string, wrapped between two separators. The last element of the array
 should be NULL to indicate the end of the array.
 • There cannot be any empty strings in your array. Draw your own conclusions
 accordingly.
 • The string given as an argument won't be modifiable.
 • Here's how it should be prototyped:
 char **ft_split(char *str, char *charset);
 ******************************************************
 * to compile it : gcc ft_split.c
 * to run it : ./a.out
 ******************************************************
 */

#include <stdlib.h>

/**********************
 * ft_is_separator - Checks if character is a separator
 * 
 * Description:
 * This function checks if a given character exists in
 * the charset string (is a separator).
 * 
 * Algorithm:
 * 1. Loop through each character in charset
 * 2. If character matches, return 1
 * 3. If no match found, return 0
 * 
 * Parameters:
 * @c: Character to check
 * @charset: String containing separator characters
 * 
 * Return:
 * 1 if character is a separator, 0 otherwise
 * 
 * Examples:
 * ft_is_separator(',', ",;") returns 1
 * ft_is_separator('a', ",;") returns 0
 **********************/
int	ft_is_separator(char c, char *charset)
{
	int	i;						/* Charset index */
	
	i = 0;						/* Initialize index */
	while (charset[i])			/* Loop through charset */
	{
		if (c == charset[i])	/* Check if character matches */
			return (1);			/* Found separator */
		i++;					/* Check next separator */
	}
	return (0);					/* Not a separator */
}

/**********************
 * ft_count_words - Counts words in string
 * 
 * Description:
 * Counts the number of words (non-empty strings) that
 * will result from splitting the string.
 * 
 * Algorithm:
 * 1. Initialize counter and in_word flag
 * 2. Loop through string
 * 3. Count transitions from separator to non-separator
 * 4. Return word count
 * 
 * Parameters:
 * @str: String to analyze
 * @charset: Separator characters
 * 
 * Return:
 * Number of words in the string
 * 
 * Examples:
 * ft_count_words("hello,world", ",") returns 2
 * ft_count_words("a b c", " ") returns 3
 **********************/
int	ft_count_words(char *str, char *charset)
{
	int	count;					/* Word counter */
	int	in_word;				/* Flag for being inside a word */
	int	i;						/* String index */
	
	count = 0;					/* Initialize counter */
	in_word = 0;				/* Not in word initially */
	i = 0;						/* Start at beginning */
	while (str[i])				/* Loop through string */
	{
		if (!ft_is_separator(str[i], charset))	/* Non-separator character */
		{
			if (!in_word)		/* Starting a new word */
			{
				count++;		/* Increment word count */
				in_word = 1;	/* Now inside a word */
			}
		}
		else					/* Separator character */
			in_word = 0;		/* No longer in word */
		i++;					/* Move to next character */
	}
	return (count);				/* Return word count */
}

/**********************
 * ft_get_word_len - Gets length of current word
 * 
 * Description:
 * Calculates the length of a word starting at the given
 * position, up to the next separator or end of string.
 * 
 * Algorithm:
 * 1. Initialize length counter
 * 2. Count characters until separator or end
 * 3. Return the length
 * 
 * Parameters:
 * @str: String containing the word
 * @start: Starting position of word
 * @charset: Separator characters
 * 
 * Return:
 * Length of the word
 * 
 * Examples:
 * ft_get_word_len("hello,world", 0, ",") returns 5
 **********************/
int	ft_get_word_len(char *str, int start, char *charset)
{
	int	len;					/* Length counter */
	
	len = 0;					/* Initialize length */
	while (str[start + len] && !ft_is_separator(str[start + len], charset))
	{
		len++;					/* Count non-separator characters */
	}
	return (len);				/* Return word length */
}

/**********************
 * ft_extract_word - Extracts a word from string
 * 
 * Description:
 * Allocates memory and copies a word from the source string
 * starting at the specified position.
 * 
 * Algorithm:
 * 1. Get word length
 * 2. Allocate memory for word
 * 3. Copy characters to new string
 * 4. Add null terminator
 * 5. Return the word
 * 
 * Parameters:
 * @str: Source string
 * @start: Starting position
 * @len: Length of word to extract
 * 
 * Return:
 * Newly allocated string containing the word
 * NULL if allocation fails
 * 
 * Examples:
 * ft_extract_word("hello", 0, 5) returns "hello"
 **********************/
char	*ft_extract_word(char *str, int start, int len)
{
	char	*word;				/* New word string */
	int		i;					/* Copy index */
	
	word = (char *)malloc(sizeof(char) * (len + 1));	/* Allocate memory */
	if (!word)					/* Check allocation */
		return (NULL);			/* Return NULL on failure */
	i = 0;						/* Initialize copy index */
	while (i < len)				/* Copy characters */
	{
		word[i] = str[start + i];	/* Copy character */
		i++;					/* Move to next character */
	}
	word[i] = '\0';				/* Add null terminator */
	return (word);				/* Return the word */
}

/**********************
 * ft_split - Splits string into array of words
 * 
 * Description:
 * Main function that splits a string using any character
 * from charset as a separator. Returns an array of strings
 * with NULL terminator.
 * 
 * Algorithm:
 * 1. Count words in string
 * 2. Allocate array for word pointers
 * 3. Extract each word:
 *    - Skip separators
 *    - Find word boundaries
 *    - Allocate and copy word
 * 4. Add NULL terminator to array
 * 5. Return the array
 * 
 * Parameters:
 * @str: String to split
 * @charset: String containing separator characters
 * 
 * Return:
 * Array of strings (NULL-terminated)
 * NULL if allocation fails
 * 
 * Examples:
 * ft_split("hello,world", ",") returns ["hello", "world", NULL]
 * ft_split("a b c", " ") returns ["a", "b", "c", NULL]
 **********************/
char	**ft_split(char *str, char *charset)
{
	char	**result;			/* Result array of strings */
	int		word_count;			/* Number of words */
	int		word_index;			/* Current word index */
	int		i;					/* String position */
	int		word_len;			/* Length of current word */
	
	word_count = ft_count_words(str, charset);		/* Count words */
	result = (char **)malloc(sizeof(char *) * (word_count + 1));	/* Allocate array */
	if (!result)				/* Check allocation */
		return (NULL);			/* Return NULL on failure */
	
	word_index = 0;				/* Initialize word index */
	i = 0;						/* Initialize string position */
	while (str[i] && word_index < word_count)		/* Process string */
	{
		/* Skip separators */
		while (str[i] && ft_is_separator(str[i], charset))
			i++;
		
		/* Extract word if found */
		if (str[i])
		{
			word_len = ft_get_word_len(str, i, charset);	/* Get word length */
			result[word_index] = ft_extract_word(str, i, word_len);	/* Extract word */
			if (!result[word_index])	/* Check extraction */
				return (NULL);		/* Return NULL on failure */
			word_index++;			/* Move to next word slot */
			i += word_len;			/* Skip past current word */
		}
	}
	result[word_index] = NULL;		/* NULL terminate array */
	return (result);				/* Return result array */
}

/**********************
 * main - Test program for ft_split function
 * 
 * Description:
 * Tests the ft_split function with various strings
 * and separator sets.
 * 
 * Return:
 * 0 on successful execution
 **********************/
#include <stdio.h>

int	main(void)
{
	char	**result;			/* Result array */
	int		i;					/* Array index */
	
	/* Test 1: Simple comma separator */
	printf("Test 1 - Split 'hello,world,42' by ',':\n");
	result = ft_split("hello,world,42", ",");
	if (result)
	{
		i = 0;
		while (result[i])
		{
			printf("  [%d]: '%s'\n", i, result[i]);
			free(result[i]);	/* Free each word */
			i++;
		}
		free(result);			/* Free array */
	}
	
	/* Test 2: Multiple separators */
	printf("\nTest 2 - Split 'one;two,three:four' by ',;:':\n");
	result = ft_split("one;two,three:four", ",;:");
	if (result)
	{
		i = 0;
		while (result[i])
		{
			printf("  [%d]: '%s'\n", i, result[i]);
			free(result[i]);
			i++;
		}
		free(result);
	}
	
	/* Test 3: Spaces as separators */
	printf("\nTest 3 - Split 'The quick brown fox' by ' ':\n");
	result = ft_split("The quick brown fox", " ");
	if (result)
	{
		i = 0;
		while (result[i])
		{
			printf("  [%d]: '%s'\n", i, result[i]);
			free(result[i]);
			i++;
		}
		free(result);
	}
	
	/* Test 4: Multiple consecutive separators */
	printf("\nTest 4 - Split ',,hello,,,world,,' by ',':\n");
	result = ft_split(",,hello,,,world,,", ",");
	if (result)
	{
		i = 0;
		while (result[i])
		{
			printf("  [%d]: '%s'\n", i, result[i]);
			free(result[i]);
			i++;
		}
		free(result);
	}
	
	/* Test 5: No separators */
	printf("\nTest 5 - Split 'noseparators' by ',':\n");
	result = ft_split("noseparators", ",");
	if (result)
	{
		i = 0;
		while (result[i])
		{
			printf("  [%d]: '%s'\n", i, result[i]);
			free(result[i]);
			i++;
		}
		free(result);
	}
	
	return (0);					/* Return success */
}