#ifndef  FOCAL_SIM_DIGITIZER_H_
#define  FOCAL_SIM_DIGITIZER_H_

#include <iostream>
#include <bitset>

class focal_sim_digitizer {
	private:
		float EnergytoADC = 1.0; //factor that converts energy to ADC value 
        int Pedestal = 0; //pedestal value
        int toa_thresh = 0; // toa threshold give a time of arrival(TOA) if ADC rise  above this
        int tot_thresh = 0; // tot threshold give time over threshold (TOT) if ADC falls below this
        bool hasTOA = 0; // this is to make sure that we get tot only when toa is already true
        bitset<8> dec_to_binary_converter(int value){ 
		if( value <0 ||value > 255) {  cout << "Invalid input number should be 0 to 255" << endl;}
		bitset <8> binary(value); 
		return  binary;	
		} //converts decimal to binary output  8 bit 
		bitset<10> ten_to_eight(bitset<8>); //10 bit to 8 bit converter
		
	public: 
		
		void Set_tot_thresh(int value ) {tot_thresh = value;} //setter for tot threshold
		void Set_toa_thresh(int value){toa_thresh = value;} //setter for toa threshold 
		void Set_pedestal(int value){Pedestal = value;}  //setter for pedestal value
		void Set_EnergytoADC(float value){ EnergytoADC = value;} // set energy to ADC value conversion constant 
		void main_digitizer(float energy, int channel ); // this outputs whole output with TOT ADC and value for 
       

		

};// end of class focal_digitizer



#endif  //FOCAL_SIM_DIGITIZER_H_
