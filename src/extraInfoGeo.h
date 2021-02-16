#ifndef __EXTRAINFOGEO_H
#define __EXTRAINFOGEO_H

#include "corPadrao.h"

typedef void* ExtraInfoGeo;

ExtraInfoGeo criaExtraInfoGeo(FILE* file, CorPadrao cores);
FILE* extraInfoGetFileSvgGeo(ExtraInfoGeo extraInfoGeo);
CorPadrao extraInfoGetCores(ExtraInfoGeo extraInfoGeo);

#endif