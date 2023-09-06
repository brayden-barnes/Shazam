#include "segment.hpp"
#include <math.h>
#include <iostream>
using namespace std;


Segment::Segment(int* segmentdata, int data_size){
    data = segmentdata;
    size_of_data = data_size;
}
Segment::~Segment(){
    delete data;
    delete fourier_coefficients;
}
int Segment::get_max_power_index(){
    return max_power_index;
}
void Segment::set_max_power_index(int index){
    max_power_index = index;
}
int* Segment::get_data(){
    return data;
}
void Segment::set_data(int* segmentdata){
    data = segmentdata;
}
complex* Segment::get_fourier_coefficients(){
    return fourier_coefficients;
}
void Segment::set_fourier_coefficients(complex* coefficients){
    fourier_coefficients = coefficients;
}

//This function finds the index where the magnitude of the fourier coefficient is maximum
void Segment::find_max_power_index(){
    int max_power = 0; //holds the max power index
    float magnitude; //holds the magnitude (sqrt(Re^2 + Im^2))
    float max_magnitude; //holds max magnitude

    //go through every coefficient and find index of maximum magnitude
    for(int i = 1; i < size_of_coefficients; i++){
        max_magnitude = sqrt(pow(fourier_coefficients[max_power].Re, 2.0) + 
            pow(fourier_coefficients[max_power].Im, 2.0));

        magnitude = sqrt(pow(fourier_coefficients[i].Re, 2.0) + pow(fourier_coefficients[i].Im, 2.0));
        
        //If magnitude is bigger than the max, update max index
        if(magnitude > max_magnitude){
            max_power = i;
        }
    }
    max_power_index = max_power;
}

//This function does fft on the input array data
// Parameters:
// data - a complex array of the song data (will be overwritten with fft values)
// length - the length of the data array
// fft -  an empty complex array to be used temporarily
void Segment::do_fft(complex *data, int length, complex *fft){
    if (length > 1){

        complex z, w, *odd_index, *even_index;
        even_index = fft;
        odd_index = fft + length / 2;

        for (int i = 0; i < length/2; i++){
            even_index[i] = data[2 * i];
            odd_index[i] = data[2 * i + 1];
        }

        do_fft(even_index, length/2, data); //do FFT on even-indexed elements of data[]
        do_fft(odd_index, length/2, data); //do FFT on odd-indexed elements of v[]

        for (int i = 0; i < length; i++){
            w.Re = cos(2 * M_PI * i / (double)length); //get real part cos(kwt) [w = 2pi/i]
            w.Im = -sin(2 * M_PI * i / (double)length); //get imaginary part -sin(kwt)

            z.Re = w.Re * odd_index[i].Re - w.Im * odd_index[i].Im; // Re(w*odd_index[i]) 
            z.Im = w.Re * odd_index[i].Im + w.Im * odd_index[i].Re; // Im(w*odd_index[i])

            data[i].Re = even_index[i].Re + z.Re; //store real value as 
            data[i].Im = even_index[i].Im + z.Im;
            data[i + length/2].Re = even_index[i].Re - z.Re;
            data[i + length/2].Im = even_index[i].Im - z.Im;
        }
    }
    return;
}


//This function performs fft on the song data and saves them into fourier_coefficients
void Segment::fft(){

    //Create new array for complex version of songdata
    complex *complex_data;
    complex_data = new complex[size_of_data];

    //Create temp array for fft array
    complex *temp_fft;
    temp_fft = new complex[size_of_data];

    //Convert song data to complex numbers
    for (int i = 0; i < size_of_data; i++){
        complex_data[i].Re = data[i]; //convert data to double and set as real part
        complex_data[i].Im = 0; //the imaginary part is 0 as song_data contains real numbers
    }

    do_fft(complex_data, size_of_data, temp_fft); //overwrites complex_data with fft

    fourier_coefficients = complex_data; //set fourier coefficients
}

