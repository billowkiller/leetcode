/*
 * =====================================================================================
 *
 *       Filename:  quick_sort.cc
 *
 *    Description:  quick sort algorithm
 *
 *        Version:  1.0
 *        Created:  04/03/2014 05:02:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  billowkiller (), billowkiller@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>

int partition(int *a, int begin, int end)
{
    int temp = a[begin];
    int i=begin+1;
    int j=end;
    while(i<j)
    {
        if(a[i]>temp)
        {
            int t = a[j];
            a[j] = a[i];
            a[i] = t;
            j--;
        }
        else
            i++;
    }
    if(a[i] > temp) i--;
    a[begin] = a[i];
    a[i] = temp;
    return i;
}

void quick_sort(int *a, int begin, int end)
{
    if(begin < end)
    {
        int q = partition(a, begin, end);
        quick_sort(a, begin, q-1);
        quick_sort(a, q+1, end);
    }
}

int main()
{
    int a[] = {2, 1, 4, 8, 3, 5};
    quick_sort(a, 0, 5);
    for(int i=0; i<6; i++)
        std::cout << a[i] << '\t';
}
