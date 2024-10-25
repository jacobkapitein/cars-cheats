#pragma once
#include <iostream>
#include "memory.h"

class Cheat {
private:
	uintptr_t scorepointer = NULL;
	uintptr_t car_x_ptr = NULL;
	uintptr_t car_y_ptr = NULL;
	uintptr_t car_z_ptr = NULL;

	Memory mem;
public:
	Cheat(const char* processName);
	~Cheat();

	bool initialized = false;

	int GetScore();
	void SetScore(int score);

	std::tuple<float, float, float> GetPosition();
	void SetPosition(float x, float y, float z);
};