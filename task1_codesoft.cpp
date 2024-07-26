#include <bits/stdc++.h>
using namespace std;

int main() {
  
  // to change the number everytime programme runned 


  srand(time(NULL));


// generation of random number using rand() function 

  int random_number = 1 + rand() % 100;
  int no_of_guess = 0 ;

int guess =0 ;
  
  // logical section 

  while (guess != random_number) {
   
    cout << "Enter your guess  : ";
    cin >> guess;

    no_of_guess++;

    if (guess == random_number) {
      cout << "Congratulations! You guessed the correct number in " << no_of_guess << " guesses." << endl;
      break;
    } else if (guess < random_number) {
      cout << "Your guess is too low." << endl;
    } else {
      cout << "Your guess is too high." << endl;
    }
    
  } ;

  return 0;
}