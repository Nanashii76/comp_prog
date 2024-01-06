#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){

    // Creating an ordened map
    map<int, int> ordered_map;

    // Add three elements to the map
    ordered_map[9] = 9*9;
    ordered_map[4] = 4*4;
    ordered_map[1] = 1;

    // Print Keys and values of the map
    // Implemented with a self-balancing red-black tree
    for(auto i = ordered_map.begin(); i != ordered_map.end(); ++i)
        cout << "Key: " << i->first << " Value: " << i->second << endl;
    
    // Using string as the key to map
    string animal1 = "aardvark";
    string animal2 = "baboon";
    string animal3 = "zebra";

    // Create an ordered map indexed by the key
    map<string, int> animals;

    // Insert using the insert method
    animals.insert(make_pair(animal3,10));
    animals.insert(make_pair(animal2,15));
    animals.insert(make_pair(animal1,20));

    for(auto i = animals.begin(); i != animals.end(); ++i)
        cout << "Key: " << i->first << " Value: " << i->second << endl;


    if(animals.find("bababoi") == animals.end())
        cout << "Not Exist" << endl;

}