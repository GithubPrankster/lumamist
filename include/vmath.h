#pragma once

#include <stdio.h>
#include <stdint.h>
#include <math.h>

float clamp(float d, float min, float max);

typedef struct{
	float x, y, z;
}vec3;
#define VEC3D(a, b, c) (vec3){a, b, c}

inline vec3 vec3_normalized(const vec3 v)
{
	float leninv = 1.f / sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
	return VEC3D(v.x * leninv, v.y * leninv, v.z * leninv);
}

inline vec3 vec3_add(const vec3 v0, const vec3 v1)
{
	return VEC3D(v0.x + v1.x, v0.y + v1.y, v0.z + v1.z);
}

inline vec3 vec3_mulf(const vec3 v, const float f)
{
	return VEC3D(v.x * f, v.y * f, v.z * f);
}

vec3 camera_ray(float x, float y, float width, float height, float fov);