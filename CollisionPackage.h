/**
 * @class CollisionPackage
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @dateBuilt  3/18/2021
 * @lastEdit 3/21/2021
 */

#ifndef COLLISION_PACKAGE_H
#define COLLISION_PACKAGE_H
#include <iostream>
#include <vector>

class PointF
{
public:
	float x;
	float y;
	PointF()
	{
		this->x = 0;
		this->y = 0;
	}
	PointF(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	~PointF() = default;
};

static int collisionPackageObjectCount = 0;
typedef long double ld;

class CollisionPackage
{
	static auto countIncrease() { collisionPackageObjectCount += 1; }
	static auto countDecrease() { collisionPackageObjectCount -= 1; }
public:

	/// <summary>
	/// The facing angle allows is used to calculate the
	/// current world coordinates of each vertex using
	///	the model - space coordinates in vertexList.
	/// </summary>
	float facingAngle;

	std::vector<PointF> vertexList;
	//sf::Vector2f* vertexList;

	int vertexListLength;

	PointF worldLocation;

	float radius;

	PointF* currentPoint;
	PointF* currentPoint2;

	CollisionPackage() {
		facingAngle = 0.0;
		vertexListLength = 0;
		worldLocation = PointF(0, 0);
		radius = 0;
		currentPoint = nullptr;
		currentPoint2 = nullptr;
	}

	CollisionPackage(
		std::vector<PointF> vertexList,
		PointF worldLocation,
		float radius,
		float facingAngle)
	{
		this->vertexListLength = vertexList.size();
		this->vertexList = vertexList;
		for (int i = 0; i < vertexListLength; i++)
		{
			this->vertexList[i].x = vertexList[i].x;
			this->vertexList[i].y = vertexList[i].y;
		}
		this->worldLocation = worldLocation;
		this->radius = radius;
		this->facingAngle = facingAngle;
		currentPoint = nullptr;
		currentPoint2 = nullptr;

		countIncrease();
	}

	/**
	 * @brief copy constructor
	 */
	CollisionPackage(const CollisionPackage& t)
	{
		vertexList = t.vertexList;
		vertexListLength = t.vertexListLength;
		worldLocation = t.worldLocation;
		radius = t.radius;
		facingAngle = t.facingAngle;
		currentPoint = t.currentPoint;
		currentPoint2 = t.currentPoint2;
		countIncrease();
	}
	/**
	 * #brief move constructor
	 */
	CollisionPackage(CollisionPackage&& t) noexcept
	{
		vertexList = t.vertexList;
		vertexListLength = t.vertexListLength;
		worldLocation = t.worldLocation;
		radius = t.radius;
		facingAngle = t.facingAngle;
		currentPoint = t.currentPoint;
		currentPoint2 = t.currentPoint2;
		countIncrease();
	}
	/**
	 * @brief copy assignment operator
	 */
	CollisionPackage& operator=(CollisionPackage&& t) noexcept
	{
		if (this != &t)
		{
			countIncrease();
		}
		return *this;
	}

	CollisionPackage& operator=(CollisionPackage other)
	{
		return *this;
	}

	static void show_objectCount() {
		std::cout << "\n collision package object count: "
			<< collisionPackageObjectCount << std::endl;
	}
	static int get_objectCount() { return collisionPackageObjectCount; }


	~CollisionPackage() = default;


};
#endif


