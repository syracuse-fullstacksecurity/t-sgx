#include <stdarg.h>
#include <stdio.h>      /* vsnprintf */

#include <string.h>
#include <sgx_cpuid.h>

#include "sgx_trts.h"
#include "Enclave.h"
#include "Enclave_t.h"  /* suprint*/

#include "../App/resort.h"

int ecall_resort(char* list, int* tv, int size){
    return resort(list,tv,size);
}

int ecall_resort_ncp(long list, long tv, int size){
    return resort((char*)list,(int*)tv,size);
}


