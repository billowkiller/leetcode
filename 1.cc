/*
 * =====================================================================================
 *
 *       Filename:  1.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/10/2014 04:05:33 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  billowkiller (), billowkiller@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string.h>
using namespace std;

string mulit(const string &a, const string &b)
{
    string c = a+b;
    return c;
}

int main()
{
    string a = mulit(string("aa"), string("bb"));
    cout << a;

}
