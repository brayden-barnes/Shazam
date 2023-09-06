#include "wave.hpp"
#include "wave_header.cpp"
#include "channel.cpp"
#include "wave_header.hpp"
#include "channel.hpp"
#include <string>
#include<fstream>
#include<iostream>
using namespace std;
                                                    //Implementation of the wave.hpp file. Mainly used to read/write .wav files and also edit.
Wave::Wave(){                                       //Constructor
    ;
}
Wave::~Wave(){                                      //Destructor
    delete Data;
    delete Channels;
}   

Wave::Wave(Header SomeHeader){                      //Setting header data
    TheHeader.SetHeader(SomeHeader);
}

void Wave::ChangeSpeed(float s){                    //Changing sample rate
    TheHeader.ChangeSampleRate(s);
}

void Wave::StereoToMono(){                            //Converting from stero to mono
    int* channel_data;
    channel_data = new int[TheHeader.GetSamplesPerChannel()*TheHeader.GetNumberOfChannels()];
    for (int i = 0; i < TheHeader.GetSamplesPerChannel(); i++){
        for (int j = 0; j< TheHeader.GetNumberOfChannels(); j++){
            channel_data[(2*i) + j] = Channels[j]->GetSample(i);
        }
    }
    delete Channels;
    Channels = new Channel*[1];
    Channels[0] = new Channel[TheHeader.GetSamplesPerChannel()*TheHeader.GetNumberOfChannels()];
    Channels[0]->SetChannelData(channel_data);
    TheHeader.SetNumberOfChannels(1);
    int temp = TheHeader.GetSamplesPerChannel() * 2;
    TheHeader.SetSamplesPerChannel(temp);
    delete channel_data;
}

void Wave::ReadWave(std::string filename){            //Reading .wav files in order to import data.
    Header temp;
    ifstream infile;
    infile.open(filename, ios::binary);
    infile.read((char*) &temp, sizeof(Header)); 
    TheHeader.SetHeader(temp);
    Data = new char[TheHeader.get_number_of_samples()*2];
    infile.read(Data, TheHeader.get_number_of_samples()*2);
    infile.close();


    int* channel_data;
    channel_data = new int[TheHeader.GetSamplesPerChannel()];
    short int* samples_array;
    samples_array = new short int[TheHeader.get_number_of_samples()];
    char* ptr = NULL;
    for (int i =0; i < TheHeader.get_number_of_samples(); i++){
        ptr = &Data[2*i];
        memcpy(&samples_array[i],ptr,TheHeader.GetBytesPerSample());
    }
    
    
    
    Channels = new Channel* [TheHeader.GetNumberOfChannels()];
    for (int i = 0; i < TheHeader.GetNumberOfChannels(); i++){
        for (int j = 0; j < TheHeader.GetSamplesPerChannel(); j++){
            channel_data[j] = int(samples_array[(2*j) + i]);
        }
        
        Channels[i] = new Channel(channel_data, TheHeader.GetSamplesPerChannel());
        Channels[i]->SetChannelData(channel_data);
        Channels[i]->SetLength(TheHeader.GetSamplesPerChannel());
    }
    delete samples_array;
    delete channel_data;
}

void Wave::WriteWave(std::string filename){                    //Writing new .wav files in order to export.
    ofstream outfile;
    Header temp;
    temp = TheHeader.GetHeader();
    outfile.open(filename, ios::binary|ios::trunc);
    outfile.write((char*)&temp, sizeof(Header));
    char* thedata;
    thedata = new char[temp.subchunk2_size];
    char* ptr = NULL;
    short int value;
    int num = 0;
    for (int i = 0; i < TheHeader.GetSamplesPerChannel(); i++){
       for (int j = 0; j < TheHeader.GetNumberOfChannels(); j++){
           value = Channels[j]->GetSample(i);
            ptr = (char*)&value;
            thedata[num] = *ptr;
            ptr++;
            thedata[num+1] = *ptr;
            num = num +2;
        }
    }
    outfile.write((char*) thedata, num);
    outfile.close();
    delete thedata;
}

//This function creates snippets of the song and adds them to this class object
void Wave::create_snippets(){
    int snippet_size = wave_header.get_sample_rate()*5; //the length of the snippet data
    
    //create temp array for snippet data (size 5 seconds)
    /*
    int* temp_array = new int[snippet_size];
    
    for (int i = 0; i < wave_header.get_number_of_samples()/snippet_size; i++){
        for (int j = 0; j < snippet_size; j++){
            temp_array[j] = 
        }
    }
    */
}



