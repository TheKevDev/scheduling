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
private:
	int machineNr;
	std::vector<Task> tasks;
	int startTime;
	int endTime;

};

#endif /* MACHINE_HPP_ */
