/*
  ----------- Handles the collision of a piece on the bottom -----------
*/
void collidedOnBottom(TETROMINO_ID tetrominoID){
	//allows generation of a new piece
	canGenerateNewPiece=true;
	//resets lastStep (allows the player to move a little more after they're on the last row)
	lastStep=true;
	//resets the number of destroyed rows
	numberOfRowsDestroyed=0;
	//adds the pieces that just fell to the secondary board
	boardPieces[i.getSquareCoordinates()[4]][i.getSquareCoordinates()[0]]=i.getTetrominoID();
	boardPieces[i.getSquareCoordinates()[5]][i.getSquareCoordinates()[1]]=i.getTetrominoID();
	boardPieces[i.getSquareCoordinates()[6]][i.getSquareCoordinates()[2]]=i.getTetrominoID();
	boardPieces[i.getSquareCoordinates()[7]][i.getSquareCoordinates()[3]]=i.getTetrominoID();
	//checks if any row filled up
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
			//play row clear sound
			engine->play2D("music/tetrisSound.ogg", false);
			//increase the number of rows destroyed
			numberOfRowsDestroyed++;
			//clean row
			for(int i=0;i<10;i++){
				board[row][i]=false;
				boardPieces[row][i]=TETROMINO_ID::NONE;
			}
			//Isaac Newton was right
			for(int row2=row;row2<20;row2++){
				for(int column=0;column<10;column++){
					if(board[row2][column]){
						board[row2-1][column]=true;
						board[row2][column]=false;
					}
					if(boardPieces[row2][column]!=TETROMINO_ID::NONE){
						boardPieces[row2-1][column]=boardPieces[row2][column];
						boardPieces[row2][column]=TETROMINO_ID::NONE;
					}
				}
			}
		}
	}
	
	//checks if it's game over and handles it
	isGameOver=false;
	for(int i=0;i<10;i++){
		if(board[21][i]){
			gameOver(&lastPiece,true);
			isGameOver=true;
			break;
		}
	}
	
	//checks if the player has any piece in the 15th row, playing a faster version of the song if so
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
			//stop the music and play the faster version
			engine->drop();
			engine=createIrrKlangDevice();
			engine->setSoundVolume(currentPlayer.getVolume());
			engine->play2D(selectedMusicSpeed.c_str(), true);
			canPlayMusic=true;
			canPlayMusic2=false;
			isSpeed=true;
		}
	}
	else{
		isSpeed=false;
		canPlayMusic2=true;
	}
	//holds the amount of extra points depending on whether the player soft or hardDropped
	int cellDropPoints=hardDrop?2:1;
	//resets the hardDrop
	hardDrop=false;
	//adds to the score, depending on how many rows the player destroyed
	if(numberOfRowsDestroyed==1){
		score+=long long(100)*level+long long(cellDropPoints*10);
		backToBack=false;
	}
	else if(numberOfRowsDestroyed==2){
		score+=long long(300)*level+long long(cellDropPoints*20);
		backToBack=false;
	}
	else if(numberOfRowsDestroyed==3){
		score+=long long(500)*level+long long(cellDropPoints*30);
		backToBack=false;
	}
	else if(numberOfRowsDestroyed==4){
		if(backToBack){
			score+=long long(1200)*level+long long(cellDropPoints*40);
		}
		else{
			score+=long long(800)*level+long long(cellDropPoints*40);
		}
		backToBack=true;
	}
	//adds to the total number of rows destroyed to increase the level of the game
	numberOfTotalRowsDestroyed+=numberOfRowsDestroyed;
	//the player can hold a piece again after dropping another
	canHold=true;
	//instanciate a new piece if the game isn't over
	if(!isGameOver){	         
		new(&i)Tetrominoes(tetrominoID,board);
	}
}