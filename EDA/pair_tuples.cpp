#include <bits/stdc++.h>

int main(void) {

    // Pairs

    std::pair<std::string, int> mypair1 = std::make_pair("Name", 19);
    std::cout << mypair1.first << " " << mypair1.second << std::endl;

    mypair1.first = "Its possible change the value after declare a pair";

    std::pair<std::string,std::string> mypair2 = std::make_pair(
        mypair1.first,"Copyyyy"
    );

    std::cout << mypair2.first << " " << mypair2.second << std::endl;

    /* OUTPUT
    Name 19
    Its possible change the value after declare a pair Copyyyy
    */

   // Tuples
   int a = 3, b = 4, c = 5;
   std::tuple<int, int, int> t{3,4,5};

    // Other form to declare
    t = std::tie(a,b,c);

    // outputing a tuple
    std::cout << std::get<0>(t) << std::get<1>(t) << std::get<2>(t) <<
    std::endl;
   


}