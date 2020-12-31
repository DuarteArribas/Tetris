/*
  ----------- Sets the initial camera position -----------
*/
void setInitialCameraPosition(float xPosition,
                              float yPosition,
                              float zPosition,
                              float positionSpeed,
                              float cameraSpeed,
                              float horizontalAngle2,
                              float verticalAngle2,
                              TRANSFORMATIONS *t){
  //set position
  position=glm::vec3(xPosition,yPosition,zPosition);
  //reset transformations
  (*t).translation=glm::mat4(1.0f);
  (*t).scaling=glm::mat4(1.0f);
  //set speed and mouseSpeed
  speed=positionSpeed;
  mouseSpeed=cameraSpeed;
  //set camera angles
  horizontalAngle=horizontalAngle2;
  verticalAngle=verticalAngle2;
}