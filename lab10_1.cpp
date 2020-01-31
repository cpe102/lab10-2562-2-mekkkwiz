// cout << "Press Enter 3 times to reveal your future.";
// cout << "You will get A in this 261102.";

#include<iostream>
#include<ctime>

using namespace std;

int main () 
{
    
    double ran;
    cout << "Press Enter 3 times to reveal your future.";
    cin.get();
    cin.get();
    cin.get();


    srand(time(0)); 
    ran = rand()%9+1;

         if (ran == 9)cout << "You will get A in this 261102.";
    else if (ran == 1)cout << "You will get B+ in this 261102.";
    else if (ran == 2)cout << "You will get B in this 261102.";
    else if (ran == 3)cout << "You will get C+ in this 261102.";
    else if (ran == 4)cout << "You will get C in this 261102.";
    else if (ran == 5)cout << "You will get D+ in this 261102.";
    else if (ran == 6)cout << "You will get D in this 261102.";
    else if (ran == 7)cout << "You will get F in this 261102.";
    else if (ran == 8)cout << "You will get W in this 261102.";
 
}