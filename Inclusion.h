#pragma once

#include "Point.h"

namespace rez {

	// Return true if point [d] is inside the boundary of triangle defined by the points a, b, c
	bool isInside(Point3d& a, Point3d& b, Point3d& c, Point3d& d);

}