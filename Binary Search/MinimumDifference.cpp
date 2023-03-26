/*Assuming the number is between the range of smallest and largest number in Array*/

#include <bits/stdc++.h>
using namespace std ;

int FloorNumber(int array[100] ,int size ,int key)
{
    int low=0 ,high=size-1 ,mid ,floor ;

    while(low<=high)
    {
        mid = low + ((high-low)/2) ;
        if(array[mid]==key)
            return array[mid] ;
        else if(array[mid]<key)
        {
            floor = array[mid] ;
            low = mid+1 ;
        }
        else
            high = mid-1 ;
    }       
    return floor ;
}

int CeilNumber(int array[100] ,int size ,int key)
{
    int low=0 ,high=size-1 ,mid , ceil ;

    while(low<=high)
    {
        mid = low + ((high-low)/2) ;
        if(array[mid]==key)
            return array[mid] ;
        else if(array[mid]>key)
        {
            ceil = array[mid] ;
            high = mid-1 ;
        }
        else
            low = mid+1 ; 
    }
    return ceil ;
}

int MinimumDifference(int array[100] ,int size ,int key)
{
    int num1 ,smaller ,num2 ,greater ;
    smaller = FloorNumber(array ,size ,key) ;
    greater = CeilNumber(array ,size ,key) ;

    num1 = key - smaller ;
    num2 = greater - key ;
    if(num1<=num2)
        return num1 ;
    else
        return num2 ;
}

int main()
{
    int array[100], size, mindiff, key ;
    cout<<"Enter the number of elements in an array : " ;
    cin>>size ;
    for(int i=0 ; i<size ; i++)
    {
        cout<<"Enter the element no. "<< i + 1 << " : " ;
        cin>>array[i] ;
    }

    cout<<"Enter the number : " ;
    cin>>key ;

    mindiff = MinimumDifference(array,size,key) ;
    cout<<"```````````````````````````````````````````\n" ; 
    cout<<"The Minimum Difference of a number with respect to Numbers in Given Array : "<<mindiff<<"."<<endl ;
        
    return 0 ;
}