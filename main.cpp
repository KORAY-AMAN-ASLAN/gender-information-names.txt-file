#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

/**
 * Determines the gender based on the second-to-last digit of a personal identification number (PID).
 *
 * @param personalNumber The PID to analyze.
 * @return True if the PID corresponds to a male, false for female.
 */
bool isMale(const std::string& personalNumber);
/**
 * Processes a file containing personal information and appends gender information to names.
 *
 * @param inputFilename  The name of the input file to read from.
 * @param outputFilename The name of the output file to write results to.
 */
void processFile(const std::string& inputFilename, const std::string& outputFilename);


int main() {
    std::string inputFilename = "C:/Users/amana/CLionProjects/readfile/names.txt";
    std::string outputFilename = "C:/Users/amana/CLionProjects/readfile/output.txt";

    processFile(inputFilename, outputFilename);

    std::cout << "Processing complete. Check " << outputFilename << " for results.\n";
    return 0;
}

bool isMale(const std::string& personalNumber) {
    // Check if the string has at least 9 characters
    if (personalNumber.length() < 9) {
        // Handle invalid input if the string is too short
        return false;
    }

    // Gender is determined by the second to last digit.
    // Odd for male, even for female.
    char genderChar = personalNumber[personalNumber.length() - 2];
    return genderChar % 2 != 0;
}


void processFile(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inputFile(inputFilename);
    std::ofstream outputFile(outputFilename);

    std::string firstname, lastname, personalNumber, address;

    while (inputFile >> firstname >> lastname) {
        inputFile >> personalNumber;
        inputFile.ignore(); // Ignore the newline character after reading personalNumber
        std::getline(inputFile, address);

        outputFile << lastname << " " << firstname;
        outputFile << (isMale(personalNumber) ? " [M]" : " [K]") << std::endl;
        outputFile << address << std::endl << std::endl; // Add an extra newline for spacing
    }
}
