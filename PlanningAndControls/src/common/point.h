#ifndef POINT_H
#define POINT_H
class Point
{
public:
	Point();
	Point(int num_d) : num_dimemsion(num_d) {};
	virtual ~Point();
	
	void set_dimemsion(int num_d);
	int get_dimemsion();

	virtual void set_coordinate(int *_coordinates);
	virtual int get_coordinate(int x_coor);

	void set_valid(bool valid_);
	bool valid();
	/* data */
protected:
	bool traversable;
	int num_dimemsion;
	int * coordinates;
};
#endif  // POINT_H
