#include "Screen.hpp"

Screen::Screen(UINTN size_x, UINTN size_y) : size_x_(size_x), size_y_(size_y) {
	g_ = new Graphics(size_x, size_y);
}

VOID Screen::Render(Drawable& object){
	if (object.GetVisible()) {
		object.Draw(*g_);
		g_->Render();
	}
}
