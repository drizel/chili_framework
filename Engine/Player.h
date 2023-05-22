#pragma once

class Player
{
	Player();
	~Player();


	void Move();
	void Draw();

	int x;
	int y;

	int r;
	int b;
	int g;

	int speed;

public:
	void Update();

	int getX() { return x; }
	int getY() { return y; }
};

