#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

char* SEPARATOR = " "; 

Matrix* init(int column, int row){
    int i;
    Matrix* matrix = malloc(sizeof(Matrix));
    matrix->row = row;
    matrix->column = column;
    matrix->array = malloc(sizeof(int*) * row);
   
    for ( i = 0; i < row; i++){
        matrix->array[i] = malloc(sizeof(int) * column);
    }
    return matrix;
}

void fill_matrix(Matrix* matrix){
    int i, j;
    for ( i = 0; i < matrix->row; i++){
        for ( j = 0; j < matrix->column; j++){
            matrix->array[i][j] = rand() % 60;
        }
    }
}

void print(Matrix* matrix){
   int i, j;
    for ( i = 0; i < matrix->row; i++){
        for ( j = 0; j < matrix->column; j++){
            printf("[%d] ",matrix->array[i][j]);
        }
        printf("\n");
    }
}

int get_columns_num(Matrix* matrix){
    return matrix->column;
}

int get_row_num(Matrix* matrix){
    return matrix->row;
}

int get_element(Matrix* matrix, int row_index, int column_index){
    return matrix->array[row_index][column_index];
}

void set(Matrix* matrix, int row_index, int column_index, int item){
    matrix->array[row_index][column_index] = item;
}

void clean_matrix(Matrix* matrix){
    int i;
    for ( i = 0; i < matrix->row; i++){
        free(matrix->array[i]);
    }
    free(matrix->array);
}

void resize_matrix(Matrix* matrix, int new_rows_num, int new_cols_num){ 
    int i, j;
    int** new_matrix = malloc(sizeof(int*) * new_rows_num);
   

    for ( i = 0; i < new_rows_num; i++){
        new_matrix[i] = calloc(sizeof(int) , new_cols_num);
    }

    for ( i = 0; i < new_rows_num && i < matrix->row; i++){
        for ( j = 0; j < new_cols_num && j < matrix->column; j++){
            new_matrix[i][j] = matrix->array[i][j];
        }        
    }

    clean_matrix(matrix);
    
    matrix->row = new_rows_num;
    matrix->column = new_cols_num;
    matrix->array = new_matrix;
}

Matrix* sum_of_matrices(Matrix* mx1, Matrix* mx2){
    int i, j;
    if (mx1->row == mx2->row && mx1->column == mx2->column){
        
        Matrix* new_matrix = init(mx1->column, mx1->row);

        for ( i = 0 ; i < new_matrix->row; i++){
            for ( j = 0; j < new_matrix->column; j++) {
                new_matrix->array[i][j] = mx1->array[i][j] + mx2->array[i][j];
            }
        }
        return new_matrix;
    }
    else{
        printf("\nYou can sum only those matrix, which have the same size\n");
        return NULL;
    }
}

Matrix* subtract_of_matrices(Matrix* mx1, Matrix* mx2){
    int i, j;
    if (mx1->row == mx2->row && mx1->column == mx2->column){
        
        Matrix* new_matrix = init(mx1->column, mx1->row);

        for ( i = 0 ; i < new_matrix->row; i++){
            for ( j = 0; j < new_matrix->column; j++) {
                new_matrix->array[i][j] = mx1->array[i][j] - mx2->array[i][j];
            }
        }
        return new_matrix;
    }
    else{
        printf("\nYou can substract only those matrix, which have the same size\n");
        return NULL;
    }
}

Matrix* multipl_of_matrices(Matrix* mx1, Matrix* mx2){
    int i, j, k;
    if (mx1->column == mx2->row){
        Matrix* new_matrix = init(mx1->column,mx2->row);

        for ( i = 0; i < new_matrix->row; i++) {
            for ( j = 0; j < new_matrix->column; j++) {
                new_matrix->array[i][j] = 0;
                for ( k = 0; k < mx1->column ; k++) { 
                    new_matrix->array[i][j] = new_matrix->array[i][j] 
                        + mx1->array[i][k] * mx2->array[k][j];
                }
            }
        }
        return new_matrix;
    }
    else{
        printf("\nYou can multiple only in case when number of columns of the first matrix is equal to the number of rows of the second\n");
        return NULL;
    }
}

Matrix* multipl_by_number(Matrix* matrix, int value){
    int i, j;
    Matrix* new_matrix = init(matrix->column, matrix->row);

    for ( i = 0; i < matrix->row; i++){
        for ( j = 0; j < matrix->column; j++){
            new_matrix->array[i][j] = matrix->array[i][j] * value;
        }
    }
    return new_matrix;
}

void save_matrix_in_file(Matrix* matrix, char* path){
    int i, j;
    FILE* file = fopen(path, "wb");
    fprintf(file,"%d\n",matrix->row);
    fprintf(file,"%d\n",matrix->column);
    
    for ( i = 0; i < matrix->row; i++){
         for( j = 0; j < matrix-> column; j++){
              fprintf(file,"%d%s",matrix->array[i][j], SEPARATOR);
         //fwrite(matrix->array[i], sizeof(int), matrix->column, file);
         }
         //fprintf(file, "\n");
    }
    fclose(file);
}

Matrix* read_matrix_from_file(char* path){
    char buffer[20];
    int i = 0, j = -1;
    int column = 0;
    int row = 0;
    
    FILE* file = fopen(path, "rb");
    if (file == NULL) {
         printf ("File not found\n"); 
         return NULL;
    }
     
    fgets (&buffer,sizeof(buffer),file);
    row = atoi(buffer);
    
    fgets (&buffer,sizeof(buffer),file);
    column = atoi(buffer);
    
    printf("\ncolumns = %d rows = %d\n",column,row);
    
    Matrix* matrix = init(column,row);
    char line[100];
    
    while (fgets(line, sizeof(line), file) != NULL) {
        char *start = line;
        int field;
        int n;
     
        while (sscanf(start, "%d%n", &field, &n) == 1) {
            
            if(j == column-1) {
               j = 0;
               i++;
            }
            else j++;
              
            matrix->array[i][j] = field;
            start += n;
         }
               
     }

    fclose(file);
    return matrix;
}



