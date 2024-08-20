#include "Canvas.h"

Canvas::Canvas() {
	this->width = 1;
	this->height = 1;
}

Canvas::Canvas(int width, int height) {
	if (width <= 0) {
		width = 1;
	}
	if (height <= 0) {
		height = 1;
	}
	this->width = width;
	this->height = height;
}

void Canvas::AddPixel(Pixel pixel) {
	if (
		pixel.coordinateX < 0 ||
		pixel.coordinateY < 0 ||
		pixel.coordinateX >= width ||
		pixel.coordinateY >= height
		) {
		return;
	}
	pixel.color.Clamp();
	pixelMap[pixel.coordinateX][pixel.coordinateY] = pixel.color;
}
