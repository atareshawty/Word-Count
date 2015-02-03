/*
	This program is to mimic a project written in a Java course. Given an arbitrary text file
	we'll count the frequency of each word in the file. A 'word' here is defined as a string
	of consecutive letter characters. Until I get more time, capitalized words will be considered 
	different than lowercase words.
*/
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include "wordCount.h"

using namespace std;

int main() {

	string file;
	cout << "What is your file name (minus the .txt): ";
	cin >> file;
	map<string, int> freqMap = addFreqFromFile(file);
	ofstream toFile;
	toFile.open("freq.txt");

	for (pair<string, int> x: freqMap) {
		toFile << "[" << x.first << "," << x.second << "]" << endl;
	}

	toFile.close();

	return 0;
}