#include "Vector.h"

float rez::crossProduct2D(Vector2f v1, Vector2f v2)
{
	return v1[X] * v2[Y] - v1[Y] * v2[X];
}

rez::Vector3f rez::crossProduct3D(Vector3f v1, Vector3f v2)
{
	float x_, y_, z_;
	x_ = v1[Y] * v2[Z] - v1[Z] * v2[Y];
	y_ = -(v2[Z] * v1[X] - v1[Z] * v2[X]);
	z_ = v1[X] * v2[Y] - v2[X] * v1[Y];
	return Vector3f(x_, y_, z_);
}

