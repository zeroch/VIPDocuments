#include "space2d.h"

Space2D::Space2D(){
	std::cout << "here is new space" <<std::endl;
}
Space2D::~Space2D(){

}
void Space2D::initialSpace(int * raw, Point2D  start_, Point2D  end_, int * resolution){
	num_dimension = 2;
	updated = false;
	memcpy(maxValuePerDimension,resolution,2*(sizeof(int)));
	int x = *resolution;
	int y = *(resolution+1);
	int start_x = start_.get_coordinate(0);
	int start_y = start_.get_coordinate(1);	
	int end_x = end_.get_coordinate(0);
	int end_y = end_.get_coordinate(1);

	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < y; ++j)
		{
			int coordinate[2] = { i , j };
			Point2D * new_point = new Point2D(coordinate, *(raw+i*x+j));
			worldMap->push_back(new_point);
		}
	}

	start = start_;
	end  = end_;

}

void Space2D::add_point(Point2D * new_point){
	std::cout << "new point" << std::endl;
	Point2D *point_ = new Point2D(new_point->get_coordinates(), new_point->valid());
	std::cout << "new point generated" << std::endl;
	std::cout << point_->get_coordinate(0) <<','<< point_->get_coordinate(1) << std::endl;

	worldMap->push_back(point_);
	std::cout << "new point push back to space" << std::endl;

}

void Space2D::printSpace(){
	std::cout << "worldMap contains:";
  	for (std::list<Point2D *>::iterator it=worldMap->begin(); it != worldMap->end(); ++it)
    std::cout << ' ' << (*it)-> get_coordinate(0) << (*it)-> get_coordinate(1)<<std::endl;;


}

