#ifndef wave_header_HPP                
#define wave_header_HPP
#include <string.h>
                                       //This header file is the main framwork for the data in our files.
typedef struct Header                 //Struct for .wav data. This includes the different components of the file type.
{
    char chunk_id[4];
    int chunk_size;
    char format[4];
    char subchunk1_id[4];
    int subchunk1_size;
    short int audio_format;
    short int num_channels;
    int sample_rate;
    int byte_rate;
    short int block_align;
    short int bits_per_sample;
    char subchunk2_id[4];
    int subchunk2_size;
} Header;


class WaveHeader                                //Class for the Wave Header. This includes most of the data for our files and the basic framework for setting and getting the data.
{
private:
    Header TheHeader;                            //Main data within the objects
    int SamplesPerChannel;
    int BytesPerSample;
    int NumberOfChannels;
    int NumberOfSamples;
    int NumberOfBytes;
    int sample_rate;
public:                                         //Constructor/destructors
    WaveHeader(Header);
    WaveHeader();
    ~WaveHeader();
   WaveHeader(class WaveHeader &AWaveHeader);    
   void SetHeader (Header header);                //Functions for setting values.
   void SetSamplesPerChannel(int samples);
   void SetBytesPerSample(int bytes);
   void SetNumberOfChannels (int channels);
   void SetNumberOfSamples (int samples);
   void SetNumberOfBytes(int bytes);
   void set_sample_rate(int sample_rate);
   
   void ChangeSampleRate(float s);
   void printheader();
   Header GetHeader();
   
   int GetSamplesPerChannel();               //functions for getting values already set.
   int GetBytesPerSample();
   int GetNumberOfChannels();
   int get_number_of_samples();
   int get_sample_rate();
   int GetNumberOfBytes();
   
};

#endif 

