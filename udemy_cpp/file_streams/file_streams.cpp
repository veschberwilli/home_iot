#include<iostream>
#include<fstream>
#include<string>
#include<iomanip> // setw()
#include<sstream> // stringstream


using namespace std;


int main(){

    cout << "+++++++++++++" << endl;
    cout << "File Streams" << endl;
    cout << "+++++++++++++" << endl;

    // Resource Management
    

    /*
    // Stringstream
    ostringstream ostr;
    string text;
    cout << "Please enter a word\n";
    cin >> text;
    ostr << setw(10) << text;
    cout << "Please enter another word\n";
    cin >> text;
    ostr << setw(5) << text;

    cout << ostr.str() << endl;
    */




    /*
    // Output formatting
    cout << setfill('.');
    cout << left << setw(20) << "Penguins" << 5 << "\n";
    cout << setw(20) << "Polar Bears" << 5 << "\n";
    cout << setfill(' ');
    */


    /*
    // write the file
    string text;
    ofstream ofile;
    
    ofile.open("hello.txt", ofstream::app | ofstream::binary); // binary mode append
    //ofstream ofile("hello.txt");
    if (ofile.is_open()){
        cout << "Writing To File ..." << endl;
        ofile << 42 << "\n";
        //ofile << "Hello, file!\n";
        ofile.close();
    }
    */

   /*
   int x;
   cout << "Please enter a number\n";
   cin >> x;

   if (cin.good()){
       cout << x << endl;
   }
   else if (cin.bad()) {
       cout << "Something has gone seriously wrong." << endl;
   }
   else if (cin.fail()) {
       cout << "Please try again." << endl;
   }
   */
   


    /*
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
    */

    
    


    return 0;

}



