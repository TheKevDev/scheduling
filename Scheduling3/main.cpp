/*
 * main.cpp
 *
 *  Created on: 22 sep. 2017
 *      Author: Stefan
 */

#include <iostream>
#include <string>

#include "JobShop.hpp"

int main(int argc, char* argv[])
{
	if (argv[1])
	{
		JobShop JS;

		if (!JS.readFile(argv[1]))
		{
			throw std::runtime_error("Error: inlezen file niet geslaagd.");
		}
		else
		{
			JS.schedule();
		}
	}
	else
	{
		std::cerr << "Error: Geen pad naar bestand meegegeven" << std::endl;
	}

	return 0;
}
