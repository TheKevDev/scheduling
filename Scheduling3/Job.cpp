/*
 * Job.cpp
 *
 *  Created on: 22 sep. 2017
 *      Author: Stefan
 */
#include <iostream>
#include "Job.hpp"

Job::Job()
: id(0), endTime(0), startTime(0)
{
}

Job::~Job()
{
}

Job::Job(int id, const std::vector<Task>& aTasks)
: id(id), endTime(0), startTime(0)
{
	tasks = aTasks;
}

unsigned int Job::getDuration() const
{
	unsigned int duration = 0;
	for(auto const& task: tasks)
	{
		duration += task.getDuration();
	}
	return duration;
}

const Task& Job::getFirstTask() const
{
	return tasks.front();
}

void Job::removeFirstTask()
{
	tasks.erase(tasks.begin());
}

bool Job::hasTasks()
{
	return !tasks.empty();
}
