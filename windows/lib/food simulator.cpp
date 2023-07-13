void HealthCheck(){
    if(health < 1){
        
    }
}

void HungerCheck(){
    if(hunger < 1){
        if(HungerTimer > 0){
            HungerTimer--;
        }
        else{
            health--;
            HungerTimer = 120;
        }
    }
}
short inc = 2;