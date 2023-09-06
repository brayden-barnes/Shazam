#ifndef wave_HPP
#define wave_HPP
#include <string.h>
#include "wave_header.hpp"
#include "channel.hpp"
#include <string>
#include "Snippet.hpp"
                                    //Header used for the Wave class. This is used in order to import data as well as create new .wav files.
class Wave{
private:                            
    WaveHeader TheHeader;
    char* Data;
    Channel** Channels;
    Snippet** snippets;
    
public:                            
    Wave();                        //Constructors/Destructor
    ~Wave();
    Wave(Header SomeHeader);
    
    void StereoToMono();                    //converting from stereo to mono
    void ChangeSpeed(float s);              //Changing sample speed
    void ReadWave(std::string filename);    //Reading .wav files to import data
    void WriteWave(std::string filename);   //Writing new .wav files for export
    
    void create_snippets();                 //Creating snippits in order to compare songs

};

#endif