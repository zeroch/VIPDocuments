#ifndef POINT_H
#define POINT_H
class Point
{
public:
	Point();
	~Point();
	virtual int get_coordinate();
	virtual bool traversable();
	/* data */
private:
	bool travers;
	int num_dimemsion;
	int *coordinates;
};
#endif  // POINT_H
