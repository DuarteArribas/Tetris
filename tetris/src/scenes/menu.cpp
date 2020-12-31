/*
  ----------- Shows the menu -----------
*/
void showMenu(){
  setInitialCameraPosition(0.014757f,0.01f,2.392263,0.0f,0.0f,15.715,-6.29,&t);
  //draw selected menu option
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
}