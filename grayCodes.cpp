//
//  grayCodes.cpp
//  
//
//  Created by Mehreen Saeed on 3/9/21.
//

#include <stdio.h>
#include<cmath>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        int number = 0;
        int index = 0;
        int pow2 = pow(2,n);
        vector<int> codes(pow2, 0);
        vector<bool> binArray(n,0);
        
        grayCode(n,codes,index,number,binArray,pow2/2);
        
        return codes;
    }
    
    void grayCode(int n, vector<int>&codes, int &index, int &number, vector<bool>&binArray, int pow2)
    {
        
        
        
        //base case
        if (n==1)
        {   //update codes array with two numbers
            codes[index] = number;
            index=index+1;
            binArray[n-1] = !binArray[n-1];
            if (binArray[n-1]) //last bit is 1
                number = number+1;
            else
                number = number-1;
            codes[index] = number;
            index = index+1;
            return;
            
        }
        //general case
        grayCode(n-1,codes,index,number,binArray,pow2/2);
        binArray[n-1] = !binArray[n-1];
        if (binArray[n-1])
            number = number+pow2*binArray[n-1];
        else
            number = number-pow2;
        grayCode(n-1,codes,index,number,binArray,pow2/2);
        
    }
};

int main()
{
    Solution soln;
    vector<int> codes = soln.grayCode(4);
    cout << "\n";
    for (int i=0;i<codes.size();++i)
        cout << codes[i] << " ";
    
    return 0;
}
