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

