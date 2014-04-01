/*
 * =====================================================================================
 *
 *       Filename:  reverse_polish_notation.cc
 *
 *    Description:  
 *
 *    Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *    Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 *    Some examples:
 *      ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *      ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 *
 *
 *        Version:  1.0
 *        Created:  04/01/2014 01:40:11 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  billowkiller (), billowkiller@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        string operators("+-*/");
        vector<int> temp;
        for(vector<string>::iterator iter=tokens.begin();iter!=tokens.end();iter++)
        {
            string::size_type pos = operators.find(*iter);
            if(string::npos == pos)
            {
                temp.push_back(atoi((*iter).c_str()));
                continue;
            }
            int a = temp.back();
            temp.pop_back();
            int b = temp.back();
            temp.pop_back();
            switch(pos)
            {
                case 0:
                    temp.push_back(b+a);
                    break;
                case 1:
                    temp.push_back(b-a);
                    break;
                case 2:
                    temp.push_back(b*a);
                    break;
                case 3:
                    temp.push_back(b/a);
                    break;
            }
        }
        return temp.back();  
    }
};

int main()
{
    Solution sol;
    string str1[] = {"2", "1", "+", "3", "*"};
    string str2[] = {"4", "13", "5", "/", "+"};
    vector<string> v1(&str1[0], &str1[5]);
    vector<string> v2(&str2[0], &str2[5]);

    cout << sol.evalRPN(v1) << endl;
    cout << sol.evalRPN(v2) << endl;

}
