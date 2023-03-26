/*Array need to be Bitonic(First Ascending and then Descending)*/

#include <bits/stdc++.h>
using namespace std ;

int MaximumElement(int array[100] ,int size) //peak
{
    int low=1 ,high=size-2 ,mid ;
    if(array[0]>array[1])
        return 0 ;
    else if(array[high]<array[size-1]) 
        return size-1 ;
    else
    {
        while(low<=high)
        {
            mid = low + ((high-low)/2) ;
            if(array[mid]>array[mid-1] && array[mid]>array[mid+1])
                return mid ;
            else if(array[mid]<array[mid+1])
                low = mid+1 ;
            else
                high = mid-1 ;
        }
    }
}

int main()
{
    int array[100], size, index ;
    cout<<"Enter the number of elements in an array : " ;
    cin>>size ;
    for(int i=0 ; i<size ; i++)
    {
        cout<<"Enter the element no. "<< i + 1 << " : " ;
        cin>>array[i] ;
    }

    index = MaximumElement(array,size) ;
    cout<<"```````````````````````````````````````````\n" ; 
    cout<<"The Maximum element is found at position : "<< index+1 <<" in Given Array."<<endl ;
        
    return 0 ;
}