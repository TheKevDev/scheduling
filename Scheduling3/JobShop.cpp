/*
 * JobShop.cpp
 *
 *  Created on: 22 sep. 2017
 *      Author: Stefan
 */
#include <iostream>
#include <regex>
#include <fstream>
#include <map>

#include "JobShop.hpp"

JobShop::JobShop()
: nrOfachines(0), currentTime(1)
{
}

JobShop::~JobShop()
{
}

bool JobShop::readFile(std::string filePath)
{
	this->filePath = filePath;
	std::string line;
	std::ifstream stream(filePath);
	if (stream.is_open())
	{
		long readingLine = 0;
		while (getline(stream, line))
		{
			if (readingLine == 0)
			{
				if (!readFirstLine(line))
					throw std::runtime_error("Error: inlezen eerste regel faalt.");
			}
			else
			{
				if (!readJobLine(readingLine - 1, line))
					throw std::runtime_error("Error: inlezen jobs faalt.");
			}
			++readingLine;
		}
		stream.close();
	}
	else
	{
		std::cout << "While opening a file an error is encountered\n";
		return false;
	}

	return true;
}

bool JobShop::readFirstLine(std::string firstLine)
{
	std::regex rx(R"((?:^|\s)([+-]?[[:digit:]]+(?:\.[[:digit:]]+)?)(?=$|\s))"); // Declare the regex with a raw string literal (?:\d*\.)?\d+ (?:[digit]*\.)?\d+
	std::smatch m;
	char nrInLine = 0;
	while (regex_search(firstLine, m, rx))
	{
		if (nrInLine != 0)
		{
			nrOfachines = std::stoi(m[1]);
			return true;
		}
		firstLine = m.suffix().str(); // Proceed to the next match
		++nrInLine;
	}
	return false;
}

bool JobShop::readJobLine(int id, std::string jobLine)
{
	std::vector<Task> tasks;
	enum Reading { MACHINE, DURATION };
	Reading r = MACHINE;
	std::regex rx(R"((?:^|\s)([+-]?[[:digit:]]+(?:\.[[:digit:]]+)?)(?=$|\s))"); // Declare the regex with a raw string literal (?:\d*\.)?\d+ (?:[digit]*\.)?\d+
	std::smatch m;
	int machine, duration, taskId;
	taskId = 0;
	while (regex_search(jobLine, m, rx)) {
		if (r == MACHINE) {
			machine = std::stoi(m[1]);
			r = DURATION;
		}else{
			duration = std::stoi(m[1]);
			tasks.push_back(Task(taskId, id, machine, duration));
			++taskId;
			r = MACHINE;
		}

		jobLine = m.suffix().str(); // Proceed to the next match
	}
	jobs.push_back(Job(id, tasks));
	machines.push_back(Machine(id));
	if (r == DURATION)
		return false;
	return true;
}

void JobShop::schedule()
{
	for(;;)
	{
		bool tasksLeft = false;
		for (auto &job : jobs)
		{
			if (job.hasTasks()) tasksLeft = true;
		}

		if (!tasksLeft) break;

		for (auto &machine : machines)
		{
			if (machine.getEndTime() < currentTime && machine.isBusy())
			{
				machine.setBusy(false);
				jobs.at(machine.getTask().getJobId()).setEndTime(currentTime);
				jobs.at(machine.getTask().getJobId()).removeFirstTask();
			}
		}

		Job& critPath = calculateCriticalPath();
		std::multimap<unsigned int, Job&> jobsWithSlack;
		for (auto &job : jobs)
		{
			if(job.hasTasks())
			{
				jobsWithSlack.insert(std::pair<unsigned int, Job&>(calculateSlack(job, critPath), job));
			}
		}

		for (auto const& jws : jobsWithSlack)
		{
			const Task& firstTask = jws.second.getFirstTask();
			Machine& m = machines.at(firstTask.getMachine());
			if (!m.isBusy())
			{
				m.setTask(firstTask, currentTime - 1);
				if(jws.second.getEndTime() == 0)
				{
					jws.second.setStartTime(currentTime - 1);
				}
			}
		}
		++currentTime;
	}

	for (auto &job : jobs)
	{
		// Print result
		std::cout << job.getId() << " " << job.getStartTime() << " " << job.getEndTime() - 1 << std::endl;
	}
}

Job& JobShop::calculateCriticalPath()
{
	Job longestJob = jobs.front();

	for(auto const& job: jobs)
	{
		if (job.getDuration() > longestJob.getDuration())
		{
			longestJob = job;
		}
	}
	return jobs.at(longestJob.getId()); //TODO: fix...
}

unsigned int JobShop::calculateSlack(const Job& job, const Job& critPath) const
{
	return (critPath.getDuration() - currentTime) - (job.getDuration() - currentTime);
}
