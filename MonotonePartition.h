#pragma once

#include <vector>
#include "Vector.h"
#include "PolygonDCEL.h"
#include "GeoUtils.h"

namespace rez {
	void get_monotone_polygons(Polygon2d* poly, std::vector<Polygon2d*>& mono_polies);
}