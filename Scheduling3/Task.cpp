/*
 * Task.cpp
 *
 *  Created on: 22 sep. 2017
 *      Author: Stefan
 */
#include <iostream>
#include "Task.hpp"

Task::Task(long id, long machine, long duration)
: duration(duration), id(id), machine(machine), startTime(0), endTime(0), planned(false), ES(0), LS(0)
{
	std::cout << __PRETTY_FUNCTION__ << " " << id << " " << machine << " " << duration << std::endl;
}

Task::~Task()
{
	// TODO Auto-generated destructor stub
}

void Task::setStartTime(long startTime)
{
	this->startTime = startTime;
	this->endTime = startTime + duration;
}

void Task::setEndTime(long endTime)
{
	this->endTime = endTime;
}

void Task::setPlanned(bool planned)
{
	this->planned = planned;
}
