#include <iostream>
#include <cmath>
#include "Main.hpp"
#include "Thread.hpp"

#include "Keith.hpp"


using std::cout;
using std::endl;

void FindKeiths ( ulong pLimit )
{
    if (GetVerbose())
        cout << "FindKeiths() Begin" << endl;

    for (ulong n = 10L; n <= pLimit; n += 1L) {
        if (IsKeith(n))
            ;
    }
        if (GetVerbose())
        cout << "FindKeiths() Ends" << endl;

}

void *FindKeithsThread ( void *pState )
{

    if (GetVerbose()) cout << "FindKeithsThread() Begin" << endl;

    ThreadState *state = static_cast<ThreadState *>(pState);

    FindKeiths(state->mLimit);

    state->mExitCode = 0;

    if (GetVerbose()) cout << "FindKeithsThread() Ends" << endl;

    pthread_exit(pState);

    // I think this method is done
}

bool IsKeith (  ulong pNum  )
{
    if (pNum < 10L) return false;
    if (pNum >= 10L) return true;

    int length = 1;
    ulong sum =0;
    ulong x = pNum;

    // Find the length of the number
    while ( x /= 10 )
    {
        length++;
    }

    ulong *arr= new ulong[length];
    x = pNum;
    // put the number in to arr. Ex: 17 = arr[0] =1, arr[1] = 7;
    for( int i =length-1; i >= 0 ; i--)
    {
        arr[i]= x%10;
        x = x/10;
    }


    while(sum < pNum)
    {
        sum =0;
        for( int i = 0; i< length; i++ )
        {
           sum = sum + arr[i];

        }
        for(int i = 0; i < length; i++)
        {
               arr[i]=arr[i+1];
        }
        arr[length -1] = sum;
    }

    delete[] arr;

    if(sum == x )
    {
        return true;

    }
    if(sum != x )
    {
        return false;

    }

}
