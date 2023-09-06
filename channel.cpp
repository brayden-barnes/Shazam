#include "channel.hpp"
                                                    //Implementation of the channel.hpp file
Channel::Channel(int* channel_data, int length){    //Constructor
    ChannelData = channel_data;
    Length = length;
}
Channel::Channel(){                                    //Constructor
    ;
}

int Channel::GetLength(){                                //Functions for creating object and pulling values
    return Length;
}
int* Channel::GetChannelData(){
    return ChannelData;
}
int Channel::GetSample(int sample_number){
    return ChannelData[sample_number];
}
void Channel::SetLength(int length){
    Length = length;
}
void Channel::SetChannelData(int* channel_data){
    ChannelData = channel_data;
}
