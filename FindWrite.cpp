//
//  FindWrite.cpp
//  C++Assignment1
//  Created by Sertaç Güler on 24.10.2022.


#include "FindWrite.h"
#include <iostream>

#include<cstdlib>
//Constructors and Destructors
FindWrite::FindWrite(){
}
FindWrite::~FindWrite(){
}
//global string outputtxt
string outputtxt;
//set outputtxt to argument sent by main
void FindWrite::set(string str){
    outputtxt=str;

}
//Taking map and key and multiplying them to get total value
int FindWrite::findvalue(int** mapptr, int** keyptr,int keylen , int& i, int& j){
    int value = 0;
    for(int p = 0; p < keylen; ++p){
        for(int q = 0; q < keylen; ++q){
            
            value += keyptr[p][q] * mapptr[i][j];
            ++j;
        }
        ++i;
        j = j - keylen;
    }
    i = i-keylen;
    
    
    return value;
}
//Findwrite commands the loop to find the key
void FindWrite:: findwrite(int** mapptr, int** keyptr, int keylen, int m, int n){
    ofstream output;
    output.open(outputtxt.c_str(), ios::app);
    
    int i= 0, j = 0;
    
    int value = findvalue(mapptr, keyptr, keylen,i , j);
    while(value < 0){
        value += 5;
    }
    
    int row = i + (keylen/2);
    int col = j + (keylen/2);
    
    output << row << "," << col << ":" << value << "\n";
    value= value % 5;
    

    while(value!=0){
        
        if(value==1) // Go keylen up if i is not on start
            {
            if(i==0){
                i+=keylen;
            }else{
                i-=keylen;
            }
            }
        else if(value==2) // Go keylen down if i is not close to down
            {
                if(i+keylen==m){
                    i-=keylen;
                }else{
                    i+=keylen;
                }
                    
            }
        else if(value==3)    // Go keylen right if j is not keylen close to right
            {
                if((j+keylen)==n){
                    j-=keylen;
                }else{
                    j+=keylen;
                }
            }
        else   //Go keylen left if j is not on start
            {
                if(j==0){
                    j+=keylen;
                }else{
                    j-=keylen;
                }
            }
        value = findvalue(mapptr, keyptr, keylen,i , j);
        //Calculating the center point of map
        row = i + (keylen/2 );
        col = j + (keylen/2);
        
        while(value < 0){
            value += 5;
        }
        output << row << "," << col << ":" << value << "\n";
        value = value%5;

        }
    //Close the output file
    output.close();
}
