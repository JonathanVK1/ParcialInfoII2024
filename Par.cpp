#include <stdio.h>
#include <stdint.h>
#include "show.h"
#include "Reg.h"



int main(){

    FILE *f=fopen("network_structure.dat","rb");
    uint64_t header;
    uint16_t Id;
    uint16_t Low;
    uint16_t Upper;
    int n=0,i=0,j=0;

    if(f==NULL){
        printf("archivo vacio");
        return -1;
    }
    else{
        printf("el archivo se abrio\n");
    }

    while(!feof(f)){
        fread(&header,sizeof(uint64_t),1,f);
        j=countDevices(j);
        //printf("header : %u\n",header);
        showIDs(header);
        //Low=(header<<16)>>48;

        //printf("Low : %u\n",Low);
        //Upper=(header<<48)>>48;
        //printf("Upper : %u\n",Upper);
    }
    printf("cant %d\n",j);
    rewind(f);
    while(!feof(f)){
        fread(&header,sizeof(uint64_t),1,f);
        getRegister(header);
    }

}
