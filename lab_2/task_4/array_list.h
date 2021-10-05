#ifndef ARRAY_LIST_H_  
#define ARRAY_LIST_H_  
 
typedef struct arrayList_struct* Array_list;

Array_list init();
int size(Array_list array_List);
void add(Array_list array_List, void * element);
void insert(Array_list array_List, int index, void * element);
void *set(Array_list array_List, int index, void * element);
void *get(Array_list array_List, int index);
void remove_element(Array_list array_List, int index);
void clear(Array_list array_List);

#endif // ARRAY_LIST_H_
