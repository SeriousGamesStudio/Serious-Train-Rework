#include "Physics.hpp"

using namespace Maths;
Physics::SquareCollider::SquareCollider(const Maths::Vector2 & position, const Maths::Vector2 & dim, Reference_Mode mode)
{
	switch (mode)
	{
	case Physics::SquareCollider::CENTER:
		this->center = position;
		this->w = dim.getX();
		this->h = dim.getY();
		break;
	case Physics::SquareCollider::UPPER_LEFT:
		center.set(position.getX() + (dim.getX() / (Real)2), position.getY() + (dim.getY() / (Real)2));
		w = dim.getX();
		h = dim.getY();
		break;
	default:
		break;
	}
}

Physics::SquareCollider::SquareCollider(Real x, Real y, Real width, Real height, Reference_Mode mode)
{
	SquareCollider({ x, y }, { width, height }, mode);
}
std::array<Vector2, 4> Physics::SquareCollider::getVertex() const
{
	const Vector2 a(center.getX() - w/2, center.getY() - h/2);
	const Vector2 b(center.getX() + w/2, center.getY() - h/2);
	const Vector2 c(center.getX() - w/2, center.getY() + h/2);
	const Vector2 d(center.getX() + w/2, center.getY() + h/2);
	

	return {a, b, c, d};
}
/*
Physics::SquareCollider::SquareCollider(const Maths::Vector2 & upper_left, const Maths::Vector2 & upper_right, const Maths::Vector2 & bottom_left, const Maths::Vector2 & bottom_right)
{
}
*/

Physics::EllipseCollider::EllipseCollider(const Maths::Vector2 & center, const Real horizontal_radious, const Real vertical_radious)
{
}

Physics::EllipseCollider::EllipseCollider(const Real cx, const Real cy, const Real horizontal_radious, const Real vertical_radious)
{
}

bool Physics::collides(const EllipseCollider & a, const EllipseCollider & b)
{
	return false;
}

bool Physics::collides(const EllipseCollider & a, const SquareCollider & b)
{
	return false;
}

bool Physics::collides(const SquareCollider & a, const SquareCollider & b)
{
	const Vector2 aul(a.center.getX() - (a.w/2), a.center.getY() - (a.h/2));
	const Vector2 aur(a.center.getX() + (a.w/2), a.center.getY() - (a.h/2));
	const Vector2 abl(a.center.getX() - (a.w/2), a.center.getY() + (a.h/2));
	const Vector2 abr(a.center.getX() - (a.w/2), a.center.getY() + (a.h/2));

	return pointInsideSquare(aul, b) 
		&& pointInsideSquare(aur, b) 
		&& pointInsideSquare(abl, b)
		&& pointInsideSquare(abr, b);
}

Physics::RayCastInfo Physics::rayCast(const Maths::Vector2 & origin, const Maths::Vector2 & direction)
{
	return RayCastInfo();
}

Physics::RayCastInfo Physics::rayCast(const Maths::Vector2 & origin, const Real & angle)
{
	return RayCastInfo();
}

bool Physics::pointInsideSquare(const Vector2 & point, const SquareCollider & sq)
{
	auto v = sq.getVertex();

	return 
		point.getX() >= v[0].getX() && point.getX() <= v[1].getX() &&
		point.getY() <= v[2].getY() && point.getY() >= v[0].getY();
}

bool Physics::pointInsideEllipse(const Vector2 & point, const EllipseCollider & e)
{
	const Vector2 normalized(point.getX() - e.center.getX(), point.getX() - e.center.getX());

	const Real nX2 = normalized.getX() * normalized.getX();
	const Real nY2 = normalized.getY() * normalized.getY();
	const Real rX2 = e.horizontal_radious * e.horizontal_radious;
	const Real rY2 = e.vertical_radious   * e.vertical_radious;


	return ((nX2 / rX2) + (nY2 / rY2)) <= (Real)1;
}
