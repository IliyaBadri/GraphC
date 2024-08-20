#include "Image.h"

Image::Image(Canvas canvas) {
	this->canvas = canvas;

    padding = 4 - ((canvas.width * 3) % 4);

    if (padding == 4) {
        padding = 0;
    }

    imageDataSize = canvas.height * ((canvas.width * 3) + padding);
}

void Image::WriteCharArray(char charArray[], int charArrayLength) {
    for (int i = 0; i < charArrayLength; i++) {
        imageBytes.push_back(charArray[i]);
    }
}

void Image::ReserveMemory() {
    int bitmapHeaderSize = 53;

    imageBytes.reserve(bitmapHeaderSize + imageDataSize);
}

void Image::WriteBitmapSignature() {
    char bitmapSignature[] = { 0x42 , 0x4D };
    WriteCharArray(bitmapSignature, sizeof(bitmapSignature));
}

void Image::IntToLittleEndianBytes(int integer, char littleEndianBytes[]) {
    for (int i = 0; i < sizeof(int); i++) {
        littleEndianBytes[i] = (integer >> i * 8) & 0xFF;
    }
}

void Image::WriteImageSize() {
    int bitmapHeaderSize = 53;
    int imageSize = bitmapHeaderSize + imageDataSize;
    char imageSizeBytes[sizeof(int)];
    IntToLittleEndianBytes(imageSize, imageSizeBytes);
    WriteCharArray(imageSizeBytes, sizeof(imageSizeBytes));
}

void Image::WriteZero() {
    char zero[] = { 0x0, 0x0, 0x0, 0x0 };
    WriteCharArray(zero, sizeof(zero));
}

void Image::WriteEndOfHeaderAddrases() {
    char offsetToStartImageData[] = { 0x36 , 0x0 , 0x0 , 0x0 };
    char sizeOfBitmapInfoHeader[] = { 0x28 , 0x0 , 0x0 , 0x0 };
    WriteCharArray(offsetToStartImageData, sizeof(offsetToStartImageData));
    WriteCharArray(sizeOfBitmapInfoHeader, sizeof(sizeOfBitmapInfoHeader));
}

void Image::WriteWidthAndHeight() {
    char imageWidthBytes[sizeof(int)];
    char imageHeightBytes[sizeof(int)];
    IntToLittleEndianBytes(canvas.width, imageWidthBytes);
    IntToLittleEndianBytes(canvas.height, imageHeightBytes);
    WriteCharArray(imageWidthBytes, sizeof(imageWidthBytes));
    WriteCharArray(imageHeightBytes, sizeof(imageHeightBytes));
}

void Image::WriteImageMetadataDetails() {
    char numberOfPlanes[] = { 0x1 , 0x0 };
    char bitsPerPixel[] = { 0x18 , 0x0 };
    WriteCharArray(numberOfPlanes, sizeof(numberOfPlanes));
    WriteCharArray(bitsPerPixel, sizeof(bitsPerPixel));
}

void Image::WriteImageDataSize() {
    char imageDataSizeBytes[sizeof(int)];
    IntToLittleEndianBytes(imageDataSize, imageDataSizeBytes);
    WriteCharArray(imageDataSizeBytes, sizeof(imageDataSizeBytes));
}

void Image::WritePixels() {
    for (int y = 0; y < canvas.height; y++) {
        if (y % 10 == 0) {
            StatusManager::SetProgress(y , canvas.height);
        }
        for (int x = 0; x < canvas.width; x++) {

            Color colorToWrite = Color(255, 255, 255);

            if (
                canvas.pixelMap.find(x) != canvas.pixelMap.end() &&
                canvas.pixelMap[x].find(y) != canvas.pixelMap[x].end()
                ) {
                colorToWrite = canvas.pixelMap[x][y];
            }

            char blueByte = static_cast<char>(colorToWrite.blue);
            char greenByte = static_cast<char>(colorToWrite.green);
            char redByte = static_cast<char>(colorToWrite.red);

            imageBytes.push_back(blueByte);
            imageBytes.push_back(greenByte);
            imageBytes.push_back(redByte);
        }

        for (int i = 0; i < padding; i++) {
            imageBytes.push_back(static_cast<char>(0x0));
        }
    }
}

void Image::BuildBytes() {
    imageBytes.clear();
    ReserveMemory();
    WriteBitmapSignature();
    WriteImageSize();
    WriteZero();
    WriteEndOfHeaderAddrases();
    WriteWidthAndHeight();
    WriteImageMetadataDetails();
    WriteZero();
    WriteImageDataSize();
    WriteZero();
    WriteZero();
    WriteZero();
    WriteZero();
    WritePixels();
}

void Image::Save() {
    std::ofstream file("output.bmp", std::ios::binary);

    if (!file.is_open()) {
        return;
    }

    file.write(imageBytes.data(), imageBytes.size());

    file.close();
}