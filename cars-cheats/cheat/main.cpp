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
			cheat.SetScore(score + 100);
		}

		std::tuple<float, float, float> car_pos = cheat.GetPosition();

		if (GetAsyncKeyState('M') & 1) {
			cheat.SetPosition(std::get<0>(car_pos) + 100, std::get<1>(car_pos), std::get<2>(car_pos));
		}
		if (GetAsyncKeyState('I') & 1) {
			cheat.SetPosition(std::get<0>(car_pos) - 100, std::get<1>(car_pos), std::get<2>(car_pos));
		}
		if (GetAsyncKeyState('J') & 1) {
			cheat.SetPosition(std::get<0>(car_pos), std::get<1>(car_pos), std::get<2>(car_pos) - 100);
		}
		if (GetAsyncKeyState('L') & 1) {
			cheat.SetPosition(std::get<0>(car_pos), std::get<1>(car_pos), std::get<2>(car_pos) + 100);
		}
		if (GetAsyncKeyState('K') & 1) {
			cheat.SetPosition(std::get<0>(car_pos), std::get<1>(car_pos) + 100, std::get<2>(car_pos));
		}
		std::cout << "X -> " << std::get<0>(car_pos) << "; Y -> " << std::get<1>(car_pos) << "; Z -> " << std::get<2>(car_pos) << std::endl;



		std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }

    return 0;
}
