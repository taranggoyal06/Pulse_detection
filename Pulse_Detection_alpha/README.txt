The directory includes the following codes:
Alpha version is modular and the following modules have to be implemented in the following way
1) Face Detector + RGB Channel seperator -> compile the cmake file into  > libICA/dat/ica.example1
2) Implementation of Independent Component Analysis with jade -> chmod +x linICA/src/run.sh && ./libICA/src/run.sh > source_signal
3) Application of Fast Fourier Transform (discrete time signal -> signal in frequency domain) on "source_signal" by -> g++ fftcode.cpp > freq_dom 
4) Passing this signal through the Band Pass Filter -> g++ bandpass.cpp 

The final signals are being obtained but cannot be further processed without the correct callibration tool .
