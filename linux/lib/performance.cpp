void scheduler(){
        autoScroll();
        RenderStats();
        crosshareAnimate();
        animationTimerRun();
        statCheack();
        heartAnim();
        settings();
        debug();
        input();
        EntityManagerAndHandler();
        persistance();
        //if(colideBox({px+scrollX, py+scrollY}, {1+scrollX, 1+scrollY}, 256, 256) == 1) std::cout << "true\n";
        //if(colideBox({px+scrollX, py+scrollY}, {1+scrollX, 1+scrollY}, 256, 256) == 0) std::cout << "false\n";
        //DrawRectangle(100 + scrollX, 100 + scrollY, 256, 256, RED);
}

void RenderStats(){
        std::string scoreSTR = "health: " + std::to_string(health);
        
        std::string name = scoreSTR;
        char *c_string;

        c_string = new char[name.length()];

        for (int index = 0; index < name.length(); index++){
            c_string[index] = name[index];
        }
        c_string[name.length()] = '\0';
        DrawText(c_string, 10, 60, 20, RED);
}

void debug(){
    if(IsKeyPressed(KEY_F1)){
        health = health + 10;
    }
    if(IsKeyPressed(KEY_F2)){
        health = health - 10;
    }

    std::string scoreSTR = "player X " + std::to_string(px-scrollX) + ", player Y " + std::to_string(py-scrollY) + "\n creep X";
    
    std::string name = scoreSTR;
    char *c_string;

    c_string = new char[name.length()];

    for (int index = 0; index < name.length(); index++){
        c_string[index] = name[index];
    }
    c_string[name.length()] = '\0';
    DrawText(c_string, 10, 100, 20, RED);

}

void crosshareAnimate(){
    if(crosshareScale > 3.4){
        scalePlus = false;
    }
    if(crosshareScale < 2.1){
        scalePlus = true;
    }
    if(scalePlus == true){
        crosshareScale = crosshareScale + 0.05;
        crosshareOffset = crosshareOffset + 0.5;
    }
    if(scalePlus == false){
        crosshareScale = crosshareScale - 0.05;
        crosshareOffset = crosshareOffset - 0.5;
    }
}

void crosshareED(){
    if(GetMousePosition().x < 0 || GetMousePosition().x > screenWidth - 0 || GetMousePosition().y < 0 || GetMousePosition().y > screenHeight - 0){
        
        EnableCursor();
        SetMousePosition(-5, -5);
    }
    else{
        Vector2 ddd = GetMousePosition();
        DisableCursor(); 
        SetMousePosition(ddd.x, ddd.y);
    }
}

void screenShot(){
    std::cout << "Alert! Screenshot not implamented\n";
}
void statCheack(){
    if(health < 0){
        gameOver(1); 
    }
    //gunrot = GetMousePosition().x;

}

#include "../exit.h"

void loadAndRenderTileMap(char* map){

    long mapWidth = 128*128;
    std::ifstream fileo(map);

    std::string outbuffer;
    int inc = 0;

    while(inc < 128*128+1){
        getline(fileo, outbuffer);
        if(outbuffer == "#"){
            tile[inc] = 1;
        }
        if(outbuffer == "&"){
            tile[inc] = 2;
        }
        if(outbuffer == "å"){
            tile[inc] = 0;
        }
        if(outbuffer == ")"){
            tile[inc] = 3;
        }
        if(outbuffer == "("){
            tile[inc] = 4;
        }
        if(outbuffer == "%"){
            tile[inc] = 5;
        }
        if(outbuffer == "{"){
            tile[inc] = 6;
        }
        if(outbuffer == "]"){
            tile[inc] = 7;
        }
        if(outbuffer == "m"){
            tile[inc] = 8;
        }
        if(outbuffer == "}"){
            tile[inc] = 9;
        }
        if(outbuffer == "1"){
            tile[inc] = 10;
        }
        if(outbuffer == "2"){
            tile[inc] = 11;
        }
        inc++;
    }
}

void input(){
    if(IsKeyPressed(KEY_RIGHT_SHIFT) || IsKeyPressed(KEY_LEFT_SHIFT)){
        //std::cout << "hit\n";
        res18 = true;
        triggerDamageCheck();
    }

    if(IsKeyDown(KEY_D)){
        px = px + playerSpeed;
        prot = 0;
        /*pxAdjust = 0;
        pyAdjust = 0;*/
    }
    if(IsKeyDown(KEY_S)){
        prot = 0;
        py = py + playerSpeed;
        /*prot = 90;
        pxAdjust = 40;
        pyAdjust = 0;*/
    }
    if(IsKeyDown(KEY_A)){
        prot = 0;
        px = px - playerSpeed;
        /*prot = 0;
        pxAdjust = 0;
        pyAdjust = 0;*/
    }
    if(IsKeyDown(KEY_W)){
        prot = 0;
        py = py - playerSpeed;
        /*prot = 165;
        pxAdjust = 0;   
        pyAdjust = 40;*/
    }
}

void EntityManagerAndHandler(){
    if(EntityManagerAPI[triggerAPIread] > 0 && APIRun == false){
        EntityManagerAPI[triggerAPIread] = 0;
        char inc = 0;
        while(inc < 6){
            APIBuff[inc] = EntityManagerAPI[inc];
            inc++;
        }
        APIRun = true;
    }
    if(APIRun == true){
        APIRun = false;
        if(APIBuff[addEntity] > 0){
            entityRender[APIBuff[EntityID]] = APIBuff[EntityType];
            entityCoords[APIBuff[EntityID]] = {APIBuff[spawnCX], APIBuff[spawnCY]};
            EntityHealth[APIBuff[EntityID]] = 100;
            entityCounter++;
        }
        if(APIBuff[removeEntity] > 0){
            entityRender[APIBuff[EntityID]] = 0;
            entityCounter--;
        }
    }
    int inc = 0;
    while(inc <= 6){
        EntityManagerAPI[inc] = 0;
        inc++;
    }
    inc = 0;
    while(inc <= 2555){
        inc++;
        if(EntityHealth[inc] < 1){
            entityRender[inc] = 0;
            entityCounter--;
        }
    }
}