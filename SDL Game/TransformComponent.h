#pragma once
#include "Components.h"

class TransformComponent : public Component
{
private:

	int xPos;
	int yPos;

public:
	TransformComponent() {
		xPos = 0;
		yPos = 0;
	}

	TransformComponent(int x, int y) {
		xPos = x;
		yPos = y;
	}

	int x() { return xPos; }
	void x (int x) { xPos = x; }
	int y() { return yPos; }
	void y(int y) { yPos = y; }


	void update() override {
		xPos++;
		yPos++;
	}

	void setPos(int x, int y) {
		xPos = x;
		yPos = y;
	}

};