#ifndef LINKED_LIST_H_  
#define LINKED_LIST_H_  
 
typedef struct {
    struct Node* next;
    int value;
}Node;

typedef struct {
    Node* root;
    int length;
} Linked_list;


Linked_list* init();
int size (Linked_list* list);
void add(Linked_list* list, int item);
void insert(Linked_list* list, int index, int item);
void remove_item(Linked_list* list, int index);
void set(Linked_list* list, int index, int item);
int get(Linked_list* list, int index);
Node* get_last(Linked_list* list);
Node* get_by_index(Linked_list* list, int index);
void print(Linked_list* list);

#endif // LINKED_LIST_H_

