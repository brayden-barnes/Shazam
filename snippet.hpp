#ifndef SNIPPET_H
#define SNIPPET_H

#include "segment.hpp"

//This class represents a snippet of code. A song is broken into snippets of 5 seconds
//get the signature for each snippet
class Snippet(){
    
    private:
    int* signature;
    int* snippet_data;
    Segment** segments;
    int length; //length of snippet_data

    public:
    Snippet();
    Snippet(int*);

    int* get_signature();
    
    void find_signature();
    void create_segments();
};

#endif