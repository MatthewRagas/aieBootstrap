#pragma once
#include<iostream>
class Vector2
{
public:
	float mX;
	float mY;
	Vector2();
	Vector2(float x, float y);
	Vector2 operator + (Vector2 & other);
	Vector2 operator - (Vector2 & other);
	Vector2 operator * (float other);
	bool operator == (Vector2 & other);
	float Dot(Vector2 & other);
	Vector2 Normalize();
	float Magnitude();
	friend std::istream& operator >> (std::istream is, Vector2 &other);
	friend std::ostream& operator << (std::ostream& is, Vector2 & other);
};


