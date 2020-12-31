/*
  ----------- Handles the saving to files -----------
*/
#include"src/support/auxiliaryFunctions.cpp"

//override general settings in file
void updateGeneralSettings(string width,string height,string fullscreen,string volume){
  ofstream fout;
  fout.open("saves/generalSettings.txt");
  fout<<width<<endl;
  fout<<height<<endl;
  fout<<fullscreen<<endl;
  fout<<volume;
}

//override score in file
void updateScore(long long score,long long highscore){
  ofstream fout;
  fout.open(save);
  fout<<score<<endl;
  fout<<highscore;
}

//load the settings from the file
void loadSettings(int *widthInt,int *heightInt,bool *fullscreenBool,float *volumeFloat){
  ifstream fin;
  fin.open("saves/generalSettings.txt");
  string width, height, fullscreen,volume;
  //handles what the line is being read
  int count=0;
  //read from file and save in variables
  while(!fin.eof()){
    if(count==0){
      getline(fin,width);
      *widthInt=std::stoi(width);
      int temp=*widthInt;
      switch(temp){
        case 700:
          subOptionSubMenu=0;
          break;
        case 800:
          subOptionSubMenu=1;
          break;
        case 900:
          subOptionSubMenu=2;
          break;
        case 1000:
          subOptionSubMenu=3;
          break;
      }
    }
    else if(count==1){
      getline(fin,height);
      *heightInt=std::stoi(height);
    }
    else if(count==2){
      getline(fin,fullscreen);
      *fullscreenBool=toBool(fullscreen);
    }
    else if(count==3){
      getline(fin,volume);
      *volumeFloat=std::stof(volume);
    }
    count++;
  }
}