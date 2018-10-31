#include "Collisions2D.h"
namespace Collisions {

RectangleCollider::RectangleCollider():
	Collider(RECTANGLE), transform(nullptr), width(0), height(0)
{
}

RectangleCollider::RectangleCollider(Transform2D* transform, const Real width, const Real height):
	Collider(RECTANGLE),transform(transform), width(width), height(height)
{
}
/*
RectangleCollider::RectangleCollider(const Vector2D & center, Real width, Real height):
	Collider(RECTANGLE), center(center), width(width), height(height)
{
	aa = {center.getX() - (width/2), center.getY() + (height/2)};
	bb = {center.getX() + (width/2), center.getY() - (height/2)};
}

RectangleCollider::RectangleCollider(const Vector2D & upper_left, const Vector2D & bottom_right):
	Collider(RECTANGLE),aa(upper_left), bb(bottom_right)
{
	width	= bb.getX() - aa.getX();
	height	= bb.getY() - aa.getY();
	center = {aa.X() + (width/2), aa.Y() - (height/2)};
}

RectangleCollider::RectangleCollider(const Real upper_left_x, const Real upper_left_y, const Real width, const Real height):
	Collider(RECTANGLE), aa(upper_left_x, upper_left_y), bb(upper_left_x + width, upper_left_y + height), width(width), height(height)
{
	center = { aa.X() + (width / 2), aa.Y() - (height / 2) };
}
*/
RectangleCollider::~RectangleCollider()
{
}

const Real RectangleCollider::getWidth() const
{
	return width;
}

const Real RectangleCollider::getHeight() const
{
	return height;
}

void RectangleCollider::setWidth(const Real newWidth)
{
	width = newWidth;
}

void RectangleCollider::setHeight(const Real newHeight)
{
	height = newHeight;
}

const Vector2D & RectangleCollider::getCenter() const
{
	return transform->getPosition();
}

const void RectangleCollider::getAABB(Vector2D & aa, Vector2D & bb) const
{
	const Vector2D& he = getHalfExtend();

	aa.setX(getCenter().getX() - he.getX());
	aa.setY(getCenter().getY() + he.getY());

	bb.setX(getCenter().getX() + he.getX());
	bb.setY(getCenter().getY() - he.getY());

}

const Vector2D RectangleCollider::getHalfExtend() const
{
	return {width* transform->getScale().getX(), height * transform->getScale().getY()};
}


CircleCollider::CircleCollider():
	Collider(CIRCLE)
{
}
CircleCollider::CircleCollider(Transform2D * transform, const Real radious):
	Collider(CIRCLE), transform(transform), radious(radious)
{
}
CircleCollider::~CircleCollider()
{
}
const Vector2D & CircleCollider::getCenter() const
{
	return transform->getPosition();
}

const Real CircleCollider::getRadious() const
{
	return radious * transform->getScale().lenght();
}
void CircleCollider::setRadious(const Real newRadious)
{
	radious = newRadious;
}
bool RectRectCollision(RectangleCollider * a, RectangleCollider * b)
{
	Vector2D A_aa;
	Vector2D A_bb;
	a->getAABB(A_aa, A_bb);

	Vector2D B_aa;
	Vector2D B_bb;
	b->getAABB(B_aa, B_bb);

	return (A_aa.X() <= B_bb.X() && B_aa.X() <= A_bb.X())
		&& (A_aa.Y() <= B_bb.Y() && B_aa.Y() <= A_bb.Y());
};
bool CircleCircleCollision(CircleCollider * a, CircleCollider * b)
{
	return a->getRadious() + b->getRadious() >= (a->getCenter() - b->getCenter()).lenght();
}

bool CircleRectangleCollision(CircleCollider* c, RectangleCollider* r) 
{

	Vector2D diff = c->getCenter() - r->getCenter();
	const Vector2D clamped = diff.clamped(-(r->getHalfExtend()), r->getHalfExtend());
	const Vector2D closest = r->getCenter() + clamped;
	diff = closest - c->getCenter();

	return diff.lenght() < c->getRadious();
}

bool collides(Collider * a, Collider * b)
{
	if (a->type == Collider::RECTANGLE && b->type == Collider::RECTANGLE)
		return RectRectCollision((RectangleCollider*)a, (RectangleCollider*)b);
	if (a->type == Collider::CIRCLE && b->type == Collider::CIRCLE)
		return CircleCircleCollision((CircleCollider*)a, (CircleCollider*)b);
	if ((a->type == Collider::CIRCLE && b->type == Collider::RECTANGLE))
		return CircleRectangleCollision((CircleCollider*)a, (RectangleCollider*)b);
	if ((a->type == Collider::RECTANGLE && b->type == Collider::CIRCLE))
		return CircleRectangleCollision((CircleCollider*)b, (RectangleCollider*)a);
}
};
