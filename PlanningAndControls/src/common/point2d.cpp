#include "point2d.h"
Point2D::Point2D(){
	num_dimemsion = 2;
}
Point2D::~Point2D(){
	
}

Point2D::Point2D(int * coordinate_, bool traversable_){
	
	num_dimemsion = 2;
	traversable = traversable_;
	for (int i = 0; i < 2; ++i)
	{
		coordinates[i]= *(coordinate_+i);
	}

}
Point2D::Point2D(std::array<int ,2> coordinate_, bool traversable_){
	num_dimemsion = 2;
	traversable = traversable_;
	coordinates = coordinate_;

}

void Point2D::set_coordinate(int *coordinates_){
	for (int i = 0; i < 2; ++i)
	{
		coordinates[i]= *(coordinates_+i);
	}
}

//return which dimemsion coordinate
int Point2D::get_coordinate(int x_coor){
	return coordinates[x_coor];
}
std::array<int,2> Point2D::get_coordinates(){
	return coordinates;
}

bool Point2D::valid(){
	return traversable;
}