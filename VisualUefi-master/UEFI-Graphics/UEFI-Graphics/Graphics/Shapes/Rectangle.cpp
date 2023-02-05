#include "Rectangle.hpp"

Rectangle::Rectangle(UINTN x, UINTN y, UINTN size_x, UINTN size_y, Color color) {
	SetPosX(x);
	SetPosY(y);
	SetSizeX(size_x);
	SetSizeY(size_y);
	SetColor(color);
}

VOID Rectangle::Draw(Graphics& g){
	g.DrawRectangle(pos_x_, pos_y_, size_x_, size_y_, color_);
}
