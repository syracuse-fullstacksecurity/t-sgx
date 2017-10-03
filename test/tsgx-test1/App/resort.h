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

int resort(char* list, int* order, int size){
        
        char newlist[size];
        int index = 0;	
	
        for (int i = 0; i < size; i++)
           {     
                index = order[i];

                newlist[index] = list[i];
				
                //bar_print("\nlist[%d]=%s",i,list[i]);
        }

        bar_print("resorted list is:\n");
		for (int i = 0; i < size; i++)
			{
			    bar_print("index is:%d, value is:%c\n",i,newlist[i]);
		}
       return 1;
}

