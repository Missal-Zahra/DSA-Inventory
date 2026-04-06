#include <stdio.h>

int firstOccurrence(int arr[], int n, int key){
    int low = 0, high = n-1, firstIndex = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == key){
            firstIndex = mid;
            high = mid - 1; // move left to find first
        }
        else if(key < arr[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return firstIndex;
}

int lastOccurrence(int arr[], int n, int key){
    int low = 0, high = n-1, lastIndex = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == key){
            lastIndex = mid;
            low = mid + 1; // move right to find last
        }
        else if(key < arr[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return lastIndex;
}

int countOccurrences(int arr[], int n, int key){
    int first = firstOccurrence(arr, n, key);
    if(first == -1) return 0; // key not found
    int last = lastOccurrence(arr, n, key);
    return last - first + 1;
}

int main(){
    int arr[] = {1,2,2,2,3,4,4,5,5,5,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 5;
    
    int count = countOccurrences(arr, n, key);
    printf("Number %d occurs %d times\n", key, count);
    
    return 0;
}