#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <bitset>
#include <string>

#include "raylib.h"
#include "lib/API_keys"
#include "lib/var.cpp"
#include "lib/extra.cpp"
#include "lib/tile.cpp"
#include "lib/food simulator.cpp"
#include "lib/stfmath.cpp"
#include "lib/animation.cpp"
#include "lib/pvp.cpp"
#include "lib/performance.cpp"

void loadAndRenderTileMap(char* map);

int main(void)
{
    int inc = 0;
    InitWindow(screenWidth, screenHeight, "Onsipino Games");
    InitAudioDevice();

    Music music = LoadMusicStream("music/main.wav");

    PlayMusicStream(music);

    float timePlayed = 0.0f;
    bool pause = false; 

    //splash screen
    Image logoTx = LoadImage("gfx/logo.png");
    Texture2D logo = LoadTextureFromImage(logoTx); 
    UnloadImage(logoTx); 


    SetTargetFPS(frameRate);
    BeginDrawing();
    DrawTexture(logo, screenWidth/2 - logo.width/2, screenHeight/2 - logo.height/2, WHITE);
    EndDrawing();
    sleep(3);
    CloseWindow();
    screenWidth = 1280;
    screenHeight = 720;
    InitWindow(screenWidth, screenHeight, "Super Tux Shooter");

    Image playerTx = LoadImage("gfx/player.png");
    Texture2D player = LoadTextureFromImage(playerTx);
    UnloadImage(playerTx);

    Image creepTx = LoadImage("gfx/creepy.png");
    Texture2D creep = LoadTextureFromImage(creepTx);
    UnloadImage(creepTx);
        
    Image grassTx = LoadImage("gfx/grass.png");
    Texture2D grass = LoadTextureFromImage(grassTx); 
    UnloadImage(grassTx); 

    Image w2Tx = LoadImage("gfx/leaves.png");
    Texture2D w2 = LoadTextureFromImage(w2Tx); 
    UnloadImage(w2Tx); 

    Image stoneTx = LoadImage("gfx/stone.png");
    Texture2D stone = LoadTextureFromImage(stoneTx); 
    UnloadImage(stoneTx); 

    Image steakTx = LoadImage("gfx/steak.png");
    Texture2D steak = LoadTextureFromImage(steakTx); 
    UnloadImage(steakTx); 

    Image t1Tx = LoadImage("gfx/tile1.png");
    Texture2D t1 = LoadTextureFromImage(t1Tx); 
    UnloadImage(t1Tx); 

    Image t2Tx = LoadImage("gfx/brick.png");
    Texture2D t2 = LoadTextureFromImage(t2Tx); 
    UnloadImage(t2Tx); 

    Image t3Tx = LoadImage("gfx/wood1.png");
    Texture2D t3 = LoadTextureFromImage(t3Tx); 
    UnloadImage(t3Tx); 

    Image t4Tx = LoadImage("gfx/window.png");
    Texture2D t4 = LoadTextureFromImage(t4Tx); 
    UnloadImage(t4Tx); 

    Image bgTx = LoadImage("gfx/bg.png");
    Texture2D BG = LoadTextureFromImage(bgTx); 
    UnloadImage(bgTx); 

    Image chTx = LoadImage("gfx/crosshare.png");
    Texture2D crosshare = LoadTextureFromImage(chTx); 
    UnloadImage(chTx);

    Image hTx = LoadImage("gfx/heart.png");
    Texture2D heart = LoadTextureFromImage(hTx); 
    UnloadImage(hTx);

    Image guTx = LoadImage("gfx/sword.png");
    Texture2D gun = LoadTextureFromImage(guTx); 
    UnloadImage(guTx);

    Image buTx = LoadImage("gfx/bullit.png");
    Texture2D bullit = LoadTextureFromImage(buTx); 
    UnloadImage(buTx);

    Image mTx = LoadImage("gfx/mine.png");
    Texture2D mine = LoadTextureFromImage(mTx); 
    UnloadImage(mTx);

    Image grTx = LoadImage("gfx/granaid.png");
    Texture2D granaid = LoadTextureFromImage(grTx); 
    UnloadImage(grTx);

    Image e1Tx = LoadImage("gfx/explosion/1.png");
    Texture2D e1 = LoadTextureFromImage(e1Tx); 
    UnloadImage(e1Tx);

    Image e2Tx = LoadImage("gfx/explosion/2.png");
    Texture2D e2 = LoadTextureFromImage(e2Tx); 
    UnloadImage(e2Tx);

    Image e3Tx = LoadImage("gfx/explosion/3.png");
    Texture2D e3 = LoadTextureFromImage(e3Tx); 
    UnloadImage(e3Tx);

    Image e4Tx = LoadImage("gfx/explosion/4.png");
    Texture2D e4 = LoadTextureFromImage(e4Tx); 
    UnloadImage(e4Tx);

    Image wood2Tx = LoadImage("gfx/wood2.png");
    Texture2D wood2 = LoadTextureFromImage(wood2Tx); 
    UnloadImage(wood2Tx); 

    Image sandTx = LoadImage("gfx/sand.png");
    Texture2D sand = LoadTextureFromImage(sandTx); 
    UnloadImage(sandTx); 

    Image waterTx = LoadImage("gfx/water.png");
    Texture2D water = LoadTextureFromImage(waterTx); 
    UnloadImage(waterTx); 

    //Font font = LoadFontEx("fonts/Smokum-Regular.ttf", 96, 0, 0);

    DisableCursor();

    scrollX = -500;
    scrollY = -500;

    Vector2 creepXY = {cx+scrollX, cy+scrollY};

    while (!WindowShouldClose()){
        UpdateMusicStream(music);
        BeginDrawing();
        DrawTextureEx(BG, {0, 0}, 0, 2, dark);
        loadAndRenderTileMap("tileMaps/layer1.tl");

        while(inc <= mapWidth*mapWidth){
            if(tile[inc] != 0){
                if(tile[inc] == 1){
                    
                    DrawTextureEx(grass, {float(pointerX*64 + scrollX), float(pointerY*64 + scrollY)}, 0, 4, dark);
                }
                if(tile[inc] == 2){
                    DrawTextureEx(stone, {float(pointerX*64 + scrollX), float(pointerY*64 + scrollY)}, 0, 4, dark);
                    
                }
                if(tile[inc] == 3){
                    DrawTexture(steak, pointerX*64+scrollX, pointerY*64 + scrollY, dark);
                    
                }
                if(tile[inc] == 4){
                    DrawTextureEx(t1, {float(pointerX*64 + scrollX), float(pointerY*64 + scrollY)}, 0, 4, dark);
                    
                }
                if(tile[inc] == 5){
                    DrawTextureEx(t2, {float(pointerX*64 + scrollX), float(pointerY*64 + scrollY)}, 0, 4, dark);
                    
                }
                if(tile[inc] == 6){
                    DrawTextureEx(t3, {float(pointerX*64 + scrollX), float(pointerY*64 + scrollY)}, 0, 4, dark);
                    
                }
                if(tile[inc] == 7){
                    DrawTextureEx(t4, {float(pointerX*64 + scrollX), float(pointerY*64 + scrollY)}, 0, 4, dark);

                }
                if(tile[inc] == 8){
                    DrawTextureEx(w2, {float(pointerX*64 + scrollX), float(pointerY*64 + scrollY)}, 0, 4, dark);
                    
                }
                if(tile[inc] == 9){
                    DrawTextureEx(wood2, {float(pointerX*64 + scrollX), float(pointerY*64 + scrollY)}, 0, 4, dark);
                    
                }
                if(tile[inc] == 10){
                    DrawTextureEx(sand, {float(pointerX*64 + scrollX), float(pointerY*64 + scrollY)}, 0, 4, dark);
                    
                }
                if(tile[inc] == 11){
                    DrawTextureEx(water, {float(pointerX*64 + scrollX), float(pointerY*64 + scrollY)}, 0, 4, dark);
                    
                }

            }
            if(pointerX > mapWidth-2){
                pointerX = 0;
                pointerY++;
            }
            else{
                pointerX++;
            }

            inc++;
            
        }
        inc = 0;
        pointerX = 0;
        pointerY = 0;

        int nutinc = 2555;
        while(nutinc >= 0){
            if(entityRender[nutinc] == 0) nutinc--;
            else{
                if(entityRender[nutinc] == mob){
                    //DrawTexture(creep, {entityCoords[nutinc].x + scrollX, entityCoords[nutinc].y + scrollY}, 0, 2, dark);
                    DrawTextureEx(creep, {float(entityCoords[nutinc].x + scrollX), float(entityCoords[nutinc].y + scrollY)}, 0, 2, dark);
                }
                nutinc--;
            }
        }

        if(hideCrosshare == false){
            DrawLineV({px + 16, py + 32}, GetMousePosition(), WHITE);
            DrawLineV({px + 17, py + 33}, GetMousePosition(), WHITE);
            DrawLineV({px + 18, py + 34}, GetMousePosition(), WHITE);
            DrawLineV({px + 19, py + 35}, GetMousePosition(), WHITE);
        }
        DrawTextureEx(gun, {px + 16, py + 16}, gunrot + prot, 4, dark);
        playerAnim(player);
        if(hideCrosshare == false){
            DrawTextureEx(crosshare, {GetMousePosition().x - crosshareOffset, GetMousePosition().y - crosshareOffset}, crosshareRotate, crosshareScale, WHITE);
        }

        loadAndRenderTileMap("tileMaps/layer2.tl");

        while(inc <= mapWidth*mapWidth){
            if(tile[inc] != 0){
                if(tile[inc] == 1){
                    
                    DrawTextureEx(grass, {float(pointerX*64 + scrollX), float(pointerY*64 + scrollY)}, 0, 4, dark);
                }
                if(tile[inc] == 2){
                    DrawTextureEx(stone, {float(pointerX*64 + scrollX), float(pointerY*64 + scrollY)}, 0, 4, dark);
                    
                }
                if(tile[inc] == 3){
                    DrawTexture(steak, pointerX*64+scrollX, pointerY*64 + scrollY, dark);
                    
                }
                if(tile[inc] == 4){
                    DrawTextureEx(t1, {float(pointerX*64 + scrollX), float(pointerY*64 + scrollY)}, 0, 4, dark);
                    
                }
                if(tile[inc] == 5){
                    DrawTextureEx(t2, {float(pointerX*64 + scrollX), float(pointerY*64 + scrollY)}, 0, 4, dark);
                    
                }
                if(tile[inc] == 6){
                    DrawTextureEx(t3, {float(pointerX*64 + scrollX), float(pointerY*64 + scrollY)}, 0, 4, dark);
                    
                }
                if(tile[inc] == 7){
                    DrawTextureEx(t4, {float(pointerX*64 + scrollX), float(pointerY*64 + scrollY)}, 0, 4, dark);

                }
                if(tile[inc] == 8){
                    DrawTextureEx(w2, {float(pointerX*64 + scrollX), float(pointerY*64 + scrollY)}, 0, 4, dark);
                    
                }
                if(tile[inc] == 9){
                    DrawTextureEx(wood2, {float(pointerX*64 + scrollX), float(pointerY*64 + scrollY)}, 0, 4, dark);
                    
                }
                if(tile[inc] == 10){
                    DrawTextureEx(sand, {float(pointerX*64 + scrollX), float(pointerY*64 + scrollY)}, 0, 4, dark);
                    
                }
                if(tile[inc] == 11){
                    DrawTextureEx(water, {float(pointerX*64 + scrollX), float(pointerY*64 + scrollY)}, 0, 4, dark);
                    
                }

            }
            if(pointerX > mapWidth-2){
                pointerX = 0;
                pointerY++;
            }
            else{
                pointerX++;
            }

            inc++;
            
        }
        
        inc = 0;
        pointerX = 0;
        pointerY = 0;
        pxy = {px + pxAdjust, py + pyAdjust};

        //DrawRectangle(px, py, 32, 32, dark);
        if(health > 0) DrawTextureEx(heart, {10, 10}, heartRotate, heartScale, WHITE);
        if(health > 20) DrawTextureEx(heart, {20 + 32, 10}, heartRotate, heartScale, WHITE);
        if(health > 40) DrawTextureEx(heart, {30 + 64, 10}, heartRotate, heartScale, WHITE);
        if(health > 60) DrawTextureEx(heart, {40 + 64 + 32, 10}, heartRotate, heartScale, WHITE);
        if(health > 80) DrawTextureEx(heart, {50 + 64 + 60 , 10}, heartRotate, heartScale, WHITE);
        /*if(gunrot > 2000 || gunrot < -2000){ 
            explosion(e1, e2, e3, e4, pxy, 2);
            if(resraws > 180){ SetMousePosition(pxy.x, pxy.y); resraws = 0;}
            resraws++;
        }*/
        if(IsKeyPressed(KEY_K)){
            EntityManagerAPI[addEntity] = 1;
            EntityManagerAPI[EntityID] = EntityInc;
            EntityManagerAPI[spawnCX] = rand() %1000;
            EntityManagerAPI[spawnCY] = rand() %600;
            EntityManagerAPI[EntityType] = mob;
            EntityManagerAPI[triggerAPIread] = 22;
            EntityInc++;
            std::cout << std::to_string(entityCounter) + "\n";
            //entityRender[1] = mob;
        }
        scheduler();
        //std::cout << std::to_string(entityManager()) + "\n";
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
