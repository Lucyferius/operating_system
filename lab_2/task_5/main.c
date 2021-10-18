#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

int main(){
    int i;
    
    Linked_list* list = init();

    for (i = 0; i < 10; i++){
        add(list,i);
    }
    printf("\n\n----- initial list------\n");
    print(list);
    
    printf("\n\n----- step 1: insert 66 to index 0 ------\n");
    insert(list,0,66);
    print(list);
    
    printf("\n\n----- step 2: remove 66 from index 0 ------\n");
    remove_item(list,0);
    print(list);
    
    printf("\n\n----- step 3: set 55 to index 2 ------\n");
    set(list,2,55);
    print(list);
    
    printf("\n\n----- step 4: remove 55 from index 2 ------\n");
    remove_item(list,2);
    print(list);
    
    printf("\n\n----- step 5: remove item from index 19999 ------\n");
    remove_item(list,19999);
    print(list);
    printf("\n\n");
    
    
    return 0;
}
