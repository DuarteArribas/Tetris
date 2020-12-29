/*
  ----------- Standard Libraries -----------
*/
//streams, strings and files
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cctype>
//time and threading libraries
#include <chrono>
#include <thread>
#include <time.h>
//math
#define _USE_MATH_DEFINES
#include <math.h>
//vector
#include<vector>
//namespaces
using namespace std::chrono;
using namespace std;

/*
  ----------- OpenGL Libraries -----------
*/
//gl libraries
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtx/transform.hpp>
#include <gtc/type_ptr.hpp>
//irrklang (sound)
#include<irrKlang/include/irrKlang.h>
//shaders
#define STB_IMAGE_IMPLEMENTATION
#include "libs/stb_image.h"
#include "libs/shader_s.h"
#include "common/shader.hpp"
#include "common/texture.hpp"
#include "common/controls.hpp"
#include "common/objloader.hpp"
#include "common/shader.cpp"
#include "common/texture.cpp"
#include "common/controls.cpp"
#include "common/objloader.cpp"
//namespaces
using namespace glm;

GLuint object3DShaders;


typedef struct {
  glm::mat4 self_rotation;
  glm::mat4 center_rotation;
  glm::mat4 translation;
  glm::mat4 scaling;
  float xPosition;
  float yPosition;
  float zPosition;
}TRANSFORMATIONS;

typedef struct{
  std::vector<glm::vec3>vertices;
  std::vector<glm::vec2>uvs;
  std::vector<glm::vec3>normals;
}OBJ_VECTORS;

typedef struct {
  GLuint VertexArrayID;
  GLuint MatrixID;
  GLuint Texture;
  GLuint TextureID;
  GLuint uvbuffer;
  GLuint vertexbuffer;
}INFO;

const char* cubeTexture="images/textures/blockTex.dds";
const char* wallsTexture="images/textures/wall.dds";
const char* menuTexture="images/textures/introMenu.dds";
const char* save1Texture="images/textures/saveMenu1.dds";
const char* save2Texture="images/textures/saveMenu2.dds";
const char* save3Texture="images/textures/saveMenu3.dds";
const char* save4Texture="images/textures/saveMenu4.dds";
const char* save5Texture="images/textures/saveMenu5.dds";
const char* savePlayGuestTexture="images/textures/saveMenuGuest.dds";
const char* menuPlayTexture="images/textures/menu/menuPlay.dds";
const char* menuProfileTexture="images/textures/menu/menuProfile.dds";
const char* menuSkinsTexture="images/textures/menu/menuSkins.dds";
const char* menuSettingsTexture="images/textures/menu/menuSettings.dds";
const char* menuRickRollTexture="images/textures/menu/menuEasterEgg.dds";
const char* settingsFullscreenTexture="images/textures/settings/settingsFullscreen.dds";
const char* settingsResolutionTexture="images/textures/settings/settingsResolution.dds";
const char* settingsAudioTexture="images/textures/settings/settingsAudio.dds";
const char* audio0Texture="images/textures/settings/audio/settingsAudio0.dds";
const char* audio1Texture="images/textures/settings/audio/settingsAudio1.dds";
const char* audio2Texture="images/textures/settings/audio/settingsAudio2.dds";
const char* audio3Texture="images/textures/settings/audio/settingsAudio3.dds";
const char* audio4Texture="images/textures/settings/audio/settingsAudio4.dds";
const char* audio5Texture="images/textures/settings/audio/settingsAudio5.dds";
const char* audio6Texture="images/textures/settings/audio/settingsAudio6.dds";
const char* audio7Texture="images/textures/settings/audio/settingsAudio7.dds";
const char* audio8Texture="images/textures/settings/audio/settingsAudio8.dds";
const char* audio9Texture="images/textures/settings/audio/settingsAudio9.dds";
const char* audio10Texture="images/textures/settings/audio/settingsAudio10.dds";
const char* resolution1Texture="images/textures/settings/resolution/resolution1.dds";
const char* resolution2Texture="images/textures/settings/resolution/resolution2.dds";
const char* resolution3Texture="images/textures/settings/resolution/resolution3.dds";
const char* resolution4Texture="images/textures/settings/resolution/resolution4.dds";
const char* chooseAudioATexture="images/textures/chooseAudio/chooseAudioA.dds";
const char* chooseAudioBTexture="images/textures/chooseAudio/chooseAudioB.dds";
const char* pauseGameTexture="images/textures/pause/pauseGame.dds";
const char* pauseMenuTexture="images/textures/pause/pauseMenu.dds";
const char* nextTexture="images/textures/text.dds";
const char* holdTexture="images/textures/text.dds";
const char* scoreTexture="images/textures/text.dds";
const char* lvlTexture="images/textures/text.dds";
const char* numberTexture="images/textures/text.dds";
const char* highscoreTexture="images/textures/text.dds";
const char* skyTexture="images/textures/sky.dds";
const char* floorTexture="images/textures/floor.dds";
const char* gameOverBackTexture="images/textures/gameOver/gameOverBackToMainMenu.dds";
const char* gameOverPlayTexture="images/textures/gameOver/gameOverPlayAgain.dds";
const char* cubeObj="objects/cube.obj";
const char* menuObj="objects/introMenu.obj";
const char* nextObj="objects/next.obj";
const char* holdObj="objects/hold.obj";
const char* scoreObj="objects/score.obj";
const char* lvlObj="objects/level.obj";
const char* skyObj="objects/sky.obj";
const char* floorObj="objects/floor.obj";
const char* zeroObj="objects/numbers/zero.obj";
const char* oneObj="objects/numbers/one.obj";
const char* twoObj="objects/numbers/two.obj";
const char* threeObj="objects/numbers/three.obj";
const char* fourObj="objects/numbers/four.obj";
const char* fiveObj="objects/numbers/five.obj";
const char* sixObj="objects/numbers/six.obj";
const char* sevenObj="objects/numbers/seven.obj";
const char* eightObj="objects/numbers/eight.obj";
const char* nineObj="objects/numbers/nine.obj";
const char* highscoreObj="objects/highscore.obj";
OBJ_VECTORS cubeObject;
OBJ_VECTORS menuObject;
OBJ_VECTORS nextObject;
OBJ_VECTORS holdObject;
OBJ_VECTORS scoreObject;
OBJ_VECTORS lvlObject;
OBJ_VECTORS skyObject;
OBJ_VECTORS floorObject;
OBJ_VECTORS zeroObject;
OBJ_VECTORS oneObject;
OBJ_VECTORS twoObject;
OBJ_VECTORS threeObject;
OBJ_VECTORS fourObject;
OBJ_VECTORS fiveObject;
OBJ_VECTORS sixObject;
OBJ_VECTORS sevenObject;
OBJ_VECTORS eightObject;
OBJ_VECTORS nineObject;
OBJ_VECTORS highscoreObject;
INFO cubeInfo;
INFO wallInfo;
INFO menuInfo;
INFO save1Info;
INFO save2Info;
INFO save3Info;
INFO save4Info;
INFO save5Info;
INFO savePlayGuestInfo;
INFO menuPlayInfo;
INFO menuProfileInfo;
INFO menuSkinsInfo;
INFO menuSettingsInfo;
INFO menuRickRollInfo;
INFO settingsFullscreenInfo;
INFO settingsResolutionInfo;
INFO settingsAudioInfo;
INFO audio0Info;
INFO audio1Info;
INFO audio2Info;
INFO audio3Info;
INFO audio4Info;
INFO audio5Info;
INFO audio6Info;
INFO audio7Info;
INFO audio8Info;
INFO audio9Info;
INFO audio10Info;
INFO resolution1Info;
INFO resolution2Info;
INFO resolution3Info;
INFO resolution4Info;
INFO chooseAudioAInfo;
INFO chooseAudioBInfo;
INFO pauseGameInfo;
INFO pauseMenuInfo;
INFO nextInfo;
INFO holdInfo;
INFO scoreInfo;
INFO lvlInfo;
INFO skyInfo;
INFO floorInfo;
INFO zeroInfo;
INFO oneInfo;
INFO twoInfo;
INFO threeInfo;
INFO fourInfo;
INFO fiveInfo;
INFO sixInfo;
INFO sevenInfo;
INFO eightInfo;
INFO nineInfo;
INFO gameOverBackInfo;
INFO gameOverPlayInfo;
INFO highscoreInfo;
TRANSFORMATIONS t;
TRANSFORMATIONS t2;
TRANSFORMATIONS t3;
TRANSFORMATIONS t4;
TRANSFORMATIONS t5;
TRANSFORMATIONS t6;
TRANSFORMATIONS t7;
TRANSFORMATIONS t8;
TRANSFORMATIONS t9;
TRANSFORMATIONS t10;

/*
  ----------- Project Libraries -----------
*/
//enums
#include"src/support/enums.cpp"
//structure
#include"src/init.cpp"
#include"src/vertexTransfer.cpp"
#include"src/sceneObjects.cpp"
#include"src/drawObjects.cpp"
//scenes
#include"src/scenes/introMenu.cpp"
#include"src/scenes/menu.cpp"
#include"src/scenes/subMenu.cpp"
//game
#include"src/game/tetrominoes.cpp"
#include"src/game/player.cpp"

/*
  ----------- Definitions -----------
*/
#define VERTICAL 0
#define LEFT -1
#define RIGHT 1

/*
  ----------- Function Prototypes -----------
*/
//handles keyboard operations
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
//reconstructs objects
void reConstructObjects(Vertices *cube,
  Vertices *menu,
  Vertices *save1,
  Vertices *save2,
  Vertices *save3,
  Vertices *save4,
  Vertices *save5,
  Vertices *savePlayGuest,
  Vertices *menuPlay,
  Vertices *menuProfile,
  Vertices *menuSkins,
  Vertices *menuSettings,
  Vertices *menuRickRoll,
  Vertices *settingsFullscreen,
  Vertices *settingsResolution,
  Vertices *settingsAudio,
  Vertices *audio0,
  Vertices *audio1,
  Vertices *audio2,
  Vertices *audio3,
  Vertices *audio4,
  Vertices *audio5,
  Vertices *audio6,
  Vertices *audio7,
  Vertices *audio8,
  Vertices *audio9,
  Vertices *audio10,
  Vertices *resolution1,
  Vertices *resolution2,
  Vertices *resolution3,
  Vertices *resolution4,
  Vertices *chooseAudioA,
  Vertices *chooseAudioB,
  Vertices *pauseGame,
  Vertices *pauseMenu
);
//calls the necessary methods for every loop
void startLoop();
void endLoop();
void CreateNumber(long long n, float x,float xInitial,float y, float z);

/*
  ----------- General Global Variables -----------
*/
//represents the current scene
Scene scene=Scene::INTRO;
//represents the current player
Player currentPlayer(700,700,false,0.5f);
//sound engine
ISoundEngine* engine = createIrrKlangDevice();
//window title
char windowTitle[]="Tetris";
//menu options
int optionMenu=0,optionSubMenu=0,subOptionSubMenu=0, optionMenuGameOver=0,optionMenuPause=0,optionMenuSave=0,optionMusicSelection=0;
//if this variable is true, the game will close
bool exitGame=false;
//makes sure the music and the music sped up don't stop and start everytime the loop happens
bool canPlayMusic=true,canPlayMusic2=true;
//makes sure the window is rebuilt if its size hasn't changed
bool canRebuildWindow=false;
//handles if the player is in the subSubMenu
bool isInSubSubMenu=false;
//textures
char textureIntroName[]="images/textures/introMenuBackground.jpg";
unsigned int textureIntro;
bool needsToRebuild=false;

/*
  ----------- Game Global Variables -----------
*/
//board
bool board[25][10];
//tetronimo
Tetrominoes i(TETROMINO_ID::I,board);
bool lastStep=true, hardDrop=false,isGameOver=false;
//piece
TETROMINO_ID nextPiece;
int lastPiece;
bool canGenerateNewPiece=true;
//piece hold
TETROMINO_ID pieceHold=TETROMINO_ID::NONE;
bool switchToHold=false,firstSwitch=false,canHold=true;
//score
long long score=0, latestScore=0;
int level=1;
bool backToBack=false;
int numberOfRowsDestroyed=0,numberOfTotalRowsDestroyed=0;
//saves
string save;
//music
string selectedMusic,selectedMusicSpeed;
//controls if the music that's playing is the sped up version
bool isSpeed=false;

/*
  ----------- Remaining Project Libraries -----------
*/
//file updates
#include"src/saves.cpp"
//remaining scenes
#include"src/scenes/pause.cpp"
#include"src/scenes/gameOver.cpp"
#include"src/game/board.cpp"
//key handling
#include"src/keyHandling.cpp"


int main(void){
  /*
    ----------- Initialization -----------
  */
  //load settings and create player instance
  int widthInt=0, heightInt=0;
  bool fullscreenBool=false;
  float volumeFloat=0.0f;
  loadSettings(&widthInt,&heightInt,&fullscreenBool,&volumeFloat);
  new(&currentPlayer)Player(widthInt,heightInt,fullscreenBool,volumeFloat);
  //initialize
  if(initialize(currentPlayer.getWindowWidth(),currentPlayer.getWindowHeight(),windowTitle,engine,currentPlayer.getVolume(),currentPlayer.getIsFullscreen())==-1) {
    return -1;
  }
  //start new game
  newGame();
 
  /*
    ----------- Variables -----------
  */
  //shaders
  Shader shader("shaders/vertexShader.vs", "shaders/fragmentShader.fs");
  object3DShaders=LoadShaders("shaders/tvs.vertexshader","shaders/cfs.fragmentshader");
  //vertices
  //Vertices introSquare(introSquareVertices,sizeof(introSquareVertices));
  //introSquare.generateVertices();
  //Vertices introSquareTriangle(triangleVertices,sizeof(triangleVertices));
  //introSquareTriangle.generateEBO();
  Vertices cube(&cubeInfo,&cubeObject,object3DShaders,cubeTexture,cubeObj);
  Vertices walls(&wallInfo,&cubeObject,object3DShaders,wallsTexture,cubeObj);
  Vertices menu(&menuInfo,&menuObject,object3DShaders,menuTexture,menuObj);
  Vertices save1(&save1Info,&menuObject,object3DShaders,save1Texture,menuObj);
  Vertices save2(&save2Info,&menuObject,object3DShaders,save2Texture,menuObj);
  Vertices save3(&save3Info,&menuObject,object3DShaders,save3Texture,menuObj);
  Vertices save4(&save4Info,&menuObject,object3DShaders,save4Texture,menuObj);
  Vertices save5(&save5Info,&menuObject,object3DShaders,save5Texture,menuObj);
  Vertices savePlayGuest(&savePlayGuestInfo,&menuObject,object3DShaders,savePlayGuestTexture,menuObj);
  Vertices menuPlay(&menuPlayInfo,&menuObject,object3DShaders,menuPlayTexture,menuObj);
  Vertices menuProfile(&menuProfileInfo,&menuObject,object3DShaders,menuProfileTexture,menuObj);
  Vertices menuSkins(&menuSkinsInfo,&menuObject,object3DShaders,menuSkinsTexture,menuObj);
  Vertices menuSettings(&menuSettingsInfo,&menuObject,object3DShaders,menuSettingsTexture,menuObj);
  Vertices menuRickRoll(&menuRickRollInfo,&menuObject,object3DShaders,menuRickRollTexture,menuObj);
  Vertices settingsFullscreen(&settingsFullscreenInfo,&menuObject,object3DShaders,settingsFullscreenTexture,menuObj);
  Vertices settingsResolution(&settingsResolutionInfo,&menuObject,object3DShaders,settingsResolutionTexture,menuObj);
  Vertices settingsAudio(&settingsAudioInfo,&menuObject,object3DShaders,settingsAudioTexture,menuObj);
  Vertices audio0(&audio0Info,&menuObject,object3DShaders,audio0Texture,menuObj);
  Vertices audio1(&audio1Info,&menuObject,object3DShaders,audio1Texture,menuObj);
  Vertices audio2(&audio2Info,&menuObject,object3DShaders,audio2Texture,menuObj);
  Vertices audio3(&audio3Info,&menuObject,object3DShaders,audio3Texture,menuObj);
  Vertices audio4(&audio4Info,&menuObject,object3DShaders,audio4Texture,menuObj);
  Vertices audio5(&audio5Info,&menuObject,object3DShaders,audio5Texture,menuObj);
  Vertices audio6(&audio6Info,&menuObject,object3DShaders,audio6Texture,menuObj);
  Vertices audio7(&audio7Info,&menuObject,object3DShaders,audio7Texture,menuObj);
  Vertices audio8(&audio8Info,&menuObject,object3DShaders,audio8Texture,menuObj);
  Vertices audio9(&audio9Info,&menuObject,object3DShaders,audio9Texture,menuObj);
  Vertices audio10(&audio10Info,&menuObject,object3DShaders,audio10Texture,menuObj);
  Vertices resolution1(&resolution1Info,&menuObject,object3DShaders,resolution1Texture,menuObj);
  Vertices resolution2(&resolution2Info,&menuObject,object3DShaders,resolution2Texture,menuObj);
  Vertices resolution3(&resolution3Info,&menuObject,object3DShaders,resolution3Texture,menuObj);
  Vertices resolution4(&resolution4Info,&menuObject,object3DShaders,resolution4Texture,menuObj);
  Vertices chooseAudioA(&chooseAudioAInfo,&menuObject,object3DShaders,chooseAudioATexture,menuObj);
  Vertices chooseAudioB(&chooseAudioBInfo,&menuObject,object3DShaders,chooseAudioBTexture,menuObj);
  Vertices pauseMenu(&pauseGameInfo, &menuObject, object3DShaders, pauseGameTexture, menuObj);
  Vertices pauseGame(&pauseMenuInfo, &menuObject, object3DShaders, pauseMenuTexture, menuObj);
  Vertices next(&nextInfo, &nextObject, object3DShaders, nextTexture, nextObj);
  Vertices hold(&holdInfo, &holdObject, object3DShaders, holdTexture, holdObj);
  Vertices scoreVertices(&scoreInfo, &scoreObject, object3DShaders, scoreTexture, scoreObj);
  Vertices levelVertices(&lvlInfo, &lvlObject, object3DShaders, lvlTexture, lvlObj);
  Vertices sky(&skyInfo, &skyObject, object3DShaders, skyTexture, skyObj);
  Vertices floor(&floorInfo, &floorObject, object3DShaders, floorTexture, floorObj);
  Vertices zero(&zeroInfo, &zeroObject, object3DShaders, numberTexture, zeroObj);
  Vertices one(&oneInfo, &oneObject, object3DShaders, numberTexture, oneObj);
  Vertices two(&twoInfo, &twoObject, object3DShaders, numberTexture, twoObj);
  Vertices three(&threeInfo, &threeObject, object3DShaders, numberTexture, threeObj);
  Vertices four(&fourInfo, &fourObject, object3DShaders, numberTexture, fourObj);
  Vertices five(&fiveInfo, &fiveObject, object3DShaders, numberTexture, fiveObj);
  Vertices six(&sixInfo, &sixObject, object3DShaders, numberTexture, sixObj);
  Vertices seven(&sevenInfo, &sevenObject, object3DShaders, numberTexture, sevenObj);
  Vertices eight(&eightInfo, &eightObject, object3DShaders, numberTexture, eightObj);
  Vertices nine(&nineInfo, &nineObject, object3DShaders, numberTexture, nineObj);
  Vertices gameOverPlay(&gameOverPlayInfo, &menuObject, object3DShaders, gameOverPlayTexture, menuObj);
  Vertices gameOverBack(&gameOverBackInfo, &menuObject, object3DShaders, gameOverBackTexture, menuObj);
  Vertices highscoreVertices(&highscoreInfo, &highscoreObject, object3DShaders, highscoreTexture, highscoreObj);

  //Vertices cube(&cubeInfo,&cubeObject,object3DShaders,cubeTexture,cubeObj);
  
  //textures
  //DrawObjects::draw(textureIntroName,&textureIntro);
  //game time
  milliseconds ms=duration_cast<milliseconds>(system_clock::now().time_since_epoch());
  milliseconds ms2=duration_cast<milliseconds>(system_clock::now().time_since_epoch());
  milliseconds ms3=duration_cast<milliseconds>(system_clock::now().time_since_epoch());
  milliseconds ms4=duration_cast<milliseconds>(system_clock::now().time_since_epoch());
  position=glm::vec3(0.014757f,0.01f,2.392263);
  t.center_rotation=glm::mat4(1.0f);
  t.self_rotation=glm::mat4(1.0f);
  t.translation=glm::mat4(1.0f);
  t.scaling=glm::mat4(1.0f);
  //game loop
  do{
    startLoop();
    //scenes
    switch(scene){
      case Scene::INTRO:
        position=glm::vec3(0.014757f,0.01f,2.392263);
        speed = 0,mouseSpeed = 0;
        horizontalAngle=15.7;
        verticalAngle=-6.285;
        DrawObjects::draw(&menuInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        //printText2D(text, 500, 0, 60); !!!!!!!!TO DO
        //introMenu(textureIntro,shader,introSquare.getVAO());
        break;
      case Scene::SAVES:
        position=glm::vec3(0.014757f,0.01f,2.392263);
        speed = 0,mouseSpeed = 0;
        horizontalAngle=15.715;
        verticalAngle=-6.29;
        if(optionMenuSave==0){
          DrawObjects::draw(&save1Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        }
        else if(optionMenuSave==1){
          DrawObjects::draw(&save2Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        }
        else if(optionMenuSave==2){
          DrawObjects::draw(&save3Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        }
        else if(optionMenuSave==3){
          DrawObjects::draw(&save4Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        }
        else if(optionMenuSave==4){
          DrawObjects::draw(&save5Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        }
        else if(optionMenuSave==5){
          DrawObjects::draw(&savePlayGuestInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        }
        break;
      case Scene::MENU:
        position=glm::vec3(0.014757f,0.01f,2.392263);
        speed = 0,mouseSpeed = 0;
        horizontalAngle=15.715;
        verticalAngle=-6.29;
        if(optionMenu==0){
          DrawObjects::draw(&menuPlayInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        }
        else if(optionMenu==1){
          DrawObjects::draw(&menuProfileInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        }
        else if(optionMenu==2){
          DrawObjects::draw(&menuSkinsInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        }
        else if(optionMenu==3){
          DrawObjects::draw(&menuSettingsInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        }
        else if(optionMenu==4){
          DrawObjects::draw(&menuRickRollInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        }
        break;
      case Scene::SUBMENU:
        speed = 0,mouseSpeed = 0;
        position=glm::vec3(0.014757f,0.01f,2.45);
        horizontalAngle=15.71;
        verticalAngle=-6.278;
        if(needsToRebuild){
          needsToRebuild=false;
          reConstructObjects(&cube,&menu,&save1,&save2,&save3,&save4,&save5,&savePlayGuest,&menuPlay,&menuProfile,&menuSkins,&menuSettings,&menuRickRoll,&settingsFullscreen,&settingsResolution,&settingsAudio,&audio0,&audio1,&audio2,&audio3,&audio4,&audio5,&audio6,&audio7,&audio8,&audio9,&audio10,&resolution1,&resolution2,&resolution3,&resolution4,&chooseAudioA,&chooseAudioB,&pauseGame,&pauseMenu);
        }
        if(!isInSubSubMenu){
          if(optionSubMenu==0){
            DrawObjects::draw(&settingsFullscreenInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
          }
          else if(optionSubMenu==1){
            DrawObjects::draw(&settingsResolutionInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
          }
          else if(optionSubMenu==2){
            DrawObjects::draw(&settingsAudioInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
          }
        }
        else{
          switch(optionSubMenu){
            case 1:
              switch(currentPlayer.getWindowWidth()){
                case 700:
                  DrawObjects::draw(&resolution1Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
                  break;
                case 800:
                  DrawObjects::draw(&resolution2Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
                  break;
                case 900:
                  DrawObjects::draw(&resolution3Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
                  break;
                case 1000:
                  DrawObjects::draw(&resolution4Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
                  break;
              }
              break;
            case 2:
              switch((int)(currentPlayer.getVolume()*10)){
                case 0:
                  DrawObjects::draw(&audio0Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
                  break;
                case 1:
                  DrawObjects::draw(&audio1Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
                  break;
                case 2:
                  DrawObjects::draw(&audio2Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
                  break;
                case 3:
                  DrawObjects::draw(&audio3Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
                  break;
                case 4:
                  DrawObjects::draw(&audio4Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
                  break;
                case 5:
                  DrawObjects::draw(&audio5Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
                  break;
                case 6:
                  DrawObjects::draw(&audio6Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
                  break;
                case 7:
                  DrawObjects::draw(&audio7Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
                  break;
                case 8:
                  DrawObjects::draw(&audio8Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
                  break;
                case 9:
                  DrawObjects::draw(&audio9Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
                  break;
                case 10:
                  DrawObjects::draw(&audio10Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
                  break;
              }
              break;
          }  
        }
        break;
      case Scene::PLAY:
        t9.center_rotation=glm::mat4(1.0f);
        t9.self_rotation=glm::mat4(1.0f);
        t9.translation=glm::mat4(1.0f);
        t9.scaling=glm::mat4(1.0f);
        t9.scaling=glm::scale(t9.scaling,glm::vec3(2.5f,2.5f,2.5f));
        CreateNumber(score,2.0f,13.8f,4.5f,0.0f);
        CreateNumber(level,2.0f,-5.5f,4.5f,0.0f);
        t7.center_rotation=glm::mat4(1.0f);
        t7.self_rotation=glm::mat4(1.0f);
        t7.translation=glm::mat4(1.0f);
        t7.scaling=glm::mat4(1.0f);
        t7.scaling=glm::scale(t7.scaling,glm::vec3(5000.0f,5000.0f,5000.0f));
        DrawObjects::draw(&skyInfo,t7,object3DShaders,GL_TRIANGLES,&skyObject.vertices);

        t8.center_rotation=glm::mat4(1.0f);
        t8.self_rotation=glm::mat4(1.0f);
        t8.translation=glm::mat4(1.0f);
        t8.scaling=glm::mat4(1.0f);
        t8.translation=glm::translate(t8.translation,glm::vec3(0.0f,-2000.0f,0.0f));
        t8.scaling=glm::scale(t8.scaling,glm::vec3(5000.0f,5000.0f,5000.0f));
        DrawObjects::draw(&floorInfo,t8,object3DShaders,GL_TRIANGLES,&floorObject.vertices);
        if(canGenerateNewPiece){
          nextPiece=Tetrominoes::getRandomPiece(8,&lastPiece); 
          canGenerateNewPiece=false;
        }
        
        speed=0;
        position=glm::vec3(6.5f,10.0f,40.45f);
        printf("%f,%f\n",horizontalAngle,verticalAngle);
        t2.center_rotation=glm::mat4(1.0f);
        t2.self_rotation=glm::mat4(1.0f);
        t2.translation=glm::mat4(1.0f);
        t2.scaling=glm::mat4(1.0f);
        for(int i=20;i>0;i--){
          for(int j=0;j<10;j++){
            if(board[i][j]){
              t2.translation=glm::mat4(1.0f);
              t2.translation=glm::translate(t2.translation,glm::vec3((float)j*1.3,(float)i*1.3,0.0f));
              DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            }
          }
        }
        t2.scaling=glm::mat4(1.0f);
        t2.translation=glm::mat4(1.0f);
        t2.translation=glm::translate(t2.translation,glm::vec3(-1.3f,13.0f,0.0f));
        t2.scaling=glm::scale(t2.scaling,glm::vec3(1.0f,27.0f,1.0f));
        DrawObjects::draw(&wallInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
        t2.scaling=glm::mat4(1.0f);
        t2.translation=glm::mat4(1.0f);
        t2.translation=glm::translate(t2.translation,glm::vec3(13.0f,13.0f,0.0f));
        t2.scaling=glm::scale(t2.scaling,glm::vec3(1.0f,27.0f,1.0f));
        DrawObjects::draw(&wallInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
        t2.scaling=glm::mat4(1.0f);
        t2.translation=glm::mat4(1.0f);
        t2.translation=glm::translate(t2.translation,glm::vec3(5.9f,0.0f,0.0f));
        t2.scaling=glm::scale(t2.scaling,glm::vec3(13.3f,1.0f,1.0f));
        DrawObjects::draw(&wallInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
        
        t3.center_rotation=glm::mat4(1.0f);
        t3.self_rotation=glm::mat4(1.0f);
        t3.scaling=glm::mat4(1.0f);
        t3.translation=glm::mat4(1.0f);
        t3.translation=glm::translate(t3.translation,glm::vec3(15.5f,23.7f,0.0f));
        t3.scaling=glm::scale(t3.scaling,glm::vec3(1.5f,1.5f,1.5f));
        DrawObjects::draw(&nextInfo,t3,object3DShaders,GL_TRIANGLES,&nextObject.vertices);

        t4.center_rotation=glm::mat4(1.0f);
        t4.self_rotation=glm::mat4(1.0f);
        t4.scaling=glm::mat4(1.0f);
        t4.translation=glm::mat4(1.0f);
        t4.translation=glm::translate(t4.translation,glm::vec3(-4.0f,23.7f,0.0f));
        t4.scaling=glm::scale(t4.scaling,glm::vec3(1.5f,1.5f,1.5f));
        DrawObjects::draw(&holdInfo,t4,object3DShaders,GL_TRIANGLES,&holdObject.vertices);

        t5.center_rotation=glm::mat4(1.0f);
        t5.self_rotation=glm::mat4(1.0f);
        t5.scaling=glm::mat4(1.0f);
        t5.translation=glm::mat4(1.0f);
        t5.translation=glm::translate(t5.translation,glm::vec3(15.5f,7.0f,0.0f));
        t5.scaling=glm::scale(t5.scaling,glm::vec3(1.5f,1.5f,1.5f));
        DrawObjects::draw(&scoreInfo,t5,object3DShaders,GL_TRIANGLES,&scoreObject.vertices);

        t6.center_rotation=glm::mat4(1.0f);
        t6.self_rotation=glm::mat4(1.0f);
        t6.scaling=glm::mat4(1.0f);
        t6.translation=glm::mat4(1.0f);
        t6.translation=glm::translate(t6.translation,glm::vec3(-4.0f,7.0f,0.0f));
        t6.scaling=glm::scale(t6.scaling,glm::vec3(1.5f,1.5f,1.5f));
        DrawObjects::draw(&lvlInfo,t6,object3DShaders,GL_TRIANGLES,&lvlObject.vertices);
        //next piece
        switch(nextPiece){
          case TETROMINO_ID::I:
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(17.5f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(19.0f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            break;
          case TETROMINO_ID::J:
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(17.5f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,22.5f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            break;
          case TETROMINO_ID::L:
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(17.5f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(17.5f,22.5f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            break;
          case TETROMINO_ID::T:
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(17.5f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,22.5f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            break;
          case TETROMINO_ID::O:
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,22.5f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,22.5f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            break;
          case TETROMINO_ID::S:
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,22.5f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(17.5f,22.5f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            break;
          case TETROMINO_ID::Z:
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,22.5f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,22.5f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(17.5f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            break;
        }

        switch(pieceHold){
          case TETROMINO_ID::I:
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(-4.5f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(-6.0f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(-7.5f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(-9.0f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            break;
          case TETROMINO_ID::J:
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(-6.5f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(-6.5f,22.5f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            break;
          case TETROMINO_ID::L:
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(-6.5f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,22.5f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            break;
          case TETROMINO_ID::T:
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(-6.5f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,22.5f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            break;
          case TETROMINO_ID::O:
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,22.5f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,22.5f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            break;
          case TETROMINO_ID::S:
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,22.5f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,22.5f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(-6.5f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            break;
          case TETROMINO_ID::Z:
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,21.0f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,22.5f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            t2.scaling=glm::mat4(1.0f);
            t2.translation=glm::mat4(1.0f);
            t2.translation=glm::translate(t2.translation,glm::vec3(-6.5f,22.5f,0.0f));
            DrawObjects::draw(&cubeInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
            break;
        }

        
        if(numberOfTotalRowsDestroyed>=10){
          level++;
          numberOfTotalRowsDestroyed=0;
        }
        if(canPlayMusic&&!isSpeed){
          engine->drop();
          engine=createIrrKlangDevice();
          engine->setSoundVolume(currentPlayer.getVolume());
          engine->play2D(selectedMusic.c_str(), true);
          canPlayMusic=false;
        }
        if(switchToHold){
          switchToHold=false;
          nextPiece=pieceHold;
          pieceHold=TETROMINO_ID::NONE;
          new(&i)Tetrominoes(nextPiece,board);
        }
        if(firstSwitch){
          nextPiece=Tetrominoes::getRandomPiece(8,&lastPiece);
          new(&i)Tetrominoes(nextPiece,board);
          firstSwitch=false;
        }
        ms=duration_cast<milliseconds>(system_clock::now().time_since_epoch());
        //new fall
        if(ms.count()>=(ms2.count()+1600-((long long)level*100))){
          ms2=ms;
          if(!((i.willCollide(board,VERTICAL))||(i.willCollideEdges(board,VERTICAL)))){
            i.moveDown(board);
            printBoard(board);
          }
        }
        //colision on the bottom
        ms3=duration_cast<milliseconds>(system_clock::now().time_since_epoch());
        
        if((i.willCollide(board,VERTICAL))||(i.willCollideEdges(board,VERTICAL))){
          if(lastStep){
            ms4=duration_cast<milliseconds>(system_clock::now().time_since_epoch());
          }
          lastStep=false;
          if(ms3.count()>=(ms4.count()+1600-((long long)level*100))||hardDrop){
            ms4=ms3;
            collidedOnBottom(nextPiece);
          }
        }
        else{
          if(ms3.count()>=(ms4.count()+1600-((long long)level*100))||hardDrop){
            lastStep=true;
          }
        }
        break;
      case Scene::GAME_OVER:
        position=glm::vec3(0.014757f,0.01f,2.392263);
        speed = 0,mouseSpeed = 0;
        horizontalAngle=15.7;
        verticalAngle=-6.285;
        if(optionMenuGameOver==0){
          DrawObjects::draw(&gameOverPlayInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        }
        else if(optionMenuGameOver==1){
          DrawObjects::draw(&gameOverBackInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        }
        t9.center_rotation=glm::mat4(1.0f);
        t9.self_rotation=glm::mat4(1.0f);
        t9.translation=glm::mat4(1.0f);
        t9.scaling=glm::mat4(1.0f);
        t9.scaling=glm::scale(t9.scaling,glm::vec3(0.2f,0.2f,0.2f));
        CreateNumber(latestScore,0.1f,.6f,0.37f,0.0f);
        CreateNumber(currentPlayer.getHighscore(),0.1f,.6f,0.0f,0.0f);
        t5.center_rotation=glm::mat4(1.0f);
        t5.self_rotation=glm::mat4(1.0f);
        t5.scaling=glm::mat4(1.0f);
        t5.translation=glm::mat4(1.0f);
        t5.translation=glm::translate(t5.translation,glm::vec3(0.33f,0.37f,0.0f));
        t5.scaling=glm::scale(t5.scaling,glm::vec3(0.15f,0.15f,0.15f));
        DrawObjects::draw(&scoreInfo,t5,object3DShaders,GL_TRIANGLES,&scoreObject.vertices);

        t10.center_rotation=glm::mat4(1.0f);
        t10.self_rotation=glm::mat4(1.0f);
        t10.scaling=glm::mat4(1.0f);
        t10.translation=glm::mat4(1.0f);
        t10.translation=glm::translate(t5.translation,glm::vec3(-0.1f,-0.35f,0.0f));
        t10.scaling=glm::scale(t5.scaling,glm::vec3(1.0f,1.0f,1.0f));
        DrawObjects::draw(&highscoreInfo,t10,object3DShaders,GL_TRIANGLES,&highscoreObject.vertices);
        
        break;
      case Scene::PAUSE:
        position=glm::vec3(0.014757f,0.01f,2.392263);
        speed = 0,mouseSpeed = 0;
        horizontalAngle=15.715;
        verticalAngle=-6.29;
        if(optionMenuPause==0){
          DrawObjects::draw(&pauseGameInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        }
        else{
          DrawObjects::draw(&pauseMenuInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        }
        break;
      case Scene::MUSIC_SELECTION:
        position=glm::vec3(0.014757f,0.01f,2.392263);
        speed = 0,mouseSpeed = 0;
        horizontalAngle=15.715;
        verticalAngle=-6.29;
        if(optionMusicSelection==0){
          DrawObjects::draw(&chooseAudioAInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        }
        else{
          DrawObjects::draw(&chooseAudioBInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        }
        break;
    }
    endLoop();
  }
  while(!exitGame);
  
  //gpu lexivia
  //introSquare.cleanData();
  //introSquareTriangle.cleanData();

  glfwTerminate();
  return 0;
}

void reConstructObjects(Vertices *cube,
                        Vertices *menu,
                        Vertices *save1,
                        Vertices *save2,
                        Vertices *save3,
                        Vertices *save4,
                        Vertices *save5,
                        Vertices *savePlayGuest,
                        Vertices *menuPlay,
                        Vertices *menuProfile,
                        Vertices *menuSkins,
                        Vertices *menuSettings,
                        Vertices *menuRickRoll,
                        Vertices *settingsFullscreen,
                        Vertices *settingsResolution,
                        Vertices *settingsAudio,
                        Vertices *audio0,
                        Vertices *audio1,
                        Vertices *audio2,
                        Vertices *audio3,
                        Vertices *audio4,
                        Vertices *audio5,
                        Vertices *audio6,
                        Vertices *audio7,
                        Vertices *audio8,
                        Vertices *audio9,
                        Vertices *audio10,
                        Vertices *resolution1,
                        Vertices *resolution2,
                        Vertices *resolution3,
                        Vertices *resolution4,
                        Vertices *chooseAudioA,
                        Vertices *chooseAudioB,
                        Vertices *pauseGame,
                        Vertices *pauseMenu
                       ){
  object3DShaders=LoadShaders("shaders/tvs.vertexshader","shaders/cfs.fragmentshader");
  new(cube)Vertices(&cubeInfo,&cubeObject,object3DShaders,cubeTexture,cubeObj);
  new(menu)Vertices(&menuInfo,&menuObject,object3DShaders,menuTexture,menuObj);
  new(save1)Vertices(&save1Info,&menuObject,object3DShaders,save1Texture,menuObj);
  new(save2)Vertices(&save2Info,&menuObject,object3DShaders,save2Texture,menuObj);
  new(save3)Vertices(&save3Info,&menuObject,object3DShaders,save3Texture,menuObj);
  new(save4)Vertices(&save4Info,&menuObject,object3DShaders,save4Texture,menuObj);
  new(save5)Vertices(&save5Info,&menuObject,object3DShaders,save5Texture,menuObj);
  new(savePlayGuest)Vertices(&savePlayGuestInfo,&menuObject,object3DShaders,savePlayGuestTexture,menuObj);
  new(menuPlay)Vertices(&menuPlayInfo,&menuObject,object3DShaders,menuPlayTexture,menuObj);
  new(menuProfile)Vertices(&menuProfileInfo,&menuObject,object3DShaders,menuProfileTexture,menuObj);
  new(menuSkins)Vertices(&menuSkinsInfo,&menuObject,object3DShaders,menuSkinsTexture,menuObj);
  new(menuSettings)Vertices(&menuSettingsInfo,&menuObject,object3DShaders,menuSettingsTexture,menuObj);
  new(menuRickRoll)Vertices(&menuRickRollInfo,&menuObject,object3DShaders,menuRickRollTexture,menuObj);
  new(settingsFullscreen)Vertices(&settingsFullscreenInfo,&menuObject,object3DShaders,settingsFullscreenTexture,menuObj);
  new(settingsResolution)Vertices(&settingsResolutionInfo,&menuObject,object3DShaders,settingsResolutionTexture,menuObj);
  new(settingsAudio)Vertices(&settingsAudioInfo,&menuObject,object3DShaders,settingsAudioTexture,menuObj);
  new(audio0)Vertices(&audio0Info,&menuObject,object3DShaders,audio0Texture,menuObj);
  new(audio1)Vertices(&audio1Info,&menuObject,object3DShaders,audio1Texture,menuObj);
  new(audio2)Vertices(&audio2Info,&menuObject,object3DShaders,audio2Texture,menuObj);
  new(audio3)Vertices(&audio3Info,&menuObject,object3DShaders,audio3Texture,menuObj);
  new(audio4)Vertices(&audio4Info,&menuObject,object3DShaders,audio4Texture,menuObj);
  new(audio5)Vertices(&audio5Info,&menuObject,object3DShaders,audio5Texture,menuObj);
  new(audio6)Vertices(&audio6Info,&menuObject,object3DShaders,audio6Texture,menuObj);
  new(audio7)Vertices(&audio7Info,&menuObject,object3DShaders,audio7Texture,menuObj);
  new(audio8)Vertices(&audio8Info,&menuObject,object3DShaders,audio8Texture,menuObj);
  new(audio9)Vertices(&audio9Info,&menuObject,object3DShaders,audio9Texture,menuObj);
  new(audio10)Vertices(&audio10Info,&menuObject,object3DShaders,audio10Texture,menuObj);
  new(resolution1)Vertices(&resolution1Info,&menuObject,object3DShaders,resolution1Texture,menuObj);
  new(resolution2)Vertices(&resolution2Info,&menuObject,object3DShaders,resolution2Texture,menuObj);
  new(resolution3)Vertices(&resolution3Info,&menuObject,object3DShaders,resolution3Texture,menuObj);
  new(resolution4)Vertices(&resolution4Info,&menuObject,object3DShaders,resolution4Texture,menuObj);
  new(chooseAudioA)Vertices(&chooseAudioAInfo,&menuObject,object3DShaders,chooseAudioATexture,menuObj);
  new(chooseAudioB)Vertices(&chooseAudioBInfo,&menuObject,object3DShaders,chooseAudioBTexture,menuObj);
  new(pauseMenu)Vertices(&pauseGameInfo, &menuObject, object3DShaders, pauseGameTexture, menuObj);
  new(pauseGame)Vertices(&pauseMenuInfo, &menuObject, object3DShaders, pauseMenuTexture, menuObj);
}

void startLoop(){
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glUseProgram(programID);
  glBindFramebuffer(GL_FRAMEBUFFER,0);
  glfwSetKeyCallback(window, key_callback);
}

void endLoop(){
  glfwSwapBuffers(window);
  glfwPollEvents();
}

void CreateNumber(long long n, float x,float xInitial, float y, float z){
  float xPos = xInitial;
  
  if(n==0){
    t9.translation=glm::mat4(1.0f);
    t9.translation=glm::translate(t9.translation,glm::vec3(xPos,y,z));
    DrawObjects::draw(&zeroInfo,t9,object3DShaders,GL_TRIANGLES,&zeroObject.vertices);
    return;
  }
  size_t numberSize=1;
  int *number=(int*)malloc(numberSize*sizeof(int));
  
  while(n){
    number[numberSize-1]=n%10;
    numberSize++;
    number=(int*)realloc(number,numberSize*sizeof(int));
    n/=10;
  }
  numberSize--;
  number=(int*)realloc(number,numberSize*sizeof(int));
  int *number2=(int*)malloc(numberSize*sizeof(int));
  for(int i=0;i<numberSize;i++){
    number2[i]=number[(numberSize-1)-i];
  }
  for(int i=0;i<numberSize;i++){
    t9.translation=glm::mat4(1.0f);
    switch(number2[i]){
      case 0:
        t9.translation=glm::translate(t9.translation,glm::vec3(xPos,y,z));
        DrawObjects::draw(&zeroInfo,t9,object3DShaders,GL_TRIANGLES,&zeroObject.vertices);
        break;
      case 1:
        t9.translation=glm::translate(t9.translation,glm::vec3(xPos,y,z));
        DrawObjects::draw(&oneInfo,t9,object3DShaders,GL_TRIANGLES,&oneObject.vertices);
        break;
      case 2:
        t9.translation=glm::translate(t9.translation,glm::vec3(xPos,y,z));
        DrawObjects::draw(&twoInfo,t9,object3DShaders,GL_TRIANGLES,&twoObject.vertices);
        break;
      case 3:
        t9.translation=glm::translate(t9.translation,glm::vec3(xPos,y,z));
        DrawObjects::draw(&threeInfo,t9,object3DShaders,GL_TRIANGLES,&threeObject.vertices);
        break;
      case 4:
        t9.translation=glm::translate(t9.translation,glm::vec3(xPos,y,z));
        DrawObjects::draw(&fourInfo,t9,object3DShaders,GL_TRIANGLES,&fourObject.vertices);
        break;
      case 5:
        t9.translation=glm::translate(t9.translation,glm::vec3(xPos,y,z));
        DrawObjects::draw(&fiveInfo,t9,object3DShaders,GL_TRIANGLES,&fiveObject.vertices);
        break;
      case 6:
        t9.translation=glm::translate(t9.translation,glm::vec3(xPos,y,z));
        DrawObjects::draw(&sixInfo,t9,object3DShaders,GL_TRIANGLES,&sixObject.vertices);
        break;
      case 7:
        t9.translation=glm::translate(t9.translation,glm::vec3(xPos,y,z));
        DrawObjects::draw(&sevenInfo,t9,object3DShaders,GL_TRIANGLES,&sevenObject.vertices);
        break;
      case 8:
        t9.translation=glm::translate(t9.translation,glm::vec3(xPos,y,z));
        DrawObjects::draw(&eightInfo,t9,object3DShaders,GL_TRIANGLES,&eightObject.vertices);
        break;
      case 9:
        t9.translation=glm::translate(t9.translation,glm::vec3(xPos,y,z));
        DrawObjects::draw(&nineInfo,t9,object3DShaders,GL_TRIANGLES,&nineObject.vertices);
        break;
    }
    xPos += x;
  }
  
}