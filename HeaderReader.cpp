#include "HeaderReader.h"
#include <iostream>
#include <fstream>
#include <string>



HeaderReader::HeaderReader(const char* inFile){


            std::ifstream inputFile;

            inputFile.open(inFile, std::ios::in|std::ios::binary);

            if(inputFile.is_open()){
                inputFile.seekg(0, std::ios::end);
                buffSize = inputFile.tellg();
                inputFile.seekg(0, std::ios::beg);
                dataBuffer = new char[buffSize];
                inputFile.read(dataBuffer, buffSize);
                std::cout << "Read: " << buffSize << "  Bytes from File: " << inFile << "\n";
              }
            else{std::cout << "Unable To Open File\n";}
      }

HeaderReader::~HeaderReader(){  /*deletes dataBuffer*/
              delete[] dataBuffer;
              dataBuffer = 0;
              if(tempBuff) delete[] tempBuff;
              tempBuff = 0;
          }

long int HeaderReader::find(std::string search){

    int j = 0;

    for(int i=0; i < buffSize; i++){
        while(dataBuffer[i] == search[j]){
            if(dataBuffer[i] == search[j]) i++; j++;
            if(j == search.length()) return i;
          }
        j = 0;
      }
      return -1;

    }


char* HeaderReader::getData(int begin, int numBytes){

  if(tempBuff) delete[] tempBuff;
  if(numBytes > buffSize) numBytes = buffSize;
  int j = 0;

  if(begin < 0 ){
        std::cout << "Index Does Not Exist\n";
        tempBuff = new char[2];}

  else{
      tempBuff = new char[numBytes];
      for(int i = begin; i < begin + numBytes; i++, j++){
          tempBuff[j] = dataBuffer[i];
        }
      }

  tempBuff[j] = '$';
  tempBuff[j+1] = '$';

  return tempBuff;
}
