#include <queue>
#include "point.h"

class Path
{
public:
	Path();
	~Path();
	virtual void trimPath();
	/* data */
private:
	Point * start;
	Point * end;
	std::queue<Point*> * path;
	
};
