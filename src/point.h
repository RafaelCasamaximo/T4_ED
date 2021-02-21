#ifndef __POINT_H 
#define __POINT_H

typedef void* Point;

//Create
Point criaPoint(float x, float y);

//Getters
float getPointX(Point point);
float getPointY(Point point);

//Setters
void setPointX(Point point, float x);
void setPointY(Point point, float y);

void atribuirPonto(Point p1, Point p2);

#endif 
