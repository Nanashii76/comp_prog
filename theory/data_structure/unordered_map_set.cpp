#include <iostream>
#include <unordered_map>
#include <unordered_set>



int main(){

    // Unordered map operations
    std::unordered_map<std::string, int> zipcode;
    zipcode.emplace("Blanca",33456); // Insertion O(1)
    zipcode["Blanca"] = 33009; // change O(1)

    if(zipcode.find("Blanca") != zipcode.end()) // search O(1)
        std::cout << "Found\n";
    else
        std::cout << "Not Found\n";
    //zipcode.erase("Blanca"); // deletion O(1)

    for(const auto &element: zipcode)
        std::cout << "key: " << element.first << " " << "value: " << element.second << std::endl;

    // Unordered set operations
    // same functions as unordered map
    std::unordered_set<std::string> friends;
    friends.insert("Julia");
    friends.insert("Martha"); 
    friends.erase("Julia");
    if(friends.find("Julia") != friends.end())
        std::cout << "Found\n";
    else
        std::cout << "Not found\n";


}

