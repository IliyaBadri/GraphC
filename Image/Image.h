#pragma once
#include "Canvas.h"
#include <fstream>
#include "../Console/StatusManager.h"

class Image {
private:
	int padding;
	int imageDataSize;
	std::vector<char> imageBytes;
	void WriteCharArray(char charArray[], int charArrayLength);
	void ReserveMemory();
	void WriteBitmapSignature();
	void IntToLittleEndianBytes(int integer, char littleEndianBytes[]);
	void WriteImageSize();
	void WriteZero();
	void WriteEndOfHeaderAddrases();
	void WriteWidthAndHeight();
	void WriteImageMetadataDetails();
	void WriteImageDataSize();
	void WritePixels();
public:
	Canvas canvas;
	Image(Canvas canvas);
	void BuildBytes();
	void Save();
};