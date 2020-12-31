/*
  ----------- Objects -----------
*/

//shader
GLuint object3DShaders;

//transformations
typedef struct{
  glm::mat4 translation;
  glm::mat4 scaling;
}TRANSFORMATIONS;

//vertices
typedef struct{
  std::vector<glm::vec3>vertices;
  std::vector<glm::vec2>uvs;
  std::vector<glm::vec3>normals;
}OBJ_VECTORS;

//buffers
typedef struct {
  GLuint VertexArrayID;
  GLuint MatrixID;
  GLuint Texture;
  GLuint TextureID;
  GLuint uvbuffer;
  GLuint vertexbuffer;
}BUFFERS;