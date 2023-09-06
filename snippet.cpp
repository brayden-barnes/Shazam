#include "snippet.hpp"

//Constructor
Snippet::Snippet(int* snippet_data, int length){
    this.snippet_data = song_data;
    this.length = length;
}

//Default constructor
Snippet::Snippet(){
    snippet_data = 0;
    length = 0;
}

//This function returns the signature of the snippet (array of int)
int* Snippet::get_signature(){
    return signature;
}

//This function splits the snippet into Segments objects of length 1024 and adds an array of them
//to the snippet class.
void Snippet::create_segments(){

    int* temp_array = new int[1024]; //create temp array for segment data

    //for each sample in snippet data
    for (int i = 0; i < length/1024; i++){ //i will increase every 1024 samples
        for (int j = 0; j < 1024; j++){
            temp_array[j] = snippet_data[i*1024+j]; //fill temp array with 1024 samples
        }
        segments[i] = new Segment(temp_array); //add new segment object
    }
}

//This function finds the signature of the snippet and adds to the snippet class
void find_signature(){
    create_segments(); //splits song into segments of length 1024

    //create temp array for max_power_indexes
    int temp_array = int[length/1024];

    //for each segment:
    for (int i = 0; i < length/1024; i++){
        signature[i] = segments[i].get_max_power_index();
    }
    signature = temp_array; //add signature to class object
}

