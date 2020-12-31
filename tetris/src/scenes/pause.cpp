/*
  ----------- Shows the pause menu -----------
*/
void showPauseMenu(){
  setInitialCameraPosition(0.014757f,0.01f,2.392263,0.0f,0.0f,15.715,-6.29,&t);
  //draw selected pause option
  if(optionMenuPause==0){
    DrawObjects::draw(&pauseGameInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
  }
  else{
    DrawObjects::draw(&pauseMenuInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
  }
}

/*
  ----------- Pauses the game -----------
*/
void pause(){
  //stop the music and reinitialize it
  engine->drop();
  engine=createIrrKlangDevice();
  engine->setSoundVolume(currentPlayer.getVolume());
  canPlayMusic=true;
  canPlayMusic2=true;
  //change scene
  scene=Scene::PAUSE;
}