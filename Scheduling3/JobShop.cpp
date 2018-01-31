/*
 * JobShop.cpp
 *
 *  Created on: 22 sep. 2017
 *      Author: Stefan
 */
#include <iostream>
#include <regex>
#include <fstream>
#include "JobShop.hpp"

JobShop::JobShop()
{
	// TODO Auto-generated constructor stub

}

JobShop::~JobShop()
{
	// TODO Auto-generated destructor stub
}

bool JobShop::readFile(std::string filePath)
{
	this->filePath = filePath;
	std::string line;
	std::cout << "inlezen: " << filePath << std::endl;

//	std::string path = "E:\\eclipseWorkspace\\scheduling\\Debug\\file.txt";
	std::ifstream stream(filePath);
	if (stream.is_open())
	{
		std::cout << "File is successfully opened" << std::endl;
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
			std::cout << readingLine << " " << line << '\n';
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
	//std::regex rx("(?:\\[[:digit:]]\\.)?\\d+");    // Declare the regex with a raw string literal
	std::regex rx(R"((?:^|\s)([+-]?[[:digit:]]+(?:\.[[:digit:]]+)?)(?=$|\s))"); // Declare the regex with a raw string literal (?:\d*\.)?\d+ (?:[digit]*\.)?\d+
	std::smatch m;
	char nrInLine = 0;
	while (regex_search(firstLine, m, rx)) {
		if (nrInLine == 0) {
			std::cout << "Jobs: " << m[1] << std::endl; // Get Captured Group 1 text
		}else{
			std::cout << "Machines: " << m[1] << std::endl; // Get Captured Group 1 text
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
			tasks.push_back(Task(taskId, machine, duration));
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
	std::cout << __PRETTY_FUNCTION__ << std::endl;



	machines.at(1).addTask(Task(0, 1, 6));
	machines.at(1).addTask(Task(2, 1, 2));
	machines.at(1).addTask(Task(3, 1, 9));
}
