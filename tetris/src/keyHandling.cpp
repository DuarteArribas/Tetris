/*
  ----------- Handles the interaction of the user with the game -----------
*/
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
  switch(scene){
    case Scene::INTRO:
      //click any key: go to saves menu
      for(size_t i=0; i<348; i++){
        if(i!=256){
          if(key==i&&action==GLFW_PRESS) {
            engine->play2D("music/enter.ogg", false);
            scene=Scene::SAVES;
          }
        }
        //exit the game
        else if(key==GLFW_KEY_ESCAPE&&action==GLFW_PRESS){
          exitGame=true;
        }
      }
      break;
    case Scene::SAVES:
      //go to the intro menu
      if(key==GLFW_KEY_ESCAPE&&action==GLFW_PRESS){
        engine->play2D("music/exit.ogg", false);
        scene=Scene::INTRO;
      }
      //change between options
      if(key==GLFW_KEY_DOWN&&action==GLFW_PRESS){
        engine->play2D("music/menu.ogg", false);
        if(optionMenuSave>4){
          optionMenuSave=0;
        }
        else{
          optionMenuSave++;
        }
      }
      if(key==GLFW_KEY_UP&&action==GLFW_PRESS){
        engine->play2D("music/menu.ogg", false);
        if(optionMenuSave<1){
          optionMenuSave=5;
        }
        else{
          optionMenuSave--;
        }
      }
      //load save and go to main menu
      if(key==GLFW_KEY_ENTER&&action==GLFW_PRESS){
        engine->play2D("music/enter.ogg", false);
        skin=0;
        ifstream fin;
        if(optionMenuSave!=5){
          save="saves/save"+std::to_string(optionMenuSave+1)+".txt";
          fin.open(save);
          string scoreTemp,highscoreTemp;
          int count=0;
          while(!fin.eof()){
            if(count==0){
              getline(fin,scoreTemp);
            }
            else if(count==1){
              getline(fin,highscoreTemp);
            }
            count++;
          }
          currentPlayer.setScore(std::stoll(scoreTemp));
          currentPlayer.setHighscore(std::stoll(highscoreTemp));
        }
        else{
          save="";
          currentPlayer.setScore(0);
        }
        scene=Scene::MENU; 
      }
      break;
    case Scene::MENU:
      //go to saves menu
      if(key==GLFW_KEY_ESCAPE&&action==GLFW_PRESS){
        engine->play2D("music/exit.ogg", false);
        if(optionMenu==4){
          engine->drop();
          engine=createIrrKlangDevice();
        }
        scene=Scene::SAVES;
      }
      //change between options
      if(key==GLFW_KEY_UP&&action==GLFW_PRESS){
        engine->play2D("music/menu.ogg", false);
        if(optionMenu==4){
          optionMenu=2;
          engine->drop();
          engine=createIrrKlangDevice();
          engine->setSoundVolume(currentPlayer.getVolume());
        }
        else if(optionMenu<1){
          optionMenu=3;
        }
        else{
          optionMenu--;
        }
      }
      if(key==GLFW_KEY_DOWN&&action==GLFW_PRESS){
        engine->play2D("music/menu.ogg", false);
        if(optionMenu==4){
          optionMenu=0;
          engine->drop();
          engine=createIrrKlangDevice();
          engine->setSoundVolume(currentPlayer.getVolume());
        }
        else if(optionMenu>2){
          optionMenu=0;
        }
        else{
          optionMenu++;
        }
      }
      //rickroll
      if(key==GLFW_KEY_R&&action==GLFW_PRESS){
        optionMenu=4;
        engine->drop();
        engine=createIrrKlangDevice();
        engine->setSoundVolume(currentPlayer.getVolume());
        engine->play2D("music/quack.ogg", false);
        engine->play2D("music/rickRoll.ogg", true);
      }
      //go to the selected scene
      if(key==GLFW_KEY_ENTER&&action==GLFW_PRESS){
        engine->play2D("music/enter.ogg", false);
        switch(optionMenu){
          case 0:
            scene=Scene::MUSIC_SELECTION;
            break;
          case 1:
            scene=Scene::PROFILE;
            break;
          case 2:
            scene=Scene::SKINS;
            break;
          case 3:
            scene=Scene::SUBMENU;
            break;
          case 4:
            engine->drop();
            engine=createIrrKlangDevice();
            scene=Scene::SUBMENU; 
            break;
        }
      }
      break;
    case Scene::PROFILE:
      //go to main menu
      if(key==GLFW_KEY_ESCAPE&&action==GLFW_PRESS){
        engine->play2D("music/exit.ogg", false);
        scene=Scene::MENU;
      }
      break;
    case Scene::SKINS:
      //go to main menu
      if(key==GLFW_KEY_ESCAPE&&action==GLFW_PRESS){
        engine->play2D("music/exit.ogg", false);
        optionSkins=0;
        scene=Scene::MENU;
      }
      
      //set initial option
      if(Player::rank(currentPlayer.getScore())=='U'||Player::rank(currentPlayer.getScore())=='B'){
        optionSkins=0;
      }
      else if(Player::rank(currentPlayer.getScore())=='S'){
        if(key==GLFW_KEY_LEFT&&action==GLFW_PRESS||key==GLFW_KEY_RIGHT&&action==GLFW_PRESS){
          engine->play2D("music/menu.ogg", false);
          if(optionSkins==1){
            optionSkins=0;
          }
          else{
            optionSkins=1;
          }
        }
      }
      else{
        if(key==GLFW_KEY_LEFT&&action==GLFW_PRESS){
          engine->play2D("music/menu.ogg", false);
          if(optionSkins<1){
            optionSkins=2;
          }
          else{
            optionSkins--;
          }
        }
        if(key==GLFW_KEY_RIGHT&&action==GLFW_PRESS){
          engine->play2D("music/menu.ogg", false);
          if(optionSkins>1){
            optionSkins=0;
          }
          else{
            optionSkins++;
          }
        }
      }
      //select skin and go to main menu
      if(key==GLFW_KEY_ENTER&&action==GLFW_PRESS){
        if(optionSkins==0){
          engine->play2D("music/8bitSound.ogg", false);
        }
        else if(optionSkins==1){
          engine->play2D("music/doomSound.ogg", false);
        }
        else if(optionSkins==2){
          engine->play2D("music/minecraftSound.ogg", false);
        }
        skin=optionSkins;
        optionSkins=0;
        scene=Scene::MENU;
      }
      break;
    case Scene::SUBMENU:
      //go to main menu
      if(key==GLFW_KEY_ESCAPE&&action==GLFW_PRESS) {
        engine->play2D("music/exit.ogg", false);
        scene=Scene::MENU;
        isInSubSubMenu=false;
      }
      //handles the settings of subsubmenus
      if(isInSubSubMenu){
        //goes back to settings
        if(key==GLFW_KEY_BACKSPACE&&action==GLFW_PRESS){
          engine->play2D("music/exit.ogg", false);
          isInSubSubMenu=false;
        }
        //handles settings
        switch(optionSubMenu){
          //fullscreen
          case 0:
            if(!currentPlayer.getIsFullscreen()){
              currentPlayer.setIsFullscreen(true);
              updateGeneralSettings(std::to_string(currentPlayer.getWindowWidth()),std::to_string(currentPlayer.getWindowHeight()),"true",std::to_string(currentPlayer.getVolume()));
              buildWindow(currentPlayer.getWindowWidth(),currentPlayer.getWindowHeight(),windowTitle,1,true);
            }
            else{
              currentPlayer.setIsFullscreen(false);
              updateGeneralSettings(std::to_string(currentPlayer.getWindowWidth()),std::to_string(currentPlayer.getWindowHeight()),"false",std::to_string(currentPlayer.getVolume()));
              buildWindow(currentPlayer.getWindowWidth(),currentPlayer.getWindowHeight(),windowTitle,1,false);
            }
            needsToRebuild=true;
            isInSubSubMenu=false;
            break;
          //resolutions
          case 1:{
            if(key==GLFW_KEY_RIGHT&&action==GLFW_PRESS){
              engine->play2D("music/menu.ogg", false);
              canRebuildWindow=true;
              if(subOptionSubMenu<3){
                (subOptionSubMenu)++;
              }
              else{
                subOptionSubMenu=0;
              }
            }
            if(key==GLFW_KEY_LEFT&&action==GLFW_PRESS){
              engine->play2D("music/menu.ogg", false);
              canRebuildWindow=true;
              if(subOptionSubMenu>0){
                (subOptionSubMenu)--;
              }
              else{
                subOptionSubMenu=3;
              }
            }
            if(canRebuildWindow){
              switch(subOptionSubMenu){
              case 0:
                currentPlayer.setWindowWidth(700);
                currentPlayer.setWindowHeight(700);
                updateGeneralSettings("700","700",(currentPlayer.getIsFullscreen()?"true":"false"),std::to_string(currentPlayer.getVolume()));
                buildWindow(currentPlayer.getWindowWidth(),currentPlayer.getWindowHeight(),windowTitle,1,false);
                canRebuildWindow=false;
                break;
              case 1: 
                currentPlayer.setWindowWidth(800);
                currentPlayer.setWindowHeight(800);
                updateGeneralSettings("800","800",(currentPlayer.getIsFullscreen()?"true":"false"),std::to_string(currentPlayer.getVolume()));
                buildWindow(currentPlayer.getWindowWidth(),currentPlayer.getWindowHeight(),windowTitle,1,false);
                canRebuildWindow=false;
                break;
              case 2: 
                currentPlayer.setWindowWidth(900);
                currentPlayer.setWindowHeight(900);
                updateGeneralSettings("900","900",(currentPlayer.getIsFullscreen()?"true":"false"),std::to_string(currentPlayer.getVolume()));
                buildWindow(currentPlayer.getWindowWidth(),currentPlayer.getWindowHeight(),windowTitle,1,false);
                canRebuildWindow=false;
                break;
              case 3:
                currentPlayer.setWindowWidth(1000);
                currentPlayer.setWindowHeight(1000);
                updateGeneralSettings("1000","1000",(currentPlayer.getIsFullscreen()?"true":"false"),std::to_string(currentPlayer.getVolume()));
                buildWindow(currentPlayer.getWindowWidth(),currentPlayer.getWindowHeight(),windowTitle,1,false);
                canRebuildWindow=false;
                break;
              }
            }
            needsToRebuild=true;
            break;
        }
        //audio volume
        case 2:
          if((key==GLFW_KEY_LEFT&&action==GLFW_PRESS)&&currentPlayer.getVolume()>0){
            currentPlayer.setVolume(currentPlayer.getVolume()-0.1f);
            engine->setSoundVolume(currentPlayer.getVolume());
            engine->play2D("music/test.ogg", false);
            updateGeneralSettings(std::to_string(currentPlayer.getWindowWidth()),std::to_string(currentPlayer.getWindowHeight()),(currentPlayer.getIsFullscreen()?"true":"false"),std::to_string(currentPlayer.getVolume()));
          }
          else if((key==GLFW_KEY_RIGHT&&action==GLFW_PRESS)&&currentPlayer.getVolume()<1){
            currentPlayer.setVolume(currentPlayer.getVolume()+0.1f);
            engine->setSoundVolume(currentPlayer.getVolume());
            engine->play2D("music/test.ogg", false);
            updateGeneralSettings(std::to_string(currentPlayer.getWindowWidth()),std::to_string(currentPlayer.getWindowHeight()),(currentPlayer.getIsFullscreen()?"true":"false"),std::to_string(currentPlayer.getVolume()));
          }
          else if(key==GLFW_KEY_M&&action==GLFW_PRESS){
            currentPlayer.setVolume(0.0f);
            engine->setSoundVolume(currentPlayer.getVolume());
            updateGeneralSettings(std::to_string(currentPlayer.getWindowWidth()),std::to_string(currentPlayer.getWindowHeight()),(currentPlayer.getIsFullscreen()?"true":"false"),std::to_string(currentPlayer.getVolume()));
          }
          break;
        }
      }
      //change between options
      else{
        if(key==GLFW_KEY_DOWN&&action==GLFW_PRESS){
          engine->play2D("music/menu.ogg", false);
          if(optionSubMenu<2){
            (optionSubMenu)++;
          }
          else{
            optionSubMenu=0;
          }
        }
        if(key==GLFW_KEY_UP&&action==GLFW_PRESS){
          engine->play2D("music/menu.ogg", false);
          if(optionSubMenu>0){
            (optionSubMenu)--;
          }
          else{
            optionSubMenu=2;
          }
        }
        //enter subsubmenu
        if((key==GLFW_KEY_ENTER&&action==GLFW_PRESS)&&!isInSubSubMenu){
          engine->play2D("music/enter.ogg", false);
          isInSubSubMenu=true;
        }
      }
      break;
    case Scene::PLAY:
      //moves the piece down
      if(key==GLFW_KEY_DOWN||key==GLFW_KEY_S){
        if((!i.willCollide(board,VERTICAL))&&(!i.willCollideEdges(board,VERTICAL))){
          i.moveDown(board);
        }
      }
      //hardDrops the piece
      if(key==GLFW_KEY_SPACE&&action==GLFW_PRESS){
        engine->play2D("music/hardrop.ogg", false);
        hardDrop=true;
        while((!i.willCollide(board,VERTICAL))&&(!i.willCollideEdges(board,VERTICAL))){
          i.moveDown(board);
        }
      }
      //moves the piece to the left
      if((key==GLFW_KEY_LEFT&&action==GLFW_PRESS)||(key==GLFW_KEY_A&&action==GLFW_PRESS)){
        if((!i.willCollide(board,LEFT))&&(!i.willCollideEdges(board,LEFT))){
          i.moveLeft(board);
        }
      }
      //moves the piece to the right
      if((key==GLFW_KEY_RIGHT&&action==GLFW_PRESS)||(key==GLFW_KEY_D&&action==GLFW_PRESS)){
        if((!i.willCollide(board,RIGHT))&&(!i.willCollideEdges(board,RIGHT))){
          i.moveRight(board);
        }
      }
      //rotates the piece clockwise
      if((key==GLFW_KEY_Z&&action==GLFW_PRESS)||(key==GLFW_KEY_RIGHT_CONTROL&&action==GLFW_PRESS)){
        if(!i.willCollideOnRotateCW(board)){
          i.rotateClockwise(board);
        }
      }
      //rotates the piece counterclockwise
      if((key==GLFW_KEY_X&&action==GLFW_PRESS)||(key==GLFW_KEY_RIGHT_SHIFT&&action==GLFW_PRESS)){
        if(!i.willCollideOnRotateCCW(board)){
          i.rotateCounterClockwise(board);
        }
      }
      //holds or deHolds the piece
      if(key==GLFW_KEY_C&&action==GLFW_PRESS){
        if(pieceHold==TETROMINO_ID::NONE){
          if(canHold){
            i.updateValues(board,false);
            pieceHold=i.getTetrominoID();
            firstSwitch=true;
            canHold=false;
          }
        }
        else{
          i.updateValues(board,false);
          switchToHold=true;
        }
      }
      //pauses the game
      if(key==GLFW_KEY_ESCAPE&&action==GLFW_PRESS){
        engine->play2D("music/enter.ogg", false);
        pause();
      }
      //allows mouse movement and camera rotation
      if(key==GLFW_KEY_I&&action==GLFW_PRESS){
        if(abs(mouseSpeed-0.002)<0.001){
          mouseSpeed=0;
        }
        else{
          mouseSpeed=0.002;
        }
      }
      break;
    case Scene::GAME_OVER:
      //go to main menu
      if(key==GLFW_KEY_ESCAPE&&action==GLFW_PRESS){
        engine->play2D("music/exit.ogg", false);
        optionMenuGameOver=0;
        scene=Scene::MENU;
      }
      //changes between options
      if(key==GLFW_KEY_DOWN&&action==GLFW_PRESS){
        engine->play2D("music/menu.ogg", false);
        if(optionMenuGameOver<1){
          optionMenuGameOver=1;
        }
        else{
          optionMenuGameOver=0;
        }
      }
      if(key==GLFW_KEY_UP&&action==GLFW_PRESS){
        engine->play2D("music/menu.ogg", false);
        if(optionMenuGameOver>0){
          optionMenuGameOver=0;
        }
        else{
          optionMenuGameOver=1;
        }
      }
      //goes back to menu or music selection
      if(key==GLFW_KEY_ENTER&&action==GLFW_PRESS){
        engine->play2D("music/enter.ogg", false);
        if(optionMenuGameOver==1){
          scene=Scene::MENU;
          optionMenuGameOver=0;
        }
        else if(optionMenuGameOver==0){
          scene=Scene::MUSIC_SELECTION;
        }
      }      
      break;
    case Scene::PAUSE:
      //go back to the game
      if(key==GLFW_KEY_ESCAPE&&action==GLFW_PRESS){
        engine->play2D("music/exit.ogg", false);
        optionMenuPause=0;
        scene=Scene::PLAY;
      }
      //changes between options
      if(key==GLFW_KEY_DOWN&&action==GLFW_PRESS){
        engine->play2D("music/menu.ogg", false);
        if(optionMenuPause<1){
          optionMenuPause=1;
        }
        else{
          optionMenuPause=0;
        }
      }
      if(key==GLFW_KEY_UP&&action==GLFW_PRESS){
        engine->play2D("music/menu.ogg", false);
        if(optionMenuPause>0){
          optionMenuPause=0;
        }
        else{
          optionMenuPause=1;
        }
      }
      //go back to the game or game over
      if(key==GLFW_KEY_ENTER&&action==GLFW_PRESS){
        engine->play2D("music/enter.ogg", false);
        if(optionMenuPause==1){
          gameOver(&lastPiece,false);
          optionMenuPause=0;
        }
        else if(optionMenuPause==0){
          scene=Scene::PLAY;
        }
      }
      break;
    case Scene::MUSIC_SELECTION:
      //go to main menu
      if(key==GLFW_KEY_ESCAPE&&action==GLFW_PRESS){
        engine->play2D("music/exit.ogg", false);
        optionMusicSelection=0;
        scene=Scene::MENU;
      }
      //changes between options
      if(key==GLFW_KEY_LEFT&&action==GLFW_PRESS){
        engine->play2D("music/menu.ogg", false);
        if(optionMusicSelection<1){
          optionMusicSelection=1;
        }
        else{
          optionMusicSelection=0;
        }
      }
      if(key==GLFW_KEY_RIGHT&&action==GLFW_PRESS){
        engine->play2D("music/menu.ogg", false);
        if(optionMusicSelection>0){
          optionMusicSelection=0;
        }
        else{
          optionMusicSelection=1;
        }
      }
      //choose the music and start the game
      if(key==GLFW_KEY_ENTER&&action==GLFW_PRESS){
        engine->play2D("music/enter.ogg", false);
        if(optionMusicSelection==0){
          selectedMusic="music/tetrisThemeA.ogg";
          selectedMusicSpeed="music/tetrisThemeASpeed.ogg";
          scene=Scene::PLAY;
        }
        else if(optionMusicSelection==1){
          selectedMusic="music/tetrisThemeB.ogg";
          selectedMusicSpeed="music/tetrisThemeBSpeed.ogg";
          scene=Scene::PLAY;
          optionMusicSelection=0;
        }
      }
      break;
  }
}