#pragma once
#include "vmath.h"

typedef struct{
	uint8_t r, g, b;
}rgb;
#define RGBD(r, g, b) (rgb){r, g, b}

inline rgb vec3_rgb(const vec3 v)
{
	return RGBD(v.x * 255.999f, v.y * 255.999f, v.z * 255.999f);
}
