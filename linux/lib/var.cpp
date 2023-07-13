long scrollX = 0;
long scrollY = 0;
long money;
long tile[128*128];
long pointer = 0;
long animationTimer;

int px = 1280/2;
int py = 720/2 -50;
int pointerX = 0;
int pointerY = 0;
int mapWidth = 128;
int playerSpeed = 8;
int trigger1X = 6212;
int trigger1Y = 7160;
int trigger12X = 6748;
int trigger12Y = 7808;
unsigned int cx;
unsigned int cy;
int frameRate = 60;
int truePx = px;
int truePy = py;
int resraws;
int DamageDeal;
int numberOfEntities;
int entitiyRes;
int EntityManagerAPI[7];

short screenWidth = 1280;
short screenHeight = 720;
short HungerTimer = 120;
short entityRender[2555];
short entityCounter;
short EntityInc = 1;

char health = 100;
unsigned char hunger = 10;
char playerObj;
char prot = 0;
char pxAdjust;
char pyAdjust;
char playerItems[3] = {3, 100, 10};
char spinINC = 0;
char tileLevel[] = "tileMaps/experiment_level1.tl";
int APIBuff[6];
char EntityHealth[2555];
int cinc = 0;

bool unload = false;
bool Food[3];
bool Foodinclude[3];
bool loadCheack = false;
bool scalePlus = false;
bool hideCrosshare = true;
bool spinCheck = true;
bool APIRun = false;
bool swing = false;
//bool foodrender[foodcount + 1] = {true, true, true, true};

float crotate = 2;
float czoom = 2;
float anspeed = 0.5;
float crosshareRotate = 0;
float crosshareScale = 3;
float crosshareOffset = 24;
float heartScale = 2;
float heartRotate = 0;
float gunrot = 90;
float spin;

#define dred CLITERAL(Color){100, 0, 0, 255}
#define BLRUE CLITERAL(Color){0, 200, 200, 255}
#define dark CLITERAL(Color){100, 100, 200, 255}
#define dyewllow CLITERAL(Color){0, 200, 200, 255}

const char mineS = 0;
const char bullitsS = 1;
const char granadesS = 2;

//const int foodcount = 3;

//Vector2 foodCords[foodcount + 1] = {{100, 100},{400, 400}, {100, 600},{400, 1400}};
Vector2 pxy = {px + pxAdjust, py + pyAdjust};
Vector2 entityCoords[2555];



void RenderStats();
void debug();
void crosshareAnimate();
void crosshareED();
void screenShot();
void animationTimerRun();
void statCheack();
void settings();
void Items();
void combat();
void input();
void EntityManagerAndHandler();
//int entityRenderer();
bool Entity(char type);
