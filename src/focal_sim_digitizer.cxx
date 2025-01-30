#include <iostream>
#include "../include/focal_sim_digitizer.h"



//to do add construtor and distructor 

void focal_sim_digitizer::main_digitizer(float energy, int channel){

	int ADC_value;

	float ADC_crude = energy/EnergytoADC;
	ADC_value = int(ADC_crude);
	

	bitset<8> myfirst_data = dec_to_binary_converter(ADC_value);

	std::cout<< "just checking if " << myfirst_data << std::endl;	





}//end main_digitzer
