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
   
void del(int arr[], int size, int pos){
    if(size>= 100){
        cout<<"\n Wrong position...";
    }
    for (int i = pos; i < size; i++)
    {
        arr[i] = arr[i+1];
    }
    
}


int main()
{
int arr[100] = {7 ,8 ,12, 27 , 88};

int size= 5, element, pos;
    
 display(arr,size);

 cout<<"\nEnter the Position: ";
 cin>>pos;

 del(arr, size, pos);

 size-=1;
 display(arr, size);

 

return 0;
}