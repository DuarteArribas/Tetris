/*
  ----------- Shows the saves menu -----------
*/
void showSaveMenu(){
	setInitialCameraPosition(0.014757f,0.01f,2.392263,0.0f,0.0f,15.715,-6.29,&t);
  //draw selected save option
  if(optionMenuSave==0){
    DrawObjects::draw(&save1Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
  }
  else if(optionMenuSave==1){
    DrawObjects::draw(&save2Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
  }
  else if(optionMenuSave==2){
    DrawObjects::draw(&save3Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
  }
  else if(optionMenuSave==3){
    DrawObjects::draw(&save4Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
  }
  else if(optionMenuSave==4){
    DrawObjects::draw(&save5Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
  }
  else if(optionMenuSave==5){
    DrawObjects::draw(&savePlayGuestInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
  }
}