#pragma once

#include <iostream>

struct Vector3D
{
	Vector3D(double x = 0, double y = 0, double z = 0);
	Vector3D(const Vector3D& other);
	~Vector3D();

	bool operator== (const Vector3D& other);
	bool operator!= (const Vector3D& other);

	Vector3D operator= (const Vector3D& other);
	Vector3D operator+ (const Vector3D& other);
	Vector3D operator- (const Vector3D& other);
	double operator* (const Vector3D& other);

	Vector3D operator+= (const Vector3D& other);
	Vector3D operator-= (const Vector3D& other);

	Vector3D operator+ (double k);
	Vector3D operator- (double k);
	Vector3D operator* (double k);

	Vector3D operator+= (double k);
	Vector3D operator-= (double k);
	Vector3D operator*= (double k);

	friend std::ostream& operator<<(std::ostream& os, const Vector3D& vec);
	friend std::istream& operator>>(std::istream& is, Vector3D& vec);

	double x, y, z;
};
