#ifndef SPACE_H
#define SPACE_H
class Space{
public:
	Space();
	~Space();
	virtual double distance(Point * x, Point * y);
	virtual Point * randomPoint();
	virtual void update();
	virtual Point * findPoint(int*);
	virtual maxVal(int Dimension);
	int getDimension();
	Point getStart();
	Point getEnd();
	bool getUpdated();
	virtual int getMaxDimension(int demension);
private:
	int num_dimension;
	bool updated;
	Point * start;
	Point * end;
	int * maxValuePerDimension;
};
#endif // SPACE_H
