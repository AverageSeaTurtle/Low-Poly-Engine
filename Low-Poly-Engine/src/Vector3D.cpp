#include "Vector3D.h"

Vector3D::Vector3D(double x, double y, double z)
	: x(x), y(y), z(z)
{

}

Vector3D::Vector3D(const Vector3D& other) : Vector3D(other.x, other.y, other.z)
{

}

Vector3D::~Vector3D()
{
}

bool Vector3D::operator==(const Vector3D& other)
{
	return (this->x == other.x &&
			this->y == other.y &&
			this->z == other.z);
}

bool Vector3D::operator!=(const Vector3D& other)
{
	return !(this == &other);
}

Vector3D Vector3D::operator=(const Vector3D& other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;

	return *this;
}

Vector3D Vector3D::operator+(const Vector3D& other)
{
	Vector3D result = *this;

	result.x += other.x;
	result.y += other.y;
	result.z += other.z;

	return result;
}

Vector3D Vector3D::operator-(const Vector3D& other)
{
	Vector3D result = *this;

	result.x -= other.x;
	result.y -= other.y;
	result.z -= other.z;

	return result;
}

double Vector3D::operator*(const Vector3D& other)
{
	return this->x * other.x + this->y * other.y + this->z * other.z;
}

Vector3D Vector3D::operator+=(const Vector3D& other)
{
	*this = *this + other;
	return *this;
}

Vector3D Vector3D::operator-=(const Vector3D& other)
{
	*this = *this - other;
	return *this;
}

Vector3D Vector3D::operator+(double k)
{
	Vector3D result = *this;

	result.x += k;
	result.y += k;
	result.z += k;

	return result;
}

Vector3D Vector3D::operator-(double k)
{
	Vector3D result = *this;

	result.x -= k;
	result.y -= k;
	result.z -= k;

	return result;
}

Vector3D Vector3D::operator*(double k)
{
	Vector3D result = *this;

	result.x *= k;
	result.y *= k;
	result.z *= k;

	return result;
}

Vector3D Vector3D::operator+=(double k)
{
	*this = *this + k;
	return *this;
}

Vector3D Vector3D::operator-=(double k)
{
	*this = *this - k;
	return *this;
}

Vector3D Vector3D::operator*=(double k)
{
	*this = *this - k;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector3D& vec)
{
	os << "(" << vec.x << "," << vec.y << "," << vec.z << ")";

	return os;
}

std::istream& operator>>(std::istream& is, Vector3D& vec)
{
	is >> vec.x >> vec.y >> vec.z;

	return is;
}
