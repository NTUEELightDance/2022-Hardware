#include "../include/pca2022.h"
#include <time.h>
#include <iostream>
using namespace std;

int OFs[156] = {
    0, 0, 0, 0, 0, 0, //PWM_RED PWM_GREEN PWM_BLUE IREF_RED IREF_GREEN IREF_BLUE of OF0 
    0, 0, 0, 0, 0, 0, //PWM_RED PWM_GREEN PWM_BLUE IREF_RED IREF_GREEN IREF_BLUE of OF1
    0, 0, 0, 0, 0, 0, //PWM_RED PWM_GREEN PWM_BLUE IREF_RED IREF_GREEN IREF_BLUE of OF2
    0, 0, 0, 0, 0, 0, //PWM_RED PWM_GREEN PWM_BLUE IREF_RED IREF_GREEN IREF_BLUE of OF3
    0, 0, 0, 0, 0, 0, //...
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, // 26 OFs in total
};

int main(int argc, char* argv[]){

    int *channelOrder = new int [26];
    for(int i=0;i<26;i++)channelOrder[i] = i+1;
    
    int **pcaTypeAddr = new int* [4];
    
    pcaTypeAddr[0] = new int[2];
    pcaTypeAddr[0][0] = 9955;
    pcaTypeAddr[0][1] = 0x3f;
    pcaTypeAddr[1] = new int[2];
    pcaTypeAddr[1][0] = 9955;
    pcaTypeAddr[1][1] = 0x2b;
    pcaTypeAddr[2] = new int[2];
    pcaTypeAddr[2][0] = 9956;
    pcaTypeAddr[2][1] = 0x56;
    pcaTypeAddr[3] = new int[2];
    pcaTypeAddr[3][0] = 9956;
    pcaTypeAddr[3][1] = 0x32;

    PCA pca(channelOrder, pcaTypeAddr); // PCA init
    
    pca.Write(OFs);

}