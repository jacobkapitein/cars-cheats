#pragma once
#include <iostream>
#include "memory.h"
#include "cheat.h"
#include "offsets.h"

Cheat::Cheat(const char* processName) : mem(processName) {
		if (!mem.GetProcessHandle())
			return;
		//scorepointer = mem.GetPointerAddress(mem.GetModuleAddress(processName), 0x003B6B2C, { 0xF8, 0xD8, 0x0, 0x10, 0x84, 0x124, 0x160 });
		scorepointer = mem.GetPointerAddress(
			mem.GetModuleAddress(processName),
			CarsOffsets::score_base,
			CarsOffsets::score_offsets
		);
		car_x_ptr = mem.GetPointerAddress(mem.GetModuleAddress(processName), CarsOffsets::player_base, CarsOffsets::player_x_offset);
		car_y_ptr = mem.GetPointerAddress(mem.GetModuleAddress(processName), CarsOffsets::player_base, CarsOffsets::player_y_offset);
		car_z_ptr = mem.GetPointerAddress(mem.GetModuleAddress(processName), CarsOffsets::player_base, CarsOffsets::player_z_offset);

		cam_pos_x_ptr = mem.GetPointerAddress(mem.GetModuleAddress(processName), CarsOffsets::cam_base, CarsOffsets::cam_pos_x_offset);
		cam_pos_y_ptr = mem.GetPointerAddress(mem.GetModuleAddress(processName), CarsOffsets::cam_base, CarsOffsets::cam_pos_y_offset);
		cam_pos_z_ptr = mem.GetPointerAddress(mem.GetModuleAddress(processName), CarsOffsets::cam_base, CarsOffsets::cam_pos_z_offset);

		cam_target_x_ptr = mem.GetPointerAddress(mem.GetModuleAddress(processName), CarsOffsets::cam_base, CarsOffsets::cam_target_x_offset);
		cam_target_y_ptr = mem.GetPointerAddress(mem.GetModuleAddress(processName), CarsOffsets::cam_base, CarsOffsets::cam_target_y_offset);
		cam_target_z_ptr = mem.GetPointerAddress(mem.GetModuleAddress(processName), CarsOffsets::cam_base, CarsOffsets::cam_target_z_offset);

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

std::tuple<float, float, float> Cheat::GetPlayerPosition() {
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

std::tuple<float, float, float> Cheat::GetCameraPosition() {
	return std::make_tuple(
		mem.ReadMemory<float>(cam_pos_x_ptr),
		mem.ReadMemory<float>(cam_pos_y_ptr),
		mem.ReadMemory<float>(cam_pos_z_ptr)
	);
}

std::tuple<float, float, float> Cheat::GetCameraTarget() {
	return std::make_tuple(
		mem.ReadMemory<float>(cam_target_x_ptr),
		mem.ReadMemory<float>(cam_target_y_ptr),
		mem.ReadMemory<float>(cam_target_z_ptr)
	);
}

void Cheat::SetCameraPosition(float x, float y, float z) {
	mem.WriteMemory<float>(cam_pos_x_ptr, x);
	mem.WriteMemory<float>(cam_target_x_ptr, x + 100);
	mem.WriteMemory<float>(cam_pos_y_ptr, y);
	mem.WriteMemory<float>(cam_target_y_ptr, y - 100);
	mem.WriteMemory<float>(cam_pos_z_ptr, z);
	mem.WriteMemory<float>(cam_target_z_ptr, z + 100);
}