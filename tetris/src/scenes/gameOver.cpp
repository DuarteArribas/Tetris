void newGame(){
  for(int i=0;i<25;i++){
    for(int j=0;j<10;j++){
      board[i][j]=false;
    }
  }

  nextPiece=Tetrominoes::getInitialPiece(&lastPiece);
  new(&i)Tetrominoes(nextPiece,board);
}

void gameOver(int *lastPiece,bool isGameOver){
  for(int i=0;i<25;i++){
    for(int j=0;j<10;j++){
      board[i][j]=false;
    }
  }
  printf("aqui!!!\n");
  for(int i=20;i<25;i++){
    for(int j=0;j<10;j++){
      if(board[i][j]){
        printf("lol tenho aqui um valor\n");
      }
    }
  }
  printf("aqui!!!\n");

  switchToHold=firstSwitch=false, canHold=true;
  *lastPiece=0;
  nextPiece=Tetrominoes::getInitialPiece(lastPiece);          
  new(&i)Tetrominoes(nextPiece,board);
  pieceHold=TETROMINO_ID::NONE;
  engine->drop();
  currentPlayer.setScore(currentPlayer.getScore()+score);
  if(currentPlayer.getHighscore()<score){
    currentPlayer.setHighscore(score);
  }
  isSpeed=false;
  if(save.length()!=0){
    updateScore(currentPlayer.getScore(),currentPlayer.getHighscore());
  }
  latestScore=score;
  score=0;
  level=1;
  numberOfRowsDestroyed=0;
  numberOfTotalRowsDestroyed=0;
  backToBack=false;
  canPlayMusic=true;
  canPlayMusic2=true;
  engine=createIrrKlangDevice();
  engine->setSoundVolume(currentPlayer.getVolume());
  if(isGameOver){
    engine->play2D("music/gameOver.ogg", false);
    scene=Scene::GAME_OVER;
  }
  else{
    scene=Scene::MENU;
  }
}