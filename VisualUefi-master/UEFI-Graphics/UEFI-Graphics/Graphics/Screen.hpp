#pragma once
#include "Graphics.hpp"
#include "Drawable.hpp"
class Screen{
public:
	Screen(UINTN size_x, UINTN size_y);
	VOID Render(Drawable& object) const;
	VOID ClearBackground(Color color) const;
private:
	VOID RemoveWatchDog();
	Graphics* g_;
	UINTN size_x_, size_y_;
};