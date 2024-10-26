#pragma once
#include <iostream>
#include "memory.h"

class Cheat {
private:
	uintptr_t scorepointer = NULL;
	uintptr_t car_x_ptr = NULL;
	uintptr_t car_y_ptr = NULL;
	uintptr_t car_z_ptr = NULL;

	uintptr_t cam_pos_x_ptr = NULL;
	uintptr_t cam_pos_y_ptr = NULL;
	uintptr_t cam_pos_z_ptr = NULL;
	uintptr_t cam_target_x_ptr = NULL;
	uintptr_t cam_target_y_ptr = NULL;
	uintptr_t cam_target_z_ptr = NULL;

	Memory mem;
public:
	Cheat(const char* processName);
	~Cheat();

	bool initialized = false;

	int GetScore();
	void SetScore(int score);

	std::tuple<float, float, float> GetPlayerPosition();
	void SetPosition(float x, float y, float z);

	std::tuple<float, float, float> GetCameraPosition();
	std::tuple<float, float, float> GetCameraTarget();

	void SetCameraPosition(float x, float y, float z);
};