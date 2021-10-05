#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>


float* generate_array(int length);
void print_array(float* array, int length);
float calc_average (float* array, int length);
int number_of_elems_bigger_than_average(float* array, int length, int average);
int get_index_of_first_negative_num (float* array, int length);
float get_sum_of_all_numbers_after_first_negative(float* array, int length, int index);

int main() {
    srand(time(NULL));
    
    int length = 6, num_count = 0, index;
    int play = 1;
    float average = 0, sum = 0;
  
    
    float* array = generate_array(length);
    if(array == NULL) exit(1);
    print_array(array, length);
    
    average = calc_average(array, length);
    num_count = number_of_elems_bigger_than_average (array, length, average);
    
    printf("Average  = %f\n", average );
    printf("Number of elems bigger than average = %d\n", num_count );
    
    index = get_index_of_first_negative_num(array, length);
    sum = get_sum_of_all_numbers_after_first_negative(array, length, index);
    printf("Sum of all numbers after first negative = %f\n", sum );
    return 0;
}

float* generate_array(int length) {
    float* array = (float*)malloc(sizeof(float) * length);
    int i;
    for (i = 0 ; i < length ; i++) {
        /* RAND_MAX -> the result is in the range of 0.0 to 1.0. */ 
        array[i] =  ((float)rand()/(float)(RAND_MAX)) * 10.0 - 5.0;
    }

    return array;
}

void print_array(float* array, int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("%f ", array[i]);
    }
    printf("\n");
}

float calc_average (float* array, int length){ 
    int i;
    float aver = 0;
    for (i = 0; i < length; i++){
        aver += array[i];
    }
    return (float) aver/length;
}

int number_of_elems_bigger_than_average(float* array, int length, int average){
    int i, count = 0;
    for (i = 0; i < length; i++){
        if(array[i] > average)
           count++;
    }
    return count;
}

int get_index_of_first_negative_num (float* array, int length){
    int i;
    for (i = 0; i < length; i++){
        if(array[i] < 0)
           return i;
    }
    return -1;
}

float get_sum_of_all_numbers_after_first_negative(float* array, int length, int index){
    int i;
    float sum = 0;
    if(index < 0) return 0;
    for (i = index+1; i < length; i++){
        sum += fabs(array[i]);
    }
    return sum;
}
