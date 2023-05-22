#include "Player.h"
#include "Graphics.h"
#include "Item.h"

Player::Player()
	: x(Graphics::ScreenWidth / 2)
	, y(Graphics::ScreenHeight / 2)
	, r(255)
	, g(255)
	, b(255)
	, speed(3)
{
	Update();
}
Player::~Player()
{

}
void Player::Update()
{

}

void Player::Move()
{
}

void Player::Draw()
{

}
