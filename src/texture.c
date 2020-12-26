#include "texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

texture* texture_load(const char* path)
{
	texture* texel = malloc(sizeof(texture));
	stbi_set_flip_vertically_on_load(1);
	texel->data = stbi_load(path, &texel->width, &texel->height, &texel->comp, 0);
	return texel;
}

vec3 texture_sample(const texture* tex, float u, float v)
{
	int i = (int)(u * tex->width);
	int j = (int)(v * tex->height);
	
	i = i >= tex->width ? tex->width - 1 : i;
	j = j >= tex->height ? tex->height - 1 : j;
	
	return (vec3){
		tex->data[tex->comp * (i + j * tex->width)] / 255.999f,
		tex->data[tex->comp * (i + j * tex->width) + 1] / 255.999f,
		tex->data[tex->comp * (i + j * tex->width) + 2] / 255.999f,
	};
}

void texture_free(texture* tex)
{
	stbi_image_free(tex->data);
	free(tex);
}