// Header Files
#include <iostream>
#include<conio.h>

using namespace std;

#define maxsize 5

int main() {

   // Declare Variables
   int var[] = {10, 20, 30, 40, 50};
   int i = 0;

   //Pointer Variable Declaration for Integer Data Type 
   int *pt;

   cout << "Pointer Example C++ Program : Pointer and Array \n";

   //& takes the address of var , Here now pt == &var, so *pt == var
   pt = &var[0];

   while (i < maxsize) {
      cout << "Position : " << i << " # Actual  : Value : " << var[i] << " , Address = " << &var[i] << " \n";
      cout << "Position : " << i << " # Pointer : Value : " << *pt << " , Address = " << pt << " \n\n";
      i++;

      // pt++ is increasing Address value based on Data Type
      pt++;
   }

   getch();
   return 0;
}
