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

	/**
	 * @brief Removes the first waiting task from the job
	 */
	void removeFirstTask();

	/**
	 * @brief checks if a job has tasks left
	 * @return false when there are no tasks left
	 * @return true when there are tasks left
	 */
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
