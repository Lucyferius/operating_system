#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "functions.h"

double factorial(double x){
    double sum = 1;
    int i = 1;
    for (i = 1; i <= x; i++){
        sum *= i;
    }
    return sum;
}

double compute_sin(double x,double eps){
    double current = 1, sum = 0;
    int i = 0, degree = 0;
    while( abs(current) > eps ){
    	degree = 2*i + 1;
    	current = pow(-1,i) * pow(x, degree) / factorial (degree);
    	sum += current;
	}
    return sum;
}

double compute_cos(double x, double eps){
    double current = 1, sum = 0;
    int i = 0, degree = 0;
    while( abs(current) > eps ){
    	degree = 2*i;
    	current = pow(-1,i) * pow(x, degree) / factorial (degree);
    	sum += current;
	}
    return sum;
}

double compute_length_of_segment(double x1, double y1, double x2, double y2){
    return sqrt(pow((x2 - x1),2) + pow((y2 - y1), 2)) ;
}



