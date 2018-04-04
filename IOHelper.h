#ifndef _IOHELPER_H_
#define _IOHELPER_H_

#include "Matrix.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

// Reads the entire file into a Matrix
Matrix readFile(std::string fname) {
	std::ifstream infile(fname);
	std::string line;
	std::vector< std::vector<double> > dataVec;

	while (std::getline(infile, line)) {
		if (line.size() == 0) {
			break;
		}
		std::istringstream iss(line);
		std::vector<double> tempVec;
		double d;
		while (iss >> d) {
			tempVec.push_back(d);
		}
		dataVec.push_back(tempVec);
	}
	return Matrix(dataVec);
}

Matrix readFile(std::string fname, int numAttributes) {
	std::ifstream infile(fname);
	std::string line;
	std::vector< std::vector<double> > dataVec;

	while (std::getline(infile, line)) {
		if (line.size() == 0) {
			break;
		}
		std::istringstream iss(line);
		std::vector<double> tempVec;
		double d;
		for (int i = 0; i < numAttributes; i++) {
			iss >> d;
			tempVec.push_back(d);
		}
		dataVec.push_back(tempVec);
	}
	return Matrix(dataVec);
}

Matrix readFileColumn(std::string fname, int columnIdx) {
	std::ifstream infile(fname);
	std::string line;
	std::vector< std::vector<double> > dataVec;

	while (std::getline(infile, line)) {
		if (line.size() == 0) {
			break;
		}
		std::istringstream iss(line);
		std::vector<double> tempVec;
		double d;
		for (int i = 0; i < columnIdx; i++) {
			iss >> d;
		}
		tempVec.push_back(d);
		dataVec.push_back(tempVec);
	}
	return Matrix(dataVec);
}

// reads the first numLines entries into the matrix
Matrix readNumLines(std::string fname, int numLines) {
	std::ifstream infile(fname);
	std::string line;
	std::vector< std::vector<double> > dataVec;

	int i = 0;
	while (std::getline(infile, line)) {
		if (i >= numLines) {
			break;
		}
		std::istringstream iss(line);
		std::vector<double> tempVec;
		double d;
		while (iss >> d) {
			tempVec.push_back(d);
		}
		dataVec.push_back(tempVec);
		i++;
	}
	return Matrix(dataVec);
}

// Reads lines starting at start index
Matrix readFileFrom(std::string fname, int start) {
	std::ifstream infile(fname);
	std::string line;
	std::vector< std::vector<double> > dataVec;

	for (int i = 0; i < start; i++) {
		std::getline(infile, line);
	}

	while (std::getline(infile, line)) {
		std::istringstream iss(line);
		std::vector<double> tempVec;
		double d;
		while (iss >> d) {
			tempVec.push_back(d);
		}
		dataVec.push_back(tempVec);
	}
	return Matrix(dataVec);

}


#endif

