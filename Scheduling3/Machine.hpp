/*
 * Machine.hpp
 *
 *  Created on: 20 okt. 2017
 *      Author: Stefan
 */

#ifndef MACHINE_HPP_
#define MACHINE_HPP_

#include <vector>

#include "Task.hpp"

class Machine
{
public:
	Machine(int nr);
	virtual ~Machine();

	bool isBusy() const
	{
		return busy;
	}
	void setBusy(bool busy)
	{
		this->busy = busy;
	}

	Task getTask() const;
	void setTask(Task task, unsigned int currentTime);

	unsigned int getEndTime() const
	{
		return endTime;
	}
	int getMachineNr() const
	{
		return machineNr;
	}

private:
	int machineNr;
	int startTime;
	unsigned int endTime;
	bool busy;
	Task task;
};

#endif /* MACHINE_HPP_ */
