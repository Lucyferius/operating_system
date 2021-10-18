#ifndef MATRIX_H_  
#define MATRIX_H_  
 
typedef struct Matrix{
    int column;
    int row;
    int** array;
}Matrix;


Matrix* init(int column, int row);
void print(Matrix* matrix);
void fill_matrix(Matrix* matrix);
int get_columns_num(Matrix* matrix);
int get_row_num(Matrix* matrix);
int get_element(Matrix* matrix, int row_index, int column_index);
void set(Matrix* matrix, int row_index, int column_index, int item);
void clean_matrix(Matrix* matrix);
void resize_matrix(Matrix* matrix, int new_rows_num, int new_cols_num);
Matrix* sum_of_matrices(Matrix* mx1, Matrix* mx2);
Matrix* multipl_of_matrices(Matrix* mx1, Matrix* mx2);
Matrix* multipl_by_number(Matrix* matrix, int value);
Matrix* subtract_of_matrices(Matrix* mx1, Matrix* mx2);
void save_matrix_in_file(Matrix* matrix, char* path);
Matrix* read_matrix_from_file(char* path);

#endif // MATRIX_H_
