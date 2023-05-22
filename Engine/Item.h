#pragma once

class Item
{
	Item(int xl,int yl,int rl,int gl,int bl);
	~Item();

	void Move();
	void Draw();
	bool IsEaten();
	
	int r;
	int g;
	int b;

	int x;
	int y;
	int speed;

	bool isEaten;

public:
	int GetX() { return x; }
	int GetY() { return y; }
	
	void Update();
};

