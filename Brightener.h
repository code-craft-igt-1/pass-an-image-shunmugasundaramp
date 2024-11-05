#pragma once
#include <cstdint>
#include "Image.h"

class ImageBrightener {
private:
	Image m_inputImage;
	int m_attenuatedPixelCount;
public:
	ImageBrightener(Image& inputImage);
	int BrightenWholeImage();
	Image GetImage();
	int GetAttenuatedPixelCount() const;

	static const int BRIGHTNESS_INCREMENT;
	static const int MAX_BRIGHTNESS;
};
