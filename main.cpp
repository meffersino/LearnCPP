#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <set>

using namespace std;


set<int> * reachedFrequencies;
int * finalResult;

void checkDuplicateFrequencies(int value);

list<int> * processFile(list<int> * output, ifstream * infile) {    
    string line;
    while(getline(*infile, line))
    {
        istringstream iss(line);
        int value;
        if(iss >> value)
        {
            output->push_back(value);
        }
    }


    return output;
}

int addValuesFromList(list<int> * list, int startValue)
{
    int finalResult = startValue;
    bool notFound = true;
    while(notFound){
        for(auto const& i : *list)
        {
            try {
                finalResult += i;
                //cout << "Result: " << result << " i: " << i << endl;
                checkDuplicateFrequencies(finalResult);
            } catch(const char* msg) {
                notFound = false;
                cout << "FOUND" << endl;
                cout << "Result value: " << finalResult << endl;
                cout << "Result address: " << &finalResult << endl;
                throw finalResult;
            }
        }
    }

    return finalResult;
}

void checkDuplicateFrequencies(int value)
{
    if(reachedFrequencies->find(value) != reachedFrequencies->end())
    {
        
        throw "found";
    } else {
        reachedFrequencies->insert(value);
    }
}

int main() {
    reachedFrequencies = new set<int>;
    ifstream infile("input.txt");
    list<int> * processedList = new list<int>;
    processedList = processFile(processedList, &infile);
    int startValue = 0;
    int result = 0;
    try {
        result = addValuesFromList(processedList, startValue);
        cout << result << endl;
    } catch(int value) {
        cout << "Value address: " << &value << endl;
        cout << "Value: " << value << endl;
        result = value;
    }

    return 0;

}
