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

    // I think this method is done
}
