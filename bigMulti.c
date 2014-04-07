/*
 * =====================================================================================
 *
 *       Filename:  bigMuliti.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/04/2014 09:23:30 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  billowkiller (), billowkiller@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <assert.h>

#define MAX_LEN 10000

char* multi(char* number_a, char* number_b){
    assert(number_a&&number_b);
    int i,j, negtive = 0, nLen_a = strlen(number_a), nLen_b = strlen(number_b);
    if(number_a[0] == '-' || number_a[0]=='+')
    {
        if(number_a[0] == '-')
            negtive = !negtive;
        nLen_a--;
        number_a++;
    }
    if(number_b[0] == '-' || number_b[0]=='+')
    {
        if(number_b[0] == '-')
            negtive = !negtive;
        nLen_b--;
        number_b++;
    }
    for(i=0; i<nLen_a; i++)
        if(number_a[i]!=0)
            break;
    if(i==nLen_a)
        return "0";

    for(i=0; i<nLen_b; i++)
        if(number_b[i]!=0)
            break;
    if(i==nLen_b)
        return "0";

    char m[nLen_a+nLen_b+1];
    unsigned a[MAX_LEN];
    unsigned b[MAX_LEN];
    unsigned result[MAX_LEN*2];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(result, 0, sizeof(result));


    for(j=0,i = nLen_a-1; i>=0; i--)
        a[j++] = number_a[i]-'0';
    for(j=0,i = nLen_b-1; i>=0; i--)
        b[j++] = number_b[i]-'0';

    for(i=0; i<nLen_b;i++)
        for(j=0; j<nLen_a; j++)
            result[i+j] += b[i]*a[j];
    
    j = nLen_a+nLen_b;
    m[j--] = '\0';
    for(i=0; result[i]!=0; i++){
        if(result[i] >= 10)
            result[i+1] += result[i]/10;
        m[j--] = (result[i]%10) + '0';
    }

    char *r;
    if(negtive)
    {
        r = (char *)malloc(i+2);
        memcpy(r+1, m+(nLen_a+nLen_b-i), i+1);
        r[0] = '-';
    }else{
        r = (char *)malloc(i+1);
        memcpy(r, m+(nLen_a+nLen_b-i), i+1);
    }
    return r;
}

int main(){
    char number_a[] = "0009";
    char number_b[] = "9999";
    printf("%s\n", multi(number_a, number_b));
    return 0;
}
