/*
  ----------- Shows the settings menu -----------
*/
void showSubMenu(){
  setInitialCameraPosition(0.014757f,0.01f,2.45,0.0f,0.0f,15.71,-6.278,&t);
  //draw the selected menu option
  if(!isInSubSubMenu){
    if(optionSubMenu==0){
      DrawObjects::draw(&settingsFullscreenInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
    }
    else if(optionSubMenu==1){
      DrawObjects::draw(&settingsResolutionInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
    }
    else if(optionSubMenu==2){
      DrawObjects::draw(&settingsAudioInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
    }
  }
  else{
    switch(optionSubMenu){
    case 1:
      switch(currentPlayer.getWindowWidth()){
      case 700:
        DrawObjects::draw(&resolution1Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        break;
      case 800:
        DrawObjects::draw(&resolution2Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        break;
      case 900:
        DrawObjects::draw(&resolution3Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        break;
      case 1000:
        DrawObjects::draw(&resolution4Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        break;
      }
      break;
    case 2:
      switch((int)(currentPlayer.getVolume()*10)){
      case 0:
        DrawObjects::draw(&audio0Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        break;
      case 1:
        DrawObjects::draw(&audio1Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        break;
      case 2:
        DrawObjects::draw(&audio2Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        break;
      case 3:
        DrawObjects::draw(&audio3Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        break;
      case 4:
        DrawObjects::draw(&audio4Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        break;
      case 5:
        DrawObjects::draw(&audio5Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        break;
      case 6:
        DrawObjects::draw(&audio6Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        break;
      case 7:
        DrawObjects::draw(&audio7Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        break;
      case 8:
        DrawObjects::draw(&audio8Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        break;
      case 9:
        DrawObjects::draw(&audio9Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        break;
      case 10:
        DrawObjects::draw(&audio10Info,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
        break;
      }
      break;
    }  
  }
}