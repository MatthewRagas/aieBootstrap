#pragma once
#include<iostream>

class Vector4
{
public:
	float mX;
	float mY;
	float mZ;
	float mW;
	Vector4();
	Vector4(float x, float y, float z, float w);
	Vector4 operator + (Vector4 & other);
	Vector4 operator - (Vector4 & other);
	Vector4 operator * (float other);
	bool operator == (Vector4 & other);
	float Dot(Vector4 & other);
	Vector4 Normalize();
	float Magnitude();
	friend std::istream& operator >> (std::istream is, Vector4 &other);
	friend std::ostream& operator << (std::ostream& is, Vector4 & other);
};