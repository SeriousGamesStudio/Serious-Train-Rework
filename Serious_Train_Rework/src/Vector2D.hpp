#pragma once
#ifndef _VECTOR_2D_H
#define _VECTOR_2D_H
#include <cmath>//for std::sqrt
#include <algorithm>//for std::min std::max
using Real = double;
//using Real = float;
class Vector2D
{
public:
	Vector2D() : x(0), y(0) {};
	Vector2D(Real x, Real y) : x(x), y(y) {};
	Vector2D(const Vector2D& other) : x(other.x), y(other.y) {};
	//Getters and Setters///////////////////////////////////////////////////////////
	inline Real getX() { return x; };
	inline const Real getX()const { return x; };
	inline Real getY() { return y; }
	inline const Real getY() const { return y; }

	inline void set(Real x, Real y) { x = x; y = y; };
	inline void setX(Real x) { x = x; };
	inline void setY(Real y) { y = y; };

	inline Real X() { return x; };
	inline const Real X()const { return x; };
	inline Real Y() { return y; }
	inline const Real Y() const { return y; }

	inline void X(Real x) { x = x; };
	inline void Y(Real y) { y = y; };
	////////////////////////////////////////////////////////////////////////////////
	//Aritmerith operators//////////////////////////////////////////////////////////
	inline Vector2D& operator=(const Vector2D& other)
	{
		x = other.x;
		y = other.y;
		return *this;
	}

	inline Vector2D operator+(const Vector2D& other) {
		return { x + other.x, y + other.y };
	};

	inline Vector2D operator-(const Vector2D& other) {
		return { x - other.x, y - other.y };
	};

	inline const Vector2D operator+(const Vector2D& other) const {
		return { x + other.x, y + other.y };
	};

	inline const Vector2D operator-(const Vector2D& other) const {
		return { x - other.x, y - other.y };
	};

	inline Vector2D& operator+=(const Vector2D& other) {
		x += other.x;
		y += other.y;
		return *this;
	}

	inline Vector2D& operator-=(const Vector2D& other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}

	inline Vector2D operator*(const Vector2D& other) {
		return { x * other.x, y * other.y };
	}

	inline Vector2D operator/(const Vector2D& other) {
		return { x / other.x, y / other.y };
	}

	inline Vector2D& operator*=(const Vector2D& other) {
		x *= other.x;
		y *= other.y;
		return *this;
	}

	inline Vector2D& operator/=(const Vector2D& other) {
		x /= other.x;
		y /= other.y;
		return *this;
	}
	////////////////////////////////////////////////////////////////////////////////
	/////Bool operators/////////////////////////////////////////////////////////////
	inline bool operator==(const Vector2D& other) {
		return x == other.x && y == other.y;
	}
	inline bool operator!=(const Vector2D& other) {
		return !(*this == other);
	}
	////////////////////////////////////////////////////////////////////////////////
	//Utility operations////////////////////////////////////////////////////////////
	inline Vector2D& operator*(const Real scale) {
		Vector2D v = *this;
		 v *= scale;
		return v;
	}
	inline Vector2D& operator*=(const Real scale) {
		x *= scale;
		y *= scale;
		return *this;
	}

	inline Vector2D operator-() const {
		return { -x, -y };
	}

	inline Real lenght() const
	{
		return (Real)std::sqrt((x*x) + (y*y));
	}
	inline Real lenghtSquared() const 
	{
		return (x*x) + (y * y);
	}

	inline Vector2D normalized() {
		Real l = lenght();
		return Vector2D(x/l, y/l);
	}
	inline void normalize() {
		Real l = lenght();
		x /= l;
		y /= l;
	}

	inline Vector2D& clamp(const Vector2D& min, const Vector2D& max) 
	{
		auto _clamp = [](Real value, Real min, Real max)
		{
			return std::max(min, std::min(value, max));
		};
		x = _clamp(x, min.x, max.x);
		y = _clamp(y, min.y, max.y);
		return *this;
	}

	inline Vector2D clamped(const Vector2D& min, const Vector2D& max) const
	{
		auto _clamp = [](Real value, Real min, Real max)
		{
			return std::max(min, std::min(value, max));
		};

		Real x_ = _clamp(x, min.x, max.x);
		Real y_ = _clamp(y, min.y, max.y);
		return Vector2D(x_, y_);
	}

	inline Real distance(Vector2D other) const
	{
		other -= (*this);
		return other.lenght();
	}
	inline static Real distance(const Vector2D& u, const Vector2D& v) 
	{
		return u.distance(v);
	}
private:
	Real x, y;
};
#endif // !_VECTOR_2D_H