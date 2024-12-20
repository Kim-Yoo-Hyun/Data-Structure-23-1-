# Data-Structure-23-1-


1.	Bubble Sort
	Bubble sort (Array, n) // Arrays: list of sortable items & n as numofkeys
{
for i=0 to n-1
{
for j=1 to n-i-1
        { 
            if Array[j-1] > Array[j] 
{   
                swap Array[j-1], Array[j]
} 
        }
                 }
} 






2.	Partition Function & Quick Sort
	Function Partition (Array, low, high) //Array: list of sortable items & low, high: integer      
{
pivot = Array[high]      // pivot: integer
i = (low-1)             // i: integer

        for j = low to high-1
{ 
            if (Array[j] < pivot)
            { 
                 i = i+1
 swap Array[i], Array[j]
             }
}
swap Array[i+1] and Array[high]
return i+1 
}
	Quicksort (Array, low, high) //Array: list of sortable items & low, high: integer
{
    if low < high
    { 
        pi initializes as partition (Array, low, high)  
        Quicksort (Array, low, pi-1)
        Quicksort (Array, pi+1, high)
    }
}
