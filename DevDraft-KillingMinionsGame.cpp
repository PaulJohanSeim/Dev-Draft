//
//  main.cpp
//  DevDraft
//
//  Created by Paul-Johan on 6/27/15.
//  Copyright (c) 2015 Paul-Johan. All rights reserved.
//

//
//  main.cpp
//  DevDraft2
//
//  Created by Paul-Johan on 6/27/15.
//  Copyright (c) 2015 Paul-Johan. All rights reserved.
//

/*
 *    C++ Program Minion Zapper
 */

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    // INITIALIZATION
    
    string line1;                       // Declaration of the string line1 which will contain the 3 integers: N, X and Y
    getline(cin, line1);                // Read in the first line
    
    string array1[3];                   // Declaration of the string array1 which will contain N, X and Y
    int i = 0;                          // Declaration of the integer i, set to zero
    stringstream ss1in(line1);          // Declaration of the stringstrem ss1in, that reads in line1
    
    while (ss1in.good() && i < 3){      // While loop to store each integer into the array array1
        ss1in >> array1[i];
        ++i;
    }
    
    int N = stoi(array1[0]);            // Declaration of the integer N: number of minions
    int X = stoi(array1[1]);            // Declaration of the integer X: damage of the spell to the first target
    int Y = stoi(array1[2]);            // Declaration of the integer Y: damage reduction with every subsequent target
    
    // Initial hit points of each minion
    
    string line2;                       // Declaration of the string line2 which will contain N amount of
                                        // initial hit points of each minion
    getline(cin, line2);                // Read in the second line
    
    string array2[10];                  // Declaration of the string array2 which will contain N amount of initial hit
                                        // points of each minion
    int j = 0;                          // Declaration of the integer j, set to zero
    stringstream ss2in(line2);          // Declaration of the stringstrem ss2in, that reads in line2
    
    while (ss2in.good() && j < N){      // While loop to store each integer into the array array2
        ss2in >> array2[j];
        ++j;
    }
    
    int minions[N];                     // Declaration of the integer array minions, with N variables, which will contain
                                        // the number of initial hit points of each minion
    for(j= 0; j < N; j++){              // For loop to store each string array variables, array2, into an integer array,
        minions[j] = stoi(array2[j]);   // minions
    }
    
    // MAIN FUNCTION: Maximum number of minions that can be killed
    
    int totM = 0;                       // Declaration of the integer totM which will contain the total number of minions
                                        // that can be killed
    for(j = 0; j < N; j++){             // For loop that calculates the number of minions that can be killed based on the
        if(X > minions[j]){             // damage of the spell to the initial target and every subsequent target
            totM += 1;
            X = X - Y;
        }
    }
    cout << totM;                       // Display maximum number of minions that can be killed
    
    
    
    
    return totM;
}

