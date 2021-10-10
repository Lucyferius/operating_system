#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "functions.h"

double curve_function(double x, double eps){
    return pow(compute_sin(x, eps),2) / (1+ pow(compute_cos(x,eps),3));
}

int main(){
    
    printf("Start computing... 1");
    double eps = 0.00001;
    int i;
	// interval of curve computation -> [a, b]
    double a = -10 , b = 20;
    // number of curve splits
	int count_of_segments = 50;
	
    double result, current_y, current_x = a, next_y, next_x;

    double step = (double)((b - a) / count_of_segments); 
    
    printf("Start computing...");
    
    current_y = curve_function(current_x, eps);
	
    for (i = 0; i < count_of_segments; i++, current_x +=step ){
    	next_x = current_x + step;
    	next_y = curve_function(next_x, eps);
        result += compute_length_of_segment(current_x, current_y, next_x, next_y);
        current_y = next_y;
    }
    
    printf("Length of curve : %lf\n", result);
    
    return 0;
}


