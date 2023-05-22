#include "Item.h"
#include "Graphics.h"

Item::Item(int xl, int yl, int rl, int gl, int bl)
	: x(xl)
	, y(xl)
	, r(150)
	, g(150)
	, b(150)
	, speed(3)
	, isEaten(false)

{
	Update();
}
Item::~Item()
{

}

void Item::Update()
{
	Move();
	Draw();
}

void Item::Move()
{
}

void Item::Draw()
{
}

bool Item::IsEaten()
{
	return isEaten;
}

