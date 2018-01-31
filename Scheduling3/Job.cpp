/*
 * Job.cpp
 *
 *  Created on: 22 sep. 2017
 *      Author: Stefan
 */
#include <iostream>
#include "Job.hpp"

Job::Job()
{
	// TODO Auto-generated constructor stub

}

Job::~Job()
{
	// TODO Auto-generated destructor stub
}

Job::Job(int id, const std::vector<Task>& aTasks)
: id(id)
{
	tasks = aTasks;
	std::cout << __PRETTY_FUNCTION__ << " " << id << std::endl;
}
