#ifndef ALGORITHM_H
#define ALGORITHM_H

class Algorithm
{
public:
	Algorithm();
	~Algorithm();
	virtual void run();
	virtual void pause();
	virtual void stop();
	virtual void runUntil();
	virtual Path pathGenerated();
	virtual Path * areaExplored();
private:
	Space * all_points;
	double deltaq;

};
#endif  // ALGORITHM_H
