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


void focal_sim_digitizer::main_digitizer_2(vector<float> energy){

    //start of the mesurement 
    for(int i=0; i<energy.size();i++){
        int myadc = GetADC(energy[i]);
        
        int toa_value = 0;
        int tot_value_ = 0;
        if(myadc<=Pedestal) continue; // no measurement below pedestal
        bool found_toa = false;
        bool found_tot_1 = false; // event when tot threshold is crossed
        bool found_tot_2 = false; //event when tot threhold  crossed back again
        if(myadc>=toa_thresh){
            if(!found_toa) toa_value = i*time_interval; //saving the TOA time only if TOA had not been found before
            found_toa = true;
            if(!found_tot_1 || !found_tot_2) tot_value_ = i*time_interval;
            //now two condition of output if belwo TOT threshold then prints ADC(BX) ADC(BX-1) and TOA(BX)
            if(myadc<tot_thresh){
               std::cout<< "ADC(BX)      " << "ADC(BX-1)       " << "TOA     "<< std::endl;
               bitset<8> myfirst_data = dec_to_binary_converter(myadc);
                bitset <8> toa_bit =  dec_to_binary_converter(toa_value); 
                
                
               if(i==0) std::cout<< myfirst_data<<"    "   << myfirst_data << toa_bit <<"    " <<  std::endl;
               else{
                   bitset<8> myfirst_data_ = dec_to_binary_converter(GetADC(energy[i-1])); 
                   std::cout<< myfirst_data<<"    "  << myfirst_data_  <<"    " <<  toa_bit << std::endl;
                   } //i !=0  
            
            }// myadc< tot_thresh
            
            
            else{
                found_tot_1 = true;
                
                if(found_tot_1){
                    if(myadc<=tot_thresh) found_tot_2 = true; 
                    
                    }// after crossed the tot threshhold
                int tot_value = tot_value_ - toa_value;
                std::cout<< "ADC(BX-1)     " << "TOT(BX)     " << "TOA(BX)    "<< std::endl;
                
                 bitset<8> tot_bit = dec_to_binary_converter(tot_value);
                 bitset<8> myfirst_data_ = dec_to_binary_converter(GetADC(energy[i-1]));
                 bitset <8> toa_bit =  dec_to_binary_converter(toa_value);
                std::cout<< tot_bit<<"    " << myfirst_data_<<"    " << toa_bit << std::endl;
            
            }//myadc>=tot_thresh
            
        
        
        }//myadc>toa 
        
        
        
    
    
    }//measurement
    
    
    
    
    
    


}//end main_digitizer 2