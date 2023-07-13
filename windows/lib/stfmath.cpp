#include <math.h>

float spinSpeed(){
    spinINC++;
    if(spinINC > frameRate){
        if(gunrot > 100){
            return 100/100;
        }
        else if(gunrot > 400){
            return 400/100;
        }
        else if(gunrot > 800){
            return 800/100;
        }
        else if(gunrot > 1200){
            return 1200/100;
        }
        else if(gunrot > 1600){
            return 1600/100;
        }
        else if(gunrot > 2000){
            return 2000/100;
        }
        else{
            return 0;
        }
    }
    else{return 0;}

}