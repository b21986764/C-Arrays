
//  main.cpp
//  C++Assignment1
//  Created by Sertaç Güler on 22.10.2022


#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <cstring>
#include "FindWrite.h"
//Including necessary files

using namespace std;


int main(int argc, const char * argv[]) {
    //Taking input argument key length and creating dynamic array
    int keylen = atoi(argv[2]);
    int** keyarr = new int*[keylen];
    
    for (int i = 0; i < keylen; i++) {
     
        keyarr[i] = new int[keylen];
    }
    
    string lower = "";
    string argument1 = argv[1];
    
    //Converting the map length to lower
    for (int i=0; i<argument1.length(); ++i)
        lower += tolower(argument1[i]);
    char lowered[lower.length() + 1];
    strcpy(lowered, lower.c_str());
    
    char* token = strtok(lowered,"x");
    int m = atoi(token);
    token = strtok(NULL, "x");
    int n = atoi(token);
    //Creating dynamic array of map
    int** maparr = new int*[m];
     
    for (int i = 0; i < m; i++) {
     
        maparr[i] = new int[n];
    }
    
    //Reading files
    FILE *file_map = fopen(argv[3], "r");
    FILE *file_key = fopen(argv[4], "r");
        
    //Making sure files are read
    if(NULL == file_key){
    
        cerr <<"File not found key" << endl;
        return 1;
    }
    if(NULL == file_map){
        
        cerr <<"File not found map" << endl;
        return 1;
    }
    //Storing lines into arrays
    for(int i = 0; i < m; i++){
              
        for(int j = 0; j < n; j++){
            fscanf(file_map, "%d", &maparr[i][j]);
        }
    }
    
    for(int i = 0; i < keylen; i++){
              
        for(int j = 0; j < keylen; j++){
            fscanf(file_key, "%d", &keyarr[i][j]);
        }
    }
    
    //Calling the FindWrite class to execute operations
    
    FindWrite execute;
    execute.set(argv[5]);
    execute.findwrite(maparr, keyarr, keylen, m, n);
    //Deleting dynamic arrays to avoid memory leak
    for(int i = 0; i < m; ++i){
        delete[] maparr[i];
    }
    delete[] maparr;
    for(int i = 0; i < keylen; ++i){
        delete[] keyarr[i];
    }
    delete[] keyarr;
    //Closing input files
    fclose( file_map );
    fclose( file_key);
    
    
    
    return 0;
}
