/**
 * @class RectangularPrism
 * @details rectangularPrism class that represents a rectangular prism object
 * @author Ryan Zurrin
 * @dateBuilt  11/4/2021
 * @lastEdit 11/4/2021
 */

#ifndef RECTANGULAR_PRISM_H
#define RECTANGULAR_PRISM_H
#include <iostream>


static int rectangularPrismObjectCount = 0;
typedef long double ld;

class RectangularPrism
{
	ld lenght;
	ld width;
	ld height;
	ld volume;
	ld surfaceArea;
	static auto countIncrease() { rectangularPrismObjectCount += 1; }
	static auto countDecrease() { rectangularPrismObjectCount -= 1; }
	ld calculateVolume()const;
	ld calculateSurfaceArea()const;
public:

	RectangularPrism()
	{
		lenght = 0.0;
		width = 0.0;
		height = 0.0;
		volume = 0.0;
		surfaceArea = 0.0;
		countIncrease();
	}

	RectangularPrism(ld length, ld width, ld height)
	{
		this->lenght = length;
		this->width = width;
		this->height = height;
		this->volume = calculateVolume();
		this->surfaceArea = calculateSurfaceArea();
		countIncrease();
	}

	/**
	 * @brief copy constructor
	 */
	RectangularPrism(const RectangularPrism& s)
	{
		lenght = s.lenght;
		width = s.width;
		height = s.height;
		volume = s.volume;
		surfaceArea = s.surfaceArea;
		countIncrease();
	}
	/**
	 * #brief move constructor
	 */
	RectangularPrism(RectangularPrism&& s) noexcept
	{
		lenght = s.lenght;
		width = s.width;
		height = s.height;
		volume = s.volume;
		surfaceArea = s.surfaceArea;
		countIncrease();
	}
	/**
	 * @brief copy assignment operator
	 */
	RectangularPrism& operator=(RectangularPrism&& s) noexcept
	{
		if (this != &s)
		{
			lenght = s.lenght;
			width = s.width;
			height = s.height;
			volume = s.volume;
			surfaceArea = s.surfaceArea;
			countIncrease();
		}
		return *this;
	}

	RectangularPrism& operator=(RectangularPrism other)
	{
		std::swap(lenght, other.lenght);
		std::swap(width, other.width);
		std::swap(height, other.height);
		std::swap(volume, other.volume);
		std::swap(surfaceArea, other.surfaceArea);
		return *this;
	}

	static void show_objectCount() {
		std::cout << "\n rectangle object count: "
			<< rectangularPrismObjectCount << std::endl;
	}
	static int get_objectCount() { return rectangularPrismObjectCount; }


	~RectangularPrism() = default;

	auto setWidth(ld w);
	auto setLength(ld l);
	auto setHeight(ld h);

	[[nodiscard]] auto getWidth() const { return width; }
	[[nodiscard]] auto getLength() const { return lenght; }
	[[nodiscard]] auto getHeight() const { return height; }
	[[nodiscard]] auto getVolume() const { return volume; }
	[[nodiscard]] auto getSurfaceArea() const { return surfaceArea; }

	void printRectangularPrismInfo()const;
};

#endif

inline ld RectangularPrism::calculateVolume() const
{
	return lenght * width * height;
}

inline ld RectangularPrism::calculateSurfaceArea() const
{
	return 2.0 * (lenght * width) + 2.0 * (lenght * height) + 2.0 * (width * height);
}

inline auto RectangularPrism::setWidth(ld w)
{
	width = w;
	surfaceArea = calculateSurfaceArea();
	volume = calculateVolume();
	
}

inline auto RectangularPrism::setLength(ld l)
{
	lenght = l;
	surfaceArea = calculateSurfaceArea();
	volume = calculateVolume();
}

inline auto RectangularPrism::setHeight(ld h)
{
	height = h;
	surfaceArea = calculateSurfaceArea();
	volume = calculateVolume();
}

inline void RectangularPrism::printRectangularPrismInfo() const
{
	std::cout << "length:    "	  << lenght << std::endl;
	std::cout << "width:     "	  << width << std::endl;
	std::cout << "height:  "	  << height << std::endl;
	std::cout << "volume: "		  << volume << std::endl;
	std::cout << "surface area: " << surfaceArea << std::endl;
}
