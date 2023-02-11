#include "Screen.hpp"

Screen::Screen(UINTN size_x, UINTN size_y) : size_x_(size_x), size_y_(size_y) {
	RemoveWatchDog();
	g_ = new Graphics(size_x, size_y);
}

VOID Screen::Render(Drawable& object) const
{
	if (object.GetVisible()) {
		object.Draw(*g_);
		g_->Render();
	}
}

VOID Screen::ClearBackground(Color color) const{
	return g_->DrawRectangle(0, 0, size_x_, size_y_, color);
}

VOID Screen::RemoveWatchDog(){
	gBS->SetWatchdogTimer(0, 0, 0, nullptr); // Default the value is 5 * 60 = 5 min. If we 0 it, its ignored.
}
