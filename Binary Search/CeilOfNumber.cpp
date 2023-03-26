/*Assuming the number is between the range of smallest and largest number in Array*/

#include <bits/stdc++.h>
using namespace std ;

int CeilNumber(int array[100] ,int size ,int key)
{
    int low=0 ,high=size-1 ,mid , result ;

    while(low<=high)
    {
        mid = low + ((high-low)/2) ;
        if(array[mid]==key)
            return array[mid] ;
        else if(array[mid]>key)
        {
            result = array[mid] ;
            high = mid-1 ;
        }
        else
            low = mid+1 ; 
    }
    return result ;
}

int main()
{
    int array[100], size, ceil, key ;
    cout<<"Enter the number of elements in an array : " ;
    cin>>size ;
    for(int i=0 ; i<size ; i++)
    {
        cout<<"Enter the element no. "<< i + 1 << " : " ;
        cin>>array[i] ;
    }

    cout<<"Enter the number of which you want find ceil : " ;
    cin>>key ;

    ceil = CeilNumber(array,size,key) ;
    cout<<"```````````````````````````````````````````\n" ; 
    cout<<"The ceil of number is : "<<ceil<<"."<<endl ;

    return 0 ;
}