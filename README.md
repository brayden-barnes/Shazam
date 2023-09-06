# Shazam
This project was written to fulfill an assignment for Dalhousie's Systems Analysis course to develop an intricate object oriented program.

The idea of this assignment is to recreate the Shazam app for .wav files. First, .wav files are added to a database. Then, by calculating the FFT of each file and cross correlating them to an input "mystery" file, the mystery file is identified by comparing its FFT to those in the database. See Wav_Spec.pdf for more details on the .wav format and how the important data was extracted.
