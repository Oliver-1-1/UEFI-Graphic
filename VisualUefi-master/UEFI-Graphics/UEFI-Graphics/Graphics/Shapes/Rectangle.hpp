#pragma once
#include "../Graphics.hpp"
#include "../Drawable.hpp"
#include "../Transformable.hpp"
class Rectangle final : public Drawable, public Transformable{
public:
	Rectangle(UINTN x, UINTN y, UINTN size_x, UINTN size_y, Color color);
	VOID Draw(Graphics& g) override;

private:
};