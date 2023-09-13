// Program to clean KTP Applications, created F23 rush by Abby Hart :)
// reads data from .csv with applications and writes them onto .txt file (to go on google docs), automating the cleaning process

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ifstream ins("/Users/abbyhart/Desktop/eecs/KTP Application proj/KTParserr/applicationsfinal.tsv");
	ofstream outs("/Users/abbyhart/Desktop/eecs/KTP Application proj/KTParserr/KTParserr/output.txt");
    

	//file cannot be opened
	if (!ins.is_open()) {
		cout << "input file could not be opened" << '\n';
        exit(1);
	}
	else if (!outs.is_open()) {
		cout << "output file could not be opened" << '\n';
        exit(1);
	}

	string rNum;
	string junk;
	string contribute;
	string environment;
	string brand;
	string five;
	string hours;
	string additional;
    
    getline(ins, junk);
    if (ins.fail()) {
        cout << "Bad";
        cerr << "Error: " << strerror(errno);
    }
    
    int i = 0;
    //go until the number of applications to parse
	while (i <  165) {
        //check stream state
        cout << i << endl;
        
        if (ins.fail()) {
            cout << "bad1";
        }
        
        //read in rushee number
        ins >> rNum;
        
        //read in junk
        for (int j = 0; j < 16; j++) {
            getline(ins, junk, '\t');
        }
        
		//read in all necessary pieces of data from tsv file
		std::getline(ins, contribute, '\t');
		std::getline(ins, environment, '\t');
		std::getline(ins, brand, '\t');
		std::getline(ins, five, '\t');
		std::getline(ins, hours, '\t');
		std::getline(ins, additional, '\t');

		//output all data onto output txt file, formatted as general application cuts doc appears
		outs << "Rushee Number: " << rNum << '\n' << '\n';
		outs << "As a brother, how will you contribute to the KTP community?\n" << contribute << '\n' << '\n';
		outs << "Tell us about a time when you created an environment of honesty, inclusion, and respect for others.\n" 
				<< environment << '\n' << '\n';
		outs << "Name a brand you identify with and explain why?\n" << brand << '\n' << '\n';
		outs << "Where do you see yourself in five years?\n" << five << '\n' << '\n';
		outs << "What's something you could talk about for hours?\n" << hours << '\n' << '\n';
		
		//if additional information is provided, output as well
		if (additional != " ") {
			outs << "Anything else?\n" << additional << '\n' << '\n';
		}
        
        //read in additional junk from other questions
        getline(ins, junk);
        i++;
	}
    
    if (ins.fail()) {
        cout << "bad";
    }
}
