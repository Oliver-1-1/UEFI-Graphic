#pragma once
#include "../Graphics.hpp"
#include "../Drawable.hpp"
#include "../Transformable.hpp"
class Circle : public Drawable, public Transformable{
public:
	Circle(INTN x, INTN y, UINTN radius, Color color);
	VOID Draw(Graphics& g) override;
	VOID SetSizeX(UINTN radius) override;
	VOID SetSizeY(UINTN radius) override;

	VOID SetRadius(UINTN radius);
	UINTN GetRadius() const;

private:
	UINTN radius_;
};