#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "utilitario.h"


int insideCirculo(float x, float y, float cx, float cy, float r){
    return (distanciaQuadrada(x, y, cx, cy) < r * r ? 1 : 0);
}

int insideRetangulo(float x, float y, float rx, float ry, float rw, float rh){
    if((x == rx || x == rx+rw) || (y == ry || y == ry + rh)){
        return 2;
    }
    return ((x > rx && x < rx + rw) && (y > ry && y < ry + rh) ? 1 : 0);
}

float distanciaQuadrada(float x1, float  y1, float  x2, float  y2){
    return ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
}

float distanciaEntrePontos(float x1, float  y1, float  x2, float  y2){
    double result = sqrt((double) ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
    return result;
}


int min(int a, int b){
    return ((a < b) ? a : b);
}

int max(int a, int b){
    return ((a > b) ? a : b);
}


float minF(float a, float b){
    return ((a < b) ? a : b);
}

float maxF(float a, float b){
    return ((a > b) ? a : b);
}


float minV(float v[], int tamanho){
    float min = v[0];
    for(int i = 1; i < tamanho; i++){
        if(min > v[i]){
            min = v[i];
        }
    }
    return min;
}

float maxV(float v[], int tamanho){
    float max = v[0];
    for(int i = 1; i < tamanho; i++){
        if(max < v[i]){
            max = v[i];
        }
    }
    return max;
}
