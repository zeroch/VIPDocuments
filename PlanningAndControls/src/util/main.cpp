

#include <iostream>
#include <array>
#include "../common/space2d.h"
#include "../common/point2d.h"

int main(int argc, char const *argv[])
{
    int  arr [] = {1,2};
    Point2D new_point(arr, false);
    std::cout << "hello world!" << std::endl;
    std::cout << "this point is "<< new_point.get_coordinate(0) << std::endl;
    Space2D  * my_space = new Space2D();
    my_space->add_point(&new_point);
   
	/* code */
	return 0;
}