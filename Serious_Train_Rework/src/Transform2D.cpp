#include "Transform2D.h"
#include <cmath>

Transform2D::Transform2D():
	position(0,0), rotation(0), _scale(1, 1)
{
}

Transform2D::Transform2D(const Vector2D & position, const Real rotation):
	position(position), rotation(rotation), _scale(1, 1)
{
}

Transform2D::~Transform2D()
{
}

const Vector2D & Transform2D::getPosition() const
{
	return position;
}

void Transform2D::setPosition(const Vector2D & newPosition)
{
	position = newPosition;
}

const Real Transform2D::getRotation() const
{
	return rotation;
}

void Transform2D::setRotation(const Real newRotation)
{
	rotation = newRotation;
}

const Vector2D & Transform2D::getScale() const
{
	return _scale;
}

void Transform2D::setScale(const Vector2D & newScale)
{
	_scale = newScale;
}

void Transform2D::rotate(const Real r)
{
	rotation += r;
}

void Transform2D::rotateAround(const Vector2D & point, Real rot)
{
	rot += rotation;
	Real dist = point.distance(position);

	Real nx = std::cos(rot) * dist;
	Real ny = std::sin(rot) * dist;
	position.set(nx, ny);
}

void Transform2D::translate(const Vector2D & v)
{
	position += v;
}

void Transform2D::scale(Real s)
{
	_scale *= s;
}

void Transform2D::scale(const Vector2D & s)
{
	_scale *= s;
}
