#include "wordCount.h"
#include <iostream>
#include <string>
#include <map>
#include <fstream>


using namespace std;

bool isLetter(char c) {
	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));
}

string nextWordOrSeparator(string line, int pos) {
	int length = 1;
	bool check = isLetter(line.at(pos));

	while ((pos + length) < line.length() && check == isLetter(line.at(pos + length))) {
		length++;
	}

	return line.substr(pos, length);
}

map <string, int> addFreqFromFile(string inputFile) {

	map<string, int> freqMap;
	ifstream inFile;
	inFile.open(inputFile + ".txt");
	string line, word;
	int length = 0;
	
	if (inFile.is_open()) {
		while (!inFile.eof()) {
			getline(inFile, line);
			while (length < line.length()) {
				word = nextWordOrSeparator(line, length);
				if (isLetter(word.at(0))) {
					if (freqMap.count(word) == 0) {
						freqMap.insert(pair<string, int>(word, 1));
					} 	else {
						freqMap.at(word) = freqMap.at(word) + 1;
					}
				}
				length += word.length();
			}
			length = 0;
		}
	}

	inFile.close();

	return freqMap;
}