#ifndef USERINPUT_H
#define USERINPUT_H

class UserInput
{
public:
	virtual void updateGoal(Point new_goal);
	virtual void updateStart(Point new_start);
	virtual void pushObstacle(Point * obstacle);
	virtual void popObstacle(Point * obstacle);
	virtual void updateMap();
	virtual void debugCommand();
private:
	Space * world_map;
};

#endif  // USERINPUT_H
