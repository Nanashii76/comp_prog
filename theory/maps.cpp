#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

/*

    ordered maps use a binary tree to search the keys
    unordered maps use a hash table to search the keys

*/



typedef struct CityRecord {
    string Name;
    uint16_t Population;
    double Latitude, Longitude;
};

int main(){

    unordered_map<string, CityRecord> citymap;
    citymap["Melbourne"] = CityRecord{ "Melbourne", 100, 2.4, 9.4 };
    citymap["Lol-town"] = CityRecord{ "Lol-town", 100, 2.4, 9.4 };
    citymap["Berlin"] = CityRecord{ "Berlin", 100, 2.4, 9.4 };
    citymap["Paris"] = CityRecord{ "Paris", 100, 2.4, 9.4 };
    citymap["London"] = CityRecord{ "London", 100, 2.4, 9.4 };

    /*

        the second value is a struct, so to print we have to put thein
        in a datatype

    */

   CityRecord &berlinData = citymap["Berlin"];

    /*
    for(auto i : citymap) {
        cout << i.first << endl;
    }
    */

   if(citymap.find("London") != citymap.end()) {
        CityRecord &Londondata = citymap["London"];
        cout << Londondata.Name <<"\n Population: " << Londondata.Population << endl; 
   }

}