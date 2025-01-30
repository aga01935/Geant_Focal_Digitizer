#include "../include/focal_sim_digitizer.h"

void run_test(){
gSystem->Load("../src/focal_sim_digitizer.cxx") ; //compiling the src
    
float energy =  10.5;
focal_sim_digitizer digitizer;

digitizer.main_digitizer(energy,1);

}


// not working 
