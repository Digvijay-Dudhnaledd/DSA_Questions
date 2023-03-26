#include <bits/stdc++.h>
using namespace std ;

char NextAlpha(char array[100] ,int size , char key)
{
    int low=0 ,high=size-1 ,mid ;
    char result ;

    while(low<=high)
    {
        mid = low + ((high-low)/2) ;

        if(array[mid]>key)
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
    char array[100] ,result ,key ;
    int size ;

    cout<<"Enter the number of alphabets present in Array : " ;
    cin>>size ;
    for(int i=0 ; i<size ; i++)
    {
        cout<<"Enter the Alphabet present at Position "<<i+1<<" : " ;
        cin>>array[i] ;
    }

    cout<<"Enter the Alphabet after which you want to find next Alphabet : " ;
    cin>>key ;

    result = NextAlpha(array,size,key) ;
    cout<<"```````````````````````````````````````````````"<<endl ;
    cout<<"The Next Alphabet after "<<key<<" which is present in Array is : "<<result<<"."<<endl ;

    return 0 ;
}