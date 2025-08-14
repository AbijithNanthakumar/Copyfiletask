
#include <fstream>
#include <iostream>
using namespace std;

//  declaration of function
void initialization(ifstream &inputFile);
bool check(const string &filename);
void process(const string &startfile, const string &endfile);
void write(ifstream &firstfile, ofstream &secondfile);
void termination(ifstream &inputFile,ifstream &secondFile);
void print(ifstream &inputFile,ifstream &secondFile);

int main() {
    ifstream inputFile("student.csv");
    ifstream secondFile("teacher.csv");
    initialization(inputFile);
    process("student.csv","teacher.csv");
    print(inputFile,secondFile);
    termination(inputFile,secondFile);
    
    return 0;
}

// Initialization :
void initialization(ifstream &inputFile) {
    // a file is checked opened
    if (!inputFile.is_open()) {
        cerr << "File 'student.csv' could not be opened .\n";
        return;
    }

    ifstream secondfile("b.csv");

    if(!secondfile.is_open()){
        cout << "No file is created or formed \n";
        fstream secfile("teacher.csv", ios::out | ios::trunc);
    
    }
    else{        
        // Clear b.csv
    ofstream secondFile("teacher.csv", ios::trunc); // ostream for open and write purpose
                                              //:::: truc used to clear the data present in the csv file.
                      // Check if b.csv is empty
    bool isCleared = check("teacher.csv");

    if (isCleared) {
        cout << " teacher.csv Data cleared.\n";
    } else {
        cout << " Data not cleared.\n";
    }                        // ios is used get constants that can be used to modify code.
    
    secondFile.close();
    
}

 }

// check
bool check(const string &filename) {
    ifstream file(filename);
    return file.peek() == ifstream::traits_type::eof();   // ?
                                                         // represents the eof of the file 
                                                         //::: this is because of character traits class
                                                         // safe to use                                          
}

// Process::::::::::::::::::::::::
void process(const string &startfile, const string &endfile){

    // reading::::
    ifstream firstfile(startfile);
    ofstream secondfile(endfile);

    if(firstfile.is_open()){
       cout << "The secondfile is opened \n";
    }

    
    //writting it on the other file::::::::::
    write(firstfile,secondfile);

}

// Writting 
void write(ifstream &firstfile, ofstream &secondfile){
  string writeline;
    while(getline(firstfile,writeline)){
        secondfile << writeline << "\n";
    }
}

// printing
void print(ifstream &inputFile,ifstream &secondFile){
    string writeline;
    while(getline(secondFile,writeline)){
        cout << writeline << "\n";
    }
}

// Termination
void termination(ifstream &inputFile,ifstream &secondFile){
    // ifstream input(inputFile);
    // ifstream output(secondFile);
    inputFile.close();
    secondFile.close();
}