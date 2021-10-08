 #include<iostream>
 using namespace std;

 int binarysearch(int arr[], int size, int element){
    int low, mid, high;
    low=0;
    high = size -1;
    while (low<=high)
    {   
         mid = (low+high)/2;
         if(arr[mid]==element){
            return mid;
         }
         if(arr[mid]<element){
            low = mid+1;   //for more eficiency low = mid +1; cazz mid is alredy checked for euality not found
         }
         else{
            high = mid-1;   //for more efficiency high = mid -1; cazzz mid is already checked not found + 
         }
    }
    cout<<"\n not found";   
    exit(0);
    
 }
 
 int main()
 {   
    int arr[]={1,3,5,6,7,9,12,15,17,19,20,21,23,24};
    int size = sizeof(arr)/sizeof(int);
    int element;
    cout<<"\n Enter the element to find: ";
    cin>>element;
    int searchindex = binarysearch(arr, size, element);

    cout<<"\nThe element "<<element<<" was found at index "<<searchindex;
    cout<<"\nNOTE: Indexing starts from 0...";
 
 
 return 0;
 }