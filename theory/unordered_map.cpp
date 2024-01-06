#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


int main(){

    // Create an unordered map of  string to integers
    // Will use it to store some constants
    unordered_map<string, double> constants;

    // Use strings for the map constants
    string pi = "PI";
    string root2 = "ROOT2";
    string e = "E";

    // add some constants to the map
    constants[pi] = 3.14159265;
    constants[root2] = 1.414;

    // We can also insert with a method
    constants.insert(make_pair(e,2.718));

    // Dump all values in the map
    for(auto i = constants.begin(); i != constants.end(); ++i)
        cout << "Key: " << i->first << " Value: " << i->second << endl;

    // Example of how to check if a value is in the map
    string lambda = "LAMBDA";

    // end points to the position after the last elements
    if (constants.find(lambda) == constants.end())
        cout << "Not find: " << lambda << endl;  


}