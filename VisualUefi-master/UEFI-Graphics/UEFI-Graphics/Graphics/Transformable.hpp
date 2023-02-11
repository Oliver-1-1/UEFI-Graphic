#pragma once
#include "Graphics.hpp"

class Transformable{
public:
	UINTN GetSizeX() const;
	UINTN GetSizeY() const;
	INTN GetPosX() const;
	INTN GetPosY() const;

	VOID SetPosX(INTN x);
	VOID SetPosY(INTN y);
	virtual VOID SetSizeX(UINTN x);
	virtual VOID SetSizeY(UINTN y);

	VOID Move(INTN x, INTN y);
	//virtual VOID Rotate(double angle);

protected:
	UINTN size_x_ = 0, size_y_ = 0;
	INTN pos_x_ = 0, pos_y_ = 0;
	UINTN scale_ = 1;

private:

	
};