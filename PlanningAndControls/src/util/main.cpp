

#include <iostream>
#include <array>
#include "../common/space2d.h"
#include "../common/point2d.h"

int main(int argc, char  *argv[])
{
    int  start_arr [] = {120,75};
    Point2D start_point(start_arr, false);
    int  end_arr [] = {180,75};
    Point2D end_point(end_arr, false);

    std::cout << "hello world!" << std::endl;
    std::cout << "this point is "<< start_point.get_coordinate(0) << std::endl;
    Space2D  * my_space = new Space2D();    

    // test to read pgm
    char *filename="../pic/circular_map.pgm";
    my_space->initFromPgm(filename);
    my_space->printSpace();
	/* code */
    return 0;
}
