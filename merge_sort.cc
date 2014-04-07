/*
 * =====================================================================================
 *
 *       Filename:  merge_sort.cc
 *
 *    Description:  merge sort
 *
 *        Version:  1.0
 *        Created:  04/04/2014 03:17:22 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  billowkiller (), billowkiller@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>

void merge(int *unsorted, int begin, int mid, int end, int *sorted)
{
    int i=begin, j=mid, k=0;
    while(i<mid && j<end)
    {
        if(unsorted[i]<unsorted[j])
            sorted[k++] = unsorted[i++];
        else
            sorted[k++] = unsorted[j++];
    }
    while(i<mid)
        sorted[k++] = unsorted[i++];
    while(j<end)
        sorted[k++] = unsorted[j++];

    for(int v=0; v<k; v++)
        unsorted[begin+v] = sorted[v];
}

void merge_sort(int *unsorted, int begin, int end, int *sorted)
{
    if(begin+1 < end)
    {
        int mid = (begin+end)/2;
        merge_sort(unsorted, begin, mid, sorted);
        merge_sort(unsorted, mid, end, sorted);
        merge(unsorted, begin, mid, end, sorted);
    }
}

int main()
{
    int x[] = { 6, 2, 4, 1, 5, 9 };
    int sorted[6];
    merge_sort(x, 0, 6, sorted);
    for(int i=0; i<6; i++)
        std::cout << x[i] << std::endl;
}
