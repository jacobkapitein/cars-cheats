#pragma once
#include <iostream>
#include "memory.h"
#include "cheat.h"

Cheat::Cheat(const char* processName) : mem(processName) {
		if (!mem.GetProcessHandle())
			return;

		//scorepointer = mem.GetPointerAddress(mem.GetModuleAddress(processName), 0x003B6B2C, { 0xF8, 0xD8, 0x0, 0x10, 0x84, 0x124, 0x160 });
		scorepointer = mem.GetPointerAddress(mem.GetModuleAddress(processName), 0x003C73A4, { 0x2C, 0x130, 0x10, 0x8C, 0x124, 0x160 });
		car_x_ptr = mem.GetPointerAddress(mem.GetModuleAddress(processName), 0x003C5920, { 0x50 });
		car_y_ptr = mem.GetPointerAddress(mem.GetModuleAddress(processName), 0x003C5920, { 0x54 });
		car_z_ptr = mem.GetPointerAddress(mem.GetModuleAddress(processName), 0x003C5920, { 0x58 });

		std::cout << "Cheat initialized!" << std::endl;
		initialized = true;
	}
Cheat::~Cheat() {}

int Cheat::GetScore() {
	return mem.ReadMemory<int>(scorepointer);
}

void Cheat::SetScore(int score) {
	mem.WriteMemory<int>(scorepointer, score);
}

std::tuple<float, float, float> Cheat::GetPosition() {
	return std::make_tuple(
		mem.ReadMemory<float>(car_x_ptr),
		mem.ReadMemory<float>(car_y_ptr),
		mem.ReadMemory<float>(car_z_ptr)
	);
}

void Cheat::SetPosition(float x, float y, float z) {
	mem.WriteMemory<float>(car_x_ptr, x);
	mem.WriteMemory<float>(car_y_ptr, y);
	mem.WriteMemory<float>(car_z_ptr, z);
}