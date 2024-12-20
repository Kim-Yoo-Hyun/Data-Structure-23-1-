
// GroupL(202235040 ¹Ú°Ç¿ì, 202235019 ±è¼±¿µ, 202035510 ±èÀ¯Çö, 202235130 Á¶Çý¸°)

#pragma warning(disable :4996)
#include <stdio.h>
#include <time.h>

int keylist[100000];
int keylist_sorted[100000];
char filename_keylist[128] = "num_list.txt";
char filename_keylist_sorted[128] = "num_list_sorted.txt";


// verify your sorting results with the validation sequence
int check_sorted(int* sorting_result)
{
    int verfiedresult = 0;

    // read the sorted result of the test sequence
    FILE* fs;
    fs = fopen(filename_keylist_sorted, "r");

    if (fs == NULL)
    {
        printf("the test seqeunce file (%s) is not accessible\n", filename_keylist_sorted);
        return verfiedresult;
    }


    int index = 0;
    while (fscanf(fs, "%d", &keylist_sorted[index]) == 1)
    {
        if (sorting_result[index] == keylist_sorted[index])
        {
            verfiedresult++;
        }
        index++;
    }

    fclose(fs);

    return verfiedresult;

}
//// swap two elements
//void swap(int* a, int* b) {
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}

// program your bubble sorting algorithm
void bubblesorting(int* original_list, int numofkeys)
{
    int temp = 0;
    for (int i = 0; i < numofkeys; i++) {
        for (int j = 1; j < numofkeys - i; j++) {
            if (original_list[j - 1] > original_list[j]) {
                //swap(&original_list[j - 1], &original_list[j]);
                temp = original_list[j - 1];
                original_list[j - 1] = original_list[j];
                original_list[j] = temp;
            }
        }
    }
}

// partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];//pivot = last element
    int i = (low - 1);
    int temp = 0;

    for (int j = low; j <= high - 1; j++) {//if find number < pivot swap with list[i] then i++
        if (arr[j] < pivot) {
            i++;
            //swap(&arr[i], &arr[j]); //if use swap function time change to 13 -> 28
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    //The process of moving pivot to the center at the end 
    //swap(&arr[i+1], &arr[high]);
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// quicksort algorithm
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);//Split into 2 based on the pivot
        quicksort(arr, low, pi - 1);//Sorting left
        quicksort(arr, pi + 1, high);//Sorting right
    }
}

// program your second sorting algorithm
// call quicksort function in yoursecondsorting
void yoursecondsorting(int* original_list, int numofkeys) {
    quicksort(original_list, 0, numofkeys - 1);
}

void sorting(int* original_list, int numofkeys)
{
    //bubblesorting(original_list, numofkeys);
    yoursecondsorting(original_list, numofkeys);
    return;
}


int main()
{

    // read the test sequence
    int numofkeys = 0;
    FILE* fs = fopen(filename_keylist, "r");
    if (fs == NULL)
    {
        printf("the test seqeunce file (%s) is not accessible\n", filename_keylist);
        return 0;
    }

    while (fscanf(fs, "%d", &keylist[numofkeys]) == 1)
    {
        numofkeys++;

    }

    fclose(fs);


    // begin sorting with the test sequence
    clock_t start, end;
    start = (double)clock();
    sorting(keylist, numofkeys);
    end = (double)clock();

    // compute the time of sorting
    float computationtime = (double)(end - start); // get the total time cost 
    printf("total time cost(ms) : %lf \n", computationtime);


    // verify with the validation sequence
    int verifiedresult = check_sorted(keylist);

    printf("=============== result =============== \n");
    if (verifiedresult == numofkeys)
    {
        printf("your sorting algorithm resulted in the correct ascending order for the given list \n\n");
    }
    else
        printf("your sorting algorithm failed to produce the correct ascending order for the given list \n\n");


}