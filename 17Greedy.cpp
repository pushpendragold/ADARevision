#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "17Greedy.h"

/*****************************************************************************************************
 * Que 1. Interval Scheduling Algorithm
 * Given a set of n intervals S = [start,end] let us assume we ant to find a maximum subset S
 * such that no pair of intervals overlaps.
 * 
 * Comments : 	1) Sort intervals according to the right-most ends [end times].
 * 		2) for every consecutive interval
 * 			- If the left-most end is after the right-most end of the last selected
 * 			  interval then we select this interval.
 * 			- Otherwise we skip it and go to the next interval.
 * 
 * Time Complexity : O(nLog(n)) Sorting +O(n) - Scanning
 * Space Complexity: O(n)
 * 
 * ***************************************************************************************************/
void TimeSchedule()
{
   int n;
   
   freopen("input","r",stdin);
   freopen("output","w",stdout);
   
   scanf("%d",&n);
   TimeInterval A[n];
   ScanIntervals(A,n);
   
   //	1) Sort intervals according to the right most end times
   qsort(A,n,sizeof(TimeInterval),compare);
   printf("After sorting\n");
   PrintIntervals(A,n);
   
   // 2) 
   TimeInterval ans[n];     //To hold answer
   int possible_events = 0; //To hold possible events.
   int previous_event = 0;
   
   ans[possible_events++] = A[0];
   for(int i=1;i<n;i++)
   {
      if(A[i].start >= A[previous_event].end)
      {
		  ans[possible_events++] = A[i];
		  previous_event = i;
      }
   }
   
   PrintIntervals(ans,possible_events);
}
int compare(const void *x, const void *y)
{
        TimeInterval *e1 = (TimeInterval *)x, *e2 = (TimeInterval *)y;
        return (*e1).end - (*e2).end;
}
void PrintIntervals(TimeInterval A[],int n)
{
   for(int i=0;i<n;i++)
   {
      printf("%d\t%d\n",A[i].start,A[i].end);
   }
}
void ScanIntervals(TimeInterval A[], int n)
{
    for(int i=0;i<n;i++)
    {
      scanf("%d %d",&A[i].start,&A[i].end);
    }
}
/***************************************************************************************************
 * Que  2. Scheduling various classes in such a way that required number of class room should
 * be minimized.
 * 
 * Comments : 	1) Finish 1st class as soon as possible
 * 
 * Time  Complexity : 
 * Space Complexity :
 * 
 * ************************************************************************************************/
int MinimizedClassRooms()
{
   int n;
   
   freopen("input","r",stdin);
   freopen("output","w",stdout);
   
   scanf("%d",&n);
   TimeInterval A[n];
   ScanIntervals(A,n);
   
   //	1) Sort intervals according to the start time
   qsort(A,n,sizeof(TimeInterval),compare);
   printf("After sorting\n");
   PrintIntervals(A,n);
   
   // 2) 
   int classRoomRequired = -1;
   int  * EndTime = new int[n];
   for(int i=0;i<n;i++)
   {
      if(classRoomRequired == -1)
	EndTime[++classRoomRequired] = A[i].end;
      else
      {
	bool foundClass = false;
	for(int j=0;j <= classRoomRequired; j++)
	{
	  if(EndTime[j] <= A[i].start)
	  {
	    EndTime[j] = A[i].end;
	    foundClass = true;
	    break;
	  }
	}
	if(!foundClass)
	  EndTime[++classRoomRequired] = A[i].end;
      }
   }
   return classRoomRequired+1;
}
int compareStart(const void *x, const void *y)
{
        TimeInterval *e1 = (TimeInterval *)x, *e2 = (TimeInterval *)y;
        return (*e1).start - (*e2).start;
}





































