#include<stdio.h>

int input(int *arr,int n){
    
    int i;
    for (i=0;i<n;i++)
    scanf("%d",&arr[i]);

}

void print_arr( int *arr, int n){
    for (int i=0;i<n;i++)
    printf("%d  ",arr[i]);
}
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void liner_sort(int *arr,int n){
int min,j,i;
for (i=0;i<n-1;i++){
    min=i;
    for (j=i+1;j<n;j++){
        if(arr[min]>arr[j])
        swap(&arr[min],&arr[j]);
        }
    }
}

void bubble_sort(int *arr,int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]>arr[j])
            swap(&arr[i],&arr[j]);
        }
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
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
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
  
        /* Move elements of arr[0..i-1], that are 
          greater than key, to one position ahead 
          of their current position */
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

void count_sort(int arr[], int size)
{
	int i,max=0;
	for(i=0;i<size;i++)
	{	
		if(arr[i]>max)
		max=arr[i];
	}
	max++;

	int count[max];
	for(i=0;i<max;i++)
	count[i]=0;
	
	for (i=0;i<size;i++)
	{
		count[arr[i]]++;
	}
	for(i=1;i<max;i++)
	count[i]=count[i]+count[i-1];
	

	int output[size];
	for(i=0;i<size;i++)
	{
		output[count[arr[i]]-1]=arr[i];
		count[arr[i]]=count[arr[i]]-1;
	}	
		
	print_arr(output,size);
	print_arr(count,max);
	
	
}


void main(){
    int n;
    printf("Enter Size of ARR : ");
    scanf("%d",&n);
    int arr[n];
    input(arr,n);
    printf("Unsorted Array : ");
    print_arr(arr,n);

    //liner_sort(parr,n);
    //bubble_sort(parr,n);
    //mergeSort(arr,0,n-1);
    //insertionSort(arr,n);
    //quickSort(arr, 0, n-1);
     count_sort(arr,n);
    printf("Sorted Array : ");
    print_arr(arr,n);
}
