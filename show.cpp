#include "show.h"
#include <stdint.h>
#include <stdio.h>

void showIDs(uint64_t header){
    uint16_t Id;
    Id=header>>48;
    printf("Id: %u\n",Id);

}

int countDevices(int j){
    j=j+1;
    return j;

}
