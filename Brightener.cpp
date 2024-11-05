#include "Brightener.h"
#include "Image.h"

ImageBrightener::ImageBrightener(Image& inputImage) : m_inputImage(inputImage) {
}

int ImageBrightener::BrightenWholeImage() {
	int attenuatedPixelCount = 0;
	for (int x = 0; x < m_inputImage.GetRows(); x++) {
		for (int y = 0; y < m_inputImage.GetColumns(); y++) {
			if (m_inputImage.GetPixel(x, y) > (255 - 25)) {
				++attenuatedPixelCount;
				m_inputImage.SetPixel(x, y, 255);
			}
			else {
				m_inputImage.SetPixel(x, y, m_inputImage.GetPixel(x, y) + 25);
			}
		}
	}
	return attenuatedPixelCount;
}

Image ImageBrightener::GetImage() {
	return m_inputImage;
}
