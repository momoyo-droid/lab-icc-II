#include "shells.h"


#include<stdio.h>
#include<stdlib.h>


#define TRUE 1
#define FALSE 0


struct s{
    double shell_diameter;
    char* name;
};


struct l{
    shell_t** elem;
    int n_shells;
    int curr_shell;
};


list_t* create_list(int n_shells){
    list_t* l = (list_t*)malloc(sizeof(list_t));
    
    if(l == NULL){
        exit(1);
        return NULL;
    }

    l->n_shells = n_shells;
    l->curr_shell = 0;
    l->elem = (shell_t**)malloc(l->n_shells*sizeof(shell_t*));
    
    
    return l;
}


shell_t* create_shell(double shell_diameter, char* name){
    shell_t* s = (shell_t*)malloc(sizeof(shell_t));
    
    s->shell_diameter = shell_diameter;
    s->name = name;
    
    
    return s;
}


int get_size_list(list_t *l){

    if(l == NULL){
        printf("NULL");
        exit(1);
    }

    return l->n_shells;
}


bool list_is_empty(list_t *l){
    if(l->n_shells == 0) return TRUE;
    
    return FALSE;
}


void print_list(list_t* l){
    for(int i = 0; i < l->curr_shell; i++){
        printf("%.3lf %s\n", l->elem[i]->shell_diameter, l->elem[i]->name);
    
    }
    
}


void insert_elem(list_t* l, shell_t* s){

    if(l == NULL){
        printf("NULL");
        exit(1);
    }

    l->elem[l->curr_shell] = s;
     
    l->curr_shell++;
    
}


void insertionSort(list_t* l, int k, int gap){
    int i, j;
      
    for(i = k+gap; i < l->n_shells; i += gap){
    
        shell_t* key = l->elem[i]; // first shell
        j = i - gap;
        
        
        while(j >= k && l->elem[j]->shell_diameter > key->shell_diameter){
           
            l->elem[j + gap] = l->elem[j];
            j = j-gap;
            
        }
        
        l->elem[j + gap] = key;
        
    }
}


void shell_sort(list_t* l){
    int d = l->n_shells/2; // sub-listing
    
    while(d >= 1){ // if d == 1, sort normally with original algorithm insertioSort
    
        for(int k = 0; k < d; k++){ // taking element k that belongs to sublist
        
            insertionSort(l, k, d); 
        }
        
        d = d/2;
    
    }

}


void free_list(list_t* l){
    if(l == NULL){
        printf("NULL");
        exit(1);
    }
    
    if(l->elem == NULL){
        printf("NULL");
        exit(1); 
    }
    
    
    for(int i = 0; i < l->curr_shell; i++){
        if(l->elem[i]->name != NULL){
            free(l->elem[i]->name);
        }
        
        if(l->elem[i] != NULL){
            free(l->elem[i]);
        }
    
    }
    
    
    free(l->elem);
    free(l);

}