#pragma once
#include "../Graphics.hpp"
#include "../Drawable.hpp"

//TODO
class Mouse final : public Drawable{
public:
	Mouse();
	~Mouse() = default;
	VOID Draw(Graphics& g) override;
private:

};