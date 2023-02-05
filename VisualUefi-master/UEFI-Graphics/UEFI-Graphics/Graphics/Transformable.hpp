#pragma once
#include "Graphics.hpp"

class Transformable{
public:
	UINTN GetSizeX() const;
	UINTN GetSizeY() const;
	UINTN GetPosX() const;
	UINTN GetPosY() const;

	VOID SetPosX(UINTN x);
	VOID SetPosY(UINTN y);
	virtual VOID SetSizeX(UINTN x);
	virtual VOID SetSizeY(UINTN y);

	VOID Move(INTN x, INTN y);
protected:
	UINTN size_x_ = 0, size_y_ = 0, pos_x_ = 0, pos_y_ = 0;

private:
};