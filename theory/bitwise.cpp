#include <iostream>
#include <bitset>

int main(void) {

    // Printing integers in Binary
    unsigned short int data {0b11111110}; // 254
    unsigned short int a{0b01000100}; // testing negation
    unsigned short int b = ~a;

    std::cout << "Section 1: Printing integers in binary or other" << std::endl;

    std::cout << "a value: " << std::bitset<8>(a) << std::endl;
    std::cout << "~a(b) value: " << std::bitset<8>(b) << std::endl;

    std::cout << "data (dec): " << std::dec << data << std::endl;
    std::cout << "data (hex): " << std::hex << std::showbase << data << std::endl;
    std::cout << "data (bin): " << std::bitset<8>(data) << std::endl;

    std::cout << std::endl;

    // Shift operators (just fot int and char)

    /*
    
    << shift to the left (same as to multiply vy 2)
    >> shift to the right (same as to divide by 2)

    obs: you can't get back a data that was lost by shifting using
    the inverse operation
    
    */

   unsigned short int value {0b00001000};
   
   std::cout << "Section 2: Shifting Operations" << std::endl;

   // Printing value before left shift
   std::cout << "Value (bin): " << std::bitset<8>(value) << std::endl;
   std::cout << "Value (dec): " << std::dec << value << std::endl;
   
   // Doing explicit cast because CPU will recognize like a int
   value = static_cast<unsigned short int>(value << 1); // just change to see what happen if shift to right
   
   std::cout << "Value (bin): " << std::bitset<8>(value) << std::endl;
   std::cout << "Value (dec): " << std::dec << value << std::endl;
   
   std::cout << std::endl;
    
    // Logical Bitwise operators

    /*
    
    & (AND) 
    | (OR)
    ^ (XOR)
    ~ (NOT)

    */

   // Assigments Operators

   /*
   
   >>= 
   <<= 
   |= 
   &= 
   ^= 


   */

  unsigned short int compare {0b00011111};
  unsigned short int result;
  
  std::cout << "Section 3: Logical and assigments operators" << std::endl;

  // &= compare
  result = static_cast<unsigned short int>(value &= compare);
  std::cout << "Value (bin): " << std::bitset<8>(result) << std::endl;
  std::cout << "Value (dec): " << std::dec << result << std::endl;

  // |= compare
  result = static_cast<unsigned short int>(value |= compare);
  std::cout << "Value (bin): " << std::bitset<8>(result) << std::endl;
  std::cout << "Value (dec): " << std::dec << result << std::endl;

  // ^= compare
  result = static_cast<unsigned short int>(value ^= compare);
  std::cout << "Value (bin): " << std::bitset<8>(result) << std::endl;
  std::cout << "Value (dec): " << std::dec << result << std::endl;

  std::cout << std::endl;

  // Masks

  /*
  
  Highlight position for bit of interest with a 1, mask other positions
  with 0
  
  */

}












