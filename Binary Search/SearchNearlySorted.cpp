/*Nearly Sorted Array : The element which should be at ith position is may be at ith, i+1th, i-1th position*/

#include <bits/stdc++.h>
using namespace std ;

int NearlySortedSearch(int array[100] ,int size, int key)
{
    int low=0 ,high=size-1 ,mid ,previous ,next ;
    while(low<=high)
    {
        mid = low + ((high-low)/2) ;
        previous = (mid-1+size) % size ;
        next = (mid+1) % size ;

        if(array[mid]==key || array[previous]==key || array[next]==key)
        {
            if(array[mid]==key)
                return mid ;
            else if(array[previous]==key)
                return previous ;
            else 
                return next ;
        }
        else if(array[mid]<key)
            low = mid+2 ;
        else 
            high = mid-2 ;
    }
    return -1 ;
}

int main()
{
    int array[100], size, index, key ;
    cout<<"Enter the number of elements in an array : " ;
    cin>>size ;
    for(int i=0 ; i<size ; i++)
    {
        cout<<"Enter the element no. "<< i + 1 << " : " ;
        cin>>array[i] ;
    }

    cout<<"Enter the number you want find : " ;
    cin>>key ;

    index = NearlySortedSearch(array,size,key) ;
    cout<<"```````````````````````````````````````````\n" ; 

    if(-1 == index)
        cout<<"The number is not found.\n"<<endl ;   
    else
        cout<<"The number is found at position : "<< index+1 <<" in Given Array."<<endl ;
        
    return 0 ;
}