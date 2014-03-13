#include "space.h"

Space::Space(){

}
Space::~Space(){

}
double Space::distance(Point * x, Point * y){
    //Eucledian Distance generalized for N Dimensions
    int dimensionality = x->get_dimemsion();
    //Assuming both points have the same number of dimensions
    double distance = 0;
    //iterates through every dimension adding the square of the distance between the two point
    //on that dimension
    for(int dim = 0 ; dim < dimensionality ; dim++){
        double dim_distance = x->get_coordinate(dim) - y->get_coordinate(dim);
        distance += std::pow(dim_distance,2);
    }
    distance = std::sqrt(distance);
    return distance;
}
Point * Space::randomPoint(){

}
void Space::update(){

}
Point * Space::findPoint(int*){

}
void Space::add_point(Point *){

}

int Space::get_dimension(){
	return num_dimension;
}

Point * Space::get_start(){
    return &start;
}

Point * Space::get_end(){
    return &end;
}

bool Space::get_updated(){
	return updated;
}
int Space::get_maxDimension(int dimension){

}
void Space::printSpace(){

}
std::vector<Point *> Space::getNeighbors(Point * a){

}



