#include"cameraPosition.cpp"
/*
  ----------- Shows the intro menu -----------
*/
void showIntroMenu(){
	setInitialCameraPosition(0.014757f,0.01f,2.392263,0.0f,0.0f,15.7,-6.285,&t);
	DrawObjects::draw(&menuInfo,t,object3DShaders,GL_TRIANGLES,&menuObject.vertices);
}