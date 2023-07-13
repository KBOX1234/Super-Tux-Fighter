void settings(){
    if(IsKeyPressed(KEY_TAB)){
        EnableCursor();
        int returnCode = system("./settings");
        //std::cout << std::to_string(returnCode) + "\n";
        DisableCursor();
        if(returnCode == 1){
            exit(0);
        }
        if(returnCode == 2){
            screenShot();
        }
        if(returnCode == 3){
            printf("jj\n");
            hideCrosshare = false;
        }
        if(returnCode == 4){
            //PauseMusicStream(music);
            std::cout << "nut\n";
        }
    }
}