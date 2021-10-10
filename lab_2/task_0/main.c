#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <malloc.h>

#include "point.h"

int main(){
	int length = 10;
	int step = 1;
	int count_of_points = length;
	Point* point_space;
	Point* buffer;
	int min_mass_id, min_path_id;
	
	printf("Inital space of points\n");
	point_space = generate_space_of_points(length);
	if(point_space == NULL) 
		exit(1);
	print_space_of_points(point_space, length);
	
	while(count_of_points > 1){
		printf("\nStep %d", step );
		min_mass_id = find_min_mass_id(point_space, count_of_points);
		min_path_id = find_min_path_id(point_space,count_of_points, min_mass_id);
		
		point_space[min_path_id].mass = point_space[min_mass_id].mass + point_space[min_path_id].mass;
		
		printf("\n--info min_mass_id = %d,  min_path_id = %d",min_mass_id, min_path_id);
		printf("\n--info point_space[min_path_id].mass = %f\n",  point_space[min_path_id].mass);
		
		count_of_points--;
		
		point_space[min_mass_id].mass = 0;
		point_space = resize_space_of_points(point_space, buffer, length);
		
		print_space_of_points(point_space, count_of_points);
		step++;
	}	
	return 0;
}
