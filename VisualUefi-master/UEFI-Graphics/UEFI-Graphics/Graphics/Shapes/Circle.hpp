#pragma once
#include "../Graphics.hpp"
#include "../Drawable.hpp"
#include "../Transformable.hpp"
class Circle final : public Drawable, public Transformable{
public:
	Circle(UINTN x, UINTN y, UINTN radius, Color color);
	VOID Draw(Graphics& g) override;
	VOID SetSizeX(UINTN x) override;
	VOID SetSizeY(UINTN y) override;

	VOID SetRadius(UINTN radius);
	UINTN GetRadius() const;

private:
	UINTN radius_;
};