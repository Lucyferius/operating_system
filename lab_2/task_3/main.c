#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>

typedef struct {
    
    char surname[12];
    int group;
    double web_mark;
    double uk_lang_mark;
    double design_inf_sys_mark;

}Sturdent;


void init_students(Sturdent students[], int count_of_students);
void print_students_with_debs(Sturdent students[], int count_of_students);
double average_mark_in_group(Sturdent students[], int count_of_students, int group);
double percent_of_students_with_well_best_mark(Sturdent students[], int count_of_students);
void subject_with_best_progress(Sturdent students[], int count_of_students);
int* worst_group(Sturdent students[], int count_of_students, int* worst_groups);
double average_mark_within_group(Sturdent students[], int count_of_students, int group);

int main(int argc, char const *argv[]){
    int count_of_students = 100;
    size_t length;
    
    Sturdent students [count_of_students];
    srand(time(NULL));
    init_students(students, count_of_students);
    
    /*for(int i =0; i < count_of_students; i++ ){
        printf("%i. %s\n", i+1, group1[i].surname );
    }*/
	
    print_students_with_debs(students, count_of_students);
    
    printf("\n\n\n-----percent_of_students_with_well_best_mark------ \n percent = %lf \n", percent_of_students_with_well_best_mark(students, count_of_students));
    
    printf("\n\n\n-----subject_with_best_progress--------\n");
    subject_with_best_progress(students, count_of_students);
    
    printf("\n\n\nThe worst groups");
    int* worst_groups =  worst_group(students, count_of_students, worst_groups);
    length = sizeof(worst_groups) / sizeof(int);
    
    for(int i=0; i<length; i++){
    	if(worst_groups[i]!=0){
        	printf("\n\tGroup: %d", worst_groups[i]);
        }
    }
    printf("\n");    
    return 0;
}

void init_students(Sturdent students[], int count_of_students){
    char name[12] = "Student";
    int i, j;
   
    for (i = 0; i < count_of_students; i++){
    	students[i].group = rand() % 4 + 1;
        students[i].design_inf_sys_mark = rand() % 90 + 10;
        students[i].uk_lang_mark = rand() % 90 + 10;
        students[i].web_mark = rand() % 90 + 10;
        
       	students[i].surname[0] = '\0';
       	for (j = 0; j < strlen(name); j++){
           students[i].surname[j] = name[j];
        }
        for (j = strlen(students[i].surname); j < 11; j++){
           students[i].surname[j] = rand()%(90 - 65) + 65;
        }
        students[i].surname[11] = '\0';
    }
}

void print_students_with_debs(Sturdent students[], int count_of_students){
    int count = 1, i;
    printf("\n\t\t--Debs--\n\n");
    for (i = 0; i < count_of_students; i++){
        if (students[i].design_inf_sys_mark < 50 || students[i].uk_lang_mark < 50|| students[i].web_mark <50){
            printf("\n\n%d. Surname : %s", count++, students[i].surname);
            if(students[i].uk_lang_mark < 50){
            	printf("\n\tuk_lang_mark: %0.2lf", students[i].uk_lang_mark);
            }
            if(students[i].design_inf_sys_mark < 50){
            	printf("\n\tdesign_inf_sys_mark: %0.2lf", students[i].design_inf_sys_mark);
            }
            if(students[i].web_mark < 50){
            	printf("\n\tweb_mark: %0.2lf", students[i].web_mark);
            }    
        }
    }
    printf("\n");
}


double percent_of_students_with_well_best_mark(Sturdent students[], int count_of_students){
    int count = 0, i;
    for (i = 0; i < count_of_students; i++){
    // mark from 70 to 89 - good
    // mark from 90 to 100 - well
        if (students[i].design_inf_sys_mark > 69 
            && students[i].uk_lang_mark > 69
            && students[i].web_mark > 69){
            count++;
        }
    }
    return (double)(count * 100) / count_of_students;
}

void subject_with_best_progress(Sturdent students[], int count_of_students){
    int i;
    double web_mark = 0;
    double uk_lang_mark = 0;
    double design_inf_sys_mark = 0;

    for (i = 0; i < count_of_students; i++){
        web_mark += students[i].web_mark;
        design_inf_sys_mark += students[i].design_inf_sys_mark;
        uk_lang_mark += students[i].uk_lang_mark;
    }
    if (uk_lang_mark >= design_inf_sys_mark 
        && uk_lang_mark >= web_mark){
        printf("uk_language has been passed the best way.\n");

    }else if (web_mark >= uk_lang_mark
        && web_mark >= design_inf_sys_mark){
        
        printf("web_design has been passed the best way.\n");
    }else{
        printf("design_inf_systems has been passed the best way.n");
    }  
}

int* worst_group(Sturdent students[], int count_of_students, int* worst_groups ){
    int i, groups_count = 4, the_worst_group_num = 1, the_worst_group_num_avg, counter=0;
    worst_groups =(int*) malloc(groups_count*sizeof(int));
    double avg_of_groups[groups_count];
   
    for	(i = 0 ; i<groups_count; i++){
    	 avg_of_groups[0] = average_mark_within_group(students,count_of_students,i+1);
    }
    the_worst_group_num_avg = avg_of_groups[0];
    for	(i = 0 ; i<groups_count-1; i++){
    	if(avg_of_groups[i] < the_worst_group_num_avg){
    	   the_worst_group_num_avg = avg_of_groups[i];
    	   the_worst_group_num = i+1;
	}
    }
    worst_groups[0] = the_worst_group_num;
    
    for	(i = 0 ; i < groups_count-1; i++){
    	if(avg_of_groups[i] == the_worst_group_num_avg){
    	   worst_groups[counter] = i+1;
    	   counter++;
	}
    }
    
    return worst_groups;
}

double average_mark_within_group(Sturdent students[], int count_of_students, int group){
    int count = 0;
    double sum = 0;

    for (size_t i = 0; i < count_of_students; i++){
        if (students[i].group == group){
            count++;
            sum += students[i].design_inf_sys_mark + 
            students[i].uk_lang_mark + students[i].web_mark;
        }
    }
    return sum / count;
}

