/*This may give wrong answer in finite arry bcoz we are increaing high as high*2 and it will cause index out of bound problem(mid<size). This will work flawlessly for Infinite array.*/

#include <bits/stdc++.h>
using namespace std ;

int InfiniteSearch(int array[100] ,int key ,int size)
{
    int low=0 ,high=1 ,mid ;
    
    while(low<=high)
    {
        if(array[high]<key)
        {
            low = high ;
            high = high*2 ;
        }
        else
        {
            mid = low + ((high-low)/2) ;
            if(array[mid]==key) 
                return mid ;
            else if(array[mid]<key)
                low = mid+1 ;
            else
                high = mid-1 ;
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

    index = InfiniteSearch(array,key,size) ;
    cout<<"```````````````````````````````````````````\n" ; 

    if(-1 == index)
        cout<<"The number is not found.\n"<<endl ;   
    else
        cout<<"The number is found at position : "<< index+1 <<" in Given Array."<<endl ;
        
    return 0 ;
}