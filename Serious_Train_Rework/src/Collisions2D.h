#pragma once
#include "Vector2D.hpp"
#include <array>
namespace Collisions {
	struct Collider
	{
		enum Type { RECTANGLE, CIRCLE/*, ELLIPSE */};
		Collider(Type type) :type(type) {};
		const Type type;
	};


	struct RectangleCollider : public Collider
	{
		RectangleCollider();
		RectangleCollider(const Vector2D& center, Real width, Real height);
		RectangleCollider(const Vector2D& upper_left, const Vector2D& bottom_right);
		RectangleCollider(const Real upper_left_x, const Real upper_left_y, const Real width, const Real height);

		~RectangleCollider();

		const Real getWidth() const;
		const Real getHeight() const;

		void setWidth(const Real newWidth);
		void setHeight(const Real newHeight);

		const Vector2D& getCenter() const;
		void setCenter(const Vector2D& newCenter);

		const std::array<const Vector2D*, 2> getAABB() const;

		//Clock-wise from upper_left
		const std::array<const Vector2D*, 4> getVertices() const;

	private:
		Vector2D aa;
		Vector2D bb;
		Vector2D center;
		Real width;
		Real height;

	};

	struct CircleCollider: public Collider
	{
		CircleCollider();
		CircleCollider(const Vector2D& center, const Real radious);

		~CircleCollider();


		const Vector2D& getCenter() const;
		void setCenter(const Vector2D& newCenter);

		const Real getRadious() const;
		void setRadious(const Real newRadious);
	private:
		Vector2D center;
		Real radious;
	};



	bool RectRectCollision(RectangleCollider* a, RectangleCollider* b);
	bool CircleCircleCollision(CircleCollider* a, CircleCollider* b);

	bool collides(Collider* a, Collider*b);

}