#ifndef _SORT_H_
#define _SORT_H_

#include <stddef.h>
#include <stdlib.h>

/* prototypes */
void print_array(const int *array, size_t size);
int get_last_digit(int digit, int pos);
int *find_last_digits(int *array, int pos, size_t size);
int *count_sort(int *digit_array, int *original_array, int pos, size_t size);
void radix_sort(int *array, size_t size);


#endif
