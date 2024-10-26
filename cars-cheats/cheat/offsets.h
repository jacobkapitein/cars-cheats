#pragma once

namespace CarsOffsets {
	const unsigned int score_base = 0x003C73A4;
	const std::vector<unsigned int> score_offsets = { 0x2C, 0x130, 0x10, 0x8C, 0x124, 0x160 };

	// Player stuff
	const unsigned int player_base = 0x003C5920;
	const std::vector<unsigned int> player_x_offset = { 0x50 };
	const std::vector<unsigned int> player_y_offset = { 0x54 };
	const std::vector<unsigned int> player_z_offset = { 0x58 };

	// Camera stuff
	const unsigned int cam_base = 0x00396380;

	const std::vector<unsigned int> cam_pos_x_offset = { 0x38, 0x0c, 0x38, 0x27c, 0x00, 0x0 };
	const std::vector<unsigned int> cam_pos_y_offset = { 0x38, 0x0c, 0x38, 0x27c, 0x04, 0x0 };
	const std::vector<unsigned int> cam_pos_z_offset = { 0x38, 0x0c, 0x38, 0x27c, 0x08, 0x0 };

	const std::vector<unsigned int> cam_target_x_offset = { 0x38, 0x0c, 0x10, 0x280, 0x00, 0x0 };
	const std::vector<unsigned int> cam_target_y_offset = { 0x38, 0x0c, 0x10, 0x280, 0x04, 0x0 };
	const std::vector<unsigned int> cam_target_z_offset = { 0x38, 0x0c, 0x10, 0x280, 0x08, 0x0 };
}