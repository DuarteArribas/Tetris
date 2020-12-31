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
using namespace std;
using namespace std::chrono;

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
//common
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

/*
  ----------- Objects -----------
*/

#include"src/objects/objectStructs.cpp"
#include"src/objects/objectTexturesBuffers.cpp"
#include"src/objects/objectDeclarations.cpp"

/*
  ----------- Project Libraries -----------
*/
//enums
#include"src/support/enums.cpp"
//structure
#include"src/init.cpp"
#include"src/vertexTransfer.cpp"
#include"src/drawObjects.cpp"
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
#include"main.h"

/*
  ----------- General Global Variables -----------
*/
//represents the current scene
Scene scene=Scene::INTRO;
//represents the current player
Player currentPlayer(700,700,false,0.5f);
//sound engine
ISoundEngine* engine = createIrrKlangDevice();
//window
char windowTitle[]="Tetris";
bool needsToRebuild=false;
//menu options
int optionMenu=0,optionSubMenu=0,subOptionSubMenu=0, optionMenuGameOver=0,optionMenuPause=0,optionMenuSave=0,optionMusicSelection=0,optionSkins=0;
//if this variable is true, the game will close
bool exitGame=false;
//makes sure the music and the music sped up don't stop and start everytime the loop happens
bool canPlayMusic=true,canPlayMusic2=true;
//makes sure the window is rebuilt if its size hasn't changed
bool canRebuildWindow=false;
//handles if the player is in the subSubMenu
bool isInSubSubMenu=false;

/*
  ----------- Game Global Variables -----------
*/
//board
bool board[25][10];
TETROMINO_ID boardPieces[25][10];
//tetronimo
Tetrominoes i(TETROMINO_ID::I,board);
bool lastStep=true, hardDrop=false,isGameOver=false;
//piece
TETROMINO_ID nextPiece;
int lastPiece;
bool canGenerateNewPiece=true;
int skin=0;
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
//control gametime
milliseconds ms=duration_cast<milliseconds>(system_clock::now().time_since_epoch());
milliseconds ms2=duration_cast<milliseconds>(system_clock::now().time_since_epoch());
milliseconds ms3=duration_cast<milliseconds>(system_clock::now().time_since_epoch());
milliseconds ms4=duration_cast<milliseconds>(system_clock::now().time_since_epoch());

/*
  ----------- Remaining Project Libraries -----------
*/
//file updates
#include"src/saves.cpp"
//remaining scenes
#include"src/scenes/introMenu.cpp"
#include"src/scenes/saveMenu.cpp"
#include"src/scenes/profileMenu.cpp"
#include"src/scenes/skinMenu.cpp"
#include"src/scenes/menu.cpp"
#include"src/scenes/pause.cpp"
#include"src/scenes/gameOver.cpp"
#include"src/scenes/subMenu.cpp"
#include"src/scenes/musicSelectionMenu.cpp"
#include"src/game/board.cpp"
#include"src/scenes/play.cpp"
//key handling
#include"src/keyHandling.cpp"

int main(void){
  /*
    ----------- Initialization -----------
  */
  //load settings and create player instance
  newPlayer();
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
  object3DShaders=LoadShaders("shaders/tvs.vertexshader","shaders/cfs.fragmentshader");
  //vertices
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
  Vertices zeroWhite(&zeroWhiteInfo, &zeroObject, object3DShaders, scoreWhiteTexture, zeroObj);
  Vertices oneWhite(&oneWhiteInfo, &oneObject, object3DShaders, scoreWhiteTexture, oneObj);
  Vertices twoWhite(&twoWhiteInfo, &twoObject, object3DShaders, scoreWhiteTexture, twoObj);
  Vertices threeWhite(&threeWhiteInfo, &threeObject, object3DShaders, scoreWhiteTexture, threeObj);
  Vertices fourWhite(&fourWhiteInfo, &fourObject, object3DShaders, scoreWhiteTexture, fourObj);
  Vertices fiveWhite(&fiveWhiteInfo, &fiveObject, object3DShaders, scoreWhiteTexture, fiveObj);
  Vertices sixWhite(&sixWhiteInfo, &sixObject, object3DShaders, scoreWhiteTexture, sixObj);
  Vertices sevenWhite(&sevenWhiteInfo, &sevenObject, object3DShaders, scoreWhiteTexture, sevenObj);
  Vertices eightWhite(&eightWhiteInfo, &eightObject, object3DShaders, scoreWhiteTexture, eightObj);
  Vertices nineWhite(&nineWhiteInfo, &nineObject, object3DShaders, scoreWhiteTexture, nineObj);
  Vertices gameOverPlay(&gameOverPlayInfo, &menuObject, object3DShaders, gameOverPlayTexture, menuObj);
  Vertices gameOverBack(&gameOverBackInfo, &menuObject, object3DShaders, gameOverBackTexture, menuObj);
  Vertices highscoreVertices(&highscoreInfo, &highscoreObject, object3DShaders, highscoreTexture, highscoreObj);
  Vertices skin0I(&skin0IInfo,&cubeObject,object3DShaders,skin0ITexture,cubeObj);
  Vertices skin0J(&skin0JInfo,&cubeObject,object3DShaders,skin0JTexture,cubeObj);
  Vertices skin0L(&skin0LInfo,&cubeObject,object3DShaders,skin0LTexture,cubeObj);
  Vertices skin0T(&skin0TInfo,&cubeObject,object3DShaders,skin0TTexture,cubeObj);
  Vertices skin0S(&skin0SInfo,&cubeObject,object3DShaders,skin0STexture,cubeObj);
  Vertices skin0Z(&skin0ZInfo,&cubeObject,object3DShaders,skin0ZTexture,cubeObj);
  Vertices skin0O(&skin0OInfo,&cubeObject,object3DShaders,skin0OTexture,cubeObj);
  Vertices skin1I(&skin1IInfo,&cubeObject,object3DShaders,skin1ITexture,cubeObj);
  Vertices skin1J(&skin1JInfo,&cubeObject,object3DShaders,skin1JTexture,cubeObj);
  Vertices skin1L(&skin1LInfo,&cubeObject,object3DShaders,skin1LTexture,cubeObj);
  Vertices skin1T(&skin1TInfo,&cubeObject,object3DShaders,skin1TTexture,cubeObj);
  Vertices skin1S(&skin1SInfo,&cubeObject,object3DShaders,skin1STexture,cubeObj);
  Vertices skin1Z(&skin1ZInfo,&cubeObject,object3DShaders,skin1ZTexture,cubeObj);
  Vertices skin1O(&skin1OInfo,&cubeObject,object3DShaders,skin1OTexture,cubeObj);
  Vertices skin2I(&skin2IInfo,&cubeObject,object3DShaders,skin2ITexture,cubeObj);
  Vertices skin2J(&skin2JInfo,&cubeObject,object3DShaders,skin2JTexture,cubeObj);
  Vertices skin2L(&skin2LInfo,&cubeObject,object3DShaders,skin2LTexture,cubeObj);
  Vertices skin2T(&skin2TInfo,&cubeObject,object3DShaders,skin2TTexture,cubeObj);
  Vertices skin2S(&skin2SInfo,&cubeObject,object3DShaders,skin2STexture,cubeObj);
  Vertices skin2Z(&skin2ZInfo,&cubeObject,object3DShaders,skin2ZTexture,cubeObj);
  Vertices skin2O(&skin2OInfo,&cubeObject,object3DShaders,skin2OTexture,cubeObj);
  Vertices skin11(&skin11Info,&menuObject,object3DShaders,skin11Texture,menuObj);
  Vertices skin21(&skin21Info,&menuObject,object3DShaders,skin21Texture,menuObj);
  Vertices skin22(&skin22Info,&menuObject,object3DShaders,skin22Texture,menuObj);
  Vertices skin31(&skin31Info,&menuObject,object3DShaders,skin31Texture,menuObj);
  Vertices skin32(&skin32Info,&menuObject,object3DShaders,skin32Texture,menuObj);
  Vertices skin33(&skin33Info,&menuObject,object3DShaders,skin33Texture,menuObj);
  Vertices unranked(&unrankedInfo,&menuObject,object3DShaders,unrankedTexture,menuObj);
  Vertices bronze(&bronzeInfo,&menuObject,object3DShaders,bronzeTexture,menuObj);
  Vertices silver(&silverInfo,&menuObject,object3DShaders,silverTexture,menuObj);
  Vertices gold(&goldInfo,&menuObject,object3DShaders,goldTexture,menuObj);
  Vertices platinum(&platinumInfo,&menuObject,object3DShaders,platinumTexture,menuObj);
  Vertices diamond(&diamondInfo,&menuObject,object3DShaders,diamondTexture,menuObj);
  Vertices master(&masterInfo,&menuObject,object3DShaders,masterTexture,menuObj);
  Vertices tetris(&tetrisInfo,&menuObject,object3DShaders,tetrisTexture,menuObj);  
  //game loop
  do{
    startLoop();
    //scenes
    switch(scene){
      case Scene::INTRO:
        showIntroMenu();
        break;
      case Scene::SAVES:
        showSaveMenu();
        break;
      case Scene::MENU:
        showMenu();
        break;
      case Scene::PROFILE:
        showProfileMenu();
        break;
      case Scene::SKINS:
        showSkinMenu();
        break;
      case Scene::SUBMENU:
        if(needsToRebuild){
          needsToRebuild=false;
          reConstructObjects(&walls,&menu,&save1,&save2,&save3,&save4,&save5,&savePlayGuest,&menuPlay,&menuProfile,&menuSkins,&menuSettings,&menuRickRoll,&settingsFullscreen,&settingsResolution,&settingsAudio,&audio0,&audio1,&audio2,&audio3,&audio4,&audio5,&audio6,&audio7,&audio8,&audio9,&audio10,&resolution1,&resolution2,&resolution3,&resolution4,&chooseAudioA,&chooseAudioB,&pauseGame,&pauseMenu,&next,&hold,&scoreVertices,&levelVertices,&sky,&floor,&zero,&one,&two,&three,&four,&five,&six,&seven,&eight,&nine,&zeroWhite,&oneWhite,&twoWhite,&threeWhite,&fourWhite,&fiveWhite,&sixWhite,&sevenWhite,&eightWhite,&nineWhite,&gameOverPlay,&gameOverBack,&highscoreVertices,&skin0I,&skin0J,&skin0L,&skin0T,&skin0S,&skin0Z,&skin0O,&skin1I,&skin1J,&skin1L,&skin1T,&skin1S,&skin1Z,&skin1O,&skin2I,&skin2J,&skin2L,&skin2T,&skin2S,&skin2Z,&skin2O,&skin11,&skin21,&skin22,&skin31,&skin32,&skin33,&unranked,&bronze,&silver,&gold,&platinum,&diamond,&master,&tetris);
        }
        showSubMenu();
        break;
      case Scene::PLAY:
        showPlayMenu();
        break;
      case Scene::GAME_OVER:
        showGameOverMenu();
        break;
      case Scene::PAUSE:
        showPauseMenu();
        break;
      case Scene::MUSIC_SELECTION:
        showMusicSelectionMenu();
        break;
    }
    endLoop();
  }
  while(!exitGame);
  //gpu lexivia

  glfwTerminate();
  return 0;
}

//reconstructs all objects upon window generation
void reConstructObjects(Vertices *walls,
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
                        Vertices *pauseMenu,
                        Vertices *next,
                        Vertices *hold,
                        Vertices *scoreVertices,
                        Vertices *levelVertices,
                        Vertices *sky,
                        Vertices *floor,
                        Vertices *zero,
                        Vertices *one,
                        Vertices *two,
                        Vertices *three,
                        Vertices *four,
                        Vertices *five,
                        Vertices *six,
                        Vertices *seven,
                        Vertices *eight,
                        Vertices *nine,
                        Vertices *zeroWhite,
                        Vertices *oneWhite,
                        Vertices *twoWhite,
                        Vertices *threeWhite,
                        Vertices *fourWhite,
                        Vertices *fiveWhite,
                        Vertices *sixWhite,
                        Vertices *sevenWhite,
                        Vertices *eightWhite,
                        Vertices *nineWhite,
                        Vertices *gameOverPlay,
                        Vertices *gameOverBack,
                        Vertices *highscoreVertices,
                        Vertices *skin0I,
                        Vertices *skin0J,
                        Vertices *skin0L,
                        Vertices *skin0T,
                        Vertices *skin0S,
                        Vertices *skin0Z,
                        Vertices *skin0O,
                        Vertices *skin1I,
                        Vertices *skin1J,
                        Vertices *skin1L,
                        Vertices *skin1T,
                        Vertices *skin1S,
                        Vertices *skin1Z,
                        Vertices *skin1O,
                        Vertices *skin2I,
                        Vertices *skin2J,
                        Vertices *skin2L,
                        Vertices *skin2T,
                        Vertices *skin2S,
                        Vertices *skin2Z,
                        Vertices *skin2O,
                        Vertices *skin11,
                        Vertices *skin21,
                        Vertices *skin22,
                        Vertices *skin31,
                        Vertices *skin32,
                        Vertices *skin33,
                        Vertices *unranked,
                        Vertices *bronze,
                        Vertices *silver,
                        Vertices *gold,
                        Vertices *platinum,
                        Vertices *diamond,
                        Vertices *master,
                        Vertices *tetris
                       ){
  object3DShaders=LoadShaders("shaders/tvs.vertexshader","shaders/cfs.fragmentshader");
  new(walls)Vertices(&wallInfo,&cubeObject,object3DShaders,wallsTexture,cubeObj);
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
  new(next)Vertices(&nextInfo, &nextObject, object3DShaders, nextTexture, nextObj);
  new(hold)Vertices(&holdInfo, &holdObject, object3DShaders, holdTexture, holdObj);
  new(scoreVertices)Vertices(&scoreInfo, &scoreObject, object3DShaders, scoreTexture, scoreObj);
  new(levelVertices)Vertices(&lvlInfo, &lvlObject, object3DShaders, lvlTexture, lvlObj);
  new(sky)Vertices(&skyInfo, &skyObject, object3DShaders, skyTexture, skyObj);
  new(floor)Vertices(&floorInfo, &floorObject, object3DShaders, floorTexture, floorObj);
  new(zero)Vertices(&zeroInfo, &zeroObject, object3DShaders, numberTexture, zeroObj);
  new(one)Vertices(&oneInfo, &oneObject, object3DShaders, numberTexture, oneObj);
  new(two)Vertices(&twoInfo, &twoObject, object3DShaders, numberTexture, twoObj);
  new(three)Vertices(&threeInfo, &threeObject, object3DShaders, numberTexture, threeObj);
  new(four)Vertices(&fourInfo, &fourObject, object3DShaders, numberTexture, fourObj);
  new(five)Vertices(&fiveInfo, &fiveObject, object3DShaders, numberTexture, fiveObj);
  new(six)Vertices(&sixInfo, &sixObject, object3DShaders, numberTexture, sixObj);
  new(seven)Vertices(&sevenInfo, &sevenObject, object3DShaders, numberTexture, sevenObj);
  new(eight)Vertices(&eightInfo, &eightObject, object3DShaders, numberTexture, eightObj);
  new(nine)Vertices(&nineInfo, &nineObject, object3DShaders, numberTexture, nineObj);
  new(zeroWhite)Vertices(&zeroWhiteInfo, &zeroObject, object3DShaders, scoreWhiteTexture, zeroObj);
  new(oneWhite)Vertices(&oneWhiteInfo, &oneObject, object3DShaders, scoreWhiteTexture, oneObj);
  new(twoWhite)Vertices(&twoWhiteInfo, &twoObject, object3DShaders, scoreWhiteTexture, twoObj);
  new(threeWhite)Vertices(&threeWhiteInfo, &threeObject, object3DShaders, scoreWhiteTexture, threeObj);
  new(fourWhite)Vertices(&fourWhiteInfo, &fourObject, object3DShaders, scoreWhiteTexture, fourObj);
  new(fiveWhite)Vertices(&fiveWhiteInfo, &fiveObject, object3DShaders, scoreWhiteTexture, fiveObj);
  new(sixWhite)Vertices(&sixWhiteInfo, &sixObject, object3DShaders, scoreWhiteTexture, sixObj);
  new(sevenWhite)Vertices(&sevenWhiteInfo, &sevenObject, object3DShaders, scoreWhiteTexture, sevenObj);
  new(eightWhite)Vertices(&eightWhiteInfo, &eightObject, object3DShaders, scoreWhiteTexture, eightObj);
  new(nineWhite)Vertices(&nineWhiteInfo, &nineObject, object3DShaders, scoreWhiteTexture, nineObj);
  new(gameOverPlay)Vertices(&gameOverPlayInfo, &menuObject, object3DShaders, gameOverPlayTexture, menuObj);
  new(gameOverBack)Vertices(&gameOverBackInfo, &menuObject, object3DShaders, gameOverBackTexture, menuObj);
  new(highscoreVertices)Vertices(&highscoreInfo, &highscoreObject, object3DShaders, highscoreTexture, highscoreObj);
  new(skin0I)Vertices(&skin0IInfo,&cubeObject,object3DShaders,skin0ITexture,cubeObj);
  new(skin0J)Vertices(&skin0JInfo,&cubeObject,object3DShaders,skin0JTexture,cubeObj);
  new(skin0L)Vertices(&skin0LInfo,&cubeObject,object3DShaders,skin0LTexture,cubeObj);
  new(skin0T)Vertices(&skin0TInfo,&cubeObject,object3DShaders,skin0TTexture,cubeObj);
  new(skin0S)Vertices(&skin0SInfo,&cubeObject,object3DShaders,skin0STexture,cubeObj);
  new(skin0Z)Vertices(&skin0ZInfo,&cubeObject,object3DShaders,skin0ZTexture,cubeObj);
  new(skin0O)Vertices(&skin0OInfo,&cubeObject,object3DShaders,skin0OTexture,cubeObj);
  new(skin1I)Vertices(&skin1IInfo,&cubeObject,object3DShaders,skin1ITexture,cubeObj);
  new(skin1J)Vertices(&skin1JInfo,&cubeObject,object3DShaders,skin1JTexture,cubeObj);
  new(skin1L)Vertices(&skin1LInfo,&cubeObject,object3DShaders,skin1LTexture,cubeObj);
  new(skin1T)Vertices(&skin1TInfo,&cubeObject,object3DShaders,skin1TTexture,cubeObj);
  new(skin1S)Vertices(&skin1SInfo,&cubeObject,object3DShaders,skin1STexture,cubeObj);
  new(skin1Z)Vertices(&skin1ZInfo,&cubeObject,object3DShaders,skin1ZTexture,cubeObj);
  new(skin1O)Vertices(&skin1OInfo,&cubeObject,object3DShaders,skin1OTexture,cubeObj);
  new(skin2I)Vertices(&skin2IInfo,&cubeObject,object3DShaders,skin2ITexture,cubeObj);
  new(skin2J)Vertices(&skin2JInfo,&cubeObject,object3DShaders,skin2JTexture,cubeObj);
  new(skin2L)Vertices(&skin2LInfo,&cubeObject,object3DShaders,skin2LTexture,cubeObj);
  new(skin2T)Vertices(&skin2TInfo,&cubeObject,object3DShaders,skin2TTexture,cubeObj);
  new(skin2S)Vertices(&skin2SInfo,&cubeObject,object3DShaders,skin2STexture,cubeObj);
  new(skin2Z)Vertices(&skin2ZInfo,&cubeObject,object3DShaders,skin2ZTexture,cubeObj);
  new(skin2O)Vertices(&skin2OInfo,&cubeObject,object3DShaders,skin2OTexture,cubeObj);
  new(skin11)Vertices(&skin11Info,&menuObject,object3DShaders,skin11Texture,menuObj);
  new(skin21)Vertices(&skin21Info,&menuObject,object3DShaders,skin21Texture,menuObj);
  new(skin22)Vertices(&skin22Info,&menuObject,object3DShaders,skin22Texture,menuObj);
  new(skin31)Vertices(&skin31Info,&menuObject,object3DShaders,skin31Texture,menuObj);
  new(skin32)Vertices(&skin32Info,&menuObject,object3DShaders,skin32Texture,menuObj);
  new(skin33)Vertices(&skin33Info,&menuObject,object3DShaders,skin33Texture,menuObj);
  new(unranked)Vertices(&unrankedInfo,&menuObject,object3DShaders,unrankedTexture,menuObj);
  new(bronze)Vertices(&bronzeInfo,&menuObject,object3DShaders,bronzeTexture,menuObj);
  new(silver)Vertices(&silverInfo,&menuObject,object3DShaders,silverTexture,menuObj);
  new(gold)Vertices(&goldInfo,&menuObject,object3DShaders,goldTexture,menuObj);
  new(platinum)Vertices(&platinumInfo,&menuObject,object3DShaders,platinumTexture,menuObj);
  new(diamond)Vertices(&diamondInfo,&menuObject,object3DShaders,diamondTexture,menuObj);
  new(master)Vertices(&masterInfo,&menuObject,object3DShaders,masterTexture,menuObj);
  new(tetris)Vertices(&tetrisInfo,&menuObject,object3DShaders,tetrisTexture,menuObj);
}

//renders all functions needed in the start of the menu
void startLoop(){
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glBindFramebuffer(GL_FRAMEBUFFER,0);
  glfwSetKeyCallback(window, key_callback);
}

//renders all functions needed in the end of the menu
void endLoop(){
  glfwSwapBuffers(window);
  glfwPollEvents();
}

//draws a number on the screen
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

//draws a white number on the screen
void CreateNumberWhite(long long n, float x,float xInitial, float y, float z){
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
      DrawObjects::draw(&zeroWhiteInfo,t9,object3DShaders,GL_TRIANGLES,&zeroObject.vertices);
      break;
    case 1:
      t9.translation=glm::translate(t9.translation,glm::vec3(xPos,y,z));
      DrawObjects::draw(&oneWhiteInfo,t9,object3DShaders,GL_TRIANGLES,&oneObject.vertices);
      break;
    case 2:
      t9.translation=glm::translate(t9.translation,glm::vec3(xPos,y,z));
      DrawObjects::draw(&twoWhiteInfo,t9,object3DShaders,GL_TRIANGLES,&twoObject.vertices);
      break;
    case 3:
      t9.translation=glm::translate(t9.translation,glm::vec3(xPos,y,z));
      DrawObjects::draw(&threeWhiteInfo,t9,object3DShaders,GL_TRIANGLES,&threeObject.vertices);
      break;
    case 4:
      t9.translation=glm::translate(t9.translation,glm::vec3(xPos,y,z));
      DrawObjects::draw(&fourWhiteInfo,t9,object3DShaders,GL_TRIANGLES,&fourObject.vertices);
      break;
    case 5:
      t9.translation=glm::translate(t9.translation,glm::vec3(xPos,y,z));
      DrawObjects::draw(&fiveWhiteInfo,t9,object3DShaders,GL_TRIANGLES,&fiveObject.vertices);
      break;
    case 6:
      t9.translation=glm::translate(t9.translation,glm::vec3(xPos,y,z));
      DrawObjects::draw(&sixWhiteInfo,t9,object3DShaders,GL_TRIANGLES,&sixObject.vertices);
      break;
    case 7:
      t9.translation=glm::translate(t9.translation,glm::vec3(xPos,y,z));
      DrawObjects::draw(&sevenWhiteInfo,t9,object3DShaders,GL_TRIANGLES,&sevenObject.vertices);
      break;
    case 8:
      t9.translation=glm::translate(t9.translation,glm::vec3(xPos,y,z));
      DrawObjects::draw(&eightWhiteInfo,t9,object3DShaders,GL_TRIANGLES,&eightObject.vertices);
      break;
    case 9:
      t9.translation=glm::translate(t9.translation,glm::vec3(xPos,y,z));
      DrawObjects::draw(&nineWhiteInfo,t9,object3DShaders,GL_TRIANGLES,&nineObject.vertices);
      break;
    }
    xPos += x;
  }
}

//creates and instanciates a new player
void newPlayer(){
  int widthInt=0, heightInt=0;
  bool fullscreenBool=false;
  float volumeFloat=0.0f;
  loadSettings(&widthInt,&heightInt,&fullscreenBool,&volumeFloat);
  new(&currentPlayer)Player(widthInt,heightInt,fullscreenBool,volumeFloat);
}