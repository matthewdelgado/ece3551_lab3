#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <iostream>

using namespace std::chrono;

int gameShow(int, int);

int main() {
	// init random seed
	srand(time(NULL));
	
	// get starting time
	auto start = high_resolution_clock::now();
	
	int playersPoints = gameShow(rand() % 11, rand() % 11);

	// get end time
	auto stop = high_resolution_clock::now();
	
	// calculate the duration
	auto duration = duration_cast<microseconds>(stop - start);

	std::cout << "You took " << duration.count() << " microseconds to answer correctly." << std::endl;
	std::cout << "You earned " << playersPoints << " points." << std::endl;
}

int gameShow(int valueX, int valueY) 
{
	int answer = valueX + valueY;
	int userInput = -1;
	// player begins game with 10 points and loses 1 point every time while loops.
	int playerHasPoints = 10;
	
	// loop runs until user inputs correct answer
	while (userInput != answer && playerHasPoints) 
	{
		std::cout << "What is " << valueX << " + " << valueY << "?" << std::endl;
		std::cin >> userInput;
		
		if (userInput == answer) 
		{
			std::cout << "Correct!" << std::endl;
		}
		else 
		{
			std::cout << "Incorrect. Try Again." << std::endl;
			playerHasPoints--;
		}
	}
	return playerHasPoints;
}
