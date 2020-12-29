#include<irrKlang/include/irrKlang.h>
using namespace irrklang;
//Program
GLuint programID;

//window
GLFWwindow *window;

//function prototypes
int buildWindow(GLint WINDOW_WIDTH,GLint WINDOW_HEIGHT,char *windowTitle,GLint focused,bool fullscreen);

int initialize(GLint WINDOW_WIDTH,GLint WINDOW_HEIGHT,char *windowTitle, ISoundEngine* engine, float volume,bool fullscreen){
	if(!glfwInit()) {
		fprintf(stderr,"Failed to initialize GLFW\n");
		getchar();
		return -1;
	}

	if(buildWindow(WINDOW_WIDTH,WINDOW_HEIGHT,windowTitle,GLFW_TRUE,fullscreen)==-1){
		return -1;
	}
	
	glewExperimental = true; // Needed for core profile
  glewInit();
	
	glfwSetInputMode(window,GLFW_STICKY_KEYS,GL_TRUE);
	glClearColor(1.0f,1.0f,1.0f,0.0f);
	programID=LoadShaders("src/TransformVertexShader.vertexshader","src/ColorFragmentShader.fragmentshader");
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	GLuint FramebufferName=0;
	glGenFramebuffers(1,&FramebufferName);

	//check irrklang initialization
	if (!engine){
		printf("Could not startup engine\n");
		return -1;
	}
	engine->setSoundVolume(volume);
	return 0;
}

int buildWindow(GLint WINDOW_WIDTH,GLint WINDOW_HEIGHT,char *windowTitle,GLint focused, bool fullscreen){
	if(window!=NULL){
		glfwDestroyWindow(window);
	}
	glfwWindowHint(GLFW_RESIZABLE,GLFW_TRUE);
	glfwWindowHint(GLFW_VISIBLE,GLFW_TRUE);
	glfwWindowHint(GLFW_DECORATED,GLFW_TRUE);
	glfwWindowHint(GLFW_FOCUSED,focused);
	glfwWindowHint(GLFW_MAXIMIZED,GLFW_FALSE);
	glfwWindowHint(GLFW_CENTER_CURSOR,GLFW_FALSE);
	glfwWindowHint(GLFW_SCALE_TO_MONITOR,GLFW_TRUE);
	glfwWindowHint(GLFW_SAMPLES,4);
	glfwWindowHint(GLFW_DOUBLEBUFFER,GLFW_TRUE);
	glfwWindowHint(GLFW_REFRESH_RATE,GLFW_DONT_CARE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	if(!fullscreen){
		window=glfwCreateWindow(WINDOW_WIDTH,WINDOW_HEIGHT,windowTitle,NULL,NULL);
	}
	else{
		window=glfwCreateWindow(WINDOW_WIDTH,WINDOW_HEIGHT,windowTitle,glfwGetPrimaryMonitor(),NULL);
	}
	
	if(window==NULL){
		fprintf(stderr,"Failed to open GLFW window, possibly because of your Intel GPU\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	//get monitor size
	const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int monitorX, monitorY;
	glfwGetMonitorPos(glfwGetPrimaryMonitor(), &monitorX, &monitorY);
	//get window size
	int windowWidth, windowHeight;
	glfwGetWindowSize(window, &windowWidth, &windowHeight);

	//center window
	glfwSetWindowPos(window, monitorX + (mode->width - windowWidth) / 2, monitorY + (mode->height - windowHeight) / 2);
	
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

	//window icon
	GLFWimage icon[1];
	icon[0].pixels = stbi_load("images/icon/icon.png", &icon[0].width, &icon[0].height, 0, 4);
	glfwSetWindowIcon(window, 1, icon); 
	stbi_image_free(icon[0].pixels);


	//make window contest
	glfwMakeContextCurrent(window);

	return 0;
}