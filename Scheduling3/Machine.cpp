/*
 * Machine.cpp
 *
 *  Created on: 20 okt. 2017
 *      Author: Stefan
 */
#include <iostream>
#include "Machine.hpp"

Machine::Machine(int nr)
: machineNr(nr), startTime(0), endTime(0), busy(false), task(nullptr), task1(1,2,3)
{
	std::cout << __PRETTY_FUNCTION__ << " " << machineNr << std::endl;

}

Machine::~Machine()
{

}

void Machine::addTask(Task aTask)
{
	tasks.push_back(aTask);

	aTask.setStartTime(endTime);

	endTime += aTask.duration;

	std::cout << __PRETTY_FUNCTION__ << " " << endTime << std::endl;
}

const Task* Machine::getTask() const
{
	return task;
}

void Machine::setTask(const Task* task)
{
	this->task = task;

	busy = true;

	endTime += task->duration;
}
