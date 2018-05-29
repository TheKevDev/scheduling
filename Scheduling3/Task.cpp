/*
 * Task.cpp
 *
 *  Created on: 22 sep. 2017
 *      Author: Stefan
 */
#include <iostream>

#include "Task.hpp"

Task::Task(long id, long jobId, long machine, long duration)
: id(id), jobId(jobId), machine(machine), duration(duration)
{
}

Task::Task()
: id(0), jobId(0), machine(0), duration(0)
{

}

Task::~Task()
{
}
