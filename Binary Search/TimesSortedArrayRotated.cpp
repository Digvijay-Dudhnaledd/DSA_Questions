#include <bits/stdc++.h>
using namespace std ;

int TimesRotated(int array[100], int size)
{
    int low=0, high=size-1, mid, result ;
    int previous, next ; // These are for checking the condition of smallest element
    
    if(array[0]<array[high])
        return 0 ;
    else
    {
        while(low<=high)
        {
            mid = low + ((high-low)/2) ;
            previous = (mid+size-1) % size ; // Necessary due to border conditions
            next = (mid+1) % size ; // if mid is 0th index then mid-1 goes out of bound and if mid is at last index then mid+1 goes out of bound

            if(array[mid]<array[previous] && array[mid]<array[next])
            {
                result = size - mid ; // this gives number of times array rotated 
                break ;
            }
            else if(array[mid]>array[low]) // right side is sorted
                low = mid ;
            else if(array[mid]==array[low])
                low = mid+1 ;
            else             // left side is sorted       
                high = mid ;  
        }
    }
    return result ;
}

int main()
{
    int size, array[100], rotations ;
    
    cout<<"Enter the Number of elements in an array : " ;
    cin>>size ;
    
    for(int i=0 ;i<size ; i++)
    {
        cout<<"Enter the element No. "<<i+1<<": ";
        cin>>array[i] ;
    }

    rotations = TimesRotated(array,size) ;
    cout<<"```````````````````````````````````````````\n" ;
    cout<<"The given array is Rotated "<<rotations<<" times."<<endl ;         
         
    return 0 ;
}