#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <stdlib.h>

#include "insultgenerator_13zh24.h"

using namespace std;

FileException::FileException(const string& message) : message(message) {}

string& FileException::what() {
	return message;
}

NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& message) : message(message) {}

string& NumInsultsOutOfBounds::what() {
	return message;
}

InsultGenerator::InsultGenerator() {}

void InsultGenerator::initialize() {
	char filename[] = "InsultsSource.txt";
	ifstream insultsIn(filename);
	string line;
	int lineNumber = 0;

	if(insultsIn.fail()) {
		ostringstream message;
		message << "Unable to open file: " << filename;
		throw FileException(message.str());
	}

	while(getline(insultsIn, line)) {
		stringstream lineStream(line);
		string word;
		for(int i = 0; i < 3; i++) {
			lineStream >> word;
			switch(i) {
				case 0:
					insultsColumn1.push_back(word);
					break;
				case 1:
					insultsColumn2.push_back(word);
					break;
				case 2:
					insultsColumn3.push_back(word);
					break;
			}
		}
		lineNumber++;
	}
}

string InsultGenerator::talkToMe() {
	int row1Number = rand() % insultsColumn1.size();
	int row2Number = rand() % insultsColumn2.size();
	int row3Number = rand() % insultsColumn3.size();
	string insult = "Thou ";

	insult += insultsColumn1.at(row1Number) + " ";
	insult += insultsColumn2.at(row2Number) + " ";
	insult += insultsColumn3.at(row3Number) + "!";

	return insult;
}

vector<string> InsultGenerator::generate(const int& numberOfInsults) {
	vector<string> insults;
	const unsigned int totalNumberOfInsults = 10000;

	if((unsigned int)numberOfInsults > totalNumberOfInsults || numberOfInsults <= 0) {
		ostringstream message;
		message << "The number of insults " << numberOfInsults << " is not in between 1 and " <<
				totalNumberOfInsults << ". Please enter a valid number.";
		throw NumInsultsOutOfBounds(message.str());
	}

	while(insults.size() < (unsigned int)numberOfInsults) {
		insults.push_back(this->talkToMe());
	}

	sort(insults.begin(), insults.end());

	return insults;
}

void InsultGenerator::generateAndSave(const string& filename, const int& numberOfInsults) {
	ofstream fileOut(filename.c_str());
	int lineCount(0);
	int lines(0);
	vector<string> insults;

	try {
		insults = this->generate(numberOfInsults);
		lines = insults.size();
	} catch(NumInsultsOutOfBounds& e) {
		throw e;
	}

	if(fileOut.fail()) {
		ostringstream message;
		message << "Unable to open file: " << filename;
		throw FileException(message.str());
	}

	while(lineCount < lines) {
		fileOut << insults.at(lineCount) << endl;
		lineCount++;
	}
}
