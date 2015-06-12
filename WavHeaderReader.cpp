#include "WavHeaderReader.h"
#include <iostream>

WavHeaderReader::WavHeaderReader(const char* inFile) : HeaderReader(inFile){
    if(HeaderReader::find("RIFF") == -1)std::cout << "File Format Not Supported\n";
}

uint16_t WavHeaderReader::getChannels(){
    uint16_t* out = (uint16_t*) HeaderReader::getData(HeaderReader::find("fmt") + 7, 2);
    return out[0];
  }


uint32_t WavHeaderReader::getSampleRate(){
    uint32_t* out = (uint32_t*) HeaderReader::getData(HeaderReader::find("fmt") + 9, 4);
    return out[0];
}


uint16_t WavHeaderReader::getBitsPerSample(){
    uint16_t* out = (uint16_t*) HeaderReader::getData(HeaderReader::find("fmt") + 19, 2);
    return out[0];
  }

uint64_t WavHeaderReader::getDataIndex(){return HeaderReader::find("data") + 4;}

uint32_t WavHeaderReader::getDataLength(){
      uint32_t* out = (uint32_t*) HeaderReader::getData(HeaderReader::find("data"), 4);
      std::cout << "Data Length: " << out[0] << std::endl;
      return out[0];
}
char* WavHeaderReader::getAudioData(){
      return dataBuffer;
}
