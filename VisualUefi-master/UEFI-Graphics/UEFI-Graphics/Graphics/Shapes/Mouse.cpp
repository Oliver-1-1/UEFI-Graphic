#include "Mouse.hpp"


Mouse::Mouse() = default;

VOID Mouse::Draw(Graphics& g){
	g.DrawRectangle(20, 20, 20, 20, Color::BLUE);
}
