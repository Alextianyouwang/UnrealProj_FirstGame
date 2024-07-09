#pragma once
#include "DrawDebugHelpers.h"
#define DRAW_SPHERE(L,S,C) if (GetWorld()) DrawDebugSphere(GetWorld(),L,S, 24, C, true);
#define DRAW_LINE(S,E,L,C) if (GetWorld()) DrawDebugLine(GetWorld(), S,E,C,true,-1.f,0,1.f);
#define DRAW_POINT(L,C) if (GetWorld()) DrawDebugPoint(GetWorld(),L,15.f,C,true,-1.f,0);