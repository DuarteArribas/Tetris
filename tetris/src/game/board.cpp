void printBoardDivisors();

void printBoard(bool board[][10]){
	printBoardDivisors();	
	for(int i=20;i>0;i--){
		printf("|");
		for(int j=0;j<10;j++){
			if(board[i][j]){
				printf(" * |");
			}
			else{
				printf("   |");
			}
		}
		printf("\n");
		printBoardDivisors();
	}
}

void collidedOnBottom(TETROMINO_ID tetrominoID){
	canGenerateNewPiece=true;
	hardDrop=false;
	lastStep=true;
	numberOfRowsDestroyed=0;
	for(int row=20;row>0;row--){
		if(board[row][0]&&
			board[row][1]&&
			board[row][2]&&
			board[row][3]&&
			board[row][4]&&
			board[row][5]&&
			board[row][6]&&
			board[row][7]&&
			board[row][8]&&
			board[row][9]
			){
			numberOfRowsDestroyed++;
			//clean row
			board[row][0]=false;
			board[row][1]=false;
			board[row][2]=false;
			board[row][3]=false;
			board[row][4]=false;
			board[row][5]=false;
			board[row][6]=false;
			board[row][7]=false;
			board[row][8]=false;
			board[row][9]=false;

			//Isaac Newton was right
			for(int row2=row;row2<20;row2++){
				for(int column=0;column<10;column++){
					if(board[row2][column]){
						board[row2-1][column]=true;
						board[row2][column]=false;
					}
				}
			}
		}
	}
	isGameOver=false;
	for(int i=0;i<10;i++){
		if(board[21][i]){
			printf("lol entrei aqui quando n era suposto: %d\n",i);

			//this debug was brought to ya by: ALEXANDRE THE GREATexpress
			gameOver(&lastPiece,true);
			isGameOver=true;
			break;
		}
	}

	if(board[15][0]||
		board[15][1]||
		board[15][2]||
		board[15][3]||
		board[15][4]||
		board[15][5]||
		board[15][6]||
		board[15][7]||
		board[15][8]||
		board[15][9]){
		if(canPlayMusic2){
			isSpeed=true;
			engine->drop();
			engine=createIrrKlangDevice();
			engine->setSoundVolume(currentPlayer.getVolume());
			engine->play2D(selectedMusicSpeed.c_str(), true);
			canPlayMusic=true;
			canPlayMusic2=false;
		}
	}
	else{
		isSpeed=false;
		canPlayMusic2=true;
	}
	if(numberOfRowsDestroyed==1){
		score+=long long(100)*level;
		backToBack=false;
	}
	else if(numberOfRowsDestroyed==2){
		score+=long long(300)*level;
		backToBack=false;
	}
	else if(numberOfRowsDestroyed==3){
		score+=long long(500)*level;
		backToBack=false;
	}
	else if(numberOfRowsDestroyed==4){
		if(backToBack){
			score+=long long(1200)*level;
		}
		else{
			score+=long long(800)*level;
		}
		backToBack=true;
	}
	numberOfTotalRowsDestroyed+=numberOfRowsDestroyed;
	canHold=true;
	if(!isGameOver){
		         
		new(&i)Tetrominoes(tetrominoID,board);
	}
}

void printBoardDivisors(){
	for(int i=0;i<41;i++){
		printf("-");
	}
	printf("\n");
}