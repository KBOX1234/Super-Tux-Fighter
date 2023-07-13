long res = 0;
bool res2 = false;
long res3;
bool res4 = true;
long res5 = 0;
float res7 = 0;
bool res6 = false;
float res8;
float res9;
bool res10 = false;
float res11;
float res12;
float res13;
float res14;
float res15;
int res16;
bool res17;
bool res18;
void gameOver(long offset){
    if(res2 == false){
        res = 0;
        res2 = true;
        res3 = -650;
    }
    if(res < 3 * GetFPS() * 2.5){
        res3 = res3 + 6;
    }
    res++;
    DrawRectangle(0, 0, 1280, 720, BLACK);
    DrawText("Game Over", res3, 500, 120, RED);
    if(res > 3.7 * GetFPS() * 2.5){
        health = 100;
        res2 = false;
    }
}
void playerAnim(Texture2D p){
    DrawTextureEx(p, pxy, prot, 2, dark);
}

void heartAnim(){
    if(res4 == true){
        heartScale = heartScale + 0.01;
        heartRotate = heartRotate + 2.5;
    }
    if(res4 == false){
        heartScale = heartScale - 0.01;
        heartRotate = heartRotate - 2.5;
    }
    if(heartRotate >= 10 || heartScale >= 4.5) res4 = false;
    if(heartRotate <= 0 || heartScale <= 2) res4 = true;
}

void explosion(Texture2D f1, Texture2D f2, Texture2D f3, Texture2D f4, Vector2 xy, float scaleOffset){
    if(res6 == false){
        res6 = true;
        res7 = scaleOffset;
        res5 = 0;
    }
    if(res5 > 0){
        DrawTextureEx(f1, xy, 0, res7, WHITE);
    }
    if(res5 > 60*0.05){
        DrawTextureEx(f2, xy, 0, res7, WHITE);
    }
    if(res5 > 60*0.1){
        DrawTextureEx(f3, xy, 0, res7, WHITE);
    }
    if(res5 > 60*0.15){
        DrawTextureEx(f4, xy, 0, res7, WHITE);
        res6 = false;
    }
    if(res5 < 60*0.2){
        res5++;
        res7 = res7 + 0.;
    }
    else{
        res6 = false;
    }
}

/*void shoot(){
    if(res10 == false){
        res10 == true;
        res8 = 100;
        res9 = 100/res15;
        res14 = GetMouseX();
        res15 = GetMouseY();
        res12 = 0;
        res9 = 100/res9;
    }
    if(px < res14){
        if(py < res15){
            if(res12 < 100){
                DrawRectangle(px - res12, py + res9, 10, 10, WHITE);
            }
        }
        if(py > res15){
            if(res12 < 100){
                DrawRectangle(px + res12, py + res9, 10, 10, WHITE);
            }
        }
    }
    if(px > res14){
        if(py < res15){
            if(res12 < 100){
                DrawRectangle(px - res12, py - res9, 10, 10, WHITE);
            }
        }
        if(py > res15){
            if(res12 < 100){
                DrawRectangle(px + res12, py - res9, 10, 10, WHITE);
            }
        }
    }
    if(res12 < 180){
        res12++;
    }
    if(res12 > 180){
        res10 = true;
    }
}*/

void swordSpin(){
    if(res17 == false){
        gunrot = 0;
        res17 = true;
        res16 = 0;
        res18 = false;
    }
    if(res16 < 20){
        gunrot = gunrot + 22;
    }
    res16++;
    if(res16 > 20){
        res17 = false;
    }
}

void animationTimerRun(){
    if(animationTimer > pow(2, 60)) animationTimer = 0;
    animationTimer++;
}
void persistance(){
    if(res18 == true) swordSpin();
}