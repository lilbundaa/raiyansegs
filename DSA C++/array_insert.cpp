#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

void display(int arr[], int n){
    int i;
    for ( i = 0; i < n; i++)
    {   
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
   
int insert(int arr[], int size, int element, int pos){
    if(size>= 100){
        return -1;
    }
    for (int i = size-1; i >= pos; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[pos] = element;
    return 1;
    
}


int main()
{
int arr[100] = {7 ,8 ,12, 27 , 88};

int size= 5, element, pos;
    
 display(arr,size);

 cout<<"\nEnter the element to be inserted: ";
 cin>>element;
 cout<<"\nEnter the Position: ";
 cin>>pos;

 insert(arr, size, element, pos);

 size+=1;
 display(arr, size);

return 0;
}