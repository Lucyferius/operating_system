#include <stdio.h>
#include "array_list.h"

int main(void){

	Array_list a = NULL;
	int menu;
	while(1){
		printf(" 1. Add\n 2. Insert\n 3. Print\n 4. Size\n 5. Remove\n 6. Set\n 7. Get\n 8. Clear\n 9. Exit\n");
		scanf("%d", &menu);
		switch(menu){
			case 1:{
					if(a==NULL)
						a = init();
					int new;
					printf("---Enter new element to add:  ");
					scanf("%d", &new);
					add(a,  new);
				}
				break;
			case 2:{
					if(a==NULL)
						a = init();
					int index, value;
					printf("---Enter the index: ");
					scanf("%d", &index);
					printf("---Enter the value of new element to add: ");
					scanf("%d", &value);
					insert(a, index, value);
				}
				break;
			case 3:{	
					if(a==NULL)
						a = init();
					printf("---Your array = (");
					for (int i = 0; i < size(a); i++)
						printf("%d ", (int *) (get(a, i)));
					printf(")\n");
				}
				break;
			case 4:
					printf("---Size of array = %d\n", size(a));
				break;
			case 5:{
					int index;
					printf("---Enter the index of element to remove: ");
					scanf("%d", &index);
					remove_element(a, index);
				}
				break;
			case 6:{	
					if(a==NULL)
						a = init();
					int index, value;
					printf("---Enter the index of element which you want to edit: ");
					scanf("%d", &index);
					if(index >= size(a)) {
						printf("---Index is bigger than amount of elements\n");
					}
					else{
						printf("---Enter the new value of element: ");
						scanf("%d", &value);
						printf("---Element(%d) = %d\n", index, (int *) (set(a, index, value)));
					}
				}break;
			case 7:{
					if(a==NULL)
						a = init();
					int index;
					printf("---Enter the index of element to show the value: ");
					scanf("%d", &index);
					printf("---Element(%d) = %d\n", index, (int *) (get(a, index)));
				}
				break;
			case 8:{
					clear(a);
					a= NULL;
					printf("---All elements were deleted\n");
				}
				break;
			case 9:{
				clear(a);
				return 0;
				}
				break;
			default:
					printf( "---Invalid input\n" );
		}
	}
	return 0;
}
