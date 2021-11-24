#pragma once
#include <vector>
#include "Point.h"
#include "Polygon.h"
#include "Bounds.h"

// Implementation of Voronoi diagram calculation and related utility functions.
namespace rez
{
	// Compute the voronoi diagram nively using halfplane intersection
	void constructVoronoiDiagram_halfplaneIntersection(std::vector<Point2d>&);

	// Compute the voronoi diagram using fortune's algorithm
	void constructVoronoiDiagram_fortunes(std::vector<Point2d>&, std::vector<Edge2dSimple>&, BoundRectangle& rect);
}