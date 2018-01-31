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
private:
	int id;
	std::vector<Task> tasks;
};

#endif /* JOB_HPP_ */