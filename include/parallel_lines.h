#pragma once

#include <functional>
#include <iostream>
#include <vector>

namespace parallel_lines
{
class scheduler
{
private:
	std::vector<std::function<void()>> functions;

public:
	scheduler(){};
	~scheduler(){};
	void update();
	void push(std::function<void()> func);

	static parallel_lines::scheduler *shared_scheduler();
};
}