#include <bits/stdc++.h>
using namespace std ;

int IndexSmallestElement(int array[100], int size)
{
    int low=0 ,high=size-1 ,mid ,result ;
    int previous ,next ;

    if(array[0]<array[high])
        return 0 ;
    else
    {
        while(low<=high)
        {
            mid = low + ((high-low)/2) ;
            previous = (mid+size-1) % size ;
            next = (mid+1) % size ;
            
            if(array[mid]<array[previous] && array[mid]<array[next])
            {
                result = mid ;
                break ;
            }
            else if(array[low]<array[mid]) // left side unsorted
                low = mid ;
            else if(array[low]==array[mid])
                low = mid+1 ;
            else    // right side unsorted
                high = mid ;
        }
    }
    return result ;
}

int SearchElement(int array[100], int size, int key)
{
    int low1, smallest, high1, low2, high2, mid ;
    
    smallest = IndexSmallestElement(array,size) ;
    low1 = 0 ;
    high1 = smallest-1 ;
    low2 = smallest ;
    high2 = size-1 ;

    if(key<=array[high1] && key>=array[low1])
    {
        while(low1<=high1)
        {
            mid = low1 + ((high1-low1)/2) ;
            if(array[mid]==key)
                return mid ;
            else if(array[mid]<key)
                low1 = mid+1 ;
            else 
                high1 = mid-1 ;
        }
    }
    else
    {
        while(low2<=high2)
        {
            mid = low2 + ((high2-low2)/2) ;
            if(array[mid]==key)
                return mid ;
            else if(array[mid]<key)
                low2 = mid+1 ;
            else 
                high2 = mid-1 ;
        }
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

    index = SearchElement(array,size,key) ;
    cout<<"```````````````````````````````````````````\n" ; 

    if(-1 == index)
        cout<<"The number is not found.\n"<<endl ;   
    else
        cout<<"The number is found at position : "<< index+1 <<" in Given Array."<<endl ;
        
    return 0 ;
}