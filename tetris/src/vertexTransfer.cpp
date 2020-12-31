/*
  ----------- Generates the object's vertices and puts them in their respective buffers -----------
*/
class Vertices{
public:
	Vertices(BUFFERS *info, OBJ_VECTORS *object,GLuint shader,const char textureName[], const char objectName[]) {
		//generate and bind VAOs
		glGenVertexArrays(1,(&info->VertexArrayID));
		glBindVertexArray((info->VertexArrayID));
		//MVP shader
		info->MatrixID = glGetUniformLocation(shader, "MVP");
		//load the texture
		info->Texture = loadDDS(textureName);
		info->TextureID = glGetUniformLocation(shader, "myTextureSampler");
		//load the object
		bool res = loadOBJ(objectName,object->vertices,object->uvs, object->normals);
		//vertices' buffer
		glGenBuffers(1, &info->vertexbuffer);
		glBindBuffer(GL_ARRAY_BUFFER, info->vertexbuffer);
		glBufferData(GL_ARRAY_BUFFER, (&object->vertices)->size() * sizeof(glm::vec3), &object->vertices[0][0], GL_STATIC_DRAW);
		//uvs' buffer
		glGenBuffers(1, &info->uvbuffer);
		glBindBuffer(GL_ARRAY_BUFFER, info->uvbuffer);
		glBufferData(GL_ARRAY_BUFFER, (&object->uvs)->size() * sizeof(glm::vec3), &object->uvs[0][0], GL_STATIC_DRAW);
	}
};