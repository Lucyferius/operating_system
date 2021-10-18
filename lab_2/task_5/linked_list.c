#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


int size(Linked_list* list){
    return list->length;
}

Node* get_last(Linked_list* list){

    if (list->root == NULL){
        return list->root;
    }
    
    Node* point = list->root;

    while (point->next != NULL){
        point = point->next;
    }
    
    return point;
}

Node* get_by_index(Linked_list* list, int index){
    int i;
    Node* point = list->root;

    if (point == NULL){
        return point;
    }
    if(index == 0){
        return point;
    }

    for ( i = 0; point->next != NULL; i++){
        if (i == index){
            return point;
        }
        point = point->next;
    }
    
    return point;
}

void add(Linked_list* list, int item){

    Node* new_node = malloc(sizeof(Node));
    new_node->value = item;
    new_node->next = NULL;

    if (list->root == NULL){
        list->root = new_node;
    }else{
        Node* last = get_last(list); 
        last->next = new_node;
    }

    list->length++;
}

void insert(Linked_list* list, int index, int item){
    if (list->root == NULL){
        add(list, item);
    }
    if (index >= list->length || index < 0){
        printf("\nIncorrect index: { size: %d; index: %d }\n",list->length, index);
        return;
    }

    Node* new_node = malloc(sizeof(Node));
    new_node->value = item;

    if(index == 0){
        new_node->next = list->root;
        list->root = new_node;
    }else{
        Node* node = get_by_index(list,index);
        new_node->next = node->next;
        node->next = new_node; 
    }

    list->length++;
}

void remove_item(Linked_list* list, int index){
    if (list->root == NULL){
        printf("\nList is empty\n");
        return;
    }
    if (index >= list->length || index < 0){
         printf("\nIncorrect index: { size: %d; index: %d }\n",list->length, index);
        return;
    }

    Node* removed_node;
    if(index == 0){
        removed_node = list->root;
        list->root = (list->root)->next;
    }else{
        Node* removed_node_previous = get_by_index(list,index-1);
        removed_node = removed_node_previous->next;
        removed_node_previous->next = removed_node->next;
    }
    int length = size(list);
    list->length = length-1;
    free(removed_node);
}

void set(Linked_list* list, int index, int item){
    if (list->root == NULL){
        printf("\nList is empty\n");
        return;
    }
    if (index >= list->length || index < 0){
        printf("\nIncorrect index: { size: %d; index: %d }\n",list->length, index);
        return;
    }
    get_by_index(list, index)->value = item;
}

int get(Linked_list* list, int index){
    if (list->root == NULL){
        printf("\nList is empty\n");
        return 0;
    }
    
    if (index >= list->length || index < 0){
        printf("\nIncorrect index: { size: %d; index: %d }\n",list->length, index);
        return 0;
    }
    return get_by_index(list->root, index)->value;
}

Linked_list* init(){
    Linked_list * list = malloc(sizeof(Linked_list));
    list->root = NULL;
    list->length = 0;
    return list;
}

void print(Linked_list* list){
     if(list->root == NULL){
        printf("\nList is empty\n");
        return;
     }
     Node* ptr = list->root;
     int i;
     for(i = 0; i < (list->length); i++){
         if(ptr->next == NULL){
            printf("[%d]", ptr->value);
         } else{
            printf("[%d]->", ptr->value);
            ptr = ptr->next;
         }
     }
}






