#include <iostream>
#include <Windows.h>
#include <thread>
#include "cheat.cpp"

int main() {
	Cheat cheat("Cars.exe");

    if (!cheat.initialized) {
		if (GetLastError() == ERROR_ACCESS_DENIED)
			std::cerr << "Access denied. Run as administrator." << std::endl;
		else
			std::cerr << "Failed to get a handle. Error code: " << GetLastError() << std::endl;
        return 1;
    }

    while (true) {
		system("cls");
		//// When the user presses enter, add 100 to the final value address
		int score = cheat.GetScore();
		std::cout << "Score: " << score << std::endl;
		if (GetAsyncKeyState(VK_RETURN) & 1) {
			cheat.SetScore(score + 10000);
		}

		std::tuple<float, float, float> car_pos = cheat.GetPlayerPosition();

		// Print player post
		std::cout << std::endl << "Player Pos:" << std::endl;
		std::cout << "X -> " << std::get<0>(car_pos) << std::endl;
		std::cout << "Y -> " << std::get<1>(car_pos) << std::endl;
		std::cout << "Z -> " << std::get<2>(car_pos) << std::endl;

		std::tuple<float, float, float> cam_pos = cheat.GetCameraPosition();
		std::tuple<float, float, float> cam_target = cheat.GetCameraTarget();

		std::cout << std::endl << "Camera:" << std::endl;
		std::cout << "X -> " << std::get<0>(cam_pos) << " - " << std::get<0>(cam_target) << std::endl;
		std::cout << "Y -> " << std::get<1>(cam_pos) << " - " << std::get<1>(cam_target) << std::endl;
		std::cout << "Z -> " << std::get<2>(cam_pos) << " - " << std::get<2>(cam_target) << std::endl;

		// Takeover cam
		if (GetAsyncKeyState('I') & 1) {
			cheat.SetCameraPosition(std::get<0>(cam_pos) + 10, std::get<1>(cam_pos), std::get<2>(cam_pos));
		}
		if (GetAsyncKeyState('K') & 1) {
			cheat.SetCameraPosition(std::get<0>(cam_pos) - 10, std::get<1>(cam_pos), std::get<2>(cam_pos));
		}
		if (GetAsyncKeyState('L') & 1) {
			cheat.SetCameraPosition(std::get<0>(cam_pos), std::get<1>(cam_pos), std::get<2>(cam_pos) + 10);
		}
		if (GetAsyncKeyState('J') & 1) {
			cheat.SetCameraPosition(std::get<0>(cam_pos), std::get<1>(cam_pos), std::get<2>(cam_pos) - 10);
		}
		if (GetAsyncKeyState('O') & 1) {
			cheat.SetCameraPosition(std::get<0>(cam_pos), std::get<1>(cam_pos) + 10, std::get<2>(cam_pos));
		}
		if (GetAsyncKeyState('U') & 1) {
			cheat.SetCameraPosition(std::get<0>(cam_pos), std::get<1>(cam_pos) - 10, std::get<2>(cam_pos));
		}


		std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }

    return 0;
}
