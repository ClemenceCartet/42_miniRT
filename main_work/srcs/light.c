#include <mini_rt.h>

float diff = max(dot(norm, lightDir), 0.0); // renvoie la valeure la plus grande
vec3 diffuse = diff * lightColor;

vec3 result = (ambient + diffuse) * objectColor;