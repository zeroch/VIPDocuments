#ifndef SPACE2D_H
#define SPACE2D_H
#include "space.h"
#include "point2d.h"
#include <list>
#include <iostream>

class Space2D : public Space
{
public:
	Space2D();
	virtual ~Space2D();
	void add_point(Point2D*);	
	void initialSpace(int * raw, Point2D  start_, Point2D  end_, int * resolution);
	void printSpace();
private:
	std::list<Point2D *> *worldMap;
	/* data */
};


#endif // SPACE2D_H