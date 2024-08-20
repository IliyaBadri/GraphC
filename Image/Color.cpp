#include "Color.h"

void Color::Clamp() {
	if (red < 0) {
		red = 0;
	}
	if (red > 255) {
		red = 255;
	}
	if (green < 0) {
		green = 0;
	}
	if (green > 255) {
		green = 255;
	}
	if (blue < 0) {
		blue = 0;
	}
	if (blue > 255) {
		blue = 255;
	}
}

