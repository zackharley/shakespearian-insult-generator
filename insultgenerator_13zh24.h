/*
 * insultgenerator_13zh24.h
 *
 *  Created on: Sep 28, 2016
 *      Author: zackh_000
 */

#pragma once

#include <string>
#include <vector>

using namespace std;

/**
 * An exception class used when read/write access is denied or fails for a given file.
 *
 * @class FileException
 */
class FileException {
public:
	/**
	 * Constructor method for the FileException class
	 *
	 * @param const string& message - The message to display for the instance of the error.
	 * @constructor
	 */
	FileException(const string& message);
	/**
	 * Method used to retrieve the message that corresponds to this instance of
	 * FileException
	 *
	 * @return string& message - The message to display for the instance of the error.
	 */
	string& what();
private:
	string message; // The message to display for the instance of the error.
};

/**
 * An exception class used when the number of insults requested is out of the specified
 * range.
 *
 * @class NumInsultsOutOfBounds
 */
class NumInsultsOutOfBounds {
public:
	/**
	 * Constructor method for the NumInsultsOutOfBounds class
	 *
	 * @param const string& message - The message to display for the instance of the error.
	 * @constructor
	 */
	NumInsultsOutOfBounds(const string& message);
	/**
	 * Method used to retrieve the message that corresponds to this instance of
	 * NumInsultsOutOfBounds.
	 *
	 * @return string& message - The message to display for the instance of the error.
	 */
	string& what();
private:
	string message; // The message to display for the instance of the error.
};

/**
 * A class used to generate Shakespearian insults in the form "Thou ____ _____ _____!".
 * To use this class, you must create a new instance of InsultGenerator then call the
 * initialize method to load the different insults from the file.
 *
 * @class InsultGenerator
 */
class InsultGenerator {
public:
	/**
	 * Constructor method for the InsultsGenerator class
	 *
	 * @constructor
	 */
	InsultGenerator();
	/**
	 * This method reads the possible insults from a file and stores them as class
	 * attributes.
	 */
	void initialize();
	/**
	 * This method generates one random insult
	 *
	 * @returns string insult - An insult in the form "Thou ____ _____ _____!"
	 * @throws FileException
	 */
	string talkToMe();
	/**
	 * This method generates between 1 and 10,000 random insults and returns them in a
	 * sorted vector.
	 *
	 * @param const int& numberOfInsults - The number of insults to generate.
	 * @returns vector<string> insults - A sorted list containing the randomly generated
	 * insults.
	 * @throws NumInsultsOutOfBounds
	 */
	vector<string> generate(const int& numberOfInsults);
	/**
	 * This method generates between 1 and 10,000 random insults and saves them in
	 * text file with a given name.
	 *
	 * @param const string& filename - The name of the file that the insults are to
	 * be saved to.
	 * @param const int& numberOfInsults - The number of insults to generate.
	 * @throws FileException
	 * @throws NumInsultsOutOfBounds
	 */
	void generateAndSave(const string& filename, const int& numberOfInsults);
private:
	vector<string> insultsColumn1; // insults from column 1 of the source file
	vector<string> insultsColumn2; // insults from column 2 of the source file
	vector<string> insultsColumn3; // insults from column 3 of the source file
};
