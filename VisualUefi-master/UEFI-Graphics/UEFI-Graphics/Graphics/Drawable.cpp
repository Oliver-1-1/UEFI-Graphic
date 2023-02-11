#include "Drawable.hpp"

bool Drawable::GetVisible() const{
	return this->visible_;
}

VOID Drawable::SetVisible(bool visible){
	this->visible_ = visible;
}

Color Drawable::GetColor() const{
	return this->color_;
}

VOID Drawable::SetColor(Color color){
	this->color_ = color;
}
