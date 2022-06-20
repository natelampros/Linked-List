#include "LinkedList.h"
#include <iostream>
#include <sstream>
#include <string>
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK;
#endif

using namespace std;

int main(int argc, char * argv[]) {
    VS_MEM_CHECK;
    if (argc < 3)
    {
        cerr << "Please provide name of input and output files";
        return 1;
    }
    cout << "Input file: " << argv[1] << endl;
    ifstream in(argv[1]);
    if (!in)
    {
        cerr << "Unable to open " << argv[1] << " for input";
        return 2;
    }
    cout << "Output file: " << argv[2] << endl;
    ofstream out(argv[2]);

    LinkedList<string> linked_list; ///WHY DOES IT HAVE TO BE A POINTER TO WORK????
    LinkedList<string> copyList;

// process input strings
    for (string line; getline(in, line);)
    {
        string item1, item2;
        if (line.size() == 0) continue;

        istringstream iss(line);
        iss >> item1;
        if (item1 == "Insert") {
            out << line;
            while (iss >> item2)
            {
//                out << " " << item2;
                linked_list.push_front(item2);
            }
            out << endl;
        }
        else if (item1 == "PrintList"){
            out << "PrintList ";
            if (linked_list.size() > 0){
                out << " " << linked_list;
            }
            else{
                out << " Empty!";
            }
            out << endl;
        }

        else if (item1 == "Clear"){
            out << "Clear ";
            linked_list.clear();
            out << " OK";
            out << endl;
        }
        else if (item1 == "Size"){
            out << "Size ";
            int counter = linked_list.size();
            out  << counter;
            out << endl;
        }
        else if (item1 == "Empty"){//TODO: FIX AND ADD PARAMETER OR CATCH THROW TO CHECK FOR EMPTINESS BEFORE HAND
            out << "Empty ";
            if (linked_list.size() == 0){
//                linked_list.empty();
//                if (linked_list.empty() == true) { TODO: GET THE BOOL FUNCTION WORKING
//                    out << " true";
//                }
                out << "true";
            }
            else{
                out << "false";
            }
            out << endl;
        }
        else if (item1 == "Reverse"){
            out << "Reverse ";
            if (linked_list.size() > 0){
                linked_list.reverse();
                out << "OK";
            }
            else {
                out << "Empty!";
            }
            out << endl;
        }
        else if (item1 == "Remove"){
            out << line;
            if (linked_list.size() > 0){
                iss >> item2;
                linked_list.remove(item2);
                out << endl;
            }
            else {
                out << endl;
            }
        }
        else if (item1 == "Delete"){
            out << "Delete ";
            if (linked_list.size() > 0){
                linked_list.pop_front();
                out << "OK";
            }
            else{
                out << "Empty!";
            }
            out << endl;
        }
        else if (item1 == "First"){
            out << "First ";
            if (linked_list.size() > 0){
                out << linked_list.front();
            }
            else{
                out << "Empty!";
            }
            out << endl;
        }
        else if (item1 == "Copy"){
            out << "Copy ";
            copyList = linked_list;
            out << "OK";
            out << endl;
        }
        else if (item1 == "PrintCopy"){
            out << "PrintCopy ";
            if (copyList.size() > 0){
                out << copyList;
            }
            else {
                out << "Empty!";
            }
            out << endl;
        }
    }
    linked_list.clear();
    copyList.clear();

    return 0;

}
