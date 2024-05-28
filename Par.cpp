#include <stdio.h>
#include <stdint.h>
#include "show.h"
#include "Reg.h"



int main(){

    FILE *f=fopen("network_structure.dat","rb");
    int Lower;
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
        showIDs(header);
    }
    printf("cant Ids %d\n",j);
    rewind(f);
    while(!feof(f)){
        fread(&header,sizeof(uint64_t),1,f);
        getRegister(header);
    }
    rewind(f);
    while(!feof(f)){
        fread(&Lower,sizeof(int),1,f);
        printf("Id anterior %u\n",Lower);

    }
}
