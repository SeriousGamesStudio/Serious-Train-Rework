#pragma once
#ifndef _TRANFORM_2D_H
#define _TRANFORM_2D_H

#include "Vector2D.hpp"

class Transform2D
{
public:
	Transform2D();
	Transform2D(const Vector2D& position, const Real rotation = 0);
	~Transform2D();
	
	const Vector2D& getPosition() const;
	void setPosition(const Vector2D& newPosition);

	const Real getRotation() const;
	void setRotation(const Real newRotation);

	const Vector2D& getScale() const;
	void setScale(const Vector2D& newScale);

	void rotate(const Real r);

	void rotateAround(const Vector2D& point, Real rot);
	void translate(const Vector2D& v);

	void scale(Real s);
	void scale(const Vector2D& s);


private:
	Vector2D position;
	Real rotation;
	Vector2D _scale;
};
#endif // !_TRANFORM_2D_H