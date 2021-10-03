#include <vector>
#include <iostream>
#include <cctype>
using namespace std;


int main(){

    vector<int> vec = {1,2,3};
    cout << vec[0] << endl;

    vector<int>::iterator it = vec.begin();
    auto it2 = vec.begin();

    for (auto v : vec){
        cout << v << endl;
    }

    while (it != vec.end()){
        cout << *it << endl;
        it++;
    }
    
    vector<string> vec2 = {"Hallo", "Bonjour"};
    for (auto v : vec2){
        cout << v << endl;
    }

    string text1, text2;
    text1 = "Hallo";
    text2 = text1 + " Du";

    cout << text1 << " --> " << text2 << endl;

    cout << *text1.begin() << text1.length() << endl;


    // get index of occurences
    string tmp = "Hallihallo";
    char tmp2 = 'l';

    int idx = 0;
    while (idx != tmp.rfind(tmp2)+1){
        idx = tmp.find(tmp2, idx);
        cout << idx << endl;
        idx++;
    }
    
    // Character Functions
    cout << "------" << endl;
    cout << isdigit('1') << endl;
    cout << isdigit('h') << endl;
    char tmp5 = 'g';
    cout  << toupper(tmp5) << endl;
    
 
    return 0;
}