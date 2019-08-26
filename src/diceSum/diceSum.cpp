#include <iostream>
#include <vector>
using namespace std;

/*
 * Write a recursive function named diceSum that accepts two parameters: 
 * an integer representing a number of 6-sided dice to roll, 
 * and a desired sum, 
 * and output all possible combinations of values that could appear on the dice 
 * that would add up to exactly the given sum. 
 * For example, the call of diceSum(3, 7); should print 
 * all combinations of rolls of 3 dice that add up to 7:
 * 
 * {1, 1, 5}
 * {1, 2, 4}
 * {1, 3, 3}
 * {1, 4, 2}
 * {1, 5, 1}
 * {2, 1, 4}
 * {2, 2, 3}
 * {2, 3, 2}
 * {2, 4, 1}
 * {3, 1, 3}
 * {3, 2, 2}
 * {3, 3, 1}
 * {4, 1, 2}
 * {4, 2, 1}
 * {5, 1, 1}
 * If the number of digits passed is 0 or negative, 
 * or if the given number of dice cannot add up to exactly the given sum, 
 * print no output. 
 * Your function must use recursion, but you can use a single for loop if necessary.
 */

void diceSumHelper(int numDice, int desiredSum, vector<int>& v)
{

    // print the vector when the desiredSum is reached
    // with the right number of dice
    if(numDice == 0 && desiredSum == 0) {
        for(int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    // recursively call diceSumHelper
    for (int i=1; i<=6; i++) {
        // choose a value for dice roll
        v.push_back(i);
        
        // call recursively if desiredSum can be reached
        if (numDice-1 >= 0 && desiredSum - i >= 0) {
            diceSumHelper(numDice-1, desiredSum - i, v);
        }
        
        // unchoose previously chosen value
        v.pop_back();
    }
}

void diceSum(int numDice, int desiredSum)
{
    // vector to store the list of values chosen
    vector<int> v;
    diceSumHelper(numDice, desiredSum, v);
}

int main()
{
    diceSum(3, 7);
    
    return 0;
}
