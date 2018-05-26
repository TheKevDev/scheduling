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

	/**
	 * @brief tries to open the given file
	 * @return true when the file has successfully been opened
	 * @return false when the file could not be opened for whatever reason
	 */
	bool readFile(std::string filePath);

	/**
	 * @brief tries to read the contents of the first line in the file opened with readFile().
	 * 		With those values it sets the nrOfMachines variable
	 * @return true if succeeded
	 * @return false if failed
	 */
	bool readFirstLine(std::string firstLine);

	/**
	 * @brief tries to read the contents of the remaining lines, until the end of the file.
	 * 		With those values it creates jobs and their tasks, and adds those to the vectors
	 * @return true if succeeded
	 * @return false if failed
	 */
	bool readJobLine(int id, std::string jobLine);

	/**
	 * @brief the part where the actual magic happens. In all seriousness, in this part the LST scheduling algorithm gets put to use.
	 * Steps that happen here:
	 * 1. Check if the jobs have tasks left. If not, break
	 * 2. Remove tasks from machines if they're done
	 * 3. Calculate the critical path using calculateCriticalPath()
	 * 4. Calculate slack time per job using calculateSlack()
	 * 5. Loop through all jobs, least slack first. If the first waiting task in a job can be assigned to a machine, assign it to a machine.
	 * 6. Add one to the time
	 * 7. When done, print the results
	 */
	void schedule();

	/**
	 * @brief As the name suggests, this function calculates the amount of slack time, according to the formula s = (d - t) - c
	 * 		where 's' is the amount of slack time,
	 * 		'd' is the deadline time, in our case the scheduled end time of the critical path,
	 * 		't' is the current time since the beginning of the simulation,
	 * 		'c' is the total computation time needed to finish the job
	 *
	 * @param job the job to calculate the slack time for
	 * @param critPath the critical path, from which we use the scheduled end time as deadline in the calculation
	 * @return the slack time
	 */
	unsigned int calculateSlack(const Job& job, const Job& critPath) const;

	/**
	 * @brief calculates the current critical path from the jobs vector
	 * @return the job which is the critical path
	 */
	Job& calculateCriticalPath();

private:
	std::string filePath;
	unsigned int nrOfachines;
	std::vector<Job> jobs;
	std::vector<Machine> machines;
	unsigned int currentTime;
};

#endif /* JOBSHOP_HPP_ */
