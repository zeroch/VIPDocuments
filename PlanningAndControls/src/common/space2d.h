#ifndef SPACE2D_H
#define SPACE2D_H
#include "space.h"
#include "point2d.h"
#include <vector>
#include <iostream>
#include <string.h>
#include <QImage>
#include <QObject>
class Space2D :  public QObject, public Space
{
    Q_OBJECT
public:
    Space2D();
	virtual ~Space2D();
	void add_point(Point2D*);
	void initialSpace(unsigned int ** raw, Point2D  start_, Point2D  end_, int * resolution);
    void initFromImage(char*);
	void printSpace();
    Point * randomPoint();
    Point * findPoint(int*);
    int get_maxDimension(int dimension);
    Point * get_start();
    Point * get_end();
    std::vector<Point *> getNeighbors(Point *);
private:
    std::vector<Point2D *> *worldMap;
    int maxValuePerDimension[2];
    QImage *m_rawImage;
    /* data */
};


#endif // SPACE2D_H
