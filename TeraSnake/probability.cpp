#include "probability.h"

bool chance(std::string requestedChance) {
	std::string converter;
	int theNumber;
	int randomizedNumber;

	if (requestedChance[requestedChance.length() - 1] != '%') {
		std::cerr << "COULDN'T RUN" << std::endl;
		return false;
	}

	for (int i = 0; i < (int)requestedChance.length() - 1; i++) {
		converter = converter + requestedChance[i];
	}

	theNumber = (int)((std::stod(converter)) * 100000);

	// Windows random generation stuff
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, 10000000);

	randomizedNumber = dist(gen);

	if (randomizedNumber < theNumber) {
		return true;
	}
	return false;
}

void statistics_reader(int falseOutput, int trueOutput) {
	int totalAmount = falseOutput + trueOutput;

	std::cout << "This is the percentage for FALSE: " << ((float)falseOutput / totalAmount) * 100 << "%" << std::endl;
	std::cout << "This is the percentage for TRUE: " << ((float)trueOutput / totalAmount) * 100 << "%" << std::endl;
}
