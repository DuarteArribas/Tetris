/*
  ----------- Shows the music selection menu -----------
*/
void showMusicSelectionMenu(){
  setInitialCameraPosition(0.014757f,0.01f,2.392263,0.0f,0.0f,15.715,-6.29,&t);
  //draw selected music option
  if(optionMusicSelection==0){
    DrawObjects::draw(&chooseAudioAInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
  }
  else{
    DrawObjects::draw(&chooseAudioBInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
  }
}