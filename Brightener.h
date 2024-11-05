#pragma once
#include <cstdint>
#include "Image.h"

class ImageBrightener {
private:
	Image m_inputImage;
public:
	ImageBrightener(Image& inputImage);
	int BrightenWholeImage();
	Image GetImage();
};
