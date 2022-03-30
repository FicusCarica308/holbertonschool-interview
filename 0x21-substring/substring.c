#include "substring.h"
#include <stdio.h>

/**
 * find_substring - finds all the possible substrings containing
 *                  a list of words, within a given string.
 * @s: is the string to scan
 * @words: is the array of words all substrings must be a
 *         concatenation arrangement of
 * @nb_words: is the number of elements in the array words
 * @n: holds the address at which to store the number of
 *     elements in the returned array
 * Return: An allocated array, storing each index in 's',
 *         at which the substring was found... NULL if no solution
 * Notes:
 *  > A valid substring of s is the concatenation of
 *    each word in words exactly once and without any intervening characters
 *  > All words in the array words are the same length
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    (void)s;
    (void)words;
    (void)nb_words;
    (void)n;

	printf("%c", words[1][0]);
	return (NULL);
}


