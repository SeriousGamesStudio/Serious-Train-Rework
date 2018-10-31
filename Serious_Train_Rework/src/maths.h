#pragma once
#ifndef MATHS_H
#define MATHS_H

#define DOUBLE_PRECISION true
#if DOUBLE_PRECISION
	typedef double Real;
#else
	typedef float Real;
#endif

#include <cmath>
#include <initializer_list>
namespace Maths
{

	class Vector2
	{
	public:
		Vector2(): x(0), y(0){};
		Vector2(Real x, Real y) : x(x), y(y) {};
		Vector2(const Vector2& other) : x(other.x), y(other.y) {};

		inline Real getX() { return x; };
		inline const Real getX()const  { return x; };
		inline Real getY() {return y; }
		inline const Real getY() const {return y; }

		inline void set(Real x, Real y) { x = x; y = y; };
		inline void setX(Real x) { x = x; };
		inline void setY(Real y) { y = y; };

		inline Vector2 operator+(const Vector2& other) {
			return { x + other.x, y + other.y };
		};

		inline Vector2 operator-(const Vector2& other){
			return { x - other.x, y - other.y };
		};

		inline const Vector2 operator+(const Vector2& other) const{
			return { x + other.x, y + other.y };
		};

		inline const Vector2 operator-(const Vector2& other) const{
			return { x - other.x, y - other.y };
		};

		inline Vector2& operator+=(const Vector2& other){
			x += other.x;
			y += other.y;
			return *this;
		}

		inline Vector2& operator-=(const Vector2& other){
			x -= other.x;
			y -= other.y;
			return *this;
		}

		inline Vector2 operator*(const Vector2& other) {
			return { x * other.x, y * other.y };
		}

		inline Vector2 operator/(const Vector2& other) {
			return { x / other.x, y / other.y };
		}

		inline Vector2& operator*=(const Vector2& other){
			x *= other.x;
			y *= other.y;
			return *this;
		}

		inline Vector2& operator/=(const Vector2& other){
			x /= other.x;
			y /= other.y;
			return *this;
		}

		inline bool operator==(const Vector2& other) {
			return x == other.x && y == other.y;
		}

		inline bool operator!=(const Vector2& other){
			return !(*this == other);
		}

		inline Vector2& operator*(const Real scale){
			x *= scale;
			y *= scale;
			return *this;
		}

		inline Vector2 operator-() const {
			return { -x, -y };
		}

		inline Real lenght() const
		{
			return (Real)std::sqrt((x*x) + (y*y));
		}

		inline Vector2& normalize() {
			Real l = lenght();
			x /= l;
			y /= l;
			return *this;
		}


	private:
		Real x, y;
	};
	class Vector3
	{
	public:
		Vector3() :x(), y(), z() {};
		Vector3(Real x, Real y, Real z) : x(x), y(y), z(z) {};
		Vector3(const Vector3& other) : x(other.x), y(other.y), z(other.z) {};

		inline Real getX() { return x; };
		inline const Real getX()const { return x; };
		inline Real getY() { return y; }
		inline const Real getY() const { return y; };
		inline Real getZ() { return z; }
		inline const Real getZ() const { return z; };

		inline void set(Real x, Real y, Real z) { this->x = x; this->y = y; this->z = z; };
		
		inline void setX(Real x) { this->x = x; };
		inline void setY(Real y) { this->y = y; };
		inline void setZ(Real z) { this->z = z; };

		inline Vector3 operator+(const Vector3& other)
		{
			return { x + other.x, y + other.y, z + other.z };
		};

		inline Vector3 operator-(const Vector3& other)
		{
			return { x - other.x, y - other.y, z - other.z };
		};

		inline Vector3& operator+=(const Vector3& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			return *this;
		}

		inline Vector3& operator-=(const Vector3& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			return *this;
		}

		inline Vector3 operator*(const Vector3& other)
		{
			return { x * other.x, y * other.y, z * other.z };
		}
		inline Vector3 operator/(const Vector3& other)
		{
			return { x / other.x, y / other.y, z / other.z };
		}

		inline Vector3& operator*=(const Vector3& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			return *this;
		}

		inline Vector3& operator/=(const Vector3& other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
			return *this;
		}

		inline bool operator==(const Vector3& other)
		{
			return x == other.x && y == other.y && z == other.z;
		}

		inline bool operator!=(const Vector3& other)
		{
			return !(*this == other);
		}

		inline Vector3& operator*(const Real scale)
		{
			x *= scale;
			y *= scale;
			z *= scale;
			return *this;
		}
		inline Real lenght()
		{
			return std::sqrt((x*x) + (y*y) + (z*z));
		}

		inline Vector3& normalize()
		{
			Real l = lenght();
			x /= l;
			y /= l;
			z /= l;
			return *this;
		}


	private:
		Real x, y, z;
	};

	inline Real distance(const Vector2& a, const Vector2&b) 
	{
		return (b - a).lenght();
	}
	/*TODO
	template<unsigned int ROWS = 1, unsigned int COLS>
	class Matrix 
	{
	public:
		Matrix() 
		{
			for (size_t i = 0; i < ROWS*COLS; i++)
				matrix[i] = (Real)0;
		}
		Matrix(const Matrix& other) 
		{
			for (unsigned int i; i < ROWS*COLS; i++)
				matrix[i] = other.matrix[i];
		}
		Matrix(std::initializer_list<std::initializer_list<Real>> l)
		{
			size_t n = 0;
			for (auto i = l.begin(); i != l.end; i++)
				for (auto j = i->begin(); j != i->end(); j++)
					matrix[n] = *j;
		}

		Real at(unsigned int row, unsigned int col) 
		{
			//TODO: assert(row < ROWS && col < COLS)
			return matrix[(row * ROWS) + col];
		}
	private:
		Real matrix[ROWS * COLS];
	};
	*/
}
#endif // !MATHS