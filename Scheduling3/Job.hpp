/*
 * Job.hpp
 *
 *  Created on: 22 sep. 2017
 *      Author: Stefan
 */

#ifndef JOB_HPP_
#define JOB_HPP_

#include <vector>

#include "Task.hpp"

class Job
{
public:
	Job();
	Job(int id, const std::vector<Task>& aTasks);
	virtual ~Job();

	unsigned int getDuration() const;

	const Task& getFirstTask() const;

	void removeFirstTask();

	bool hasTasks();

	int getId() const
	{
		return id;
	}

	unsigned int getEndTime() const
	{
		return endTime;
	}

	void setEndTime(unsigned int endTime)
	{
		this->endTime = endTime;
	}

	unsigned int getStartTime() const
	{
		return startTime;
	}

	void setStartTime(unsigned int startTime)
	{
		this->startTime = startTime;
	}

private:
	int id;
	unsigned int endTime;
	unsigned int startTime;
	std::vector<Task> tasks;
};

#endif /* JOB_HPP_ */
