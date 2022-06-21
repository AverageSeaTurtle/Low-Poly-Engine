#pragma once

#include <GLFW/glfw3.h>
#include <glm/vec4.hpp>

//#define glClearColor(COLOR) glClearColor(COLOR.r, COLOR.g, COLOR.b, COLOR.alpha);
//#define glColor3f(COLOR) glColor3f(COLOR.r, COLOR.g, COLOR.b);

#define WHITE COLOR::RGB_f(1.0,1.0,1.0,1.0)
#define BLACK COLOR::RGB_f(0.0,0.0,0.0,1.0)
#define RED COLOR::RGB_f(1.0,0.0,0.0,1.0)
#define BLUE COLOR::RGB_f(0.0,0.0,1.0,1.0)
#define GREEN COLOR::RGB_f(0.0,1.0,0.0,1.0)
#define YELLOW COLOR::RGB_f(1.0,1.0,0.0,1.0)

namespace COLOR
{
	struct RGB_i
	{
		RGB_i(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t alpha = 255);
		~RGB_i() {};

		uint8_t r, g, b, alpha;

		glm::vec4 vec4() { return glm::vec4(r, g, b, alpha); };

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

		glm::vec4 vec4() { return glm::vec4(r, g, b, alpha); };

		RGB_f operator += (const RGB_f& other);
		RGB_f operator -= (const RGB_f& other);
	};

};