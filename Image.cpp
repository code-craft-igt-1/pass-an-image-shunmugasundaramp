#include "Image.h"

Image::Image(int rows, int columns)
{
    m_pixels = std::make_unique<int[]>(rows * columns);
    m_rows = rows;
    m_columns = columns;
}

Image::Image(const Image& image)
{
    m_rows = image.m_rows;
    m_columns = image.m_columns;
    int size = m_rows * m_columns;
    m_pixels = std::make_unique<int[]>(size);
    std::memcpy(m_pixels.get(), image.m_pixels.get(), size * sizeof(int));
}

Image::~Image()
{
    
}

int Image::GetRows() const
{
    return m_rows;
}

int Image::GetColumns() const
{
    return m_columns;
}

int Image::GetPixel(int x, int y) const
{
	return m_pixels[x * m_columns + y];
}

void Image::SetPixel(int x, int y, int value)
{
	m_pixels[x * m_columns + y] = value;
}