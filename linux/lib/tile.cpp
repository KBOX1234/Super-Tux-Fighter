/*
bool tileRender(const char string[], int width, int height, int startX, int startY){
    Image grassTx = LoadImage(string);
    Texture2D grass = LoadTextureFromImage(grassTx);
    UnloadImage(grassTx);
    double inx = 0;
    double iny = 0;
    double inx2 = width;
    double drawX = startX + scrollX;
    double drawY = startY + scrollY;
    if(width > 1 && height > 1){
        while(inx2 > 0){
            while(iny <= height + 64 * height){
                DrawTexture(grass, drawX + inx, drawY + iny, WHITE);
                iny = iny + 64;

            }
            iny = 0;
            inx = inx + 64;
            inx2--;
        }
    }
    else{
        DrawTexture(grass, drawX, drawY, WHITE);
    }
        if(unload == true){
            SetTargetFPS(2000);
            UnloadTexture(grass);
            SetTargetFPS(60);
        }
        short h = height*64;
        short w = width*64;
        if(px > drawX && px < w+drawX && py > drawY && py < h+drawY && px + 100 > startX && IsKeyDown(KEY_LEFT)){
            return true;
        }
        else{
            return 0;
        }
}

bool spriteRender(const char* string, int width, int height, int startX, int startY){
    Image grassTx = LoadImage(string);
    Texture2D grass = LoadTextureFromImage(grassTx);
    UnloadImage(grassTx);
    int inx = 0;
    int iny = 0;
    int inx2 = width;
    int drawX = startX;
    int drawY = startY;
    DrawTexture(grass, drawX + inx, drawY + iny, WHITE);
    if(unload == true){
        SetTargetFPS(2000);
        UnloadTexture(grass);
        SetTargetFPS(60);
    }
    return false;
}*/

void autoScroll(){
        if(px > 1280/2 + 200 && IsKeyDown(KEY_D)){
            px = 1280/2 +200;
            scrollX = scrollX - playerSpeed;
        }
        if(px < 1280/2 - 200 && IsKeyDown(KEY_A)){
            px = 1280/2 - 200;
            scrollX = scrollX + playerSpeed;
        }
        if(py > 720/2 + 100 && IsKeyDown(KEY_S)){
            py = 720/2 + 100;
            scrollY = scrollY - playerSpeed;
        }
        if(py < 720/2 - 100 && IsKeyDown(KEY_W)){
            py = 720/2 - 100;
            scrollY = scrollY + playerSpeed;
        }
}