/*
  ----------- Shows the play menu and handles the play scene-----------
*/
void showPlayMenu(){
  //score and level numbers
  t9.translation=glm::mat4(1.0f);
  t9.scaling=glm::mat4(1.0f);
  t9.scaling=glm::scale(t9.scaling,glm::vec3(2.5f,2.5f,2.5f));
  CreateNumber(score,2.0f,13.8f,4.5f,0.0f);
  CreateNumber(level,2.0f,-5.5f,4.5f,0.0f);
  //draw sky        
  t7.translation=glm::mat4(1.0f);
  t7.scaling=glm::mat4(1.0f);
  t7.scaling=glm::scale(t7.scaling,glm::vec3(5000.0f,5000.0f,5000.0f));
  DrawObjects::draw(&skyInfo,t7,object3DShaders,GL_TRIANGLES,&skyObject.vertices);
  //draw floor
  t8.translation=glm::mat4(1.0f);
  t8.scaling=glm::mat4(1.0f);
  t8.translation=glm::translate(t8.translation,glm::vec3(0.0f,-2000.0f,0.0f));
  t8.scaling=glm::scale(t8.scaling,glm::vec3(5000.0f,5000.0f,5000.0f));
  DrawObjects::draw(&floorInfo,t8,object3DShaders,GL_TRIANGLES,&floorObject.vertices);
  //draw wall
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
  //draw next text
  t3.scaling=glm::mat4(1.0f);
  t3.translation=glm::mat4(1.0f);
  t3.translation=glm::translate(t3.translation,glm::vec3(15.5f,23.7f,0.0f));
  t3.scaling=glm::scale(t3.scaling,glm::vec3(1.5f,1.5f,1.5f));
  DrawObjects::draw(&nextInfo,t3,object3DShaders,GL_TRIANGLES,&nextObject.vertices);
  //draw hold text
  t4.scaling=glm::mat4(1.0f);
  t4.translation=glm::mat4(1.0f);
  t4.translation=glm::translate(t4.translation,glm::vec3(-4.0f,23.7f,0.0f));
  t4.scaling=glm::scale(t4.scaling,glm::vec3(1.5f,1.5f,1.5f));
  DrawObjects::draw(&holdInfo,t4,object3DShaders,GL_TRIANGLES,&holdObject.vertices);
  //draw score text
  t5.scaling=glm::mat4(1.0f);
  t5.translation=glm::mat4(1.0f);
  t5.translation=glm::translate(t5.translation,glm::vec3(15.5f,7.0f,0.0f));
  t5.scaling=glm::scale(t5.scaling,glm::vec3(1.5f,1.5f,1.5f));
  DrawObjects::draw(&scoreInfo,t5,object3DShaders,GL_TRIANGLES,&scoreObject.vertices);
  //draw level text
  t6.scaling=glm::mat4(1.0f);
  t6.translation=glm::mat4(1.0f);
  t6.translation=glm::translate(t6.translation,glm::vec3(-4.0f,7.0f,0.0f));
  t6.scaling=glm::scale(t6.scaling,glm::vec3(1.5f,1.5f,1.5f));
  DrawObjects::draw(&lvlInfo,t6,object3DShaders,GL_TRIANGLES,&lvlObject.vertices);
  //generate new piece
  if(canGenerateNewPiece){
    nextPiece=Tetrominoes::getRandomPiece(8,&lastPiece); 
    canGenerateNewPiece=false;
  }
  //reset speed
  speed=0;
  position=glm::vec3(6.5f,10.0f,40.45f);
  //draw pieces
  t2.translation=glm::mat4(1.0f);
  t2.scaling=glm::mat4(1.0f);
  for(int k=20;k>0;k--){
    for(int j=0;j<10;j++){
      if(board[k][j]){
        t2.translation=glm::mat4(1.0f);
        t2.translation=glm::translate(t2.translation,glm::vec3((float)j*1.3,(float)k*1.3,0.0f));
        if(skin==0){
          if(boardPieces[k][j]==TETROMINO_ID::I){
            DrawObjects::draw(&skin0IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
          }
          else if(boardPieces[k][j]==TETROMINO_ID::J){
            DrawObjects::draw(&skin0JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
          }
          else if(boardPieces[k][j]==TETROMINO_ID::L){
            DrawObjects::draw(&skin0LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
          }
          else if(boardPieces[k][j]==TETROMINO_ID::T){
            DrawObjects::draw(&skin0TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
          }
          else if(boardPieces[k][j]==TETROMINO_ID::S){
            DrawObjects::draw(&skin0SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
          }
          else if(boardPieces[k][j]==TETROMINO_ID::Z){
            DrawObjects::draw(&skin0ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
          }
          else if(boardPieces[k][j]==TETROMINO_ID::O){
            DrawObjects::draw(&skin0OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
          }
          else{
            switch(i.getTetrominoID()){
            case TETROMINO_ID::I:
              DrawObjects::draw(&skin0IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
              break;
            case TETROMINO_ID::J:
              DrawObjects::draw(&skin0JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
              break;
            case TETROMINO_ID::L:
              DrawObjects::draw(&skin0LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
              break;
            case TETROMINO_ID::T:
              DrawObjects::draw(&skin0TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
              break;
            case TETROMINO_ID::S:
              DrawObjects::draw(&skin0SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
              break;
            case TETROMINO_ID::Z:
              DrawObjects::draw(&skin0ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
              break;
            case TETROMINO_ID::O:
              DrawObjects::draw(&skin0OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
              break;
            }
          }
        }
        else if(skin==1){
          if(boardPieces[k][j]==TETROMINO_ID::I){
            DrawObjects::draw(&skin1IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
          }
          else if(boardPieces[k][j]==TETROMINO_ID::J){
            DrawObjects::draw(&skin1JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
          }
          else if(boardPieces[k][j]==TETROMINO_ID::L){
            DrawObjects::draw(&skin1LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
          }
          else if(boardPieces[k][j]==TETROMINO_ID::T){
            DrawObjects::draw(&skin1TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
          }
          else if(boardPieces[k][j]==TETROMINO_ID::S){
            DrawObjects::draw(&skin1SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
          }
          else if(boardPieces[k][j]==TETROMINO_ID::Z){
            DrawObjects::draw(&skin1ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
          }
          else if(boardPieces[k][j]==TETROMINO_ID::O){
            DrawObjects::draw(&skin1OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
          }
          else{
            switch(i.getTetrominoID()){
            case TETROMINO_ID::I:
              DrawObjects::draw(&skin1IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
              break;
            case TETROMINO_ID::J:
              DrawObjects::draw(&skin1JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
              break;
            case TETROMINO_ID::L:
              DrawObjects::draw(&skin1LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
              break;
            case TETROMINO_ID::T:
              DrawObjects::draw(&skin1TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
              break;
            case TETROMINO_ID::S:
              DrawObjects::draw(&skin1SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
              break;
            case TETROMINO_ID::Z:
              DrawObjects::draw(&skin1ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
              break;
            case TETROMINO_ID::O:
              DrawObjects::draw(&skin1OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
              break;
            }
          }
        }
        else if(skin==2){
          if(boardPieces[k][j]==TETROMINO_ID::I){
            DrawObjects::draw(&skin2IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
          }
          else if(boardPieces[k][j]==TETROMINO_ID::J){
            DrawObjects::draw(&skin2JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
          }
          else if(boardPieces[k][j]==TETROMINO_ID::L){
            DrawObjects::draw(&skin2LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
          }
          else if(boardPieces[k][j]==TETROMINO_ID::T){
            DrawObjects::draw(&skin2TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
          }
          else if(boardPieces[k][j]==TETROMINO_ID::S){
            DrawObjects::draw(&skin2SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
          }
          else if(boardPieces[k][j]==TETROMINO_ID::Z){
            DrawObjects::draw(&skin2ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
          }
          else if(boardPieces[k][j]==TETROMINO_ID::O){
            DrawObjects::draw(&skin2OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
          }
          else{
            switch(i.getTetrominoID()){
            case TETROMINO_ID::I:
              DrawObjects::draw(&skin2IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
              break;
            case TETROMINO_ID::J:
              DrawObjects::draw(&skin2JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
              break;
            case TETROMINO_ID::L:
              DrawObjects::draw(&skin2LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
              break;
            case TETROMINO_ID::T:
              DrawObjects::draw(&skin2TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
              break;
            case TETROMINO_ID::S:
              DrawObjects::draw(&skin2SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
              break;
            case TETROMINO_ID::Z:
              DrawObjects::draw(&skin2ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
              break;
            case TETROMINO_ID::O:
              DrawObjects::draw(&skin2OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
              break;
            }
          }
        }
      }
    }
  }

  //next piece
  if(skin==0){
    //next piece
    switch(nextPiece){
    case TETROMINO_ID::I:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,21.0f,0.0f));
      DrawObjects::draw(&skin0IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,21.0f,0.0f));
      DrawObjects::draw(&skin0IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(17.5f,21.0f,0.0f));
      DrawObjects::draw(&skin0IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(19.0f,21.0f,0.0f));
      DrawObjects::draw(&skin0IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::J:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,21.0f,0.0f));
      DrawObjects::draw(&skin0JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,21.0f,0.0f));
      DrawObjects::draw(&skin0JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(17.5f,21.0f,0.0f));
      DrawObjects::draw(&skin0JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,22.5f,0.0f));
      DrawObjects::draw(&skin0JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::L:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,21.0f,0.0f));
      DrawObjects::draw(&skin0LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,21.0f,0.0f));
      DrawObjects::draw(&skin0LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(17.5f,21.0f,0.0f));
      DrawObjects::draw(&skin0LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(17.5f,22.5f,0.0f));
      DrawObjects::draw(&skin0LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::T:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,21.0f,0.0f));
      DrawObjects::draw(&skin0TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,21.0f,0.0f));
      DrawObjects::draw(&skin0TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(17.5f,21.0f,0.0f));
      DrawObjects::draw(&skin0TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,22.5f,0.0f));
      DrawObjects::draw(&skin0TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::O:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,21.0f,0.0f));
      DrawObjects::draw(&skin0OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,21.0f,0.0f));
      DrawObjects::draw(&skin0OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,22.5f,0.0f));
      DrawObjects::draw(&skin0OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,22.5f,0.0f));
      DrawObjects::draw(&skin0OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::S:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,21.0f,0.0f));
      DrawObjects::draw(&skin0SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,21.0f,0.0f));
      DrawObjects::draw(&skin0SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,22.5f,0.0f));
      DrawObjects::draw(&skin0SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(17.5f,22.5f,0.0f));
      DrawObjects::draw(&skin0SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::Z:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,22.5f,0.0f));
      DrawObjects::draw(&skin0ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,22.5f,0.0f));
      DrawObjects::draw(&skin0ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,21.0f,0.0f));
      DrawObjects::draw(&skin0ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(17.5f,21.0f,0.0f));
      DrawObjects::draw(&skin0ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    }
    //piece hold
    switch(pieceHold){
    case TETROMINO_ID::I:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-4.5f,21.0f,0.0f));
      DrawObjects::draw(&skin0IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-6.0f,21.0f,0.0f));
      DrawObjects::draw(&skin0IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-7.5f,21.0f,0.0f));
      DrawObjects::draw(&skin0IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-9.0f,21.0f,0.0f));
      DrawObjects::draw(&skin0IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::J:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,21.0f,0.0f));
      DrawObjects::draw(&skin0JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,21.0f,0.0f));
      DrawObjects::draw(&skin0JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-6.5f,21.0f,0.0f));
      DrawObjects::draw(&skin0JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-6.5f,22.5f,0.0f));
      DrawObjects::draw(&skin0JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::L:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,21.0f,0.0f));
      DrawObjects::draw(&skin0LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,21.0f,0.0f));
      DrawObjects::draw(&skin0LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-6.5f,21.0f,0.0f));
      DrawObjects::draw(&skin0LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,22.5f,0.0f));
      DrawObjects::draw(&skin0LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::T:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,21.0f,0.0f));
      DrawObjects::draw(&skin0TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,21.0f,0.0f));
      DrawObjects::draw(&skin0TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-6.5f,21.0f,0.0f));
      DrawObjects::draw(&skin0TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,22.5f,0.0f));
      DrawObjects::draw(&skin0TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::O:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,21.0f,0.0f));
      DrawObjects::draw(&skin0OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,21.0f,0.0f));
      DrawObjects::draw(&skin0OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,22.5f,0.0f));
      DrawObjects::draw(&skin0OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,22.5f,0.0f));
      DrawObjects::draw(&skin0OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::S:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,22.5f,0.0f));
      DrawObjects::draw(&skin0SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,22.5f,0.0f));
      DrawObjects::draw(&skin0SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,21.0f,0.0f));
      DrawObjects::draw(&skin0SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-6.5f,21.0f,0.0f));
      DrawObjects::draw(&skin0SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::Z:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,21.0f,0.0f));
      DrawObjects::draw(&skin0ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,21.0f,0.0f));
      DrawObjects::draw(&skin0ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,22.5f,0.0f));
      DrawObjects::draw(&skin0ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-6.5f,22.5f,0.0f));
      DrawObjects::draw(&skin0ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    }
  }
  else if(skin==1){
    //next piece
    switch(nextPiece){
    case TETROMINO_ID::I:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,21.0f,0.0f));
      DrawObjects::draw(&skin1IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,21.0f,0.0f));
      DrawObjects::draw(&skin1IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(17.5f,21.0f,0.0f));
      DrawObjects::draw(&skin1IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(19.0f,21.0f,0.0f));
      DrawObjects::draw(&skin1IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::J:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,21.0f,0.0f));
      DrawObjects::draw(&skin1JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,21.0f,0.0f));
      DrawObjects::draw(&skin1JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(17.5f,21.0f,0.0f));
      DrawObjects::draw(&skin1JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,22.5f,0.0f));
      DrawObjects::draw(&skin1JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::L:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,21.0f,0.0f));
      DrawObjects::draw(&skin1LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,21.0f,0.0f));
      DrawObjects::draw(&skin1LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(17.5f,21.0f,0.0f));
      DrawObjects::draw(&skin1LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(17.5f,22.5f,0.0f));
      DrawObjects::draw(&skin1LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::T:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,21.0f,0.0f));
      DrawObjects::draw(&skin1TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,21.0f,0.0f));
      DrawObjects::draw(&skin1TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(17.5f,21.0f,0.0f));
      DrawObjects::draw(&skin1TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,22.5f,0.0f));
      DrawObjects::draw(&skin1TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::O:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,21.0f,0.0f));
      DrawObjects::draw(&skin1OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,21.0f,0.0f));
      DrawObjects::draw(&skin1OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,22.5f,0.0f));
      DrawObjects::draw(&skin1OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,22.5f,0.0f));
      DrawObjects::draw(&skin1OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::S:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,21.0f,0.0f));
      DrawObjects::draw(&skin1SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,21.0f,0.0f));
      DrawObjects::draw(&skin1SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,22.5f,0.0f));
      DrawObjects::draw(&skin1SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(17.5f,22.5f,0.0f));
      DrawObjects::draw(&skin1SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::Z:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,22.5f,0.0f));
      DrawObjects::draw(&skin1ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,22.5f,0.0f));
      DrawObjects::draw(&skin1ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,21.0f,0.0f));
      DrawObjects::draw(&skin1ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(17.5f,21.0f,0.0f));
      DrawObjects::draw(&skin1ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    }
    //piece hold
    switch(pieceHold){
    case TETROMINO_ID::I:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-4.5f,21.0f,0.0f));
      DrawObjects::draw(&skin1IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-6.0f,21.0f,0.0f));
      DrawObjects::draw(&skin1IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-7.5f,21.0f,0.0f));
      DrawObjects::draw(&skin1IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-9.0f,21.0f,0.0f));
      DrawObjects::draw(&skin1IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::J:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,21.0f,0.0f));
      DrawObjects::draw(&skin1JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,21.0f,0.0f));
      DrawObjects::draw(&skin1JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-6.5f,21.0f,0.0f));
      DrawObjects::draw(&skin1JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-6.5f,22.5f,0.0f));
      DrawObjects::draw(&skin1JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::L:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,21.0f,0.0f));
      DrawObjects::draw(&skin1LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,21.0f,0.0f));
      DrawObjects::draw(&skin1LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-6.5f,21.0f,0.0f));
      DrawObjects::draw(&skin1LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,22.5f,0.0f));
      DrawObjects::draw(&skin1LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::T:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,21.0f,0.0f));
      DrawObjects::draw(&skin1TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,21.0f,0.0f));
      DrawObjects::draw(&skin1TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-6.5f,21.0f,0.0f));
      DrawObjects::draw(&skin1TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,22.5f,0.0f));
      DrawObjects::draw(&skin1TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::O:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,21.0f,0.0f));
      DrawObjects::draw(&skin1OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,21.0f,0.0f));
      DrawObjects::draw(&skin1OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,22.5f,0.0f));
      DrawObjects::draw(&skin1OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,22.5f,0.0f));
      DrawObjects::draw(&skin1OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::S:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,22.5f,0.0f));
      DrawObjects::draw(&skin1SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,22.5f,0.0f));
      DrawObjects::draw(&skin1SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,21.0f,0.0f));
      DrawObjects::draw(&skin1SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-6.5f,21.0f,0.0f));
      DrawObjects::draw(&skin1SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::Z:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,21.0f,0.0f));
      DrawObjects::draw(&skin1ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,21.0f,0.0f));
      DrawObjects::draw(&skin1ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,22.5f,0.0f));
      DrawObjects::draw(&skin1ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-6.5f,22.5f,0.0f));
      DrawObjects::draw(&skin1ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    }
  }
  else if(skin==2){
    //next piece
    switch(nextPiece){
    case TETROMINO_ID::I:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,21.0f,0.0f));
      DrawObjects::draw(&skin2IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,21.0f,0.0f));
      DrawObjects::draw(&skin2IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(17.5f,21.0f,0.0f));
      DrawObjects::draw(&skin2IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(19.0f,21.0f,0.0f));
      DrawObjects::draw(&skin2IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::J:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,21.0f,0.0f));
      DrawObjects::draw(&skin2JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,21.0f,0.0f));
      DrawObjects::draw(&skin2JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(17.5f,21.0f,0.0f));
      DrawObjects::draw(&skin2JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,22.5f,0.0f));
      DrawObjects::draw(&skin2JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::L:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,21.0f,0.0f));
      DrawObjects::draw(&skin2LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,21.0f,0.0f));
      DrawObjects::draw(&skin2LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(17.5f,21.0f,0.0f));
      DrawObjects::draw(&skin2LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(17.5f,22.5f,0.0f));
      DrawObjects::draw(&skin2LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::T:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,21.0f,0.0f));
      DrawObjects::draw(&skin2TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,21.0f,0.0f));
      DrawObjects::draw(&skin2TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(17.5f,21.0f,0.0f));
      DrawObjects::draw(&skin2TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,22.5f,0.0f));
      DrawObjects::draw(&skin2TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::O:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,21.0f,0.0f));
      DrawObjects::draw(&skin2OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,21.0f,0.0f));
      DrawObjects::draw(&skin2OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,22.5f,0.0f));
      DrawObjects::draw(&skin2OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,22.5f,0.0f));
      DrawObjects::draw(&skin2OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::S:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,21.0f,0.0f));
      DrawObjects::draw(&skin2SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,21.0f,0.0f));
      DrawObjects::draw(&skin2SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,22.5f,0.0f));
      DrawObjects::draw(&skin2SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(17.5f,22.5f,0.0f));
      DrawObjects::draw(&skin2SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::Z:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(14.5f,22.5f,0.0f));
      DrawObjects::draw(&skin2ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,22.5f,0.0f));
      DrawObjects::draw(&skin2ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(16.0f,21.0f,0.0f));
      DrawObjects::draw(&skin2ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(17.5f,21.0f,0.0f));
      DrawObjects::draw(&skin2ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    }
    //piece hold
    switch(pieceHold){
    case TETROMINO_ID::I:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-4.5f,21.0f,0.0f));
      DrawObjects::draw(&skin2IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-6.0f,21.0f,0.0f));
      DrawObjects::draw(&skin2IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-7.5f,21.0f,0.0f));
      DrawObjects::draw(&skin2IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-9.0f,21.0f,0.0f));
      DrawObjects::draw(&skin2IInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::J:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,21.0f,0.0f));
      DrawObjects::draw(&skin2JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,21.0f,0.0f));
      DrawObjects::draw(&skin2JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-6.5f,21.0f,0.0f));
      DrawObjects::draw(&skin2JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-6.5f,22.5f,0.0f));
      DrawObjects::draw(&skin2JInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::L:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,21.0f,0.0f));
      DrawObjects::draw(&skin2LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,21.0f,0.0f));
      DrawObjects::draw(&skin2LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-6.5f,21.0f,0.0f));
      DrawObjects::draw(&skin2LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,22.5f,0.0f));
      DrawObjects::draw(&skin2LInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::T:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,21.0f,0.0f));
      DrawObjects::draw(&skin2TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,21.0f,0.0f));
      DrawObjects::draw(&skin2TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-6.5f,21.0f,0.0f));
      DrawObjects::draw(&skin2TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,22.5f,0.0f));
      DrawObjects::draw(&skin2TInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::O:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,21.0f,0.0f));
      DrawObjects::draw(&skin2OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,21.0f,0.0f));
      DrawObjects::draw(&skin2OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,22.5f,0.0f));
      DrawObjects::draw(&skin2OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,22.5f,0.0f));
      DrawObjects::draw(&skin2OInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::S:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,22.5f,0.0f));
      DrawObjects::draw(&skin2SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,22.5f,0.0f));
      DrawObjects::draw(&skin2SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,21.0f,0.0f));
      DrawObjects::draw(&skin2SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-6.5f,21.0f,0.0f));
      DrawObjects::draw(&skin2SInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    case TETROMINO_ID::Z:
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-3.5f,21.0f,0.0f));
      DrawObjects::draw(&skin2ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,21.0f,0.0f));
      DrawObjects::draw(&skin2ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-5.0f,22.5f,0.0f));
      DrawObjects::draw(&skin2ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      t2.scaling=glm::mat4(1.0f);
      t2.translation=glm::mat4(1.0f);
      t2.translation=glm::translate(t2.translation,glm::vec3(-6.5f,22.5f,0.0f));
      DrawObjects::draw(&skin2ZInfo,t2,object3DShaders,GL_TRIANGLES,&cubeObject.vertices);
      break;
    }
  }
  //increase the level every 10 clears
  if(numberOfTotalRowsDestroyed>=10){
    level++;
    numberOfTotalRowsDestroyed=0;
  }
  //play regular music
  if(canPlayMusic&&!isSpeed){
    engine->drop();
    engine=createIrrKlangDevice();
    engine->setSoundVolume(currentPlayer.getVolume());
    engine->play2D(selectedMusic.c_str(), true);
    canPlayMusic=false;
  }
  //hold piece
  if(firstSwitch){
    new(&i)Tetrominoes(nextPiece,board);
    nextPiece=Tetrominoes::getRandomPiece(8,&lastPiece);
    firstSwitch=false;
  }
  //switch to hold piece
  if(switchToHold){
    TETROMINO_ID temp=i.getTetrominoID();
    switchToHold=false;
    nextPiece=pieceHold;
    pieceHold=TETROMINO_ID::NONE;
    new(&i)Tetrominoes(nextPiece,board);
    nextPiece=temp;
  }
  ms=duration_cast<milliseconds>(system_clock::now().time_since_epoch());
  //new fall
  if(ms.count()>=(ms2.count()+1600-((long long)level*100))){
    ms2=ms;
    if(!((i.willCollide(board,VERTICAL))||(i.willCollideEdges(board,VERTICAL)))){
      i.moveDown(board);
    }
  }
  //colision on the bottom
  ms3=duration_cast<milliseconds>(system_clock::now().time_since_epoch());
  //collision
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
}