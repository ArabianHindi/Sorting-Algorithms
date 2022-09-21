#include <iostream>
#include <time.h>
using namespace std;
int count = 0; //swaps For Merge Sort
int CCount=0; //comparisons For Merge Sort
int compCounter=0; //comparisons For Quick Sort
int SwapCounter=0; //swaps For Quick Sort
int countComp = 0;//comparisons For Heap Sort
int countSwap = 0;//swaps For Heap Sort
//------------------------------------------------------------------------------
//Sorted List Start
int SortList(int arr[], int length)
{
    int temp = 0;
    //int length ;
    printf("\nElements of original array: \n");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("\n");
    printf("Elements of array sorted in Sorted order: \n");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
//------------------------------------------------------------------------------
//Inversely SORT START
int Inversely_Sorted_List(int number[],int n)
{

        int i, j, a;
         printf("\nElements of original array: \n");
        for (int i = 0; i < n; i++)
        {
        printf("%d ", number[i]);
        }
        for (i = 0; i < n; ++i)
        {
            for (j = i + 1; j < n; ++j)
            {
                if (number[i] < number[j])
                {
                    a = number[i];
                    number[i] = number[j];
                    number[j] = a;
                }
            }
        }
        printf("\n");
        printf("The numbers arranged in descending order are given below\n");
        for (i = 0; i < n; ++i)
        {
            printf("%d ", number[i]);
        }
}
//Inversely SORTED END
//------------------------------------------------------------------------------
//Random Sort Started
void swapp (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printRandom (int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
        cout << "\n";
}
int randomize (int arr[], int n)
{

    srand (time(NULL));
    printf("\nElements of original array: \n");
        for (int i = 0; i < n; i++)
        {
        printf("%d ", arr[i]);
        }

    for (int i = n - 1; i > 0; i--)
    {

        int j = rand() % (i + 1);
        swapp(&arr[i], &arr[j]);
    }
        printf("\n");
        printf("The numbers arranged in Random order are given below\n");
        printRandom(arr,n);
}
//Random Sort Ended
//------------------------------------------------------------------------------
//HEAP SORT STARTED
void heapify(int arr[], int n, int i, int& countComparisons, int& countSwaps)
{
    int largest = i;  // Initialize largest as root
    int l = 2 * i + 1;  // left = 2*i + 1
    int r = 2 * i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
    {
        countComparisons++;
        largest = l;
    }

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
    {
        countComparisons++;
        largest = r;
    }

    // If largest is not root
    if (largest != i)
    {
        countSwaps++;
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest, countComparisons, countSwaps);
    }
}
// main function to do heap sort
void heapSort(int arr[], int n, int& countComparisons, int& countSwaps)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, countComparisons, countSwaps);

    for (int i = n - 1; i >= 0; i--)
    {
        countSwaps++;
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, countComparisons, countSwaps); //<=== changed `n` to `i`
    }
}
//HEAP SORT ENDED
//------------------------------------------------------------------------------
//MERGE SORT START
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    // Create temp arrays
    int L[n1], R[n2];
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // indexes initialization
    int i = 0;
    int j = 0;
    int k = l;

    // merges the subarrays
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
            count++;
        } else {
            arr[k] = R[j];
            j++;
            count++;
        }
        k++;


    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        CCount++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        CCount++;
    }
}
void mergeSort(int arr[], int l, int r) {

    if (l >= r) {
        return;
    }
    int m = (l + r - 1) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}
//MERGE SORT ENDED
//------------------------------------------------------------------------------
void printArray(int arr[], int n)
{
    printf("\n");
    cout << "Printing array elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}
//------------------------------------------------------------------------------
//QUICK SORT START
//------------------------------------------------------------------------------
int partition(int array[], int low, int high)
    {
        int pivot = array[high];
        int i = (low-1);
        for (int j = low; j < high; j++)
        {
            compCounter++;
            if (array[j] <= pivot)
            {
                i++;
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                SwapCounter++;
            }
        }

        int temp = array[i+1];
        array[i+1] = array[high];
        array[high] = temp;
        SwapCounter++;

        return i+1;
    }
    void quickSort(int array[], int low, int high)
    {
        if (low < high)
        {
            int pivotPoint = partition(array, low, high);
            quickSort(array, low, pivotPoint-1);
            quickSort(array, pivotPoint+1, high);
        }
    }
//END QUICK SORT
//------------------------------------------------------------------------------
int getInvCount(int arr[], int n)
{
    int inv_count = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                inv_count++;

    return inv_count;
}
//------------------------------------------------------------------------------
int main()
{
     int x,xy;
     int arr[] = { 1 , 10 , 11 , 9 , 14 , 3 , 2 , 20 , 19, 43, 3, 2};
     int arr_size = sizeof(arr)/sizeof(arr[0]);
     printf("Choose From The List What Do You Want!!!::\n");
     printf("Enter 1 For Sorted List::\n");
     printf("Enter 2 For Inversely List::\n");
     printf("Enter 3 For Random Sort::\n");
     scanf("%d",&x);
     if(x>0&&x<4)
     {
        if(x==1)
        {
          SortList(arr,arr_size);
        }
        else if(x==2)
        {
            Inversely_Sorted_List(arr,arr_size);
        }
        else if(x==3)
        {
            randomize(arr,arr_size);
        }
     }
     int assignment_statements = getInvCount(arr, arr_size);
     printf("\nChoose From The List What Do You Want!!!::\n");
     printf("Enter 1 For Heap Sort::\n");
     printf("Enter 2 For Quick Sort::\n");
     printf("Enter 3 For Merge Sort::\n");
     printf("Enter 4 For ALL Sort::\n");
     scanf("%d",&xy);
     if(xy>0&&xy<=4)
     {
        if(xy==1)
        {
             clock_t start = clock();
             heapSort(arr, arr_size, countComp, countSwap);
             printArray(arr, arr_size);
             printf("\n");
             cout << "comparisons: " << countComp << " swaps: " << countSwap << endl;
             printf("\nNumber of inversions are %d \n", assignment_statements);
             clock_t end = clock();
             double elapsed1 = ( (double)(end - start) / CLOCKS_PER_SEC);
             printf("\nTime elapsed for Heap Sort  %f\n", elapsed1);

        }
        else if(xy==2)
        {
             clock_t start = clock();
             quickSort(arr,0,arr_size-1);
             printArray(arr, arr_size);
             printf("\n");
             cout << "comparisons: " << compCounter << " swaps: " << SwapCounter << endl;
             printf("\nNumber of inversions are %d \n", assignment_statements);
             clock_t end = clock();
             double elapsed1 = ( (double)(end - start) / CLOCKS_PER_SEC);
             printf("\nTime elapsed for Heap Sort  %f\n", elapsed1);
        }
        else if(xy==3)
        {
            clock_t start = clock();
            mergeSort(arr, 0, arr_size - 1);
            cout << "\nMerge Sorted array is \n";
            printArray(arr, arr_size);
            printf("\n");
            cout << "comparisons: " << CCount << " swaps: " << count << endl;
            printf("\nNumber of inversions are %d \n", assignment_statements);
            clock_t end = clock();
            double elapsed1 = ( (double)(end - start) / CLOCKS_PER_SEC);
            printf("\nTime elapsed for Heap Sort  %f\n", elapsed1);
        }
        else if(xy==4)
        {
             clock_t start = clock();
             heapSort(arr, arr_size, countComp, countSwap);
             printArray(arr, arr_size);
             printf("\n");
             cout << "comparisons: " << countComp << " swaps: " << countSwap << endl;
             printf("\nNumber of inversions are %d \n", assignment_statements);
             clock_t end = clock();
             double elapsed1 = ( (double)(end - start) / CLOCKS_PER_SEC);
             printf("\nTime elapsed for Heap Sort  %f\n", elapsed1);
             //*************************************************************************
             quickSort(arr,0,arr_size-1);
             printArray(arr, arr_size);
             printf("\n");
             cout << "comparisons: " << compCounter << " swaps: " << SwapCounter << endl;
             printf("\nNumber of inversions are %d \n", assignment_statements);
             //**************************************************************************
             mergeSort(arr, 0, arr_size - 1);
             cout << "\nMerge Sorted array is \n";
             printArray(arr, arr_size);
             printf("\n");
             cout << "comparisons: " << CCount << " swaps: " << count << endl;
             printf("\nNumber of inversions are %d \n", assignment_statements);
        }
     }
}
