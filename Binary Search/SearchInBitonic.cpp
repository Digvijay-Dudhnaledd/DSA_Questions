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

int Search(int array[100] ,int size ,int key) 
{
    int low1 ,high1 ,low2 ,high2 ,Maximum ,mid ;
    Maximum = MaximumElement(array,size) ;

    low1 = 0 ;
    high1 = Maximum ;
    low2 = Maximum+1 ;
    high2 = size-1 ;

    while(low1<=high1)
    {
        mid = low1 + ((high1-low1)/2) ;
        if(array[mid]==key)
            return mid ;
        else if(array[mid]>key)
            high1 = mid-1 ;
        else
            low1 = mid+1 ;
    }

    while(low2<=high2)
    {
        mid = low2 + ((high2-low2)/2) ;
        if(array[mid]==key)
            return mid ;
        else if(array[mid]<key)
            high2 = mid-1 ;
        else 
            low2 = mid+1 ;
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

    index = Search(array,size,key) ;
    cout<<"```````````````````````````````````````````\n" ; 

    if(-1 == index)
        cout<<"The number is not found.\n"<<endl ;   
    else
        cout<<"The number is found at position : "<< index+1 <<" in Given Array."<<endl ;
        
    return 0 ;
}