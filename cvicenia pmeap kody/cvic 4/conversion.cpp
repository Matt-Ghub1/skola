/* scanf example */
#include <iostream>
#include <string>
#include <bitset>
//using namespace std;

int main ()
{
  char str [80];
  int i;
  float f;
  
  printf ("Enter your family name: ");
  scanf ("%79s",str);  
  printf ("Enter your age: ");
  scanf ("%d",&i);
  printf ("Enter your float number: ");
  scanf ("%f",&f);
  printf ("Mr. %s , %d years old, half of float is %f.\n",str,i,f/2);
  printf ("Enter a hexadecimal number: ");
  scanf ("%x",&i);
  printf ("You have entered %#x (%d).\n",i,i);
  
  std::cout << "Enter binary number: " << std::endl;
  std::string bin_string; // = "10";
  std::cin >> bin_string;
  std::cout  << "Starting binary string is: " << bin_string << std::endl;
  int number =0;
  number = std::stoi(bin_string, 0, 2);
  std::cout << number << std::endl;
  printf ("You have entered binary that is in decimal %d.\n",number);
  std::string binary = std::bitset<8>(number).to_string();
  std::cout << binary << std::endl;
    
  return 0;
}