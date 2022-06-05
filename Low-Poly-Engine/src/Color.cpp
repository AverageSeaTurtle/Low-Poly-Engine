#include "Color.h"

COLOR::RGB_i::RGB_i(uint8_t r, uint8_t g, uint8_t b, uint8_t alpha)
	: r(r), g(b), b(b), alpha(alpha)
{

}

bool COLOR::RGB_i::operator==(const RGB_i& other)
{
	return (this->r == other.r &&
		this->g == other.g &&
		this->b == other.b &&
		this->alpha == other.alpha);
}

bool COLOR::RGB_i::operator!=(const RGB_i& other)
{
	return !(*this == other);
}

COLOR::RGB_i COLOR::RGB_i::operator=(const RGB_i& other)
{
	if (*this != other) {
		this->r = other.r;
		this->g = other.g;
		this->b = other.b;
		this->alpha = other.alpha;
	}
	return *this;
}

COLOR::RGB_f::RGB_f(float r, float g, float b, float alpha)
{
	if (r < 0.0)
		this->r = 0.0;
	else if (r > 1.0)
		this->r = 1.0;
	else
		this->r = r;

	if (g < 0.0)
		this->g = 0.0;
	else if (g > 1.0)
		this->g = 1.0;
	else
		this->g = g;

	if (b < 0.0)
		this->b = 0.0;
	else if (b > 1.0)
		this->b = 1.0;
	else
		this->b = b;

	if (alpha < 0.0)
		this->alpha = 0.0;
	else if (alpha > 1.0)
		this->alpha = 1.0;
	else
		this->alpha = alpha;
}

bool COLOR::RGB_f::operator==(const RGB_f& other)
{
	return (this->r == other.r &&
		this->g == other.g &&
		this->b == other.b &&
		this->alpha == other.alpha);
}

bool COLOR::RGB_f::operator!=(const RGB_f& other)
{
	return !(*this == other);
}

COLOR::RGB_f COLOR::RGB_f::operator=(const RGB_f& other)
{
	if (*this != other) {
		this->r = other.r;
		this->g = other.g;
		this->b = other.b;
		this->alpha = other.alpha;
	}
	return *this;
}
