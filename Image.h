#pragma once
#include <cstdint>
#include <memory>

class Image {
public:
	Image() = delete;
	Image(int rows, int columns);
	Image(const Image& other);
	Image& operator=(const Image& other) = delete;
	~Image();

	int GetRows() const;
	int GetColumns() const;
	int GetPixel(int x, int y) const;
	void SetPixel(int x, int y, int value);

private:
	int m_rows;
	int m_columns;
	std::unique_ptr<int[]> m_pixels;
};
