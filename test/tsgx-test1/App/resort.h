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

void bubbleSort(char let[], int order[], int n) {
      int swap = 1;
      int j = 0;
      int ntmp;
      char ctmp;
      while (swap > 0) {
            swap = 0;
            j++;
            for (int i = 0; i < n - j; i++) {
                  if (order[i] > order[i + 1]) {
                        ntmp = order[i];
                        order[i] = order[i + 1];
                        order[i+1] = ntmp;

                        ctmp = let[i];
                        let[i] = let[i + 1];
                        let[i + 1] = ctmp;
                        swap = 1;
                  }
            }
      }
}


int resort(char* list, int* order, int size){
        
/*        int* newlist = (int*)malloc(size*sizeof(int*));
          int index = 0;	
	
        for (int i = 0; i < size; i++)
           {     
                index = order[i];

                newlist[index] = list[i];
				
               // bar_print("handling list[%d]=%c\n",i,list[i]);
        }*/
        double time1[2], time2[2];
        ocall_getTime(time1);
        bubbleSort(list,order,size);
        ocall_getTime(time2);
        
        bar_print("\nList is resorted! Used time: %f us\n",(time2[0]-time1[0])*1000000+(time2[1]-time1[1]));
       	/*for (int i = 0; i < size; i++)
	{
	  bar_print("index:%d, value:%c, order:%d\n",i,list[i],order[i]);
	}*/
       
    //   free(newlist);
       return 1;
}

