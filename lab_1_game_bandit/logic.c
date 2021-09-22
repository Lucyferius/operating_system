#include <stdlib.h>
#include <stdio.h>
#include "logic.h"

const int NUMBER_TO_RETURN_BET = 7;
const int NUMBER_TO_TRIPPLE_WIN = 7;

int* generate_array(int length) {
    int* array = (int*)malloc(sizeof(int) * length);
    int i;
    for (i = 0 ; i < length ; i++) {
        array[i] = (rand() % 12) + 1;
    }

    return array;
}

void print_array(int* array, int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/* 
	1 - all are equal
	0 - not
*/
int check_all_numbers_equals_double_win(int* array, int length) {
    int i, j;
    for(i = 0; i < length; i++){
        for(j = i + 1; j < length; j++){
            if(array[i] != array[j]){
                return 0;
            }
        }
    }
    
    return 1;
}

/* 
	1 - all are NUMBER_TO_TRIPPLE_WIN
	0 - not
*/

int check_tripple_win(int* array, int length) {
    int i;
    for (i = 0; i < length; i++) {
        if (array[i] != NUMBER_TO_TRIPPLE_WIN) {
            return 0;
        }
    }
    
    return 1;
}

/* 
	1 - one number is NUMBER_TO_RETURN_BET
	0 - not
*/

int check_return_bet(int* array, int length) {
    int i;

    for (i = 0; i < length; i++) {
        if (array[i] == NUMBER_TO_RETURN_BET) {
            return 1;
        }
    }
    
    return 0;
}

int check_one_thirds_numbers_are_the_same(int* array, int length) {
    int equals_numbers = 0;
    int max_equals = 0;
    int ratio = length / 3.0;

    int i, j;
    for (i = 0; i < length; i++) {
    
        for (j = i+1; j < length-1; j++) {
            if (array[i] == array[j]) {
                equals_numbers++;
            }
        }

        if (max_equals < equals_numbers) {
            max_equals = equals_numbers;
        }

        equals_numbers = 0;
    }
    
    return max_equals == ratio ? 1 : 0;
}


