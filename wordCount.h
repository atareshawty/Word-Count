//Functions used for wordCount.cpp
#ifndef WORD_COUNT_H
#define WORD_COUNT_H

#include <string>
#include <map>

using namespace std;

//Returns true iff 'c' is a capital or lower case letter
bool isLetter(char c);

/*
	Starting at 'pos' will return the resulting a substring of 'line'
	If line.at(pos) is not a letter, the returned string will be 
	every consecutive non letter in 'line' until a letter is reached and vice versa
*/
std::string nextWordOrSeparator(string line, int pos);

//Will return a map with words(keys) and their frequencies(values) from a txt file
std::map <std::string, int> addFreqFromFile(std::string inputFile);

#endif