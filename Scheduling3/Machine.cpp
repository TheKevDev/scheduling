/*
 * Machine.cpp
 *
 *  Created on: 20 okt. 2017
 *      Author: Stefan
 */
#include <iostream>
#include "Machine.hpp"

Machine::Machine(int nr)
: machineNr(nr), startTime(0), endTime(0)
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
