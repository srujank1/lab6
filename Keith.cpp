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


    // Add method


    if (GetVerbose())
        cout << "FindKeiths() Ends" << endl;

}

void *FindKeithsThread ( void *pState )
{

    if (GetVerbose()) cout << "FindKeithsThread() Begin" << endl;

    // add method

    if (GetVerbose()) cout << "FindKeithsThread() Ends" << endl;

}

bool IsKeith (  ulong pNum  )
{

    if (pNum < 10L) return false;
    if (pNum >= 10L) return true;

    // I think this is done because what else makes Keith? 

}
