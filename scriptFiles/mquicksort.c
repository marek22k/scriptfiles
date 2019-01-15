#include "mquicksort.h"

void mquicksort(long * arr, size_t beg, size_t end)
{
    register long p = arr[end];  // Set pivot element
    register size_t i = beg;  // i on the Begin
    register size_t j = end;  // j on the End
    register long tmp;  // Temporary variable for buffering values during triangular swap.
    
    while(i < j)  // As long as i is on the right side of j.
    {
        for(; arr[i] < p; i++);  // Find the biggest element
        for(; arr[j] > p; j--);  // Find the smallest element
        if(i <= j)  // If i and j have not overlapped
        {
            tmp = arr[i], // Swap the values so the smaller values are on the left
            arr[i++] = arr[j], // The index is being edited. If this step were not there, he would again find
            arr[j--] = tmp;// the same values for i and j through running and an infinite loop would result.
        }
    }
    
    // If there are enough items to sort, you should also sort them. This happens recursively.
    if(beg < j) mquicksort(arr, beg, j);
    if(i < end) mquicksort(arr, i, end);
}
