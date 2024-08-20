#pragma once
#include <string>
#include <iostream>

class StatusManager {
public:
	static int tasksDone;
	static int totalTasks;
	static std::string status;

	static void Update();

	static void SetStatus(std::string newStatus);

	static void SetProgress(int done, int total);
};