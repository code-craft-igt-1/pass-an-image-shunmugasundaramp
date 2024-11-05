#include "Brightener.h"
#include "Image.h"

const int ImageBrightener::BRIGHTNESS_INCREMENT = 25;
const int ImageBrightener::MAX_BRIGHTNESS = 255;

ImageBrightener::ImageBrightener(Image& inputImage) 
	: m_inputImage(inputImage)
	, m_attenuatedPixelCount(0) {
}

int ImageBrightener::BrightenWholeImage() {
	for (int x = 0; x < m_inputImage.GetRows(); x++) {
		for (int y = 0; y < m_inputImage.GetColumns(); y++) {
			int thresholdBrightness = ImageBrightener::MAX_BRIGHTNESS - ImageBrightener::BRIGHTNESS_INCREMENT;
			if (m_inputImage.GetPixel(x, y) > thresholdBrightness) {
				++m_attenuatedPixelCount;
				m_inputImage.SetPixel(x, y, ImageBrightener::MAX_BRIGHTNESS);
			}
			else {
				m_inputImage.SetPixel(x, y, m_inputImage.GetPixel(x, y) + ImageBrightener::BRIGHTNESS_INCREMENT);
			}
		}
	}
	return m_attenuatedPixelCount;
}

Image ImageBrightener::GetImage() {
	return m_inputImage;
}

int ImageBrightener::GetAttenuatedPixelCount() const {
	return m_attenuatedPixelCount;
}
