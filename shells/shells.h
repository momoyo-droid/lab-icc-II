/*
* program designed to receive a certain number of shells, the diameter and name of each one of them, line by line
* until completing the number typed by the user in the input. Afterwards, sort them with the ShellSort algorithm
* and the modified InsertionSort.

** Made by: 
*** Ana Cristina Silva de Oliveira - 11965630 - Universidade de São Paulo (USP) - Campus São Carlos - ICMC. ***

*/


#ifndef SHELLS_H
#define SHELLS_H

typedef struct s shell_t;
typedef struct l list_t;

typedef int bool;

/*
* @resume create the list according to the number of shells
* @parameters int (integer)
* @return struct list_t type pointer
*/
list_t* create_list(int n_shells);
/*
* @resume creates the shell according to its diameter and its name (color + texture)
* @parameters double, char* (string)
* @return struct shell_t type pointer
*/
shell_t* create_shell(double shell_diameter, char* name);
/*
* @resume return list size
* @parameters struct list_t type pointer
* @return list size
*/
int get_size_list(list_t* l);
/*
* @resume check if the list is empty
* @parameters struct list_t type pointer
* @return boolean
*/
bool list_is_empty(list_t* l);
/*
* @resume print the list
* @parameters struct list_t type pointer
* @return void
*/
void print_list(list_t* l);
/*
* @resume insert an element into the list
* @parameters struct list_t type pointer, struct shell_t type pointer
* @return void
*/
void insert_elem(list_t* l, shell_t* s);
/*
* @resume sorting algorithm. divide the list into sub-lists
* @parameters struct list_t type pointer
* @return void
*/
void shell_sort(list_t* l);
/*
* @resume sorting algorithm. sorts the sub-lists according to the position of the element k and the "gap"
* @parameters struct list_t type pointer, int (integer)
* @return void
*/
void insertionSort(list_t* l, int k, int gap);
/*
* @resume deallocate allocated memory
* @parameters struct list_t type pointer
* @return void
*/
void free_list(list_t* l);

#endif