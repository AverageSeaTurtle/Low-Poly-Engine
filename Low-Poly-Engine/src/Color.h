#pragma once

#include <GLFW/glfw3.h>

#define glClearColor(COLOR) glClearColor(COLOR.r, COLOR.g, COLOR.b, COLOR.alpha);
#define glColor3f(COLOR) glColor3f(COLOR.r, COLOR.g, COLOR.b);

#define WHITE_COLOR COLOR::RGB_f(1.0,1.0,1.0)

namespace COLOR
{
	struct RGB_i
	{
		RGB_i(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t alpha = 255);
		~RGB_i() {};

		uint8_t r, g, b, alpha;

		// TODO: RGB_i operators
		bool operator == (const RGB_i& other);
		bool operator != (const RGB_i& other);
		RGB_i operator = (const RGB_i& other);
		RGB_i operator + (const RGB_i& other);
		RGB_i operator - (const RGB_i& other);

		RGB_i operator += (const RGB_i& other);
		RGB_i operator -= (const RGB_i& other);
	};

	struct RGB_f
	{
		RGB_f(float r = 0.0, float g = 0.0, float b = 0.0, float alpha = 1.0);
		~RGB_f() {};

		float r, g, b, alpha;

		// TODO: RGB_f operators
		bool operator == (const RGB_f& other);
		bool operator != (const RGB_f& other);
		RGB_f operator = (const RGB_f& other);
		RGB_f operator + (const RGB_f& other);
		RGB_f operator - (const RGB_f& other);

		RGB_f operator += (const RGB_f& other);
		RGB_f operator -= (const RGB_f& other);
	};

};