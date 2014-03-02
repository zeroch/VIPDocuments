#include "point.h"

Point::Point(){
	traversable = false;
	num_dimemsion = 0;

}
Point::~Point(){
	
}
void Point::set_dimemsion(int num_d){
	num_dimemsion = num_d;
}
int Point::get_dimemsion(){
	return num_dimemsion;
}

void Point::set_coordinate(int *_coordinates){
	for (int i = 0; i < num_dimemsion; ++i)
	{
		*(coordinates+i) = *(_coordinates+i);
	}
}
int Point::get_coordinate(int x_coor){
	return coordinates[x_coor];
}
void Point::set_valid(bool valid_){
	traversable = valid_;
}
bool Point::valid(){
	return traversable;
}

