#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "path.h"
#include "space.h"
class Algorithm
{
public:
    Algorithm(Space * problem, int deltaq = 1);
	~Algorithm();
	virtual void run();
	virtual void pause();
	virtual void stop();
	virtual void runUntil();
    virtual Path * pathGenerated();
	virtual Path * areaExplored();
protected:
	Space * all_points;
	double deltaq;

};
#endif  // ALGORITHM_H
