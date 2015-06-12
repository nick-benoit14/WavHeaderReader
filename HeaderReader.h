#ifndef HEADER_READER_H
#define HEADER_READER_H
#include <string>

/*Super Class to read data from binary file*/

class HeaderReader{

public:
  HeaderReader(const char* inFile); /*filename of desired file in current directory*/
  long int find(std::string search); /*returns index immediately following searched phrase. -1 if phrase not present in file*/
  char* getData(int begin, int numBytes); /*copies numbytes to temporary buffer and returns pointer. Buffer terminated by two '$' in sequence*/
  ~HeaderReader(); /*deletes dataBuffer*/

protected:

 long int buffSize = 0; /*Stores length of data buffer*/
 char* dataBuffer = 0; /*contents of file are read into buffer*/
 char* tempBuff = 0; /*Stores data temporarily to be accessed via getData() method*/

};



#endif
