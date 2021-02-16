#include <stdio.h>
#include <stdlib.h>

#include "corPadrao.h"
#include "extraInfoGeo.h"

typedef struct{
    FILE* fileSvgGeo;
    CorPadrao cores;
}ExtraInfoGeoStruct;

ExtraInfoGeo criaExtraInfoGeo(FILE* file, CorPadrao cores){
    ExtraInfoGeoStruct* eig = (ExtraInfoGeoStruct*)malloc(sizeof(ExtraInfoGeoStruct));
    eig->cores = cores;
    eig->fileSvgGeo = file;

    return eig;
}

FILE* extraInfoGetFileSvgGeo(ExtraInfoGeo extraInfoGeo){
    ExtraInfoGeoStruct* eig = (ExtraInfoGeoStruct*)extraInfoGeo;
    return eig->fileSvgGeo;
}

CorPadrao extraInfoGetCores(ExtraInfoGeo extraInfoGeo){
    ExtraInfoGeoStruct* eig = (ExtraInfoGeoStruct*)extraInfoGeo;
    return eig->cores;
}