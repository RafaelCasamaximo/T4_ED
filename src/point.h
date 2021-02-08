#ifndef __POINT_H 
#define __POINT_H

typedef void* Point;

//Cria point
Point criaPoint(float x, float y);

//Getters e Setters
float getPointX(Point point);

float getPointY(Point point);

void setPointX(Point point, float x);

void setPointY(Point point, float y);

#endif 
