void settings(){
    if(IsKeyPressed(KEY_TAB)){
        EnableCursor();
        int returnCode = system("./settings");
        //std::cout << std::to_string(returnCode) + "\n";
        DisableCursor();
        if(returnCode == 256){
            exit(0);
        }
        if(returnCode == 512){
            screenShot();
        }
        if(returnCode == 768){
            printf("jj\n");
            hideCrosshare = false;
        }
        if(returnCode == 1024){
            //PauseMusicStream(music);
            std::cout << "nut\n";
        }
    }
}