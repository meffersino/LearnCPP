#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <set>

using namespace std;


set<int> * reachedFrequencies;

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
    int result = startValue;
    bool notFound = true;
    while(notFound){
        for(auto const& i : *list)
        {
            try {
                result += i;
                checkDuplicateFrequencies(result);
            } catch(const char* msg) {
                notFound = false;
                throw &result;
            }
        }
    }

    return result;
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
    } catch(int * value) {
        cout << *value << endl;
        cout << "result: " << *value << endl;
        result = *value;
    }

    return 0;

}
