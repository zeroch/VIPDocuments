#ifndef SPACE2D_H
#define SPACE2D_H
#include "space.h"
#include "point2d.h"
#include <vector>
#include <iostream>
#include <string.h>
extern "C"{
#include "pam.h"
}


class Space2D : public Space
{
public:
    Space2D();
	virtual ~Space2D();
	void add_point(Point2D*);
	void initialSpace(unsigned int ** raw, Point2D  start_, Point2D  end_, int * resolution);
	void initFromPgm(char*);
	void printSpace();
    Point * randomPoint();
    Point * findPoint(int*);
    int get_maxDimension(int dimension);
    Point * get_start();
    Point * get_end();
    std::vector<Point *> getNeighbors(Point *);
private:
    std::vector<Point2D *> *worldMap;
	/* data */
};


#endif // SPACE2D_H
