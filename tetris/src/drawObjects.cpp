class DrawObjects{
private:
  constexpr static float minOrtho=-100.0f, maxOrtho=100.0f; //square ortho
public:
  void static draw(GLint buffer, GLint color, GLfloat translateX, GLfloat translateY, GLfloat scaleX, GLfloat scaleY, 
    GLfloat ang, GLint pointSize, GLint primitive, GLint numberOfPoints){
    //ortho
    glm::mat4 mvp = glm::ortho(minOrtho, maxOrtho, minOrtho, maxOrtho);
    unsigned int orthoMatrix= glGetUniformLocation(programID, "mvp");
    glUniformMatrix4fv(orthoMatrix, 1, GL_FALSE, &mvp[0][0]);
    //translate
    glm::mat4 translate=glm::translate(glm::mat4(1.0), glm::vec3(translateX, translateY, 0.0f));
    unsigned int translateMatrix = glGetUniformLocation(programID, "translate");
    glUniformMatrix4fv(translateMatrix, 1, GL_FALSE, &translate[0][0]);
    //scale
    glm::mat4 scale = glm::scale(glm::mat4(1.0f), vec3(scaleX, scaleY, 0.0f));
    unsigned int scaleMatrix = glGetUniformLocation(programID, "scale");
    glUniformMatrix4fv(scaleMatrix, 1, GL_FALSE, &scale[0][0]);
    //rotate
    glm::mat4 rotate = glm::rotate(glm::mat4(1.0), glm::radians(ang), glm::vec3(0, 0, 1));
    unsigned int rotateMatrix = glGetUniformLocation(programID, "rotate");
    glUniformMatrix4fv(rotateMatrix, 1, GL_FALSE, &rotate[0][0]);

    //buffer
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

    //color
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, color);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,0,(void*)0);

    glEnable(GL_PROGRAM_POINT_SIZE);
    glPointSize(pointSize);
    glDrawArrays(primitive, 0, numberOfPoints);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
  }

  void static draw(char *textureName, unsigned int *texture){
    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glGenTextures(1, texture);
    glBindTexture(GL_TEXTURE_2D, *texture); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load(textureName, &width, &height, &nrChannels, 0);
    if (data){
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
      glGenerateMipmap(GL_TEXTURE_2D);
    }
    else{
      std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
  }
  
  static glm::mat4 setMVP(TRANSFORMATIONS transformations) {
    // Compute the MVP matrix from keyboard and mouse input
    computeMatricesFromInputs();
    glm::mat4 ProjectionMatrix = getProjectionMatrix();
    glm::mat4 ViewMatrix = getViewMatrix();
    glm::mat4 ModelMatrix = glm::mat4(1.0);
    glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix * transformations.center_rotation * transformations.translation * transformations.self_rotation * transformations.scaling;
    return MVP;
  }

  void static draw(INFO *info,TRANSFORMATIONS transformations,GLuint shader,GLuint primitive,std::vector<glm::vec3>*vertices){
    glUseProgram(shader);
    glm::mat4 MVP=setMVP(transformations);

    // Send our transformation to the currently bound shader, 
    // in the "MVP" uniform
    glUniformMatrix4fv(info->MatrixID, 1, GL_FALSE, &MVP[0][0]);

    // Bind our texture in Texture Unit 0
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, info->Texture);
    // Set our "myTextureSampler" sampler to use Texture Unit 0
    glUniform1i(info->TextureID, 0);

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, info->vertexbuffer);
    glVertexAttribPointer(
      0,                  // attribute
      3,                  // size
      GL_FLOAT,           // type
      GL_FALSE,           // normalized?
      0,                  // stride
      (void*)0            // array buffer offset
    );

    // 2nd attribute buffer : UVs
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, info->uvbuffer);
    glVertexAttribPointer(
      1,                                // attribute
      2,                                // size
      GL_FLOAT,                         // type
      GL_FALSE,                         // normalized?
      0,                                // stride
      (void*)0                          // array buffer offset
    );

    // Draw the triangle !
    glDrawArrays(primitive, 0, vertices->size());

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    
  }
};