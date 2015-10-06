#ifndef _H_GREEDY_H_
#define _H_GREEDY_H_

/* Questions related to Greedy algorithms */

// Que 1. Interval Scheduling Algorithm
// Given a set of n intervals S = [start,end] let us assume we ant to find a maximum subset S
// such that no pair of intervals overlaps.
typedef struct TimeInterval{ int start; int end; }TimeInterval;

void ScanIntervals(TimeInterval A[],int n);
void TimeSchedule();
int  compare(const void *x, const void *y);
void PrintIntervals(TimeInterval A[],int n);


// Que  2. Scheduling various classes in such a way that required number of class room should
// be minimized.
int MinimizedClassRooms();

#endif