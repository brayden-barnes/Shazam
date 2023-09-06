#ifndef channel_HPP
#define channel_HPP
                                        //This file exists for the channel class.
class Channel{                          //Data within a channel. Along with functions for creating new channel objects
    private:
        int* ChannelData;
        int Length;
    public:
    Channel(int* channel_data, int length);
    Channel();
    int GetLength();
    int* GetChannelData();
    int GetSample(int sample_number);
    void SetLength(int length);
    void SetChannelData(int* channel_data);
};

#endif