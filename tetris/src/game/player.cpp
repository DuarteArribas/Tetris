class Player{
private:
	GLint windowHeight,windowWidth; //768, 768
	bool fullscreen;//false
	float volume;//0.5f
	long long score=0,highscore;
public:
	Player(GLint windowHeight,GLint windowWidth, bool fullscreen, float volume){
		this->windowHeight=windowHeight;
		this->windowWidth=windowWidth;
		this->fullscreen=fullscreen;
		this->volume=volume;
	}

	GLint getWindowHeight(){
		return this->windowHeight;
	}

	GLint getWindowWidth(){
		return this->windowWidth;
	}

	bool getIsFullscreen(){
		return this->fullscreen;
	}

	float getVolume(){
		return this->volume;
	}

	long long getScore(){
		return this->score;
	}
	
	long long getHighscore(){
		return this->highscore;
	}

	void setWindowHeight(GLint windowHeight){
		this->windowHeight=windowHeight;
	}

	void setWindowWidth(GLint windowWidth){
		this->windowWidth=windowWidth;
	}

	void setIsFullscreen(bool fullscreen){
		this->fullscreen=fullscreen;
	}

	void setVolume(float volume){
		this->volume=volume;
	}

	void setScore(long long score){
		this->score=score;
	}

	void setHighscore(long long highscore){
		this->highscore=highscore;
	}

	static char rank(long long n){
		int count = 0;
		while (n != 0) {
			n /= 10;     
			count++;
		}
		if(count > 10){
			return 'T';
		}
		else if(count > 9){
			return 'M';
		}
		else if(count > 8){
			return 'D';
		}
		else if(count > 7){
			return 'P';
		}
		else if(count > 6){
			return 'G';
		}
		else if(count > 5){
			return 'S';
		}
		else if(count > 3){
			return 'B';
		}
		else if(count <= 3){
			return 'U';
		}
	}
};