#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "color.h"
#include "vmath.h"
#include "texture.h"

static vec3 ray_col(const vec3 vec, const texture* tex)
{
	float u = (atan2f(-vec.z, vec.x) + M_PI) / (2 * M_PI);
	float v = acosf(-vec.y) / M_PI;
	
	u = 1.f - clamp(u, .0f, 1.f);
	v = clamp(v, .0f, 1.f);
	
	vec3 col = texture_sample(tex, u, v);
	
	return col;
}

int main(void)
{
	texture* panorama = texture_load("assets/panorama.png");
	
	const unsigned width = 1280, height = 720;
	rgb *img = malloc(sizeof(rgb) * width * height);
	for(unsigned x = 0; x < width; ++x){
		for(unsigned y = 0; y < height; ++y){
			vec3 cam = camera_ray(x, y, width, height, M_PI / .4f);
			img[x + y * width] = vec3_rgb(ray_col(cam, panorama));
		}
	}
	stbi_write_png("gamer.png", width, height, sizeof(rgb), img, sizeof(rgb) * width);
	free(img);
	texture_free(panorama);
	return 0;
}