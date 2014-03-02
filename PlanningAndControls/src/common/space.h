#ifndef SPACE_H
#define SPACE_H
#include "point.h"
class Space{
public:
	Space();
	virtual ~Space();
	virtual void add_point(Point *);
	virtual double distance(Point * x, Point * y);
	virtual Point * randomPoint();
	virtual void update();
	virtual Point * findPoint(int*);
	virtual int get_dimension();
	virtual Point get_start();
	virtual Point get_end();
	virtual bool get_updated();
	virtual int get_maxDimension(int demension);
	virtual void printSpace();
protected:
	int num_dimension;
	bool updated;
	Point  start;
	Point  end;
	int * maxValuePerDimension;
};
#endif // SPACE_H
