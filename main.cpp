#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>

using namespace std;


list<int> * processFile(list<int> * output, ifstream * infile) {
    cout << "1" << endl;
    
    string line;
    while(getline(*infile, line))
    {
        cout << "2" << endl;
        istringstream iss(line);
        cout << "3" << endl;
        int value;
        if(iss >> value)
        {
            cout << "4" << endl;
            cout << "value: " << value << endl;
            output->push_back(value);
            cout << "5" << endl;
        }
    }


    return output;
}

int addValuesFromList(list<int> * list, int startValue)
{
    int result = startValue;
    for(auto const& i : *list)
    {
        result += i;
    }


    return result;
}

int main() {
    ifstream infile("input.txt");
    list<int> * processedList = new list<int>;
    processedList = processFile(processedList, &infile);
    int startValue = 0;
    int result = addValuesFromList(processedList, startValue);

    cout << "result: " << result << endl;
    return 0;

}
