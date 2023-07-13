void triggerDamageCheck(){
    int inc20 = 2555;
    while(inc20 >= 0){
        if(/*IsKeyPressed(KEY_RIGHT_SHIFT) || IsKeyPressed(KEY_LEFT_SHIFT) && */px - 80 > entityCoords[inc20].x && px - 80 < entityCoords[inc20].x + 256 && py - 80 > entityCoords[inc20].y && py - 80 < entityCoords[inc20].y + 256){
            /*EntityHealth[inc20] = EntityHealth[inc20] - 10;
            cinc++;
            std::cout << "colide" + std::to_string(cinc) + "\n";*/
            health = -1;
        }
        inc20--;
    }
    
}