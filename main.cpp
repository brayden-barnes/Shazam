
#include "wave.cpp"
#include <iostream>
#include <string>

using namespace std;


int main(){
    Wave Mywave;
    Mywave.ReadWave("f3.wav");
    Mywave.ChangeSpeed(0.5);
    Mywave.WriteWave("f3slow.wav");

    Wave Otherwave;
    Otherwave.ReadWave("f4.wav");
    Otherwave.StereoToMono();
    Otherwave.WriteWave("f4mono.wav");

    return 0;
}