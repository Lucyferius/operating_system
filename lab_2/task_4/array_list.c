#include<stdlib.h>
#include "array_list.h"


struct arrayList_struct {
  	int capacity;
  	int number_of_elements;
  	void ** elements;
};

void resize(Array_list array_list, size_t size) {
  	array_list->capacity = size / sizeof(void*);
  	array_list->elements = realloc(array_list->elements, size);
}

Array_list init(){
  	Array_list array_list = calloc(1, sizeof(Array_list));
  	array_list->capacity = 10;
  	array_list->number_of_elements = 0;
  	array_list->elements = calloc(10, sizeof(void**) * 10);
  	return array_list;
}

int size(Array_list array_list){
	return array_list->number_of_elements;
}

void add(Array_list array_list, void * element){
	if (array_list->number_of_elements+1 > array_list->capacity) 
    	resize(array_list, (array_list->capacity * 2) * sizeof(void*));
  
  	array_list->elements[array_list->number_of_elements] = element;
  	array_list->number_of_elements++;
}

void *set(Array_list array_list, int index, void * element){
	array_list->elements[index] = element;
	return array_list->elements[index];
}

void insert(Array_list array_list, int index, void * element){
	if(array_list->number_of_elements+1 > array_list->capacity){
    		resize(array_list, (array_list->capacity * 2) * sizeof(void*));
    	}
    	if(index > (array_list->number_of_elements)){
    		set(array_list, array_list->number_of_elements, element);
    	}
    	else{
		for(int i = array_list->number_of_elements; i>index;i--){
			array_list->elements[i] = array_list-> elements[i-1];
		}
		set(array_list, index, element);	
	}	

  	array_list->number_of_elements++;
}	

void *get(Array_list array_list, int index){
	return array_list->elements[index];
}

void clear(Array_list array_list){
    array_list->capacity = 0;
    free(array_list->elements);
    array_list->elements = NULL;
}

void remove_element(Array_list array_list, int index){
	if (index > array_list->number_of_elements - 1)
        return;
    if (array_list->number_of_elements == 1) {
        clear(array_list);
        return;
    }
    for (int i = index; i < array_list->number_of_elements; i++) {
        if (i == array_list->number_of_elements - 1)
            array_list->elements[i] = NULL;
        else
            array_list->elements[i] = array_list->elements[i + 1];
    }
    array_list->number_of_elements--;
}
