#include<iostream>
using namespace std;

void merge(int *arr, int start, int end)
{
    int mid = (start+end)/2;

    int len1 = mid-start+1;
    int len2 = end-mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values of first half of array in first array
    int startingIndex  = start;
    for(int  i=0; i<len1 ; i++)
    {
        first[i] = arr[startingIndex++];
    }

    //copy values of second half in second array
    startingIndex = mid+1;
    for(int i = 0; i<len2 ; i++)
    {
        second[i] = arr[startingIndex++];
    }


    //merge (two sorted arrays)
    int i = 0;
    int j = 0;
    startingIndex = start;

    while(i < len1 && j<len2)
    {
        if (first[i] < second[j])
        {
            arr[startingIndex++] = first[i++];
        }
        else{
            arr[startingIndex++] = second[j++];
        }
    }

    while(i<len1)
    {
        arr[startingIndex++] = first[i++];
    }

    while(j<len2)
    {
        arr[startingIndex++] = second[j++];
    }
}


void mergeSort(int *arr, int start, int end)
{
    //base case
    if(start>=end)
    {
        return;
    }

    int mid = (start+end)/2;

    //sorting left part
    mergeSort(arr,start,mid);

    //sorting right part
    mergeSort(arr,mid+1,end);

    //merge
    merge(arr,start,end);
}


int main()
{
    int arr[6]= {1,3,5,2,4,0};

    int n=6;

    mergeSort(arr , 0, n-1);

    for(int i = 0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}