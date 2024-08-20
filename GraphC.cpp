#include "GraphC.h"

int MathFunction(int x) {
	double xDouble = x;

	return (int)(30 * ((xDouble - 512) / 100) * ((xDouble - 512) / 100));
}

int main()
{
	int imageWidth = 1024;
	Canvas imageCanvas(imageWidth, imageWidth);
	Color blueColor = Color(255, 0, 0);
	StatusManager::SetStatus("Processing math function . . .");
	for (int x = 0; x < imageWidth; x++) {
		int y = MathFunction(x);
		Pixel pixel = Pixel(x, y, blueColor);
		imageCanvas.AddPixel(pixel);
	}
	Image image(imageCanvas);

	StatusManager::SetStatus("Processing image . . .");
	image.BuildBytes();

	StatusManager::SetStatus(" Saving image . . .");
	image.Save();
	StatusManager::SetProgress(1, 1);
	return 0;
}

