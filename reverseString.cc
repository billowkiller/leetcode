/*
 * =====================================================================================
 *
 *       Filename:  reverseString.cc
 *
 *    Description:  
 *
 *    Given an input string, reverse the string word by word.
 *    For example,
 *    Given s = "the sky is blue",
 *    return "blue is sky the".
 *
 *        Version:  1.0
 *        Created:  04/01/2014 09:17:54 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  billowkiller (), billowkiller@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution
{
    public:

    void reverseWords(string &s)
    {
        string::iterator iter = s.end()-1;
        string str;
        int len = 0;
    
        for(; iter>=s.begin(); iter--)
        {
            if(!isspace(*iter))
                len++;
            else if(len>0)
            {
                str.append(s, iter-s.begin()+1, len);
                str+=' ';
                len = 0;
            }
        }
        if(len) 
        {
            str.append(s, 0, len);
            s = str;
        }
        else
        {
            s = str.substr(0, str.size()-1);
        }
    }
};

