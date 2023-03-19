#include <bits/stdc++.h>
using namespace std ;

int First_Occurrence(int array[100], int size, int key)
{
    int index=-1 ,mid ,low=0 ,high=size-1 ;
    while (low<=high)
    {
        mid = low + ((high-low)/2) ;
        if(array[mid]==key)
        {
            index = mid ;
            high = mid-1 ;
        }
        else if(array[mid]>key)
            high = mid-1 ;
        else
            low = mid+1 ; 
    }
    return index ;
}

int Last_Occurrence(int array[100], int size, int key)
{
    int index=-1 ,mid ,low=0 ,high=size-1 ;
    while (low<=high)
    {
        mid = low + ((high-low)/2) ;
        if(array[mid]==key)
        {
            index = mid ;
            low = mid+1 ;
        }
        else if(array[mid]>key)
            high = mid-1 ;
        else
            low = mid+1 ; 
    }
    return index ;
}

int main()
{
    int array[100], size, first_index, last_index, key ;
    cout<<"Enter the number of elements in an array : " ;
    cin>>size ;
    for(int i=0 ; i<size ; i++)
    {
        cout<<"Enter the element no. "<< i + 1 << " : " ;
        cin>>array[i] ;
    }

    cout<<"Enter the number you want find : " ;
    cin>>key ;

    first_index = First_Occurrence(array,size,key) ;
    last_index = Last_Occurrence(array,size,key) ;
    cout<<"```````````````````````````````````````````\n" ; 

    if(-1 == first_index )
        cout<<"The number is not found.\n"<<endl ;         
    else 
    {
        cout<<"The first occurrence of a number is at position : "<< first_index+1 <<" in Given Array."<<endl ;
        cout<<"The last occurrence of a number is at position : "<< last_index+1 <<" in Given Array."<<endl ;
    }
            
    return 0 ;
}