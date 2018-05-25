/*
 * Machine.hpp
 *
 *  Created on: 20 okt. 2017
 *      Author: Stefan
 */

#ifndef MACHINE_HPP_
#define MACHINE_HPP_

#include "Task.hpp"
#include <vector>

class Machine
{
public:
	Machine(int nr);
	virtual ~Machine();
	void addTask(Task aTask);

	bool isBusy() const
	{
		return busy;
	}

	Task getTask() const;
	void setTask(Task task1);

private:
	int machineNr;
	std::vector<Task> tasks;
	int startTime;
	int endTime;
	bool busy;
	Task task;

};

#endif /* MACHINE_HPP_ */
