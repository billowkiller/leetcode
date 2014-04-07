/*
 * =====================================================================================
 *
 *       Filename:  combination.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/06/2014 09:53:03 PM
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
#include <cstring>

using namespace std;

void select_m(char *pstr, int m, vector<char> &result)
{
    if(pstr == NULL || (*pstr=='\0' && m!=0))
        return;
    if(m==0)
    {
        for(int i=0; i<result.size(); i++)
            cout << result[i];
        cout << endl;
        return;
    }
    result.push_back(*pstr);
    select_m(pstr+1, m-1, result);
    result.pop_back();
    select_m(pstr+1, m, result);
}

void combination(char *pstr)
{
    if(pstr == NULL || *pstr=='\0')
        return;
    int len = strlen(pstr);
    for(int i=1; i<=len; i++)
    {
        vector<char> result;
        select_m(pstr, i, result);
    }
}

void swap (char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
void permute(char *pstr, char *pbegin)
{
    if(*pbegin == '\0')
        cout << pstr << endl;
    else{
        for(char *pch = pbegin; *pch!='\0'; pch++)
        {
            swap(pch, pbegin);
            permute(pstr, pbegin+1);
            swap(pch, pbegin);
        }
    }
}

void permutation(char *pstr)
{
    if(pstr == NULL || *pstr=='\0')
        return;

    permute(pstr, pstr);
}

int main()
{
    char pstr[] = "abc";
    combination(pstr);
    permutation(pstr);
    return 0;
}
