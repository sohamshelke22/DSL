/*Name: Soham Shelke 

Class: SE2

Roll Number: 72

PRN Number: F23112151



Problem Statement

Read Marks of ‘N’ Students for the subject Data Structures. Sort the data and

display the topper for the Subject.*/



#include <iostream>

using namespace std;

void merge(int a[], int beg, int mid, int end)

{

int i, j, k;

int n1 = mid - beg + 1;

int n2 = end - mid;

int LeftArray[n1], RightArray[n2];

for (int i = 0; i < n1; i++)

LeftArray[i] = a[beg + i];

for (int j = 0; j < n2; j++)

RightArray[j] = a[mid + 1 + j];

i = 0;

j = 0;

k = beg;

while (i < n1 && j < n2) {

if(LeftArray[i] <= RightArray[j]) {

a[k] = LeftArray[i];

i++;

}

else

{

a[k] = RightArray[j];

j++;

}

k++;

}

while (i<n1)

{

a[k] = LeftArray[i];

i++;

k++;

}

while (j<n2)

{

a[k] = RightArray[j];

j++;

k++;

}

}

void mergeSort(int a[], int beg, int end)

{

if (beg < end) {

int mid = (beg + end) / 2;

mergeSort(a, beg, mid);

mergeSort(a, mid + 1, end);

merge(a, beg, mid, end);

}

}

void printArray(int a[], int n) {

int i;

for (i = 0; i < n; i++)

cout<<a[i]<<" ";

}

int main()

{

int n;

cout<<"\nEnter the number of students: ";

cin>>n;

cout<<"\n Enter marks of"<<n<<"students:\n";

int a[n];

for(int i=0;i<n;i++)

cin>>a[i];

mergeSort(a, 0, n - 1);

cout<<"\nStudent marks: \n";

printArray(a, n);

cout<<"\nTopper is: "<<a[n-1];

return 0;

} 





/*

Output



Enter the number of students: 5

Enter marks of5students:

95

89

91

55

67

Student marks:

55 67 89 91 95

Topper is: 95



*/
