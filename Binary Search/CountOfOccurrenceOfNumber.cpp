#include <bits/stdc++.h>
using namespace std ;

int First_Occurrence(int array[100], int size, int key)
{
    int low=0 ,high=size-1 ,index=-1 ,mid ;
    while(low<=high)
    {
        mid = low + ((high-low)/2) ;
        if(array[mid]==key)
        {
            index = mid ;
            high = mid-1 ;
        }
        else if(array[mid]<key)
            low = mid+1 ;
        else
            high = mid-1 ;
    }
    return index ;
}

int Last_Occurrence(int array[100], int size, int key)
{
    int low=0, high=size-1, mid, index=-1 ;
    while(low<=high)
    {
        mid = low + ((high-low)/2) ;
        if(array[mid]==key)
        {
            index = mid ;
            low = mid+1 ;
        }
        else if(array[mid]<key)
            low = mid+1 ;
        else
            high = mid-1 ;
    }
    return index ;
}

int main()
{
    int last_index, first_index, size, array[100], key ;
    
    cout<<"Enter the Number of elements in an array : " ;
    cin>>size ;
    
    for(int i=0 ;i<size ; i++)
    {
        cout<<"Enter the element No. "<<i+1<<": ";
        cin>>array[i] ;
    }

    cout<<"Enter the number of which you want to count Occurrence : " ;
    cin>>key ;

    first_index = First_Occurrence(array,size,key) ;
    last_index = Last_Occurrence(array,size,key) ;
    cout<<"```````````````````````````````````````````\n" ;

    if(-1 == first_index )
        cout<<"The number is not found.\n"<<endl ;         
    else 
        cout<<"The number is occured "<< (last_index - first_index + 1) <<" times in Given Array."<<endl ;
        
    return 0 ;
}