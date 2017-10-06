/* 
 * printf: 
 *   Invokes OCALL to display the enclave buffer to the terminal.
 */
int bar_print(const char *fmt, ...)
{
    int ret[1];
    char buf[BUFSIZ] = {'\0'};
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buf, BUFSIZ, fmt, ap);
    va_end(ap);
    ocall_print(buf, ret);
    return ret[0];
}

void merge(int arr[], char brr[],int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];
    char LL[n1];
    char RR[n2];
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
     {
         L[i] = arr[l + i];
         LL[i] = brr[l + i];
     }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1+ j];
        RR[j] = brr[m + 1+ j];
    }

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            brr[k] = LL[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            brr[k] = RR[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        brr[k] = LL[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        brr[k] = RR[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], char brr[],int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l+(r-l)/2;
        //printf("l:%d, m:%d, r:%d\n",l,m,r);
		// Sort first and second halves
		mergeSort(arr, brr, l, m);
		mergeSort(arr, brr, m+1, r);


		merge(arr, brr, l, m, r);
	}
}

int resort(char* list, int* order, int size){
        

         double time1[2], time2[2];
         ocall_getTime(time1); 
         mergeSort(order,list,0,size-1);
         ocall_getTime(time2);
         bar_print("\nList is resorted! Used time: %f us\n",(time2[0]-time1[0])*1000000+(time2[1]-time1[1]));
       /*	for (int i = 0; i < size; i++)
	{
	  bar_print("index:%d, value:%c, order:%d\n",i,newlist[i],order[i]);
	}*/
       
      // free(newlist);
       return 1;
}

