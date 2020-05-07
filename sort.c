#include <stdio.h> 
#include <stdlib.h>

// A function to implement bubble sort 
void bubbleSort(int arr[], int n) 
{ 
   int i, j, temp; 
  
  for (i = 0; i < n-1; i++)       
  {
       // Last i elements are already in place    
    for (j = 0; j < n-i-1; j++)  
    {
      if (arr[j] > arr[j+1]) 
      {
          temp = arr[j];
          arr[j]=arr[j+1];
          arr[j+1]= temp;

      }
    }
  }

  for(i=0;i<n;i++)
  {
    printf("%d ",arr[i]);
  }
} 


void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for large l and h
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 

} 

// Driver program to test above functions 
int main() 
{ 
    int n;
    printf("Enter size of array: \n");
    scanf("%d",&n);
    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter array elements: \n");
    int a;
    for(int i =0;i<n;i++)
    {
        scanf("%d",&a);
        *(arr+i) = a;
    }
   // bubbleSort(arr, n); 

    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
      printf("%d ",arr[i]);
    }
    free(arr);
    printf("\n");
    return 0; 
} 