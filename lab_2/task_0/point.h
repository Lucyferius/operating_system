#ifndef POINT_H_  
#define POINT_H_
 
typedef struct Point{
	float x;
	float y;
	float mass;
}Point;

int find_min_mass_id(Point* array, int length);
int find_min_path_id(Point* array, int length, int point_id);
Point* generate_space_of_points(int length);
void print_space_of_points(Point* point_space,  int length);
Point* resize_space_of_points(Point* array, Point* buf, int length);


#endif // POINT_H_
