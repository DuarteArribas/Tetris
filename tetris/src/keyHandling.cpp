void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
  switch(scene){
  case Scene::INTRO:
    for(size_t i=0; i<348; i++){
      if(i!=256){
        if(key==i&&action==GLFW_PRESS) {
          scene=Scene::SAVES;
        }
      }
      else if(key==GLFW_KEY_ESCAPE&&action==GLFW_PRESS) {
        exitGame=true;
      }
    }
    break;
  case Scene::SAVES:
    if(key==GLFW_KEY_ESCAPE&&action==GLFW_PRESS){
      scene=Scene::INTRO;
    }
    if(key==GLFW_KEY_DOWN&&action==GLFW_PRESS){
      if(optionMenuSave>4){
        optionMenuSave=0;
      }
      else{
        optionMenuSave++;
      }
    }
    if(key==GLFW_KEY_UP&&action==GLFW_PRESS){
      if(optionMenuSave<1){
        optionMenuSave=5;
      }
      else{
        optionMenuSave--;
      }
    }

    if(key==GLFW_KEY_ENTER&&action==GLFW_PRESS){
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
    if(key==GLFW_KEY_ESCAPE&&action==GLFW_PRESS){
      if(optionMenu==4){
        engine->drop();
        engine=createIrrKlangDevice();
      }
      scene=Scene::SAVES;
    }

    if(key==GLFW_KEY_UP&&action==GLFW_PRESS){
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

    if(key==GLFW_KEY_R&&action==GLFW_PRESS){
      optionMenu=4;
      engine->drop();
      engine=createIrrKlangDevice();
      engine->setSoundVolume(currentPlayer.getVolume());
      engine->play2D("music/rickRoll.ogg", true);
    }

    if(key==GLFW_KEY_ENTER&&action==GLFW_PRESS){
      switch(optionMenu){
      case 0:
        scene=Scene::MUSIC_SELECTION;
        horizontalAngle=15.691002;
        verticalAngle=-6.0f;
        mouseSpeed=0;
        printBoard(board);
        break;
      case 3:
      case 4:
        engine->drop();
        engine=createIrrKlangDevice();
        scene=Scene::SUBMENU; 
        break;
      }
    }

    break;
  case Scene::SUBMENU:
    if(key==GLFW_KEY_ESCAPE&&action==GLFW_PRESS) {
      scene=Scene::MENU;
      isInSubSubMenu=false;
    }
    if(isInSubSubMenu){
      if(key==GLFW_KEY_BACKSPACE&&action==GLFW_PRESS){
        isInSubSubMenu=false;
      }
      switch(optionSubMenu){
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
      case 1:{
        if(key==GLFW_KEY_RIGHT&&action==GLFW_PRESS){
          canRebuildWindow=true;
          if(subOptionSubMenu<3){
            (subOptionSubMenu)++;
          }
          else{
            subOptionSubMenu=0;
          }
        }
        if(key==GLFW_KEY_LEFT&&action==GLFW_PRESS){
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
    else{
      if(key==GLFW_KEY_DOWN&&action==GLFW_PRESS){
        if(optionSubMenu<2){
          (optionSubMenu)++;
        }
        else{
          optionSubMenu=0;
        }
      }
      if(key==GLFW_KEY_UP&&action==GLFW_PRESS){
        if(optionSubMenu>0){
          (optionSubMenu)--;
        }
        else{
          optionSubMenu=2;
        }
      }
      if((key==GLFW_KEY_ENTER&&action==GLFW_PRESS)&&!isInSubSubMenu){
        isInSubSubMenu=true;
      }
    }
    break;
  case Scene::PLAY:
    if(key==GLFW_KEY_DOWN){
      if((!i.willCollide(board,VERTICAL))&&(!i.willCollideEdges(board,VERTICAL))){
        i.moveDown(board);
        printBoard(board);
      }
    }
    if(key==GLFW_KEY_SPACE&&action==GLFW_PRESS){
      hardDrop=true;
      while((!i.willCollide(board,VERTICAL))&&(!i.willCollideEdges(board,VERTICAL))){
        i.moveDown(board);
      }
      printBoard(board);
    }
    if(key==GLFW_KEY_LEFT&&action==GLFW_PRESS){
      if((!i.willCollide(board,LEFT))&&(!i.willCollideEdges(board,LEFT))){
        i.moveLeft(board);
        printBoard(board); 
      }
    }
    if(key==GLFW_KEY_RIGHT&&action==GLFW_PRESS){
      if((!i.willCollide(board,RIGHT))&&(!i.willCollideEdges(board,RIGHT))){
        i.moveRight(board);
        printBoard(board);
      }
    }
    if(key==GLFW_KEY_Z&&action==GLFW_PRESS){
      if(!i.willCollideOnRotateCW(board)){
        i.rotateClockwise(board);
        printBoard(board);  
      }
    }
    if(key==GLFW_KEY_X&&action==GLFW_PRESS){
      if(!i.willCollideOnRotateCCW(board)){
        i.rotateCounterClockwise(board);
        printBoard(board);
      }
    }
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
    if(key==GLFW_KEY_ESCAPE&&action==GLFW_PRESS){
      pause();
    }
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
    if(key==GLFW_KEY_DOWN&&action==GLFW_PRESS){
      if(optionMenuGameOver<1){
        optionMenuGameOver=1;
      }
      else{
        optionMenuGameOver=0;
      }
    }
    if(key==GLFW_KEY_UP&&action==GLFW_PRESS){
      if(optionMenuGameOver>0){
        optionMenuGameOver=0;
      }
      else{
        optionMenuGameOver=1;
      }
    }

    if(key==GLFW_KEY_ENTER&&action==GLFW_PRESS){
      if(optionMenuGameOver==1){
        scene=Scene::MENU;
        optionMenuGameOver=0;
      }
      else if(optionMenuGameOver==0){
        scene=Scene::MUSIC_SELECTION;
      }
    }

    if(key==GLFW_KEY_ESCAPE&&action==GLFW_PRESS){
      optionMenuGameOver=0;
      scene=Scene::MENU;
    }
    break;
  case Scene::PAUSE:
    if(key==GLFW_KEY_DOWN&&action==GLFW_PRESS){
      if(optionMenuPause<1){
        optionMenuPause=1;
      }
      else{
        optionMenuPause=0;
      }
    }
    if(key==GLFW_KEY_UP&&action==GLFW_PRESS){
      if(optionMenuPause>0){
        optionMenuPause=0;
      }
      else{
        optionMenuPause=1;
      }
    }

    if(key==GLFW_KEY_ENTER&&action==GLFW_PRESS){
      if(optionMenuPause==1){
        gameOver(&lastPiece,false);
        optionMenuPause=0;
      }
      else if(optionMenuPause==0){
        scene=Scene::PLAY;
      }
    }

    if(key==GLFW_KEY_ESCAPE&&action==GLFW_PRESS){
      optionMenuPause=0;
      scene=Scene::PLAY;
    }
    break;
  case Scene::MUSIC_SELECTION:
    if(key==GLFW_KEY_LEFT&&action==GLFW_PRESS){
      if(optionMusicSelection<1){
        optionMusicSelection=1;
      }
      else{
        optionMusicSelection=0;
      }
    }
    if(key==GLFW_KEY_RIGHT&&action==GLFW_PRESS){
      if(optionMusicSelection>0){
        optionMusicSelection=0;
      }
      else{
        optionMusicSelection=1;
      }
    }

    if(key==GLFW_KEY_ENTER&&action==GLFW_PRESS){
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

    if(key==GLFW_KEY_ESCAPE&&action==GLFW_PRESS){
      optionMusicSelection=0;
      scene=Scene::MENU;
    }
    break;
  }
}