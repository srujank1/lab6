//**************************************************************************************************************
// FILE: Thread.cpp
//**************************************************************************************************************
#include "Amicable.hpp"
#include "Keith.hpp"
#include "Main.hpp"
#include "Prime.hpp"
#include "Thread.hpp"

//==============================================================================================================
// Function Definitions
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// StartThread()
//
// Starts a thread.
//
// PSEUDOCODE:
// Define a variable named 'state' to be a pointer to a ThreadState structure
// Set state->mLimit to pLimit
// Define a variable named 'threadId' of type pthread_t
// Start the thread by calling pthread_create() and assign the return value to state->mStarted. The params are
//   the address of threadId, 0 (or NULL) for the thread attributes, pFunction is the starting function, and
//   'state' type casted to void *.
// If state->mStarted is 0, then the thread started successfully, so assign state->mThreadId the threadId.
// Return 'state'
//-------------------------------------------------------------------------------------------------------------
ThreadState *StartThread(ThreadFunction const pFunction, ulong const pLimit){
	ThreadState *state;
	state->mLimit=pLimit;
	pthread_t threadId;
	state->mStarted=pthread_create(&threadId, 0, pFunction, state<void*>(&ThreadState));
	if(state->mStarted==0){
		    state->mThreadId=threadId;
	}
	return state;
}
