#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

int COLUMN = 3;
int ROW = 4;

int main(){
    srand(time(NULL));
    
    Matrix* matrix1;
    Matrix* matrix2;
    Matrix* matrix3;
    Matrix* initial_matrix;
    Matrix* result_matrix;
    printf("------ init matrix ---------\n\n");
   
    initial_matrix = init(COLUMN,ROW);
    fill_matrix (initial_matrix);
    print(initial_matrix);

    printf("\n\n------ save matrix in file ---------\n\n");
    save_matrix_in_file(initial_matrix,"matrix.txt");

    Matrix* saved_matrix = read_matrix_from_file("matrix.txt");
    
    printf("\n\n------ read saved matrix ---------\n\n");
    print(saved_matrix);

   
    printf("\n------ init matrix1 and matrix2 ---------\n\n");
    matrix1 = init(COLUMN,ROW);
    matrix2 = init(COLUMN,ROW);
    fill_matrix (matrix1);
    fill_matrix (matrix2);
    printf("\n------ matrix1 ---------\n\n");
    print(matrix1);
    printf("\n------ matrix2 ---------\n\n");
    print(matrix2);
    
    printf("\n------ sum matrix1 and matrix2 ---------\n\n");
    result_matrix = sum_of_matrices(matrix1,matrix2);
    print(result_matrix);

    printf("\n------ subctruct matrix1 and matrix3---------\n\n");
    result_matrix = subtract_of_matrices(matrix1,matrix2);
    print(result_matrix);

    printf("\n------ multiple matrix1 to matrix3 ---------\n\n");
    matrix3 = init(ROW, COLUMN);
    fill_matrix(matrix3);
    printf("\n------ matrix3 ---------\n\n");
    print(matrix3);
    
    printf("\n------ result ---------\n\n");
    result_matrix = multipl_of_matrices(matrix1,matrix3);
    print(result_matrix);
    
    printf("\n------ multiple initial matrix by 100 ---------\n\n");
    result_matrix = multipl_by_number(initial_matrix, 100);
    print(result_matrix);
    
    printf("\n------ set to col=0, row=0 number = 5555 ---------\n\n");
    set(initial_matrix,0,0,5555);
    print(initial_matrix);
    
    printf("\n------ get item from col=0, row=0 ---------\n\n");
    printf("Get: %d\n\n", get_element(initial_matrix,0,0));

    printf("\n------ resize initial matrix ---------\n\n");
    resize_matrix(initial_matrix, ROW+2, COLUMN+2);
    print(initial_matrix);
    
    printf("\n------ overfill initial matrix ---------\n\n");
    fill_matrix (initial_matrix);
    print(initial_matrix);

    clean_matrix(matrix1);
    clean_matrix(matrix2);
    clean_matrix(result_matrix);
    clean_matrix(initial_matrix);
   
    return 0;
}
