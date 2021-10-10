#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#include "point.h"

Point* generate_space_of_points(int length){
	int i;
	Point* point_space = (Point*)malloc(length * sizeof(Point));
	srand(time(NULL));
	for (i=0; i < length; i++){
		point_space[i].x = ((float)rand()/(float)(RAND_MAX)) * 10.0 - 5.0;
		point_space[i].y = ((float)rand()/(float)(RAND_MAX)) * 10.0 - 5.0;
		point_space[i].mass = ((float)rand()/(float)(RAND_MAX)) * 4.0;
	}
	return point_space;
}

void print_space_of_points(Point* point_space,  int length){
	int i; 
	printf("\n");	
	for (i=0; i < length; i++){
		printf("a[%d]: ( %0.3f ; %0.3f )  mass = %f \n",i, point_space[i].x, point_space[i].y, point_space[i].mass );
	}
}

Point* resize_space_of_points(Point* array, Point* buf, int length){
	int i;
	int flag = 0;
	for(i =0; i<length-1; i++){
		if(flag == 0  && array[i].mass != 0) continue;
		else {
			if(flag == 0 ){
				flag = 1;
			}
			array[i].x = array[i+1].x;
			array[i].y = array[i+1].y;
			array[i].mass = array[i+1].mass;
		}
	}
	
	buf = array;     
	int next_size = length -1;
    	if((array = (Point*)realloc(array, next_size * sizeof(Point))) ==  NULL ){
		free( buf );  // free original block
		exit( 1 );
	}
	return array;
}
int find_min_mass_id(Point* array, int length){
	int i, tmp, min_id;
	tmp=array[0].mass;
	min_id = 0;
	for (i = 0; i < length; i++){
		if(array[i].mass < tmp){
			tmp = array[i].mass;
			min_id = i;	
		}	
	}
	return min_id;
}

int find_min_path_id(Point* array, int length, int point_id){
	int i, min_dist, min_id;
	int check = 0;
	if(point_id != 0){
		min_dist = sqrt(pow((array[point_id].x - array[0].x),2) + pow((array[point_id].y - array[0].y),2));
		min_id = 0;
	} else {
		min_dist = sqrt(pow((array[point_id].x - array[1].x),2) + pow((array[point_id].y - array[1].y),2));
		min_id = 1;
		check = 1;
	}

	for (i = 0; i < length; i++){
		if(check == 0 && i == 0) continue;
		if(check == 1 && i == 1) continue;
		if(point_id != i){
			if(sqrt(pow((array[i].x - array[point_id].x),2) + pow((array[i].y - array[point_id].y),2)) < min_dist){
				min_dist = sqrt(pow((array[i].x - array[point_id].x),2) + pow((array[i].y - array[point_id].y),2));
				min_id = i;
			}
		}	
	}
	return min_id;
}
