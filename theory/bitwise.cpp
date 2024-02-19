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

  * set bit position(s)
  * reset bit position(s)
  * check bit position(s)
  * toggle bit position(s)
  
  */

  std::cout << "Section 4: Masks" << std::endl;

  const unsigned char mask_bit_0 {0b00000001};
  const unsigned char mask_bit_1 {0b00000010};
  const unsigned char mask_bit_2 {0b00000100};
  const unsigned char mask_bit_3 {0b00001000};
  const unsigned char mask_bit_4 {0b00010000};
  const unsigned char mask_bit_5 {0b00100000};
  const unsigned char mask_bit_6 {0b01000000};
  const unsigned char mask_bit_7 {0b10000000};

  unsigned char var {0b00000000};

  // Setting bits (var |= mask)

  std::cout << "** Setting bits in nth position" << std::endl;

  // Setting bit in position 1
  std::cout << "Setting bit in position 1" << std::endl;
  var |= mask_bit_1;
  std::cout << "Result: " << std::bitset<8>(var) << std::endl;

  // Setting bit in position 5
  std::cout << "Setting bit in position 5" << std::endl;
  var |= mask_bit_5;
  std::cout << "Result: " << std::bitset<8>(var) << std::endl; 

  // Resetting bit position (var &= ~(mask))

  std::cout << "** Resetting bit position" << std::endl;

  // Resseting bit position 5
  // Reseting bit mask to compare with 0, because just reset if in this position the value is 1
  var &= ~(mask_bit_5);
  std::cout << "Result: " << std::bitset<8>(var) << std::endl;

  std::cout << std::endl;

  std::cout << "Masking multiple bits at once (examples)" << std::endl;
  std::cout << "Set all bits" << std::endl;
  var |= (mask_bit_0 | mask_bit_1 | mask_bit_2 | mask_bit_3 |
         mask_bit_4 | mask_bit_5 | mask_bit_6 | mask_bit_7);
  std::cout << "Result: " << std::bitset<8>(var) << std::endl;

  std::cout << "Reseting bits 0,1,5,6,7" << std::endl;
  var &= ~(mask_bit_0 | mask_bit_1 | mask_bit_5 | mask_bit_6 |
          mask_bit_7);
  std::cout << "Result: " << std::bitset<8>(var) << std::endl;

  std::cout << std::endl;

  // Check bit position ((var & mask) >> n_mask_position)
  std::cout << "Checking state of 2,3 and 7" << std::endl;
  std::cout << "Actual var: " << std::bitset<8>(var) << std::endl;

  std::cout << "bit2 is: " << ((var & mask_bit_2) >> 2) << std::endl;
  std::cout << "bit3 is: " << ((var & mask_bit_3) >> 3) << std::endl;
  std::cout << "bit7 is: " << ((var & mask_bit_7) >> 7) << std::endl;

  // Interpreting with booleans

  std::cout << "bit6 is: " << static_cast<bool>(var & mask_bit_6) << std::endl;

  std::cout << std::endl;

  // Toggling(change the value) bit position( var ^= n_mask_position)
  std::cout << "Actual var: " << std::bitset<8>(var) << std::endl;

  std::cout << "Toggle bit 0" << std::endl;
  var ^= mask_bit_0;
  std::cout << "Result: " << std::bitset<8>(var) << std::endl;

  std::cout << "Toggle bit 7" << std::endl;
  var ^= mask_bit_7;
  std::cout << "Result: " << std::bitset<8>(var) << std::endl;

  std::cout << "Toggle multiple bits" << std::endl;
  var ^= (mask_bit_0 | mask_bit_7 | mask_bit_1 | mask_bit_2);
  std::cout << "Result: " << std::bitset<8>(var) << std::endl;

  std::cout << std::endl;

  // Colors
  std::cout << "Extra Section: Working with colors mask" << std::endl;


  const unsigned int red_mask {0xFF000000};
  const unsigned int green_mask {0x00FF0000};
  const unsigned int blue_mask {0x0000FF00};
  const unsigned int alpha_mask {0x000000FF};

  unsigned int my_color {0xAABCDE00};

  // We shift to make sure the color byte of interest is in the
  // lower index byte position so that we can interpret that as an integer
  // which will be between 0 and 255.

  // print in hex base
  std::cout << std::hex << std::showbase << std::endl;

  std::cout << "My color: " << my_color << std::endl;

  std::cout << "Red is: " << ((my_color & red_mask) >> 24) << std::endl;
  std::cout << "Green is: " << ((my_color & green_mask) >> 16) << std::endl;
  std::cout << "Blue is: " << ((my_color & blue_mask) >> 8) << std::endl;
  std::cout << "Alpha is: " << ((my_color & alpha_mask) >> 0) << std::endl;



}












