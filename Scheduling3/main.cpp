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
	if (argv[1]){
		std::cout << "ok" << std::endl;
		JobShop JS;

		if (!JS.readFile(argv[1]))
			throw std::runtime_error("Error: inlezen file faalt.");
		else
			std::cout << "File is ingelezen." << std::endl;

		JS.schedule();





	}else{
		std::cerr << "geen pad naar bestand meegegeven" << std::endl;
	}

//
//
//	std::string test;
//	std::cin >> test;

	return 0;
}
