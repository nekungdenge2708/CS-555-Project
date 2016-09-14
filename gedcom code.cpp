/*
Michelle Wong
CS-555
Project 02
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream gedcomFile;
    ofstream output;
    string gedcomLine;
    string levelNum, tag;
    string delimiter = " ";
    int level;
    
    output.open("output.txt");
    
    // Check for command line args.
    if(argc != 2) {
            output << "Invalid file!" << endl;
            cout << "Invalid file!" << endl;
    }
    
    // Open file.
    gedcomFile.open(argv[1]);
    
    // Check file.
    if(!gedcomFile.is_open()) {
         output << "Failed to open file! Exiting..." << endl;
         cout << "Failed to open file! Exiting..." << endl;
         cin.ignore();
         return 0;
    }
    
    output << "-----------------------------------------------" << endl;
    output << "File \"" << argv[1] << "\" opened!"<< endl;
    output << "Reading and Printing file..." << endl;
    output << "-----------------------------------------------" << endl;
    
    cout << "-----------------------------------------------" << endl;
    cout << "File \"" << argv[1] << "\" opened!"<< endl;
    cout << "Reading and Printing file..." << endl;
    cout << "-----------------------------------------------" << endl;
    
    // Read file line by line.
    while(getline(gedcomFile, gedcomLine)) {
           output << gedcomLine << endl;
           cout << gedcomLine << endl;
           
           // Get and print level number.
           levelNum = gedcomLine.substr(0, gedcomLine.find(delimiter));
           level = atoi(levelNum.c_str());
           output << "Level Number: " << level << endl;
           cout << "Level Number: " << level << endl;
           
           // Don't care about preserving the string.
           gedcomLine.erase(0, gedcomLine.find(delimiter)+1);
           
           // Get and print tag/invalid tag.
           tag = gedcomLine.substr(0, gedcomLine.find(delimiter));
           // Check tag/level
           if(level == 0) {
                if(!(tag.compare("HEAD") == 0) && !(tag.compare("TRLR") == 0) && !(tag.compare("NOTE") == 0)) {
                    // Check for/skip xrefid
                    gedcomLine.erase(0, gedcomLine.find(delimiter)+1);
                    tag = gedcomLine.substr(0, gedcomLine.find(delimiter));
                    
                    if(!(tag.compare("INDI") == 0) && !(tag.compare("FAM") == 0)) {
                       tag = "Invalid tag!";
                    }
                }
           } else if (level == 1) {
                if(!(tag.compare("NAME") == 0) && !(tag.compare("SEX") == 0) && !(tag.compare("BIRT") == 0)&& !(tag.compare("DEAT") == 0) && !(tag.compare("FAMC") == 0) && !(tag.compare("FAMS") == 0) && !(tag.compare("MARR") == 0) && !(tag.compare("HUSB") == 0) && !(tag.compare("WIFE") == 0) && !(tag.compare("CHIL") == 0) && !(tag.compare("DIV") == 0)) {
                   tag = "Invalid tag!";
                }
           } else if (level == 2) {
                if(!(tag.compare("DATE") == 0)) {
                   tag = "Invalid tag!";
                }
           }
           
           output << "Tag: " << tag << endl;
           cout << "Tag: " << tag << endl;
           
           // Make output look neat and pretty.
           output << "---------" << endl;
           cout << "---------" << endl;
    }
    
    gedcomFile.close();
    output.close();

    cin.ignore();
    return 0;
}
