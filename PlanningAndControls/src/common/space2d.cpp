#include "space2d.h"

Space2D::Space2D(){
	std::cout << "here is new space" <<std::endl;
	worldMap = new std::list<Point2D *> ;
}
Space2D::~Space2D(){

}
void Space2D::initialSpace(unsigned int ** raw, Point2D  start_, Point2D  end_, int * resolution){
	num_dimension = 2;
	updated = false;
	int x = *resolution;
	int y = *(resolution+1);

	maxValuePerDimension[0] = x;
	maxValuePerDimension[1] = y;

	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < y; ++j)
		{
			int coordinate[2] = { i , j };
			bool valid_;

			if(raw[i][j] == 0){
				valid_ = true;
			}else valid_ = false;

			Point2D * new_point = new Point2D(coordinate, valid_);
			worldMap->push_back(new_point);
		}
	}

	start = start_;
	end  = end_;

}
void Space2D::initFromPgm(char *filename){
    gray **image;
    gray max;
    int cols, rows;

    FILE *file = pm_openr(filename);
    image = pgm_readpgm(file, &cols, &rows, &max);
    maxValuePerDimension[0] = rows;
    maxValuePerDimension[1] = cols;
    
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            int coordinate[2] = { i , j };
            bool valid_;
            if(image[i][j] == 0){
                valid_ = true;
            }else valid_ = false;
            Point2D * new_point = new Point2D(coordinate, valid_);
            worldMap->push_back(new_point);
        }
    }
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
    for (std::list<Point2D *>::iterator it=worldMap->begin(); it != worldMap->end(); ++it){
    std::cout << ' ' << (*it)-> get_coordinate(0) << ',' << (*it)-> get_coordinate(1)<<std::endl;
    }
}

