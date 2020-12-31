/*
  ----------- Draw Objects -----------
*/
class DrawObjects{
public:
  //set MVP
  static glm::mat4 setMVP(TRANSFORMATIONS transformations){
    computeMatricesFromInputs();
    glm::mat4 ProjectionMatrix = getProjectionMatrix();
    glm::mat4 ViewMatrix = getViewMatrix();
    glm::mat4 ModelMatrix = glm::mat4(1.0);
    glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix * transformations.translation * transformations.scaling;
    return MVP;
  }
  
  //draw a 3d object on screen
  void static draw(BUFFERS *info,TRANSFORMATIONS transformations,GLuint shader,GLuint primitive,std::vector<glm::vec3>*vertices){
    glUseProgram(shader);
    glm::mat4 MVP=setMVP(transformations);
    glUniformMatrix4fv(info->MatrixID, 1, GL_FALSE, &MVP[0][0]);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, info->Texture);
    glUniform1i(info->TextureID, 0);

    //vertices buffer
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, info->vertexbuffer);
    glVertexAttribPointer(
      0,                 
      3,                 
      GL_FLOAT,          
      GL_FALSE,          
      0,                 
      (void*)0           
    );

    //uvs vertices
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, info->uvbuffer);
    glVertexAttribPointer(
      1,                              
      2,                              
      GL_FLOAT,                       
      GL_FALSE,                       
      0,                              
      (void*)0                        
    );

    //draw the object
    glDrawArrays(primitive, 0, vertices->size());
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
  }
};