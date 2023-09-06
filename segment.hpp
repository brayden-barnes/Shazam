#ifndef segment_HPP
#define segment_HPP

typedef float real;
typedef struct {real Re; real Im; } complex;

class Segment{
private:
    int max_power_index;
    int size_of_coefficients;
    int size_of_data;
    int* data;
    complex* fourier_coefficients;

public:
    Segment();
    Segment(int* data, int size);
    ~Segment();
    int get_max_power_index();
    void set_max_power_index(int index);
    int* get_data();
    void set_data(int* data);

    complex* get_fourier_coefficients();
    void set_fourier_coefficients(complex* coefficients);
    void find_max_power_index();
    void fft();
    void do_fft(complex*, int, complex*);


};


#endif