/*
  ----------- Shows the skins menu -----------
*/
void showSkinMenu(){
  setInitialCameraPosition(0.014757f,0.01f,2.45,0.0f,0.0f,15.71,-6.278,&t);
  //draws the selected skin menu according to the player's rank
  if(Player::rank(currentPlayer.getScore())=='U'||Player::rank(currentPlayer.getScore())=='B'){
    DrawObjects::draw(&skin11Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
  }
  else if(Player::rank(currentPlayer.getScore())=='S'){
    if(optionSkins==0){
      DrawObjects::draw(&skin21Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
    }
    else if(optionSkins==1){
      DrawObjects::draw(&skin22Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
    }
    else if(optionSkins==2){
      DrawObjects::draw(&skin22Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
    }
  }
  else{
    if(optionSkins==0){
      DrawObjects::draw(&skin31Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
    }
    else if(optionSkins==1){
      DrawObjects::draw(&skin32Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
    }
    else if(optionSkins==2){
      DrawObjects::draw(&skin33Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
    }
  }
}