/*
	----------- Represents the current player and its general settings -----------
*/
class Player{
private:
	GLint windowHeight,windowWidth;
	bool fullscreen;
	float volume;
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
	
	//returns the player's rank according to its total score
	static char rank(long long totalScore){
		int count=0;
		while(totalScore!=0){
			totalScore /= 10;     
			count++;
		}
		if(count>8){
			return 'T';
		}
		else if(count>7){
			return 'M';
		}
		else if(count>6){
			return 'D';
		}
		else if(count>5){
			return 'P';
		}
		else if(count>4){
			return 'G';
		}
		else if(count>3){
			return 'S';
		}
		else if(count>2){
			return 'B';
		}
		else if(count<=1){
			return 'U';
		}
	}
};