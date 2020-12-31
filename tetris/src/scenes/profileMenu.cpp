/*
  ----------- Shows the profile menu -----------
*/
void showProfileMenu(){
  setInitialCameraPosition(0.014757f,0.01f,2.45,0.0f,0.0f,15.71,-6.278,&t);
  t9.translation=glm::mat4(1.0f);
  t9.scaling=glm::mat4(1.0f);
  t9.scaling=glm::scale(t9.scaling,glm::vec3(0.2f,0.2f,0.2f));
  //draw the player's rank
  if(Player::rank(currentPlayer.getScore())!='U'&&Player::rank(currentPlayer.getScore())!='T'){
    CreateNumberWhite(currentPlayer.getScore(),0.1f,0.1f,-0.3f,0.0f);
  }
  if(Player::rank(currentPlayer.getScore())=='U'){
    DrawObjects::draw(&unrankedInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
  }
  else if(Player::rank(currentPlayer.getScore())=='B'){
    DrawObjects::draw(&bronzeInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
  }
  else if(Player::rank(currentPlayer.getScore())=='S'){
    DrawObjects::draw(&silverInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
  }
  else if(Player::rank(currentPlayer.getScore())=='G'){
    DrawObjects::draw(&goldInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
  }
  else if(Player::rank(currentPlayer.getScore())=='P'){
    DrawObjects::draw(&platinumInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
  }
  else if(Player::rank(currentPlayer.getScore())=='D'){
    DrawObjects::draw(&diamondInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
  }
  else if(Player::rank(currentPlayer.getScore())=='M'){
    DrawObjects::draw(&masterInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
  }
  else if(Player::rank(currentPlayer.getScore())=='T'){
    DrawObjects::draw(&tetrisInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
    CreateNumberWhite(currentPlayer.getScore(),0.1f,0.1f,-0.7f,0.0f);
  }
}