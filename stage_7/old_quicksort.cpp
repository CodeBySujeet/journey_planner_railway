#ifndef STD_HEADERS
#include "std_headers.h"
#endif

#ifndef PLANNER_H
#include "planner.h"
#endif

#ifndef DICTIONARY_H
#include "dictionary.h"
#endif

#ifndef CODES_H
#include "codes.h"
#endif
listOfObjects<TrainInfoPerStation *> choosePivot(listOfObjects<TrainInfoPerStation *> *start, int k,listOfObjects<TrainInfoPerStation *> *end)
{
    
}

void copy(TrainInfoPerStation object1, TrainInfoPerStation object2) // copies the first object to second object.
{
    object2.arrTime = object1.arrTime;
    object2.depTime = object1.depTime;
    object2.journeyCode = object1.journeyCode;
    object2.stopSeq = object1.stopSeq;
    for (int i=0;i<7;i++) object2.daysOfWeek[i] = object1.daysOfWeek[i];
}

bool lessthan(listOfObjects<TrainInfoPerStation *> object1, listOfObjects<TrainInfoPerStation *> object2)
{// to check if the first one is earlier than second one
    bool* days1 = object1.object->daysOfWeek;
    bool* days2 = object2.object->daysOfWeek;
    for (int i=0;i<7;i++){
        if (days1[i] == 1 && days2[i] == 1) break;// both are true
        else if (days1[i] == 1) return true;
        else if (days2[i] == 1) return false;
        else continue; // both are false
    }
    // sorting according to arrival time
    if (object1.object->arrTime > object2.object->arrTime) return false;
    else return true;
}

void swapit(listOfObjects<TrainInfoPerStation *> object1, listOfObjects<TrainInfoPerStation *> object2)// to swap the data in the nodes
{
    TrainInfoPerStation trainInfo = *(object1.object);
    copy(*(object2.object),*(object1.object));
    copy(trainInfo,*(object2.object)); 
}

listOfObjects<TrainInfoPerStation *> *find_tail(listOfObjects<TrainInfoPerStation *> *list){
    while (list->next != nullptr) list = list -> next;
    return list; 
}

listOfObjects<TrainInfoPerStation *>  *partition(listOfObjects<TrainInfoPerStation *> *start, int k,listOfObjects<TrainInfoPerStation *> *end)
{
    listOfObjects<TrainInfoPerStation *> pivot = choosePivot(start, k,end);
    //listOfObjects<TrainInfoPerStation *> *left = stnInfoList;
    int left = 0 ,right = 0;
    listOfObjects<TrainInfoPerStation *> *tail = end;
    listOfObjects<TrainInfoPerStation *> *head = start;
    while (true){
        while (lessthan(*head,pivot) ) {
            left ++;
            head = head -> next;
        }
        while (lessthan(pivot,*tail)){
            right++;
            tail = tail ->prev;
        }
        if (left < right){
            swapit(*head,*tail);
        } 
        else return tail; 
    }
}
void DoQuicksort(listOfObjects<TrainInfoPerStation *> *start, int k,listOfObjects<TrainInfoPerStation *> *end)
{
    // Put your code here.
    if (start == end) return;
    listOfObjects<TrainInfoPerStation *> *mid = partition(start,k,end);
    DoQuicksort(start,k,mid->prev);
    DoQuicksort(mid,k,end);    
}

void Quicksort(listOfObjects<TrainInfoPerStation *> *stnInfoList, int k)
{
    // Put your code here.
    DoQuicksort(stnInfoList,k,find_tail(stnInfoList) );

}