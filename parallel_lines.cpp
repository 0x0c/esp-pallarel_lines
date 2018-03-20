#include "parallel_lines.h"

namespace parallel_lines
{
void scheduler::update()
{
	if (!this->functions.empty()) {
		// xSemaphoreTake(this->mutex, portMAX_DELAY);
		for (int i = 0; i < this->functions.size(); ++i) {
			this->functions[i]();
		}
		this->functions.clear();
		// xSemaphoreGive(this->mutex);
	}
}

void scheduler::push(std::function<void()> func)
{
	// xSemaphoreTake(this->mutex, portMAX_DELAY);
	this->functions.push_back(func);
	// xSemaphoreGive(this->mutex);
}

parallel_lines::scheduler *scheduler::shared_scheduler()
{
	static scheduler shared_instance;
	return &shared_instance;
}
}