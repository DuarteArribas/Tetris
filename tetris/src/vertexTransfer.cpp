class Vertices{
private:
	unsigned int VBO=0,VAO=0,vertexArraySize;
	float *vertexArray;
	unsigned int *vertexArray2;
public:
	Vertices(float *array,size_t vertexArraySize) {
		vertexArray=(float *)malloc(vertexArraySize*sizeof(float));
		this->vertexArraySize=vertexArraySize;
		for(int i=0; i<this->vertexArraySize/sizeof(float); i++) {
			try {
				vertexArray[i]=array[i];
			}
			catch(int x) {
				printf("something");
			}
		}
	}

	Vertices(unsigned int *array,size_t vertexArraySize) {
		vertexArray2=(unsigned int *)malloc(vertexArraySize*sizeof(unsigned int));
		this->vertexArraySize=vertexArraySize;
		for(int i=0; i<this->vertexArraySize/sizeof(int); i++) {
			try {
				vertexArray2[i]=array[i];
			}
			catch(int x) {
				printf("something");
			}
		}
	}

	Vertices(INFO *info, OBJ_VECTORS *object,GLuint shader,const char* textureName, const char* objectName) {
		glGenVertexArrays(1,(&info->VertexArrayID));
		glBindVertexArray((info->VertexArrayID));
		info->MatrixID = glGetUniformLocation(shader, "MVP");
		info->Texture = loadDDS(textureName);
		info->TextureID = glGetUniformLocation(shader, "myTextureSampler");
		bool res = loadOBJ(objectName,object->vertices,object->uvs, object->normals);
		glGenBuffers(1, &info->vertexbuffer);
		glBindBuffer(GL_ARRAY_BUFFER, info->vertexbuffer);
		glBufferData(GL_ARRAY_BUFFER, (&object->vertices)->size() * sizeof(glm::vec3), &object->vertices[0][0], GL_STATIC_DRAW);

		glGenBuffers(1, &info->uvbuffer);
		glBindBuffer(GL_ARRAY_BUFFER, info->uvbuffer);
		glBufferData(GL_ARRAY_BUFFER, (&object->uvs)->size() * sizeof(glm::vec3), &object->uvs[0][0], GL_STATIC_DRAW);
	}

	unsigned int getVBO() {
		return VBO;
	}

	unsigned int getVAO() {
		return VAO;
	}

	void setVBO(GLuint VBO) {
		this->VBO=VBO;
	}

	void setVAO(GLuint VAO) {
		this->VAO=VAO;
	}

	void generateVertices() {
		glGenVertexArrays(1,&VAO);
		glBindVertexArray(VAO);

		glGenBuffers(1,&VBO);
		glBindBuffer(GL_ARRAY_BUFFER,VBO);
		glBufferData(GL_ARRAY_BUFFER,this->vertexArraySize,vertexArray,GL_STATIC_DRAW);
	}

	void generateVertices3D() {
		glGenVertexArrays(1,&VAO);
		glBindVertexArray(VAO);

		glGenBuffers(1,&VBO);
		glBindBuffer(GL_ARRAY_BUFFER,VBO);
		glBufferData(GL_ARRAY_BUFFER,this->vertexArraySize,vertexArray,GL_STATIC_DRAW);
	}

	void generateEBO() {
		glGenBuffers(1,&VBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,VBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,this->vertexArraySize,vertexArray2,GL_STATIC_DRAW);
	}

	void cleanData() {
		glDeleteVertexArrays(1,&VAO);
		glDeleteBuffers(1,&VBO);
	}
};