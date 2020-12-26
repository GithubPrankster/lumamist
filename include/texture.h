#pragma once
#include "vmath.h"

typedef struct{
	uint8_t* data;
	int width, height, comp;
}texture;

texture* texture_load(const char* path);
vec3 texture_sample(const texture* tex, float u, float v);
void texture_free(texture* tex);