#ifndef __QRY2_H
#define __QRY2_H

#include "quadTree.h"

void dq(QuadTree* qt, char* id, float r, int hashtag, FILE* fileTxt);

void del(QuadTree* qt, char* id, FILE* fileTxt);

void cbq(QuadTree* qt, float x, float y, float r, char* cstrk, FILE* fileTxt);

void crd(QuadTree* qt, char* id, FILE* fileTxt);

void car(QuadTree* qt, float x, float y, float w, float h, FILE* fileTxt);

#endif