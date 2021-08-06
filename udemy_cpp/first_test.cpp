



#include<iostream>
#include<fstream>
#include<string>

using namespace std;


int main(){

    cout << "+++++++++++++" << endl;
    cout << "File Streams" << endl;
    cout << "+++++++++++++" << endl;

    string text;


    // write the file
    ofstream ofile("hello.txt");
    if (ofile){
        cout << "Writing To File ..." << endl;
        ofile << "Hello, file!\n";
        ofile.close();
    }

    // read the file
    ifstream ifile("hello.txt");
    cout << "Example with getline:" << endl;
    while (getline(ifile, text)){
        cout << text << endl;
    }
    ifile.close();

    ifstream ifile2("hello.txt");
    cout << "Example with single word:" << endl;
    if (ifile2){
        cout << "GGG" << endl;
        ifile2 >> text;
        ifile2.close();
        cout << text << endl;
    }
    
    ifstream ifile3("hello.txt");
    cout << "Example with word by word:" << endl;
    while (ifile3 >> text){
        cout << text << ",";
    }
    ifile3.close();


    
    


    return 0;

}



