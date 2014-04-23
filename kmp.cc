/*
 * =====================================================================================
 *
 *       Filename:  kmp.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/23/2014 10:04:49 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  billowkiller (), billowkiller@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstring>
using namespace std;

int getNext(int next[], char p[])
{
    int j=0, k=-1;
    next[j] = k;
    
    while(p[j]!='\0')
    {
        if(k == -1 || p[j]==p[k])
            next[++j] = ++k;
        else
            k = next[k];
    }
}

int strstr(char s[], char p[], int next[])
{
    int i=0, j=0, len = strlen(p);
    while(s[i]!='\0' && j<len)
    {
        if(j==-1 || s[i] == p[j])
        {
            i++; j++;
        }
        else
        {
            j = next[j];   
        }
    }
    
    if(s[i] == 0)
        return -1;
    else return i-len;
}

int main()
{
    char *p = "abaabcac";
    char *s = "abaddabaabcacdd";
    int *next = new int[strlen(p)];
    getNext(next, p);    
    for(int i=0; i<strlen(p); i++)
        cout << next[i] << " ";
        
    cout<< endl << strstr(s, p, next);
}
