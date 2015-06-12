/*WavHeaderReader is a simple class to facilate reading data from Wav Files.
This class was initially developed to aid in a small school project. We used
an audio library called PortAudio instead of the native ubuntu audio API. I would
greatly recommend this to anyone interested in playing music from Wav files.

More information can be found at http://portaudio.com/docs/v19-doxydocs/index.html

For more information on the Wav file format, this website was incredibly helpful

http://www.topherlee.com/software/pcm-tut-wavformat.html

Happy Coding!

-Nick Benoit
6/11/15

*/




#ifndef WAV_HEADER_READER_H
#define WAV_HEADER_READER_H
#include "HeaderReader.h"

class WavHeaderReader : public HeaderReader{

public:
  WavHeaderReader(const char* inFile); /*Checks for RIFF header and reads file into memory*/
  uint16_t getChannels(); /*Returns number of channels.  example value: 2*/
  uint32_t getSampleRate(); /*Returns sample Rate. example value: 44100*/
  uint16_t getBitsPerSample(); /*Returns number of bits per sample. example value: 16*/
  uint64_t getDataIndex(); /*Returns index where audio data begins. example value: 44*/
  uint32_t getDataLength(); /*Returns number of following data bytes example value: 43000000 (43MB / 3ish Minute Song)*/
  char* getAudioData(); /*Returns pointer to data buffer. Offset in implementation by getDataIndex()*/




};



#endif
