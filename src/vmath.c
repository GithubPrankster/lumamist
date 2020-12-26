#include "vmath.h"

float clamp(float d, float min, float max) {
  const float t = d < min ? min : d;
  return t > max ? max : t;
}

vec3 camera_ray(float x, float y, float width, float height, float fov)
{
	float tanfov = tanf(fov / 2.f);
	float i = (2.f * (x + .5f) / width - 1.f) * tanfov * width / height;
	float j = -(2.f * (y + .5f) / height - 1.f) * tanfov;
	
	/* Optimized normalization */
	float leninv = 1.f / sqrtf(i * i + j * j + 1);
	return VEC3D(i * leninv, j * leninv, -1 * leninv);
}