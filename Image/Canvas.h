#pragma once

#include <vector>
#include <unordered_map>
#include "Pixel.h"

class Canvas {
public:
	int width;
	int height;
	std::unordered_map<int, std::unordered_map<int, Color>> pixelMap;
	Canvas();
	Canvas(int width, int height);
	void AddPixel(Pixel pixel);
};