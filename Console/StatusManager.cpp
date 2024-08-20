#include "StatusManager.h"

int StatusManager::tasksDone = 0;
int StatusManager::totalTasks = 0;
std::string StatusManager::status = "";

void StatusManager::Update() {
	int statusMaxLength = 32;
	std::string subStatusString = status.substr(0, statusMaxLength);
	int newStatusLength = subStatusString.length();
	if (newStatusLength < statusMaxLength) {
		for (int i = 0; i < (statusMaxLength - newStatusLength); i++) {
			subStatusString += " ";
		}
	}
	std::cout << subStatusString;
	std::cout << " [";
	int barWidth = 50;
	if (totalTasks != 0) {
		float ratio = static_cast<float>(tasksDone) / static_cast<float>(totalTasks);
		int barPosition = static_cast<int>(barWidth * ratio);
		int percentage = static_cast<int>(ratio * 100);

		if (barPosition < 0) {
			barPosition = 0;
		}

		if (barPosition > barWidth) {
			barPosition = barWidth;
		}

		for (int i = 1; i <= barWidth; i++) {
			if (i > barPosition) {
				std::cout << " ";
			}
			if (i == barPosition) {
				std::cout << ">";
			}
			if (i < barPosition) {
				std::cout << "=";
			}
		}

		std::cout << "] ";
		if (percentage < 10) {
			std::cout << percentage;
			std::cout << "%  ";
		}
		else if (percentage < 100) {
			std::cout << percentage;
			std::cout << "% ";
		}
		else {
			std::cout << "100%";
		}
		
		std::cout << "\r";
	}
	else {
		for (int i = 1; i <= barWidth; i++) {
			std::cout << " ";
		}
		std::cout << "] 0%  \r";
	}

	std::cout.flush();
}

void StatusManager::SetStatus(std::string newStatus) {
	status = newStatus;
	tasksDone = 0;
	totalTasks = 0;
	Update();
}

void StatusManager::SetProgress(int done, int total) {
	tasksDone = done;
	totalTasks = total;
	Update();
}
