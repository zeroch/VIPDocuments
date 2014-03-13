#include "space2d.h"

Space2D::Space2D(){
	std::cout << "here is new space" <<std::endl;
    worldMap = new std::vector<Point2D *> ;
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

void Space2D::initFromImage(char *filename){
    int cols, rows;
    m_rawImage = new QImage();
    m_rawImage->load(filename);
    rows = m_rawImage->width();
    cols = m_rawImage->height();
    maxValuePerDimension[0] = rows;
    maxValuePerDimension[1] = cols;
    
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            int coordinate[2] = { i , j };
            bool valid_;
            if(m_rawImage->pixelIndex(i,j) == 0){
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
    for (std::vector<Point2D *>::iterator it=worldMap->begin(); it != worldMap->end(); ++it){
    std::cout << ' ' << (*it)-> get_coordinate(0) << ',' << (*it)-> get_coordinate(1)<<std::endl;
    }
}

std::vector<Point *> Space2D::getNeighbors(Point * a){
    std::vector<Point *> neighbors;
    for(int x = -1; x < 2; x++){
        for(int y = -1; y < 2; y++){
            int xcoord = (a->get_coordinate(0) + x);
            int ycoord = a->get_coordinate(1) + y;
            bool xcoordInvalid = xcoord < 0 ||
                    xcoord > maxValuePerDimension[0];
            bool ycoordInvalid = ycoord < 0 ||
                    ycoord > maxValuePerDimension[1];
            bool bothInvalid = ycoord == a->get_coordinate(1) &&
                    xcoord == a->get_coordinate(0);
            if(!(xcoordInvalid || ycoordInvalid || bothInvalid)){
                int index = xcoord * maxValuePerDimension[0] + ycoord;
                neighbors.push_back((*worldMap)[index]);
            }
        }
    }
}

Point * Space2D::randomPoint(){
 //todo
    int x = (rand() % maxValuePerDimension[0]) * maxValuePerDimension[1];
    int y = rand() % maxValuePerDimension[1];
    return (*worldMap)[x+y];
}

Point * Space2D::findPoint(int* coordinates){
//todo
    int x = coordinates[0] * maxValuePerDimension[1];
    return (*worldMap)[x + coordinates[1]];
}

Point * Space2D::get_start(){
    return &start;
}

Point * Space2D::get_end(){
    return &end;
}

int Space2D::get_maxDimension(int dimension){
    return this->maxValuePerDimension[dimension];
}

int get_dimension(){
   return 2;
}
