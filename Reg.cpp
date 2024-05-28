#include "Reg.h"
#include <stdio.h>
#include <stdint.h>



void getRegister(uint64_t header){

    uint16_t showIDs(header);
    printf("ID : %u \t",showIDs);

    uint16_t Low=(header<<16)>>48;
    printf("Lower Level : %u\n",Low);

    uint8_t type=(header <<38)>>62;

    uint16_t Upper=(header<<48)>>48;
    if(type==0){
        printf("Devide Type %u\t",type);
        printf("Info : ignorar\t");
        printf("UpperLevel : %u\n",Upper);

    }
    if(type==3){
        printf("Devide Type %u\t",type);
        printf("Info : ignorar\t");
        printf("UpperLevel : %u\n",Upper);
    }
    if(type==1){
        uint8_t Sens=(header<<44)>>62;
        if(Sens==0){
            printf("Devide Type %u\t",type);
            printf("Info : Flow\t",Sens);
            printf("UpperLevel : %u\n",Upper);
        }
        if(Sens==1){
            printf("Devide Type %u\t",type);
            printf("Info : Temp\t",Sens);
            printf("UpperLevel : %u\n",Upper);
        }
        if(Sens==2){
            printf("Devide Type %u\t",type);
            printf("Info : Presure\t",Sens);
            printf("UpperLevel : %u\n",Upper);
        }
        if(Sens==3){
            printf("Devide Type %u\t",type);
            printf("Info : Level\t",Sens);
            printf("UpperLevel : %u\n",Upper);
        }
    }
    if(type==2){
        uint8_t Act=(header<<40)>>63;
        if(Act==1){
            printf("Devide Type %u\t",type);
            printf("Info : Valve\t",Act);
            printf("UpperLevel : %u\n",Upper);
        }
        if(Act==2){
            printf("Devide Type %u\t",type);
            printf("Info : Motor\t",Act);
            printf("UpperLevel : %u\n",Upper);
        }
    }
}

