#include "Circle.hpp"

Circle::Circle(INTN x, INTN y, UINTN radius, Color color) {
	SetPosX(x);
	SetPosY(y);
	SetColor(color);
	SetRadius(radius);
}

VOID Circle::Draw(Graphics& g){ // Circle equation.
	for (UINTN x = pos_x_ - radius_; x <= pos_x_ + radius_; x++) {
		for (UINTN y = pos_y_ - radius_; y <= pos_y_ + radius_; y++) {
			if ((x - pos_x_) * (x - pos_x_) + (y - pos_y_) * (y - pos_y_) <= radius_ * radius_) {
				g.DrawPixel(x, y, color_);
			}
		}
	}
}

VOID Circle::SetSizeX(UINTN radius){
	SetRadius(radius);
}

VOID Circle::SetSizeY(UINTN radius){
	SetRadius(radius);
}

VOID Circle::SetRadius(UINTN radius){
	this->radius_ = radius;
	this->size_x_ = radius;
	this->size_y_ = radius;
}

UINTN Circle::GetRadius() const
{
	return radius_;
}
