/*
 * Machine.cpp
 *
 *  Created on: 20 okt. 2017
 *      Author: Stefan
 */
#include <iostream>
#include "Machine.hpp"

Machine::Machine(int nr)
: machineNr(nr), startTime(0), endTime(0), busy(false), task()
{
}

Machine::~Machine()
{
}

void Machine::addTask(Task aTask)
{
	tasks.push_back(aTask);
	aTask.setStartTime(endTime);
	endTime += aTask.duration;
}

Task Machine::getTask() const
{
	return task;
}

void Machine::setTask(Task task, unsigned int currentTime)
{
	this->task = task;
	busy = true;
	endTime = task.duration + currentTime;
}
