#pragma once
#ifndef _PHYSICS_HPP
#define _PHYSICS_HPP
#include "maths.h"
#include <array>
using namespace Maths;
class Physics
{
public:
	//Forms/////////////////////////////////
	class SquareCollider 
	{
		friend class Physics;
	public:
		enum Reference_Mode {CENTER, UPPER_LEFT};
		SquareCollider(const Maths::Vector2& position, const Maths::Vector2& dim, Reference_Mode mode = CENTER);
		SquareCollider(Real x, Real y, Real width, Real height, Reference_Mode mode = CENTER);
		//TODO: Should we allow not pallalem quads?
		//SquareCollider(const Maths::Vector2& upper_left, const Maths::Vector2& upper_right, const Maths::Vector2& bottom_left, const Maths::Vector2& bottom_right);
		
		//0  1
		//|--|
		//|--|
		//2  3
		std::array<Vector2, 4> getVertex() const;
	private:
		Maths::Vector2 center;
		Real w, h;
	};
	
	class EllipseCollider
	{
		friend class Physics;
	public:
		EllipseCollider(const Maths::Vector2& center, const Real horizontal_radious, const Real vertical_radious);
		EllipseCollider(const Real cx, const Real cy, const Real horizontal_radious, const Real vertical_radious);

	private:
		Maths::Vector2 center;
		Real horizontal_radious, vertical_radious;
	};
	//Collisions///////////////////////////////
	static bool collides(const EllipseCollider& a, const EllipseCollider& b);
	static bool collides(const EllipseCollider& a, const SquareCollider& b);
	inline static bool collides(const SquareCollider& a, const EllipseCollider& b) { return collides(b, a); };
	static bool collides(const SquareCollider& a, const SquareCollider& b);
	//RayCasting//////////////////////////////
	struct RayCastInfo 
	{
		bool hitted;
		Real distance;
	};

	static RayCastInfo rayCast(const Maths::Vector2& origin, const Maths::Vector2& direction);
	static RayCastInfo rayCast(const Maths::Vector2& origin, const Real& angle);
private:

	static bool pointInsideSquare(const Vector2& point, const SquareCollider& sq);
	static bool pointInsideEllipse(const Vector2& point, const EllipseCollider& e);
};

#endif
