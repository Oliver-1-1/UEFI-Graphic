#pragma once
#include "Graphics.hpp"

class Drawable{
public:
	virtual VOID Draw(Graphics& g) {};
	bool GetVisible() const;
	VOID SetVisible(bool visible);

	VOID SetColor(Color color);
	Color GetColor() const;
protected:
	~Drawable() = default;
	bool visible_ = true;
	Color color_ = Color::BLACK;

private:
};