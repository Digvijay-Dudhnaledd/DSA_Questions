#include <bits/stdc++.h>
using namespace std ;

int Order_Agnostic(int array[100], int size , int key)
{
    int flag = 0 ,mid ,low=0 ,high=size ;
    if(array[0]<array[1])
        flag = 1 ;      // 1 for ascending order array
    else
        flag = 2 ;      // 2 for descending order array
    
    while(low<=high)
    {
        mid = low + ((high-low)/2) ;
        if(flag==1)
        {
            if(array[mid]==key)
                return mid ;
            else if(array[mid]<key)
                low = mid+1 ;
            else 
                high = mid-1 ;
        }
        else if(flag==2)
        {
            if(array[mid]==key)
                return mid ;
            else if(array[mid]<key)
                high = mid-1 ;
            else
                low = mid+1 ;
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

    index = Order_Agnostic(array,size,key) ;
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