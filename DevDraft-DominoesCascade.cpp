//
//  main2.cpp
//  DevDraft - Part 1- Final 3
//
//  Created by Paul-Johan on 6/28/15.
//  Copyright (c) 2015 Paul-Johan. All rights reserved.
//

/*
 *    C++ Program Dominoes
 */

#include <iostream>                     // Directive
#include <sstream>                      // Directive

using namespace std;

int main(int argc, const char * argv[]) {
     
    // INITIALIZATION
     
    // Line 1
    string line1;                       // Declaration of the string line1 which will contain one integer, N, the length of
                                        // the line of dominoes
    getline(cin, line1);                // Read in the first line (N)
     
    string array1[1];                   // Declaration of the string array1 which will contain N
    int i = 0;                          // Declaration of the integer i, set to zero
    stringstream ss1in(line1);          // Declaration of the stringstrem ss1in, that reads in line1
     
    while (ss1in.good() && i < 1){      // While loop to store each integer into the array array1
    ss1in >> array1[i];
        ++i;
    }
    int N = stoi(array1[0]);            // Declaration of the integer N: length of the line of dominoes

    // Line 2
    string line2;                       // Declaration of the string line2 which will contain the height of the domino at each
                                        // position
    getline(cin, line2);                // Read in the second line
    string array2[100];                 // Declaration of the string array2 which will contain the height of the domino at
                                        // each position
    int j = 0;                          // Declaration of the integer j, set to zero
    stringstream ss2in(line2);          // Declaration of the stringstrem ss2in, that reads in line2
     
    while (ss2in.good() && j < 100){    // While loop to store each integer into the array array2
        ss2in >> array2[j];
        ++j;
    }
     
     
    int domArray[N];                    // Declaration of the integer array domArray that stores the height of the domino
                                        // at each position
    for(j= 0; j < N; j++){              // For loop to store he height of the domino at each position
         domArray[j] = stoi(array2[j]);
    }
    // Test Case 1
    if (N < 0 || N > 100){
        cout << "N value out of range!" << endl;
    }
     
    // Right Cascade
     
    for(int pos = 0; pos < N; pos++){       // For loop to check the cascade height for each domino position
        if(domArray[pos]>0){                // Check if the domino has a height at position pos
            int k = domArray[pos];          // Declaration of the integer k the remaining cascade height of the original position
            int newPos = pos;               // Declaration of newPos as not to modify the original pos
            while(k>0){                     // While loop that counts down the remaining cascade length
                if(newPos + 1>= N){         // Verify that the length of the line of dominoes is not exceeded
                    break;
                }
                else if(domArray[newPos+1] >= k){                               // Check if the next domino height is taller
                                                                                // than the currently remaining cascade
                    domArray[pos] = domArray[newPos+1] + newPos + 1 - pos;      // Set the new cascade length
                    k = domArray[newPos+1];                                     // Set the new remaining cascade length
                    newPos++;                                                   // Move to next position to the right
                }
                else{
                    k--;                                                        // Decrease the remaining cascade length
                    newPos++;                                                   // Move to next position to the right
                }
            }
        }
    }
    
    for(int i= 0; i < N; i++){
        cout << domArray[i] << " ";
    }
    cout << endl;
     
    // Left Cascade
     
    int domArray2[N];                       // Declaration of the integer array domArray2 that stores the height of the domino
                                            // at each position
    for(j= 0; j < N; j++){                  // For loop to store he height of the domino at each position
        domArray2[j] = stoi(array2[j]);
    }
    
    for(int pos = N-1; pos > 0; pos--){     // For loop to check the cascade height for each domino position
        if(domArray2[pos]>0){               // Check if the domino has a height at position pos
            int k = domArray2[pos];         // Declaration of the integer k the remaining cascade height of the original position
            int newPos = pos;               // Declaration of newPos as not to modify the original pos
            while(k>0){                     // While loop that counts down the remaining cascade length
                if(newPos <= 0){            // Verify that the length of the line of dominoes is not exceeded
                    break;
                }
                else if(domArray2[newPos-1] >= k){                              // Check if the next domino height is taller
                                                                                // than the currently remaining cascade
                    domArray2[pos] = domArray2[newPos-1] + pos - newPos + 1;    // Set the new cascade length
                    k = domArray2[newPos-1];                                    // Set the new remaining cascade length
                    newPos--;                                                   // Move to next position to the left
                }
                else{
                    k--;                                                        // Decrease the remaining cascade length
                    newPos--;                                                   // Move to next position to the left
                }
            }
        }
    }
    
    for(int i= 0; i < N; i++){
        cout << domArray2[i] << " ";
    }
    
    return 0;
}


