/*This may give wrong answer in finite arry bcoz we are increaing high as high*2 and it will cause index out of bound problem(mid<size). This will work flawlessly for Infinite array.*/

#include <bits/stdc++.h>
using namespace std ;

int BinaryFirstOneSearch(int array[100])
{
    int low=0 ,high=1 ,result ,mid ;
    while(low<=high)
    {
        if(array[high]!=1)
        {
            low = high ;
            high = high * 2 ;
        }
        else
        {
            mid = low + ((high-low)/2) ;
            if(array[mid]==1)
            {
                result = mid ;
                high = mid-1 ;
            }
            else
                low = mid+1 ;            
        }
    }
    return result ;
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

    index = BinaryFirstOneSearch(array) ;
    cout<<"```````````````````````````````````````````\n" ; 
    cout<<"First time one is Occurred at position : "<< index+1 <<" in Given Array."<<endl ;
        
    return 0 ;
}