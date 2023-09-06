#include "wave_header.hpp"
#include <iostream>
using namespace std;
                                                                    //This file is the implementation of the functions created in wave_header.hpp
WaveHeader::WaveHeader(Header someheader){                            //Constructor
    TheHeader = someheader;
    BytesPerSample =  (someheader.bits_per_sample/8);
    NumberOfChannels = someheader.num_channels;
    NumberOfSamples = (someheader.subchunk2_size/BytesPerSample);
    SamplesPerChannel = NumberOfSamples/NumberOfChannels;
    NumberOfBytes = someheader.subchunk2_size;
}

WaveHeader::WaveHeader(){                                                //Constructor
    ;
}

WaveHeader::~WaveHeader(){                                                //destructor

}
void WaveHeader::ChangeSampleRate(float s){                               //Changing sample rate
    TheHeader.sample_rate = TheHeader.sample_rate * s;
}

void WaveHeader::SetHeader (Header someheader){                            //Defining values in the object
    TheHeader = someheader;
    BytesPerSample =  (someheader.bits_per_sample/8);
    NumberOfChannels = someheader.num_channels;
    NumberOfSamples = (someheader.subchunk2_size/BytesPerSample);
    SamplesPerChannel = NumberOfSamples/NumberOfChannels;
    NumberOfBytes = someheader.subchunk2_size;
}

void WaveHeader::SetSamplesPerChannel(int samples){                        //Functions within the class
    SamplesPerChannel = samples;
}
void WaveHeader::SetBytesPerSample(int bytes){
    BytesPerSample = bytes;
}
void WaveHeader::SetNumberOfChannels (int channels){
    NumberOfChannels = channels;
}
void WaveHeader::SetNumberOfSamples (int samples){
    NumberOfSamples = samples;
}   
void WaveHeader::SetNumberOfBytes (int bytes){
    NumberOfBytes = bytes;
    TheHeader.subchunk2_size = bytes;
}
void WaveHeader::set_sample_rate(sample_rate){
    this.sample_rate = sample_rate;
}

Header WaveHeader::GetHeader(){
    return TheHeader;
}
int WaveHeader::GetSamplesPerChannel(){
    return SamplesPerChannel;
}
int WaveHeader::GetBytesPerSample(){
    return BytesPerSample;
}
int WaveHeader::GetNumberOfChannels(){
    return NumberOfChannels;
}
int WaveHeader::get_number_of_samples(){
    return NumberOfSamples;
}
int WaveHeader::get_sample_rate(){
    return sample_rate;
}

int WaveHeader::GetNumberOfBytes(){
    return NumberOfBytes;
}

