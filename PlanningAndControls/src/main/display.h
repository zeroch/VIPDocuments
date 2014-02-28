#ifndef DISPLAY_H
#define DISPLAY_H
class Display
{
public:
	Display();
	~Display();
	virtual void renderMap();
	virtual void renderPath();
	virtual void run();
private:
	Space * world_map;
	Path * currentPath;
	Path * areaExplored;
	Point * start;
	Point * end;
};
#endif  // DISPLAY_H
