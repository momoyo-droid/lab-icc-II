#ifndef STRING_H
#define STRING_H

#include<stdio.h>

typedef char* string_t;

typedef float float_t;
typedef double double_t;

string_t read_all(FILE* input);
string_t read_until(FILE* input, char final_ref);
string_t read_from(FILE* input, char initial_ref);
string_t read_from_to(FILE* input, char initial_ref, char final_ref);
int read_int(FILE* input);
float_t read_float_until(FILE*, char final_ref);
double_t read_double_until(FILE*, char final_ref);
void print_string(string_t str);

#endif