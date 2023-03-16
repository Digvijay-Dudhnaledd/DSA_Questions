#include <bits/stdc++.h>
using namespace std ;

int Binary_Search_Ascending(int array[100], int size, int key)
{
    int low=0, high=size, mid ;
    while(low<=high)
    {
        mid = low + ((high-low)/2) ;
        if(key == array[mid])
            return mid ;
        else if(key > array[mid])
            low = mid + 1 ;
        else 
            high = mid - 1 ;
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

    index = Binary_Search_Ascending(array,size,key) ;
    cout<<"```````````````````````````````````````````\n" ; 

    if(-1 == index)
    {
        cout<<"The number is not found.\n"<<endl ;
    }      
    else
    {
        cout<<"The number is found at position : "<< index+1 <<" in Given Array."<<endl ;
    }
        
    return 0 ;
}