#include "read_lib.h"
#include "shells.h"

#include<stdlib.h>


int main(){   
    double shell_diameter;
    char* name;
    unsigned int n_shells;
    
    shell_t* s;
    n_shells = read_int(stdin);
    list_t* l = create_list(n_shells);
    
    
    for(int i = 0; i < n_shells; i++){ 
        shell_diameter = read_double_until(stdin, ' ');
        name = read_until(stdin, '\n');
        
        s = create_shell(shell_diameter, name);
        insert_elem(l, s);
    }
    
    shell_sort(l);
    print_list(l);
    free_list(l);

    return EXIT_SUCCESS;
}