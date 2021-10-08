 #include<iostream>
 using namespace std;

 int linearsearch(int arr[], int size, int element){
     for (int i = 0; i < size; i++)
     {
         if(arr[i]==element){
             return 1;
         }
     }
     return -1;
 }
 
 int main()
 {  
    int arr[]={1,3,2,35,6,34,76,23,6,4,8,45,7,22};
    int size = sizeof(arr)/sizeof(int);
    int element = 4;
    int searchindex = linearsearch(arr, size, 4);

    cout<<"\nThe element "<<element<<" was found at index "<<searchindex;
 
 
 return 0;
 }