#include "Collisions2D.h"
namespace Collisions {

RectangleCollider::RectangleCollider():
	Collider(RECTANGLE)
{
}

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
	return center;
}

void RectangleCollider::setCenter(const Vector2D & newCenter)
{
	center = newCenter;
	aa = { center.getX() - (width / 2), center.getY() + (height / 2) };
	bb = { center.getX() + (width / 2), center.getY() - (height / 2) };
}

const std::array<const Vector2D*, 2> RectangleCollider::getAABB() const
{
	return std::array<const Vector2D*, 2>{&aa, &bb};
}

const std::array<const Vector2D*, 4> RectangleCollider::getVertices() const
{
	return std::array<const Vector2D*, 4>{&aa, &Vector2D(bb.X(), aa.Y()), &bb, &Vector2D(aa.X(), bb.Y())};
}
CircleCollider::CircleCollider():
	Collider(CIRCLE)
{
}
CircleCollider::CircleCollider(const Vector2D & center, const Real radious):
	Collider(CIRCLE), center(center), radious(radious)
{
}
CircleCollider::~CircleCollider()
{
}
const Vector2D & CircleCollider::getCenter() const
{
	return center;
}
void CircleCollider::setCenter(const Vector2D & newCenter)
{
	center = newCenter;
}
const Real CircleCollider::getRadious() const
{
	return radious;
}
void CircleCollider::setRadious(const Real newRadious)
{
	radious = newRadious;
}
bool RectRectCollision(RectangleCollider * a, RectangleCollider * b)
{
	const Vector2D& A_aa = *a->getAABB()[0];
	const Vector2D& A_bb = *a->getAABB()[1];
	const Vector2D& B_aa = *b->getAABB()[0];
	const Vector2D& B_bb = *b->getAABB()[1];

	return (A_aa.X() <= B_bb.X() && B_aa.X() <= A_bb.X())
		&& (A_aa.Y() <= B_bb.Y() && B_aa.Y() <= A_bb.Y());
};
bool CircleCircleCollision(CircleCollider * a, CircleCollider * b)
{
	return a->getRadious() + b->getRadious() >= (a->getCenter() - b->getCenter()).lenght();
}

bool CircleRectangleCollision(CircleCollider* c, RectangleCollider* r) 
{

	Vector2D diff = c->getCenter() -  r->getCenter();
	const Vector2D half_extends{r->getWidth()/2.0, r->getHeight()/2};
	const Vector2D clamped = diff.clamped(-half_extends, half_extends);
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
