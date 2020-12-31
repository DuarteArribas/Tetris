/*
  ----------- Shows the game over menu -----------
*/
void showGameOverMenu(){
  setInitialCameraPosition(0.014757f,0.01f,2.392263,0.0f,0.0f,15.7,-6.285,&t);
  
  //show selected game over menu option
  if(optionMenuGameOver==0){
    DrawObjects::draw(&gameOverPlayInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
  }
  else if(optionMenuGameOver==1){
    DrawObjects::draw(&gameOverBackInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
  }

  //draw score and highscore
  t9.translation=glm::mat4(1.0f);
  t9.scaling=glm::mat4(1.0f);
  t9.scaling=glm::scale(t9.scaling,glm::vec3(0.2f,0.2f,0.2f));
  CreateNumber(latestScore,0.1f,.6f,0.37f,0.0f);
  CreateNumber(currentPlayer.getHighscore(),0.1f,.6f,0.0f,0.0f);

  //draw score text
  t5.scaling=glm::mat4(1.0f);
  t5.translation=glm::mat4(1.0f);
  t5.translation=glm::translate(t5.translation,glm::vec3(0.33f,0.37f,0.0f));
  t5.scaling=glm::scale(t5.scaling,glm::vec3(0.15f,0.15f,0.15f));
  DrawObjects::draw(&scoreInfo,t5,object3DShaders,GL_TRIANGLES,&scoreObject.vertices);

  //draw highscore
  t10.scaling=glm::mat4(1.0f);
  t10.translation=glm::mat4(1.0f);
  t10.translation=glm::translate(t5.translation,glm::vec3(-0.1f,-0.35f,0.0f));
  t10.scaling=glm::scale(t5.scaling,glm::vec3(1.0f,1.0f,1.0f));
  DrawObjects::draw(&highscoreInfo,t10,object3DShaders,GL_TRIANGLES,&highscoreObject.vertices);
}

/*
  ----------- Resets the game boards -----------
*/
void resetBoards(){
  //reset board
  for(int i=0;i<25;i++){
    for(int j=0;j<10;j++){
      board[i][j]=false;
    }
  }
  //reset secondary board (the tetronimo specified board)
  for(int i=0;i<25;i++){
    for(int j=0;j<10;j++){
      boardPieces[i][j]=TETROMINO_ID::NONE;
    }
  }
}

/*
  ----------- Starts a new game -----------
*/
void newGame(){
  resetBoards();
  //generate new random piece
  nextPiece=Tetrominoes::getInitialPiece(&lastPiece);
  //instanciate new piece
  new(&i)Tetrominoes(nextPiece,board);
}

/*
  ----------- Opengl libraries and namespaces -----------
*/
void gameOver(int *lastPiece,bool isGameOver){
  resetBoards();
  //generate new random piece
  nextPiece=Tetrominoes::getInitialPiece(lastPiece);
  //instanciate new piece
  new(&i)Tetrominoes(nextPiece,board);
  //stop the music and reinitialize it
  engine->drop();
  engine=createIrrKlangDevice();
  engine->setSoundVolume(currentPlayer.getVolume());
  //save score and check for highscore
  currentPlayer.setScore(currentPlayer.getScore()+score);
  if(currentPlayer.getHighscore()<score){
    currentPlayer.setHighscore(score);
  }
  //save score to file unless playing as a guest
  if(save.length()!=0){
    updateScore(currentPlayer.getScore(),currentPlayer.getHighscore());
  }
  //reset game variables
  switchToHold=firstSwitch=false, canHold=true;
  pieceHold=TETROMINO_ID::NONE;
  *lastPiece=0;
  isSpeed=false;
  latestScore=score;
  score=0;
  level=1;
  numberOfRowsDestroyed=0;
  numberOfTotalRowsDestroyed=0;
  backToBack=false;
  canPlayMusic=true;
  canPlayMusic2=true;
  canGenerateNewPiece=true;
  //change scenes
  if(isGameOver){
    engine->play2D("music/gameOver.ogg", false);
    scene=Scene::GAME_OVER;
  }
  else{
    scene=Scene::MENU;
  }
}