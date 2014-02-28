#ifndef CONTROLLER_H
#define CONTROLLER_H
class Controller
{
public:
	Controller();
	~Controller();
	virtual void execute();
	virtual void pause();
	virtual void run();
	virtual void update(Path * newPath);
private:
	Path * currentPath;
	Point * currentPoint;
	Point * nextPoint;
};
#endif  // CONTROLLER_H
