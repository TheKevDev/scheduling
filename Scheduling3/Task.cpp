/*
 * Task.cpp
 *
 *  Created on: 22 sep. 2017
 *      Author: Stefan
 */
#include <iostream>

#include "Task.hpp"

Task::Task(long id, long jobId, long machine, long duration)
: duration(duration), id(id), jobId(jobId), machine(machine), startTime(0), endTime(0), planned(false), ES(0), LS(0)
{
}

Task::Task()
: duration(0), id(0), jobId(0), machine(0), startTime(0), endTime(0), planned(false), ES(0), LS(0)
{

}

Task::~Task()
{
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
