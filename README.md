# Super-Tux-Fighter

## DO NOT LEAK >:(

### building on linux
g++ main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o STF -Wwrite-strings -Wnarrowing -std=c++17
g++ -o settings settings.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

### building on windows
g++ -o settings.exe settings.cpp -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lstdc++fs -static -std=c++17
g++ main.cpp -o stf.exe -std=c++17 -lraylib -lopengl32 -lgdi32 -lwinmm
