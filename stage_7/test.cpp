#include<iostream>

using namespace std;

void partition (int *arr, int x, int n){
    int i = 0;
    for (int j=0;j<n;j++){
        if (arr[j] < x){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    for (int i=0;i<n;i++) cout << arr[i] << endl;
}

int myfunc(){static int i=0;i++;return i;}

int main(){
    //int a[5] = {5,4,3,2,1};
    //partition(a,3,5);
    //for (int i=0;i<5;i++){
    //    cout << myfunc()<< endl;
    //}
    int *p,*q;
    p = new int;
    *p = 5;
    p = q;
    p = new int;
    *p = 10;
    cout << *p << endl << *q << endl;
}   