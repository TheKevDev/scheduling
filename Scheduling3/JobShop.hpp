/*
 * JobShop.hpp
 *
 *  Created on: 22 sep. 2017
 *      Author: Stefan
 */

#ifndef JOBSHOP_HPP_
#define JOBSHOP_HPP_
#include <vector>
#include <string>

#include "Job.hpp"
#include "Task.hpp"
#include "Machine.hpp"

class JobShop
{
public:
	JobShop();
	virtual ~JobShop();

	bool readFile(std::string filePath);
	bool readFirstLine(std::string firstLine);
	bool readJobLine(int id, std::string jobLine);

	void schedule();

	Job& calculateCriticalPath();

private:
	std::string filePath;
	int nrOfachines;
	std::vector<Job> jobs;
	std::vector<Machine> machines;
};

#endif /* JOBSHOP_HPP_ */
