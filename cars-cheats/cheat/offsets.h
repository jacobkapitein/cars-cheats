#pragma once

namespace CarsOffsets {
	const unsigned int score_base = 0x003C73A4;
	const std::vector<unsigned int> score_offsets = { 0x2C, 0x130, 0x10, 0x8C, 0x124, 0x160 };

	const unsigned int player_base = 0x003C5920;
	const std::vector<unsigned int> player_x_offset = { 0x50 };
	const std::vector<unsigned int> player_y_offset = { 0x54 };
	const std::vector<unsigned int> player_z_offset = { 0x58 };

	const unsigned int camera_from_x_
}