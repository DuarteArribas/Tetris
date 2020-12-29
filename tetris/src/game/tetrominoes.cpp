class Tetrominoes{
private:
	int xPosition, yPosition, rotationCenterX,rotationCenterY, rotationState;
	int squareCoordinates[8];
	TETROMINO_ID tetrominoID;
public:
	Tetrominoes(TETROMINO_ID tetrominoID, bool board[][10]){
		this->tetrominoID=tetrominoID;
		rotationState=0;
		switch(tetrominoID){
			case TETROMINO_ID::I:
				board[20][3]=true;
				board[20][4]=true;
				board[20][5]=true;
				board[20][6]=true;
				this->xPosition=3;
				this->yPosition=20;
				this->rotationCenterX=4;
				this->rotationCenterY=20;
				/* x and y point
				+ - - -
				*/
				//squareX
				squareCoordinates[0]=3;
				squareCoordinates[1]=4;
				squareCoordinates[2]=5;
				squareCoordinates[3]=6;
				//squareY
				squareCoordinates[4]=20;
				squareCoordinates[5]=20;
				squareCoordinates[6]=20;
				squareCoordinates[7]=20;
				break;
			case TETROMINO_ID::J:
				board[21][3]=true;
				board[20][3]=true;
				board[20][4]=true;
				board[20][5]=true;
				this->xPosition=3;
				this->yPosition=21;
				this->rotationCenterX=4;
				this->rotationCenterY=20;
				/* x and y point
				+
				- - -
				*/
				//squareX
				squareCoordinates[0]=3;
				squareCoordinates[1]=3;
				squareCoordinates[2]=4;
				squareCoordinates[3]=5;
				//squareY
				squareCoordinates[4]=21;
				squareCoordinates[5]=20;
				squareCoordinates[6]=20;
				squareCoordinates[7]=20;
				break;
			case TETROMINO_ID::L:
				board[20][3]=true;
				board[20][4]=true;
				board[20][5]=true;
				board[21][5]=true;
				this->xPosition=5;
				this->yPosition=21;
				this->rotationCenterX=4;
				this->rotationCenterY=20;
				/* x and y point
				    +
				- - -
				*/
				//squareX
				squareCoordinates[0]=3;
				squareCoordinates[1]=4;
				squareCoordinates[2]=5;
				squareCoordinates[3]=5;
				//squareY
				squareCoordinates[4]=20;
				squareCoordinates[5]=20;
				squareCoordinates[6]=20;
				squareCoordinates[7]=21;
				break;
			case TETROMINO_ID::S:
				board[20][3]=true;
				board[20][4]=true;
				board[21][4]=true;
				board[21][5]=true;
				this->xPosition=5;
				this->yPosition=21;
				this->rotationCenterX=4;
				this->rotationCenterY=20;
				/* x and y point
				   - -
				 - +
				*/
				//squareX
				squareCoordinates[0]=3;
				squareCoordinates[1]=4;
				squareCoordinates[2]=4;
				squareCoordinates[3]=5;
				//squareY
				squareCoordinates[4]=20;
				squareCoordinates[5]=20;
				squareCoordinates[6]=21;
				squareCoordinates[7]=21;
				break;
			case TETROMINO_ID::Z:
				board[21][3]=true;
				board[21][4]=true;
				board[20][4]=true;
				board[20][5]=true;
				this->xPosition=3;
				this->yPosition=21;
				this->rotationCenterX=4;
				this->rotationCenterY=20;
				/* x and y point
				+ -
				  - -
				*/
				//squareX
				squareCoordinates[0]=3;
				squareCoordinates[1]=4;
				squareCoordinates[2]=4;
				squareCoordinates[3]=5;
				//squareY
				squareCoordinates[4]=21;
				squareCoordinates[5]=21;
				squareCoordinates[6]=20;
				squareCoordinates[7]=20;
				break;
			case TETROMINO_ID::O:
				board[21][4]=true;
				board[20][4]=true;
				board[21][5]=true;
				board[20][5]=true;
				this->xPosition=4;
				this->yPosition=20;
				this->rotationCenterX=4;
				this->rotationCenterY=20;
				/* x and y point
				  - -
					+ -
				*/
				//squareX
				squareCoordinates[0]=4;
				squareCoordinates[1]=4;
				squareCoordinates[2]=5;
				squareCoordinates[3]=5;
				//squareY
				squareCoordinates[4]=21;
				squareCoordinates[5]=20;
				squareCoordinates[6]=21;
				squareCoordinates[7]=20;
				break;
			case TETROMINO_ID::T:
				board[20][3]=true;
				board[20][4]=true;
				board[21][4]=true;
				board[20][5]=true;
				this->xPosition=4;
				this->yPosition=21;
				this->rotationCenterX=4;
				this->rotationCenterY=20;
				/* x and y point
					+
				- - -
				*/
				//squareX
				squareCoordinates[0]=3;
				squareCoordinates[1]=4;
				squareCoordinates[2]=4;
				squareCoordinates[3]=5;
				//squareY
				squareCoordinates[4]=20;
				squareCoordinates[5]=20;
				squareCoordinates[6]=21;
				squareCoordinates[7]=20;
				break;
		}
	}
	
	TETROMINO_ID getTetrominoID(){
		return this->tetrominoID;
	}

	void moveDown(bool board[][10]){
		updateValues(board,false);
		this->yPosition--;
		this->squareCoordinates[4]--;
		this->squareCoordinates[5]--;
		this->squareCoordinates[6]--;
		this->squareCoordinates[7]--;
		updateValues(board,true);
	}

	void moveUp(bool board[][10]){
		updateValues(board,false);
		this->yPosition++;
		this->squareCoordinates[4]++;
		this->squareCoordinates[5]++;
		this->squareCoordinates[6]++;
		this->squareCoordinates[7]++;
		updateValues(board,true);
	}

	void moveLeft(bool board[][10]){
		updateValues(board,false);
		this->xPosition--;
		this->squareCoordinates[0]--;
		this->squareCoordinates[1]--;
		this->squareCoordinates[2]--;
		this->squareCoordinates[3]--;
		updateValues(board,true);
	}

	void moveRight(bool board[][10]){
		updateValues(board,false);
		this->xPosition++;
		this->squareCoordinates[0]++;
		this->squareCoordinates[1]++;
		this->squareCoordinates[2]++;
		this->squareCoordinates[3]++;
		updateValues(board,true);
	}

	void rotateClockwise(bool board[][10]){
		updateValues(board,false);
		
		if(tetrominoID==TETROMINO_ID::O){
			updateValues(board,true);
			return;
		}
		else if(tetrominoID==TETROMINO_ID::I){
			if(rotationState==0){
				this->squareCoordinates[0]+=2;
				this->squareCoordinates[4]+=2;
				this->squareCoordinates[1]++;
				this->squareCoordinates[5]++;
				this->squareCoordinates[3]--;
				this->squareCoordinates[7]--;
				rotationState=1;
			}
			else if(rotationState==1){
				this->squareCoordinates[0]+=2;
				this->squareCoordinates[4]-=2;
				this->squareCoordinates[1]++;
				this->squareCoordinates[5]--;
				this->squareCoordinates[3]--;
				this->squareCoordinates[7]++;
				rotationState=2;
			}
			else if(rotationState==2){
				this->squareCoordinates[0]-=2;
				this->squareCoordinates[4]-=2;
				this->squareCoordinates[1]--;
				this->squareCoordinates[5]--;
				this->squareCoordinates[3]++;
				this->squareCoordinates[7]++;
				rotationState=3;
			}
			else if(rotationState==3){
				this->squareCoordinates[0]-=2;
				this->squareCoordinates[4]+=2;
				this->squareCoordinates[1]--;
				this->squareCoordinates[5]++;
				this->squareCoordinates[3]++;
				this->squareCoordinates[7]--;
				rotationState=0;
			}
		}
		else if(tetrominoID==TETROMINO_ID::J){
			if(rotationState==0){
				this->squareCoordinates[0]+=2;
				this->squareCoordinates[1]++;
				this->squareCoordinates[5]++;
				this->squareCoordinates[3]--;
				this->squareCoordinates[7]--;
				rotationState=1;
			}
			else if(rotationState==1){
				this->squareCoordinates[4]-=2;
				this->squareCoordinates[1]++;
				this->squareCoordinates[5]--;
				this->squareCoordinates[3]--;
				this->squareCoordinates[7]++;
				rotationState=2;
			}
			else if(rotationState==2){
				this->squareCoordinates[0]-=2;
				this->squareCoordinates[1]--;
				this->squareCoordinates[5]--;
				this->squareCoordinates[3]++;
				this->squareCoordinates[7]++;
				rotationState=3;
			}
			else if(rotationState==3){
				this->squareCoordinates[4]+=2;
				this->squareCoordinates[1]--;
				this->squareCoordinates[5]++;
				this->squareCoordinates[3]++;
				this->squareCoordinates[7]--;
				rotationState=0;
			}
		}
		else if(tetrominoID==TETROMINO_ID::L){
			if(rotationState==0){
				this->squareCoordinates[0]++;
				this->squareCoordinates[4]++;
				this->squareCoordinates[2]--;
				this->squareCoordinates[6]--;
				this->squareCoordinates[7]-=2;
				rotationState=1;
			}
			else if(rotationState==1){
				this->squareCoordinates[0]++;
				this->squareCoordinates[4]--;
				this->squareCoordinates[2]--;
				this->squareCoordinates[6]++;
				this->squareCoordinates[3]-=2;
				rotationState=2;
			}
			else if(rotationState==2){
				this->squareCoordinates[0]--;
				this->squareCoordinates[4]--;
				this->squareCoordinates[2]++;
				this->squareCoordinates[6]++;
				this->squareCoordinates[7]+=2;
				rotationState=3;
			}
			else if(rotationState==3){
				this->squareCoordinates[0]--;
				this->squareCoordinates[4]++;
				this->squareCoordinates[2]++;
				this->squareCoordinates[6]--;
				this->squareCoordinates[3]+=2;
				rotationState=0;
			}
		}
		else if(tetrominoID==TETROMINO_ID::T){
			if(rotationState==0){
				this->squareCoordinates[0]++;
				this->squareCoordinates[4]++;
				this->squareCoordinates[2]++;
				this->squareCoordinates[6]--;
				this->squareCoordinates[3]--;
				this->squareCoordinates[7]--;
				rotationState=1;
			}
			else if(rotationState==1){
				this->squareCoordinates[0]++;
				this->squareCoordinates[4]--;
				this->squareCoordinates[2]--;
				this->squareCoordinates[6]--;
				this->squareCoordinates[3]--;
				this->squareCoordinates[7]++;
				rotationState=2;
			}
			else if(rotationState==2){
				this->squareCoordinates[0]--;
				this->squareCoordinates[4]--;
				this->squareCoordinates[2]--;
				this->squareCoordinates[6]++;
				this->squareCoordinates[3]++;
				this->squareCoordinates[7]++;
				rotationState=3;
			}
			else if(rotationState==3){
				this->squareCoordinates[0]--;
				this->squareCoordinates[4]++;
				this->squareCoordinates[2]++;
				this->squareCoordinates[6]++;
				this->squareCoordinates[3]++;
				this->squareCoordinates[7]--;
				rotationState=0;
			}
		}
		else if(tetrominoID==TETROMINO_ID::S){
			if(rotationState==0){
				this->squareCoordinates[0]++;
				this->squareCoordinates[4]++;
				this->squareCoordinates[2]++;
				this->squareCoordinates[6]--;
				this->squareCoordinates[7]-=2;
				rotationState=1;
			}
			else if(rotationState==1){
				this->squareCoordinates[0]++;
				this->squareCoordinates[4]--;
				this->squareCoordinates[2]--;
				this->squareCoordinates[6]--;
				this->squareCoordinates[3]-=2;
				rotationState=2;
			}
			else if(rotationState==2){
				this->squareCoordinates[0]--;
				this->squareCoordinates[4]--;
				this->squareCoordinates[2]--;
				this->squareCoordinates[6]++;
				this->squareCoordinates[7]+=2;
				rotationState=3;
			}
			else if(rotationState==3){
				this->squareCoordinates[0]--;
				this->squareCoordinates[4]++;
				this->squareCoordinates[2]++;
				this->squareCoordinates[6]++;
				this->squareCoordinates[3]+=2;
				rotationState=0;
			}
		}
		else if(tetrominoID==TETROMINO_ID::Z){
			if(rotationState==0){
				this->squareCoordinates[0]+=2;
				this->squareCoordinates[1]++;
				this->squareCoordinates[5]--;
				this->squareCoordinates[3]--;
				this->squareCoordinates[7]--;
				rotationState=1;
			}
			else if(rotationState==1){
				this->squareCoordinates[4]-=2;
				this->squareCoordinates[1]--;
				this->squareCoordinates[5]--;
				this->squareCoordinates[3]--;
				this->squareCoordinates[7]++;
				rotationState=2;
			}
			else if(rotationState==2){
				this->squareCoordinates[0]-=2;
				this->squareCoordinates[1]--;
				this->squareCoordinates[5]++;
				this->squareCoordinates[3]++;
				this->squareCoordinates[7]++;
				rotationState=3;
			}
			else if(rotationState==3){
				this->squareCoordinates[4]+=2;
				this->squareCoordinates[1]++;
				this->squareCoordinates[5]++;
				this->squareCoordinates[3]++;
				this->squareCoordinates[7]--;
				rotationState=0;
			}
		}		
		updateValues(board,true);
	}

	void rotateCounterClockwise(bool board[][10]){
		updateValues(board,false);
		if(tetrominoID==TETROMINO_ID::O){
			updateValues(board,true);
			return;
		}
		else if(tetrominoID==TETROMINO_ID::I){
			if(rotationState==0){
				this->squareCoordinates[0]+=2;
				this->squareCoordinates[4]-=2;
				this->squareCoordinates[1]++;
				this->squareCoordinates[5]--;
				this->squareCoordinates[3]--;
				this->squareCoordinates[7]++;
				rotationState=3;
			}
			else if(rotationState==3){
				this->squareCoordinates[0]+=2;
				this->squareCoordinates[4]+=2;
				this->squareCoordinates[1]++;
				this->squareCoordinates[5]++;
				this->squareCoordinates[3]--;
				this->squareCoordinates[7]--;
				rotationState=2;
			}
			else if(rotationState==2){
				this->squareCoordinates[0]-=2;
				this->squareCoordinates[4]+=2;
				this->squareCoordinates[1]--;
				this->squareCoordinates[5]++;
				this->squareCoordinates[3]++;
				this->squareCoordinates[7]--;
				rotationState=1;
			}
			else if(rotationState==1){
				this->squareCoordinates[0]-=2;
				this->squareCoordinates[4]-=2;
				this->squareCoordinates[1]--;
				this->squareCoordinates[5]--;
				this->squareCoordinates[3]++;
				this->squareCoordinates[7]++;
				rotationState=0;
			}
		}
		else if(tetrominoID==TETROMINO_ID::J){
			if(rotationState==0){
				this->squareCoordinates[4]-=2;
				this->squareCoordinates[1]++;
				this->squareCoordinates[5]--;
				this->squareCoordinates[3]--;
				this->squareCoordinates[7]++;
				rotationState=3;
			}
			else if(rotationState==3){
				this->squareCoordinates[0]+=2;
				this->squareCoordinates[1]++;
				this->squareCoordinates[5]++;
				this->squareCoordinates[3]--;
				this->squareCoordinates[7]--;
				rotationState=2;
			}
			else if(rotationState==2){
				this->squareCoordinates[4]+=2;
				this->squareCoordinates[1]--;
				this->squareCoordinates[5]++;
				this->squareCoordinates[3]++;
				this->squareCoordinates[7]--;
				rotationState=1;
			}
			else if(rotationState==1){
				this->squareCoordinates[0]-=2;
				this->squareCoordinates[1]--;
				this->squareCoordinates[5]--;
				this->squareCoordinates[3]++;
				this->squareCoordinates[7]++;
				rotationState=0;
			}
		}
		else if(tetrominoID==TETROMINO_ID::L){
			if(rotationState==0){
				this->squareCoordinates[0]++;
				this->squareCoordinates[4]--;
				this->squareCoordinates[2]--;
				this->squareCoordinates[6]++;
				this->squareCoordinates[3]-=2;
				rotationState=3;
			}
			else if(rotationState==3){
				this->squareCoordinates[0]++;
				this->squareCoordinates[4]++;
				this->squareCoordinates[2]--;
				this->squareCoordinates[6]--;
				this->squareCoordinates[7]-=2;
				rotationState=2;
			}
			else if(rotationState==2){
				this->squareCoordinates[0]--;
				this->squareCoordinates[4]++;
				this->squareCoordinates[2]++;
				this->squareCoordinates[6]--;
				this->squareCoordinates[3]+=2;
				rotationState=1;
			}
			else if(rotationState==1){
				this->squareCoordinates[0]--;
				this->squareCoordinates[4]--;
				this->squareCoordinates[2]++;
				this->squareCoordinates[6]++;
				this->squareCoordinates[7]+=2;
				rotationState=0;
			}
		}
		else if(tetrominoID==TETROMINO_ID::T){
			if(rotationState==0){
				this->squareCoordinates[0]++;
				this->squareCoordinates[4]--;
				this->squareCoordinates[2]--;
				this->squareCoordinates[6]--;
				this->squareCoordinates[3]--;
				this->squareCoordinates[7]++;
				rotationState=3;
			}
			else if(rotationState==3){
				this->squareCoordinates[0]++;
				this->squareCoordinates[4]++;
				this->squareCoordinates[2]++;
				this->squareCoordinates[6]--;
				this->squareCoordinates[3]--;
				this->squareCoordinates[7]--;
				rotationState=2;
			}
			else if(rotationState==2){
				this->squareCoordinates[0]--;
				this->squareCoordinates[4]++;
				this->squareCoordinates[2]++;
				this->squareCoordinates[6]++;
				this->squareCoordinates[3]++;
				this->squareCoordinates[7]--;
				rotationState=1;
			}
			else if(rotationState==1){
				this->squareCoordinates[0]--;
				this->squareCoordinates[4]--;
				this->squareCoordinates[2]--;
				this->squareCoordinates[6]++;
				this->squareCoordinates[3]++;
				this->squareCoordinates[7]++;
				rotationState=0;
			}
		}
		else if(tetrominoID==TETROMINO_ID::S){
			if(rotationState==0){
				this->squareCoordinates[0]++;
				this->squareCoordinates[4]--;
				this->squareCoordinates[2]--;
				this->squareCoordinates[6]--;
				this->squareCoordinates[3]-=2;
				rotationState=3;
			}
			else if(rotationState==3){
				this->squareCoordinates[0]++;
				this->squareCoordinates[4]++;
				this->squareCoordinates[2]++;
				this->squareCoordinates[6]--;
				this->squareCoordinates[7]-=2;
				rotationState=2;
			}
			else if(rotationState==2){
				this->squareCoordinates[0]--;
				this->squareCoordinates[4]++;
				this->squareCoordinates[2]++;
				this->squareCoordinates[6]++;
				this->squareCoordinates[3]+=2;
				rotationState=1;
			}
			else if(rotationState==1){
				this->squareCoordinates[0]--;
				this->squareCoordinates[4]--;
				this->squareCoordinates[2]--;
				this->squareCoordinates[6]++;
				this->squareCoordinates[7]+=2;
				rotationState=0;
			}
		}
		else if(tetrominoID==TETROMINO_ID::Z){
			if(rotationState==0){
				this->squareCoordinates[4]-=2;
				this->squareCoordinates[1]--;
				this->squareCoordinates[5]--;
				this->squareCoordinates[3]--;
				this->squareCoordinates[7]++;
				rotationState=3;
			}
			else if(rotationState==3){
				this->squareCoordinates[0]+=2;
				this->squareCoordinates[1]++;
				this->squareCoordinates[5]--;
				this->squareCoordinates[3]--;
				this->squareCoordinates[7]--;
				rotationState=2;
			}
			else if(rotationState==2){
				this->squareCoordinates[4]+=2;
				this->squareCoordinates[1]++;
				this->squareCoordinates[5]++;
				this->squareCoordinates[3]++;
				this->squareCoordinates[7]--;
				rotationState=1;
			}
			else if(rotationState==1){
				this->squareCoordinates[0]-=2;
				this->squareCoordinates[1]--;
				this->squareCoordinates[5]++;
				this->squareCoordinates[3]++;
				this->squareCoordinates[7]++;
				rotationState=0;
			}
		}	
		updateValues(board,true);
	}

	bool willCollide(bool board[][10],int direction){
		if(direction==1){
			for(int i=0;i<4;i++){
				if(board[squareCoordinates[i+4]][squareCoordinates[i]+1]){
					if(!((squareCoordinates[0]==squareCoordinates[i]+1)&&(squareCoordinates[4]==squareCoordinates[i+4])||
						   (squareCoordinates[1]==squareCoordinates[i]+1)&&(squareCoordinates[5]==squareCoordinates[i+4])||
							 (squareCoordinates[2]==squareCoordinates[i]+1)&&(squareCoordinates[6]==squareCoordinates[i+4])||
							 (squareCoordinates[3]==squareCoordinates[i]+1)&&(squareCoordinates[7]==squareCoordinates[i+4]))
						){
						return true;
					}		
				}
			}
			return false;
		}

		if(direction==-1){
			for(int i=0;i<4;i++){
				if(board[squareCoordinates[i+4]][squareCoordinates[i]-1]){
					if(!((squareCoordinates[0]==squareCoordinates[i]-1)&&(squareCoordinates[4]==squareCoordinates[i+4])||
						   (squareCoordinates[1]==squareCoordinates[i]-1)&&(squareCoordinates[5]==squareCoordinates[i+4])||
							 (squareCoordinates[2]==squareCoordinates[i]-1)&&(squareCoordinates[6]==squareCoordinates[i+4])||
							 (squareCoordinates[3]==squareCoordinates[i]-1)&&(squareCoordinates[7]==squareCoordinates[i+4]))
						){
						return true;
					}					
				}
			}
			return false;
		}

		if(direction==0){
			for(int i=0;i<4;i++){
				if(board[squareCoordinates[i+4]-1][squareCoordinates[i]]){
					if(!((squareCoordinates[0]==squareCoordinates[i])&&(squareCoordinates[4]==squareCoordinates[i+4]-1)||
						   (squareCoordinates[1]==squareCoordinates[i])&&(squareCoordinates[5]==squareCoordinates[i+4]-1)||
							 (squareCoordinates[2]==squareCoordinates[i])&&(squareCoordinates[6]==squareCoordinates[i+4]-1)||
							 (squareCoordinates[3]==squareCoordinates[i])&&(squareCoordinates[7]==squareCoordinates[i+4]-1))
						){
						return true;
					}		
				}
			}
			return false;
		}

		if(direction==-2){
			if(rotationState==0){
				if(board[squareCoordinates[4]+2][squareCoordinates[0]+2]||
					 board[squareCoordinates[5]+1][squareCoordinates[1]+1]||
					 board[squareCoordinates[7]-1][squareCoordinates[3]-1]
					){
					return true;
				}
			}
			else if(rotationState==1){
				if(board[squareCoordinates[4]-2][squareCoordinates[0]+2]||
					 board[squareCoordinates[5]-1][squareCoordinates[1]+1]||
					 board[squareCoordinates[7]+1][squareCoordinates[3]-1]
					){
					return true;
				}
			}
			else if(rotationState==2){
				if(board[squareCoordinates[4]-2][squareCoordinates[0]-2]||
					 board[squareCoordinates[5]-1][squareCoordinates[1]-1]||
					 board[squareCoordinates[7]+1][squareCoordinates[3]+1]
					){
					return true;
				}
			}
			else if(rotationState==3){
				if(board[squareCoordinates[4]+2][squareCoordinates[2]-2]||
					 board[squareCoordinates[5]+1][squareCoordinates[1]-1]||
					 board[squareCoordinates[7]-1][squareCoordinates[3]+1]
					){
					return true;
				}
			}
			return false;
		}
		return false;
	}

	bool willCollideEdges(bool board[][10],int direction){
		if(direction==0){
			if(squareCoordinates[4]-2<0||squareCoordinates[5]-2<0||squareCoordinates[6]-2<0||squareCoordinates[7]-2<0){
				return true;
			}
			else{
				return false;
			}
		}
		if(direction==1){
			if(squareCoordinates[0]+1>9||squareCoordinates[1]+1>9||squareCoordinates[2]+1>9||squareCoordinates[3]+1>9){
				return true;
			}
			else{
				return false;
			}
		}
		if(direction==-1){
			if(squareCoordinates[0]-1<0||squareCoordinates[1]-1<0||squareCoordinates[2]-1<0||squareCoordinates[3]-1<0){
				return true;
			}
			else{
				return false;
			}
		}
		return false;
	}
	
	#define LEFTMOST 0
	#define RIGHTMOST 9
	#define UPPERMOST 20
	#define DOWNARDSMOST 1

	bool willCollideOnRotateCW(bool board[][10]){
		if(tetrominoID==TETROMINO_ID::I){
			if(rotationState==0){
				if(board[squareCoordinates[4]+2][squareCoordinates[0]+2]||
					 board[squareCoordinates[5]+1][squareCoordinates[1]+1]||
					 board[squareCoordinates[7]-1][squareCoordinates[3]-1]){
					return true;
				}
				if(squareCoordinates[0]+2>RIGHTMOST||
					 squareCoordinates[0]+2<LEFTMOST||
					 squareCoordinates[4]+2>UPPERMOST||
					squareCoordinates[4]+2<DOWNARDSMOST||
					squareCoordinates[1]+1>RIGHTMOST||
					squareCoordinates[1]+1<LEFTMOST||
					squareCoordinates[5]+1>UPPERMOST||
					squareCoordinates[5]+1<DOWNARDSMOST||
					squareCoordinates[3]-1>RIGHTMOST||
					squareCoordinates[3]-1<LEFTMOST||
					squareCoordinates[7]-1>UPPERMOST||
					squareCoordinates[7]-1<DOWNARDSMOST){
					return true;
				}
			}
			else if(rotationState==1){
				if(board[squareCoordinates[4]-2][squareCoordinates[0]+2]||
					board[squareCoordinates[5]-1][squareCoordinates[1]+1]||
					board[squareCoordinates[7]+1][squareCoordinates[3]-1]){
					return true;
				}
				if(squareCoordinates[0]+2>RIGHTMOST||
					squareCoordinates[0]+2<LEFTMOST||
					squareCoordinates[4]-2>UPPERMOST||
					squareCoordinates[4]-2<DOWNARDSMOST||
					squareCoordinates[1]+1>RIGHTMOST||
					squareCoordinates[1]+1<LEFTMOST||
					squareCoordinates[5]-1>UPPERMOST||
					squareCoordinates[5]-1<DOWNARDSMOST||
					squareCoordinates[3]-1>RIGHTMOST||
					squareCoordinates[3]-1<LEFTMOST||
					squareCoordinates[7]+1>UPPERMOST||
					squareCoordinates[7]+1<DOWNARDSMOST){
					return true;
				}
			}
			else if(rotationState==2){
				if(board[squareCoordinates[4]-2][squareCoordinates[0]-2]||
					board[squareCoordinates[5]-1][squareCoordinates[1]-1]||
					board[squareCoordinates[7]+1][squareCoordinates[3]+1]){
					return true;
				}
				if(squareCoordinates[0]-2>RIGHTMOST||
					squareCoordinates[0]-2<LEFTMOST||
					squareCoordinates[4]-2>UPPERMOST||
					squareCoordinates[4]-2<DOWNARDSMOST||
					squareCoordinates[1]-1>RIGHTMOST||
					squareCoordinates[1]-1<LEFTMOST||
					squareCoordinates[5]-1>UPPERMOST||
					squareCoordinates[5]-1<DOWNARDSMOST||
					squareCoordinates[3]+1>RIGHTMOST||
					squareCoordinates[3]+1<LEFTMOST||
					squareCoordinates[7]+1>UPPERMOST||
					squareCoordinates[7]+1<DOWNARDSMOST){
					return true;
				}
			}
			else if(rotationState==3){
				if(board[squareCoordinates[4]+2][squareCoordinates[0]-2]||
					board[squareCoordinates[5]+1][squareCoordinates[1]-1]||
					board[squareCoordinates[7]-1][squareCoordinates[3]+1]){
					return true;
				}
				if(squareCoordinates[0]-2>RIGHTMOST||
					squareCoordinates[0]-2<LEFTMOST||
					squareCoordinates[4]+2>UPPERMOST||
					squareCoordinates[4]+2<DOWNARDSMOST||
					squareCoordinates[1]-1>RIGHTMOST||
					squareCoordinates[1]-1<LEFTMOST||
					squareCoordinates[5]+1>UPPERMOST||
					squareCoordinates[5]+1<DOWNARDSMOST||
					squareCoordinates[3]+1>RIGHTMOST||
					squareCoordinates[3]+1<LEFTMOST||
					squareCoordinates[7]-1>UPPERMOST||
					squareCoordinates[7]-1<DOWNARDSMOST){
					return true;
				}
			}
		}
		else if(tetrominoID==TETROMINO_ID::J){
			if(rotationState==0){
				if(board[squareCoordinates[4]][squareCoordinates[0]+2]||
					board[squareCoordinates[5]+1][squareCoordinates[1]+1]||
					board[squareCoordinates[7]-1][squareCoordinates[3]-1]){
					return true;
				}
				if(squareCoordinates[0]+2>RIGHTMOST||
					squareCoordinates[0]+2<LEFTMOST||
					squareCoordinates[1]+1>RIGHTMOST||
					squareCoordinates[1]+1<LEFTMOST||
					squareCoordinates[5]+1>UPPERMOST||
					squareCoordinates[5]+1<DOWNARDSMOST||
					squareCoordinates[3]-1>RIGHTMOST||
					squareCoordinates[3]-1<LEFTMOST||
					squareCoordinates[7]-1>UPPERMOST||
					squareCoordinates[7]-1<DOWNARDSMOST){
					return true;
				}
			}
			else if(rotationState==1){
				if(board[squareCoordinates[4]-2][squareCoordinates[0]]||
					board[squareCoordinates[5]-1][squareCoordinates[1]+1]||
					board[squareCoordinates[7]+1][squareCoordinates[3]-1]){
					return true;
				}
				if(squareCoordinates[0]>RIGHTMOST||
					squareCoordinates[0]<LEFTMOST||
					squareCoordinates[4]-2>UPPERMOST||
					squareCoordinates[4]-2<DOWNARDSMOST||
					squareCoordinates[1]+1>RIGHTMOST||
					squareCoordinates[1]+1<LEFTMOST||
					squareCoordinates[5]-1>UPPERMOST||
					squareCoordinates[5]-1<DOWNARDSMOST||
					squareCoordinates[3]-1>RIGHTMOST||
					squareCoordinates[3]-1<LEFTMOST||
					squareCoordinates[7]+1>UPPERMOST||
					squareCoordinates[7]+1<DOWNARDSMOST){
					return true;
				}
			}
			else if(rotationState==2){
				if(board[squareCoordinates[4]][squareCoordinates[0]-2]||
					board[squareCoordinates[5]-1][squareCoordinates[1]-1]||
					board[squareCoordinates[7]+1][squareCoordinates[3]+1]){
					return true;
				}
				if(squareCoordinates[0]-2>RIGHTMOST||
					squareCoordinates[0]-2<LEFTMOST||
					squareCoordinates[1]-1>RIGHTMOST||
					squareCoordinates[1]-1<LEFTMOST||
					squareCoordinates[5]-1>UPPERMOST||
					squareCoordinates[5]-1<DOWNARDSMOST||
					squareCoordinates[3]+1>RIGHTMOST||
					squareCoordinates[3]+1<LEFTMOST||
					squareCoordinates[7]+1>UPPERMOST||
					squareCoordinates[7]+1<DOWNARDSMOST){
					return true;
				}
			}
			else if(rotationState==3){
				if(board[squareCoordinates[4]+2][squareCoordinates[0]]||
					board[squareCoordinates[5]+1][squareCoordinates[1]-1]||
					board[squareCoordinates[7]-1][squareCoordinates[3]+1]){
					return true;
				}
				if(squareCoordinates[4]+2>UPPERMOST||
					squareCoordinates[4]+2<DOWNARDSMOST||
					squareCoordinates[1]-1>RIGHTMOST||
					squareCoordinates[1]-1<LEFTMOST||
					squareCoordinates[5]+1>UPPERMOST||
					squareCoordinates[5]+1<DOWNARDSMOST||
					squareCoordinates[3]+1>RIGHTMOST||
					squareCoordinates[3]+1<LEFTMOST||
					squareCoordinates[7]-1>UPPERMOST||
					squareCoordinates[7]-1<DOWNARDSMOST){
					return true;
				}
			}
		}
		else if(tetrominoID==TETROMINO_ID::L){
			if(rotationState==0){
				if(board[squareCoordinates[4]+1][squareCoordinates[0]+1]||
					board[squareCoordinates[6]-1][squareCoordinates[2]-1]||
					board[squareCoordinates[7]-2][squareCoordinates[3]]){
					return true;
				}
				if(squareCoordinates[0]+1>RIGHTMOST||
					squareCoordinates[0]+1<LEFTMOST||
					squareCoordinates[4]+1>UPPERMOST||
					squareCoordinates[4]+1<DOWNARDSMOST||
					squareCoordinates[2]-1>RIGHTMOST||
					squareCoordinates[2]-1<LEFTMOST||
					squareCoordinates[6]-1>UPPERMOST||
					squareCoordinates[6]-1<DOWNARDSMOST||
					squareCoordinates[7]-2>UPPERMOST||
					squareCoordinates[7]-2<DOWNARDSMOST){
					return true;
				}
			}
			else if(rotationState==1){
				if(board[squareCoordinates[4]-1][squareCoordinates[0]+1]||
					board[squareCoordinates[6]+1][squareCoordinates[2]-1]||
					board[squareCoordinates[7]][squareCoordinates[3]-2]){
					return true;
				}
				if(squareCoordinates[0]+1>RIGHTMOST||
					squareCoordinates[0]+1<LEFTMOST||
					squareCoordinates[4]-1>UPPERMOST||
					squareCoordinates[4]-1<DOWNARDSMOST||
					squareCoordinates[2]-1>RIGHTMOST||
					squareCoordinates[2]-1<LEFTMOST||
					squareCoordinates[6]+1>UPPERMOST||
					squareCoordinates[6]+1<DOWNARDSMOST||
					squareCoordinates[3]-2>RIGHTMOST||
					squareCoordinates[3]-2<LEFTMOST){
					return true;
				}
			}
			else if(rotationState==2){
				if(board[squareCoordinates[4]-1][squareCoordinates[0]-1]||
					board[squareCoordinates[6]+1][squareCoordinates[2]+1]||
					board[squareCoordinates[7]+2][squareCoordinates[3]]){
					return true;
				}
				if(squareCoordinates[0]-1>RIGHTMOST||
					squareCoordinates[0]-1<LEFTMOST||
					squareCoordinates[4]-1>UPPERMOST||
					squareCoordinates[4]-1<DOWNARDSMOST||
					squareCoordinates[2]+1>RIGHTMOST||
					squareCoordinates[2]+1<LEFTMOST||
					squareCoordinates[6]+1>UPPERMOST||
					squareCoordinates[6]+1<DOWNARDSMOST||
					squareCoordinates[7]+2>UPPERMOST||
					squareCoordinates[7]+2<DOWNARDSMOST){
					return true;
				}
			}
			else if(rotationState==3){
				if((board[squareCoordinates[4]+1][squareCoordinates[0]-1])||
					(board[squareCoordinates[6]-1][squareCoordinates[2]+1])||
					(board[squareCoordinates[7]][squareCoordinates[3]+2])){
					return true;
				}
				if(squareCoordinates[0]-1>RIGHTMOST||
					squareCoordinates[0]-1<LEFTMOST||
					squareCoordinates[4]+1>UPPERMOST||
					squareCoordinates[4]+1<DOWNARDSMOST||
					squareCoordinates[2]+1>RIGHTMOST||
					squareCoordinates[2]+1<LEFTMOST||
					squareCoordinates[6]-1>UPPERMOST||
					squareCoordinates[6]-1<DOWNARDSMOST||
					squareCoordinates[3]+2>RIGHTMOST||
					squareCoordinates[3]+2<LEFTMOST){
					return true;
				}
			}
		}
		else if(tetrominoID==TETROMINO_ID::S){
			if(rotationState==0){
				if((board[squareCoordinates[4]+1][squareCoordinates[0]+1]&&isNotSamePiece(board,squareCoordinates[0]+1,squareCoordinates[4]+1))||
					(board[squareCoordinates[6]-1][squareCoordinates[2]+1]&&isNotSamePiece(board,squareCoordinates[2]+1,squareCoordinates[6]-1))||
					(board[squareCoordinates[7]-2][squareCoordinates[3]]&&isNotSamePiece(board,squareCoordinates[3],squareCoordinates[7]-2))){
					return true;
				}
				if(squareCoordinates[0]+1>RIGHTMOST||
					squareCoordinates[0]+1<LEFTMOST||
					squareCoordinates[4]+1>UPPERMOST||
					squareCoordinates[4]+1<DOWNARDSMOST||
					squareCoordinates[2]+1>RIGHTMOST||
					squareCoordinates[2]+1<LEFTMOST||
					squareCoordinates[6]-1>UPPERMOST||
					squareCoordinates[6]-1<DOWNARDSMOST||
					squareCoordinates[7]-2>UPPERMOST||
					squareCoordinates[7]-2<DOWNARDSMOST){
					return true;
				}
			}
			else if(rotationState==1){
				if((board[squareCoordinates[4]-1][squareCoordinates[0]+1]&&isNotSamePiece(board,squareCoordinates[0]+1,squareCoordinates[4]-1))||
					(board[squareCoordinates[6]-1][squareCoordinates[2]-1]&&isNotSamePiece(board,squareCoordinates[2]-1,squareCoordinates[6]-1))||
					(board[squareCoordinates[7]][squareCoordinates[3]-2]&&isNotSamePiece(board,squareCoordinates[3]-2,squareCoordinates[7]))){
					return true;
				}
				if(squareCoordinates[0]+1>RIGHTMOST||
					squareCoordinates[0]+1<LEFTMOST||
					squareCoordinates[4]-1>UPPERMOST||
					squareCoordinates[4]-1<DOWNARDSMOST||
					squareCoordinates[2]-1>RIGHTMOST||
					squareCoordinates[2]-1<LEFTMOST||
					squareCoordinates[6]-1>UPPERMOST||
					squareCoordinates[6]-1<DOWNARDSMOST||
					squareCoordinates[3]-2>RIGHTMOST||
					squareCoordinates[3]-2<LEFTMOST){
					return true;
				}
			}
			else if(rotationState==2){
				if((board[squareCoordinates[4]-1][squareCoordinates[0]-1]&&isNotSamePiece(board,squareCoordinates[0]-1,squareCoordinates[4]-1))||
					(board[squareCoordinates[6]+1][squareCoordinates[2]-1]&&isNotSamePiece(board,squareCoordinates[2]-1,squareCoordinates[6]+1))||
					(board[squareCoordinates[7]+2][squareCoordinates[3]]&&isNotSamePiece(board,squareCoordinates[3],squareCoordinates[7]+2))){
					return true;
				}
				if(squareCoordinates[0]-1>RIGHTMOST||
					squareCoordinates[0]-1<LEFTMOST||
					squareCoordinates[4]-1>UPPERMOST||
					squareCoordinates[4]-1<DOWNARDSMOST||
					squareCoordinates[2]-1>RIGHTMOST||
					squareCoordinates[2]-1<LEFTMOST||
					squareCoordinates[6]+1>UPPERMOST||
					squareCoordinates[6]+1<DOWNARDSMOST||
					squareCoordinates[7]+2>UPPERMOST||
					squareCoordinates[7]+2<DOWNARDSMOST){
					return true;
				}
			}
			else if(rotationState==3){
				if((board[squareCoordinates[4]+1][squareCoordinates[0]-1]&&isNotSamePiece(board,squareCoordinates[0]-1,squareCoordinates[4]+1))||
					(board[squareCoordinates[6]+1][squareCoordinates[2]+1]&&isNotSamePiece(board,squareCoordinates[2]+1,squareCoordinates[6]+1))||
					(board[squareCoordinates[7]][squareCoordinates[3]+2]&&isNotSamePiece(board,squareCoordinates[3]+2,squareCoordinates[7]))){
					return true;
				}
				if(squareCoordinates[0]-1>RIGHTMOST||
					squareCoordinates[0]-1<LEFTMOST||
					squareCoordinates[4]+1>UPPERMOST||
					squareCoordinates[4]+1<DOWNARDSMOST||
					squareCoordinates[2]+1>RIGHTMOST||
					squareCoordinates[2]+1<LEFTMOST||
					squareCoordinates[6]+1>UPPERMOST||
					squareCoordinates[6]+1<DOWNARDSMOST||
					squareCoordinates[3]+2>RIGHTMOST||
					squareCoordinates[3]+2<LEFTMOST){
					return true;
				}
			}
		}
		else if(tetrominoID==TETROMINO_ID::Z){
			if(rotationState==0){
				if((board[squareCoordinates[4]][squareCoordinates[0]+2]&&isNotSamePiece(board,squareCoordinates[0]+2,squareCoordinates[4]))||
					(board[squareCoordinates[5]-1][squareCoordinates[1]+1]&&isNotSamePiece(board,squareCoordinates[1]+1,squareCoordinates[5]-1))||
					(board[squareCoordinates[7]-1][squareCoordinates[3]-1]&&isNotSamePiece(board,squareCoordinates[3]-1,squareCoordinates[7]-1))){
					return true;
				}
				if(squareCoordinates[0]+2>RIGHTMOST||
					squareCoordinates[0]+2<LEFTMOST||
					squareCoordinates[1]+1>RIGHTMOST||
					squareCoordinates[1]+1<LEFTMOST||
					squareCoordinates[5]-1>UPPERMOST||
					squareCoordinates[5]-1<DOWNARDSMOST||
					squareCoordinates[3]-1>RIGHTMOST||
					squareCoordinates[3]-1<LEFTMOST||
					squareCoordinates[7]-1>UPPERMOST||
					squareCoordinates[7]-1<DOWNARDSMOST){
					return true;
				}
			}
			else if(rotationState==1){
				if((board[squareCoordinates[4]-2][squareCoordinates[0]]&&isNotSamePiece(board,squareCoordinates[0],squareCoordinates[4]-2))||
					(board[squareCoordinates[5]-1][squareCoordinates[1]-1]&&isNotSamePiece(board,squareCoordinates[1]-1,squareCoordinates[5]-1))||
					(board[squareCoordinates[7]+1][squareCoordinates[3]-1]&&isNotSamePiece(board,squareCoordinates[3]-1,squareCoordinates[7]+1))){
					return true;
				}
				if(squareCoordinates[4]-2>UPPERMOST||
					squareCoordinates[4]-2<DOWNARDSMOST||
					squareCoordinates[1]-1>RIGHTMOST||
					squareCoordinates[1]-1<LEFTMOST||
					squareCoordinates[5]-1>UPPERMOST||
					squareCoordinates[5]-1<DOWNARDSMOST||
					squareCoordinates[3]-1>RIGHTMOST||
					squareCoordinates[3]-1<LEFTMOST||
					squareCoordinates[7]+1>UPPERMOST||
					squareCoordinates[7]+1<DOWNARDSMOST){
					return true;
				}
			}
			else if(rotationState==2){
				if((board[squareCoordinates[4]][squareCoordinates[0]-2]&&isNotSamePiece(board,squareCoordinates[0]-2,squareCoordinates[4]))||
					(board[squareCoordinates[5]+1][squareCoordinates[1]-1]&&isNotSamePiece(board,squareCoordinates[1]-1,squareCoordinates[5]+1))||
					(board[squareCoordinates[7]+1][squareCoordinates[3]+1]&&isNotSamePiece(board,squareCoordinates[3]+1,squareCoordinates[7]+1))){
					return true;
				}
				if(squareCoordinates[0]-2>RIGHTMOST||
					squareCoordinates[0]-2<LEFTMOST||
					squareCoordinates[1]-1>RIGHTMOST||
					squareCoordinates[1]-1<LEFTMOST||
					squareCoordinates[5]+1>UPPERMOST||
					squareCoordinates[5]+1<DOWNARDSMOST||
					squareCoordinates[3]+1>RIGHTMOST||
					squareCoordinates[3]+1<LEFTMOST||
					squareCoordinates[7]+1>UPPERMOST||
					squareCoordinates[7]+1<DOWNARDSMOST){
					return true;
				}
			}
			else if(rotationState==3){
				if((board[squareCoordinates[4]+2][squareCoordinates[0]]&&isNotSamePiece(board,squareCoordinates[0],squareCoordinates[4]+2))||
					(board[squareCoordinates[5]+1][squareCoordinates[1]+1]&&isNotSamePiece(board,squareCoordinates[1]+1,squareCoordinates[5]+1))||
					(board[squareCoordinates[7]-1][squareCoordinates[3]+1]&&isNotSamePiece(board,squareCoordinates[3]+1,squareCoordinates[7]-1))){
					return true;
				}
				if(squareCoordinates[4]+2>UPPERMOST||
					squareCoordinates[4]+2<DOWNARDSMOST||
					squareCoordinates[1]+1>RIGHTMOST||
					squareCoordinates[1]+1<LEFTMOST||
					squareCoordinates[5]+1>UPPERMOST||
					squareCoordinates[5]+1<DOWNARDSMOST||
					squareCoordinates[3]+1>RIGHTMOST||
					squareCoordinates[3]+1<LEFTMOST||
					squareCoordinates[7]-1>UPPERMOST||
					squareCoordinates[7]-1<DOWNARDSMOST){
					return true;
				}
			}
		}
		else if(tetrominoID==TETROMINO_ID::T){
			if(rotationState==0){
				if((board[squareCoordinates[4]+1][squareCoordinates[0]+1]&&isNotSamePiece(board,squareCoordinates[0]+1,squareCoordinates[4]+1))||
					(board[squareCoordinates[6]-1][squareCoordinates[2]+1]&&isNotSamePiece(board,squareCoordinates[2]+1,squareCoordinates[6]-1))||
					(board[squareCoordinates[7]-1][squareCoordinates[3]-1]&&isNotSamePiece(board,squareCoordinates[3]-1,squareCoordinates[7]-1))){
					return true;
				}
				if(squareCoordinates[0]+1>RIGHTMOST||
					squareCoordinates[0]+1<LEFTMOST||
					squareCoordinates[4]+1>UPPERMOST||
					squareCoordinates[4]+1<DOWNARDSMOST||
					squareCoordinates[2]+1>RIGHTMOST||
					squareCoordinates[2]+1<LEFTMOST||
					squareCoordinates[6]-1>UPPERMOST||
					squareCoordinates[6]-1<DOWNARDSMOST||
					squareCoordinates[3]-1>RIGHTMOST||
					squareCoordinates[3]-1<LEFTMOST||
					squareCoordinates[7]-1>UPPERMOST||
					squareCoordinates[7]-1<DOWNARDSMOST){
					return true;
				}
			}
			else if(rotationState==1){
				if((board[squareCoordinates[4]-1][squareCoordinates[0]+1]&&isNotSamePiece(board,squareCoordinates[0]+1,squareCoordinates[4]-1))||
					(board[squareCoordinates[6]-1][squareCoordinates[2]-1]&&isNotSamePiece(board,squareCoordinates[2]-1,squareCoordinates[6]-1))||
					(board[squareCoordinates[7]+1][squareCoordinates[3]-1]&&isNotSamePiece(board,squareCoordinates[3]-1,squareCoordinates[7]+1))){
					return true;
				}
				if(squareCoordinates[0]+1>RIGHTMOST||
					squareCoordinates[0]+1<LEFTMOST||
					squareCoordinates[4]-1>UPPERMOST||
					squareCoordinates[4]-1<DOWNARDSMOST||
					squareCoordinates[2]-1>RIGHTMOST||
					squareCoordinates[2]-1<LEFTMOST||
					squareCoordinates[6]-1>UPPERMOST||
					squareCoordinates[6]-1<DOWNARDSMOST||
					squareCoordinates[3]-1>RIGHTMOST||
					squareCoordinates[3]-1<LEFTMOST||
					squareCoordinates[7]+1>UPPERMOST||
					squareCoordinates[7]+1<DOWNARDSMOST){
					return true;
				}
			}
			else if(rotationState==2){
				if((board[squareCoordinates[4]-1][squareCoordinates[0]-1]&&isNotSamePiece(board,squareCoordinates[0]-1,squareCoordinates[4]-1))||
					(board[squareCoordinates[6]+1][squareCoordinates[2]-1]&&isNotSamePiece(board,squareCoordinates[2]-1,squareCoordinates[6]+1))||
					(board[squareCoordinates[7]+1][squareCoordinates[3]+1]&&isNotSamePiece(board,squareCoordinates[3]+1,squareCoordinates[7]+1))){
					return true;
				}
				if(squareCoordinates[0]-1>RIGHTMOST||
					squareCoordinates[0]-1<LEFTMOST||
					squareCoordinates[4]-1>UPPERMOST||
					squareCoordinates[4]-1<DOWNARDSMOST||
					squareCoordinates[2]-1>RIGHTMOST||
					squareCoordinates[2]-1<LEFTMOST||
					squareCoordinates[6]+1>UPPERMOST||
					squareCoordinates[6]+1<DOWNARDSMOST||
					squareCoordinates[3]+1>RIGHTMOST||
					squareCoordinates[3]+1<LEFTMOST||
					squareCoordinates[7]+1>UPPERMOST||
					squareCoordinates[7]+1<DOWNARDSMOST){
					return true;
				}
			}
			else if(rotationState==3){
				if((board[squareCoordinates[4]+1][squareCoordinates[0]-1]&&isNotSamePiece(board,squareCoordinates[0]-1,squareCoordinates[4]+1))||
					(board[squareCoordinates[6]+1][squareCoordinates[2]+1]&&isNotSamePiece(board,squareCoordinates[2]+1,squareCoordinates[6]+1))||
					(board[squareCoordinates[7]-1][squareCoordinates[3]+1]&&isNotSamePiece(board,squareCoordinates[3]+1,squareCoordinates[7]-1))){
					return true;
				}
				if(squareCoordinates[0]-1>RIGHTMOST||
					squareCoordinates[0]-1<LEFTMOST||
					squareCoordinates[4]+1>UPPERMOST||
					squareCoordinates[4]+1<DOWNARDSMOST||
					squareCoordinates[2]+1>RIGHTMOST||
					squareCoordinates[2]+1<LEFTMOST||
					squareCoordinates[6]+1>UPPERMOST||
					squareCoordinates[6]+1<DOWNARDSMOST||
					squareCoordinates[3]+1>RIGHTMOST||
					squareCoordinates[3]+1<LEFTMOST||
					squareCoordinates[7]-1>UPPERMOST||
					squareCoordinates[7]-1<DOWNARDSMOST){
					return true;
				}
			}
		}
		return false;
	}

	bool willCollideOnRotateCCW(bool board[][10]){
		if(tetrominoID==TETROMINO_ID::I){
			if(rotationState==0){
				if(board[squareCoordinates[4]-2][squareCoordinates[0]+2]||
					board[squareCoordinates[5]-1][squareCoordinates[1]+1]||
					board[squareCoordinates[7]+1][squareCoordinates[3]-1]){
					return true;
				}
				if(squareCoordinates[0]+2>RIGHTMOST||
					 squareCoordinates[0]+2<LEFTMOST||
					 squareCoordinates[4]-2>UPPERMOST||
					 squareCoordinates[4]-2<DOWNARDSMOST||
					 squareCoordinates[1]+1>RIGHTMOST||
					 squareCoordinates[1]+1<LEFTMOST||
					 squareCoordinates[5]-1>UPPERMOST||
					 squareCoordinates[5]-1<DOWNARDSMOST||
					 squareCoordinates[3]-1>RIGHTMOST||
					 squareCoordinates[3]-1<LEFTMOST||
					 squareCoordinates[7]+1>UPPERMOST||
					 squareCoordinates[7]+1<DOWNARDSMOST){
					return true;
				}
			}
			else if(rotationState==1){
				if(board[squareCoordinates[4]-2][squareCoordinates[0]-2]||
					 board[squareCoordinates[5]-1][squareCoordinates[1]-1]||
					 board[squareCoordinates[7]+1][squareCoordinates[3]+1]){
					return true;
				}
				if(squareCoordinates[0]-2>RIGHTMOST||
					 squareCoordinates[0]-2<LEFTMOST||
					 squareCoordinates[4]-2>UPPERMOST||
					 squareCoordinates[4]-2<DOWNARDSMOST||
					 squareCoordinates[1]-1>RIGHTMOST||
					 squareCoordinates[1]-1<LEFTMOST||
					 squareCoordinates[5]-1>UPPERMOST||
					 squareCoordinates[5]-1<DOWNARDSMOST||
					 squareCoordinates[3]+1>RIGHTMOST||
					 squareCoordinates[3]+1<LEFTMOST||
					 squareCoordinates[7]+1>UPPERMOST||
					 squareCoordinates[7]+1<DOWNARDSMOST){
					return true;
				}	
			}
			else if(rotationState==2){
				if(board[squareCoordinates[4]+2][squareCoordinates[0]-2]||
					 board[squareCoordinates[5]+1][squareCoordinates[1]-1]||
					 board[squareCoordinates[7]-1][squareCoordinates[3]+1]){
					return true;
				}
				if(squareCoordinates[0]-2>RIGHTMOST||
					 squareCoordinates[0]-2<LEFTMOST||
					 squareCoordinates[4]+2>UPPERMOST||
					 squareCoordinates[4]+2<DOWNARDSMOST||
					 squareCoordinates[1]-1>RIGHTMOST||
					 squareCoordinates[1]-1<LEFTMOST||
					 squareCoordinates[5]+1>UPPERMOST||
					 squareCoordinates[5]+1<DOWNARDSMOST||
					 squareCoordinates[3]+1>RIGHTMOST||
					 squareCoordinates[3]+1<LEFTMOST||
					 squareCoordinates[7]-1>UPPERMOST||
					 squareCoordinates[7]-1<DOWNARDSMOST){
					return true;
				}		
			}
			else if(rotationState==3){
				if(board[squareCoordinates[4]+2][squareCoordinates[0]+2]||
					 board[squareCoordinates[5]+1][squareCoordinates[1]+1]||
					 board[squareCoordinates[7]-1][squareCoordinates[3]-1]){
					return true;
				}
				if(squareCoordinates[0]+2>RIGHTMOST||
					 squareCoordinates[0]+2<LEFTMOST||
					 squareCoordinates[4]+2>UPPERMOST||
					 squareCoordinates[4]+2<DOWNARDSMOST||
					 squareCoordinates[1]+1>RIGHTMOST||
					 squareCoordinates[1]+1<LEFTMOST||
					 squareCoordinates[5]+1>UPPERMOST||
					 squareCoordinates[5]+1<DOWNARDSMOST||
					 squareCoordinates[3]-1>RIGHTMOST||
					 squareCoordinates[3]-1<LEFTMOST||
					 squareCoordinates[7]-1>UPPERMOST||
					 squareCoordinates[7]-1<DOWNARDSMOST){
					return true;
				}			
			}
		}
		else if(tetrominoID==TETROMINO_ID::J){
			if(rotationState==0){
				if(board[squareCoordinates[4]-2][squareCoordinates[0]]||
					board[squareCoordinates[5]-1][squareCoordinates[1]+1]||
					board[squareCoordinates[7]+1][squareCoordinates[3]-1]){
					return true;
				}
				if(squareCoordinates[4]-2>UPPERMOST||
					 squareCoordinates[4]-2<DOWNARDSMOST||
					 squareCoordinates[1]+1>RIGHTMOST||
					 squareCoordinates[1]+1<LEFTMOST||
					 squareCoordinates[5]-1>UPPERMOST||
					 squareCoordinates[5]-1<DOWNARDSMOST||
					 squareCoordinates[3]-1>RIGHTMOST||
					 squareCoordinates[3]-1<LEFTMOST||
					 squareCoordinates[7]+1>UPPERMOST||
					 squareCoordinates[7]+1<DOWNARDSMOST){
					return true;
				}
			}
			else if(rotationState==1){
				if(board[squareCoordinates[4]][squareCoordinates[0]-2]||
					 board[squareCoordinates[5]-1][squareCoordinates[1]-1]||
					 board[squareCoordinates[7]+1][squareCoordinates[3]+1]){
					return true;
				}
				if(squareCoordinates[0]-2>RIGHTMOST||
					 squareCoordinates[0]-2<LEFTMOST||
					 squareCoordinates[1]-1>RIGHTMOST||
					 squareCoordinates[1]-1<LEFTMOST||
					 squareCoordinates[5]-1>UPPERMOST||
					 squareCoordinates[5]-1<DOWNARDSMOST||
					 squareCoordinates[3]+1>RIGHTMOST||
					 squareCoordinates[3]+1<LEFTMOST||
					 squareCoordinates[7]+1>UPPERMOST||
					 squareCoordinates[7]+1<DOWNARDSMOST){
					return true;
				}	
			}
			else if(rotationState==2){
				if(board[squareCoordinates[4]+2][squareCoordinates[0]]||
					 board[squareCoordinates[5]+1][squareCoordinates[1]-1]||
					 board[squareCoordinates[7]-1][squareCoordinates[3]+1]){
					return true;
				}
				if(squareCoordinates[4]+2>UPPERMOST||
					 squareCoordinates[4]+2<DOWNARDSMOST||
					 squareCoordinates[1]-1>RIGHTMOST||
					 squareCoordinates[1]-1<LEFTMOST||
					 squareCoordinates[5]+1>UPPERMOST||
					 squareCoordinates[5]+1<DOWNARDSMOST||
					 squareCoordinates[3]+1>RIGHTMOST||
					 squareCoordinates[3]+1<LEFTMOST||
					 squareCoordinates[7]-1>UPPERMOST||
					 squareCoordinates[7]-1<DOWNARDSMOST){
					return true;
				}		
			}
			else if(rotationState==3){
				if(board[squareCoordinates[4]][squareCoordinates[0]+2]||
					 board[squareCoordinates[5]+1][squareCoordinates[1]+1]||
					 board[squareCoordinates[7]-1][squareCoordinates[3]-1]){
					return true;
				}
				if(squareCoordinates[0]+2>RIGHTMOST||
					 squareCoordinates[0]+2<LEFTMOST||
					 squareCoordinates[1]+1>RIGHTMOST||
					 squareCoordinates[1]+1<LEFTMOST||
					 squareCoordinates[5]+1>UPPERMOST||
					 squareCoordinates[5]+1<DOWNARDSMOST||
					 squareCoordinates[3]-1>RIGHTMOST||
					 squareCoordinates[3]-1<LEFTMOST||
					 squareCoordinates[7]-1>UPPERMOST||
					 squareCoordinates[7]-1<DOWNARDSMOST){
					return true;
				}			
			}
		}
		else if(tetrominoID==TETROMINO_ID::L){
			if(rotationState==0){
				if(board[squareCoordinates[4]-1][squareCoordinates[0]+1]||
					board[squareCoordinates[6]+1][squareCoordinates[2]-1]||
					board[squareCoordinates[7]][squareCoordinates[3]-2]){
					return true;
				}
				if(squareCoordinates[0]+1>RIGHTMOST||
					 squareCoordinates[0]+1<LEFTMOST||
					 squareCoordinates[4]-1>UPPERMOST||
					 squareCoordinates[4]-1<DOWNARDSMOST||
					 squareCoordinates[2]-1>RIGHTMOST||
					 squareCoordinates[2]-1<LEFTMOST||
					 squareCoordinates[6]+1>UPPERMOST||
					 squareCoordinates[6]+1<DOWNARDSMOST||
					 squareCoordinates[3]-2>RIGHTMOST||
					 squareCoordinates[3]-2<LEFTMOST){
					return true;
				}
			}
			else if(rotationState==1){
				if(board[squareCoordinates[4]-1][squareCoordinates[0]-1]||
					board[squareCoordinates[6]+1][squareCoordinates[2]+1]||
					board[squareCoordinates[7]+2][squareCoordinates[3]]){
					return true;
				}
				if(squareCoordinates[0]-1>RIGHTMOST||
					 squareCoordinates[0]-1<LEFTMOST||
					 squareCoordinates[4]-1>UPPERMOST||
					 squareCoordinates[4]-1<DOWNARDSMOST||
					 squareCoordinates[2]+1>RIGHTMOST||
					 squareCoordinates[2]+1<LEFTMOST||
					 squareCoordinates[6]+1>UPPERMOST||
					 squareCoordinates[6]+1<DOWNARDSMOST||
					 squareCoordinates[3]+2>UPPERMOST||
					 squareCoordinates[3]+2<DOWNARDSMOST){
					return true;
				}
			}
			else if(rotationState==2){
				if(board[squareCoordinates[4]+1][squareCoordinates[0]-1]||
					board[squareCoordinates[6]-1][squareCoordinates[2]+1]||
					board[squareCoordinates[7]][squareCoordinates[3]+2]){
					return true;
				}
				if(squareCoordinates[0]-1>RIGHTMOST||
					 squareCoordinates[0]-1<LEFTMOST||
					 squareCoordinates[4]+1>UPPERMOST||
					 squareCoordinates[4]+1<DOWNARDSMOST||
					 squareCoordinates[2]+1>RIGHTMOST||
					 squareCoordinates[2]+1<LEFTMOST||
					 squareCoordinates[6]-1>UPPERMOST||
					 squareCoordinates[6]-1<DOWNARDSMOST||
					 squareCoordinates[3]+2>RIGHTMOST||
					 squareCoordinates[3]+2<LEFTMOST){
					return true;
				}	
			}
			else if(rotationState==3){
				if(board[squareCoordinates[4]+1][squareCoordinates[0]+1]||
					board[squareCoordinates[6]-1][squareCoordinates[2]-1]||
					board[squareCoordinates[7]-2][squareCoordinates[3]]){
					return true;
				}
				if(squareCoordinates[0]+1>RIGHTMOST||
					 squareCoordinates[0]+1<LEFTMOST||
					 squareCoordinates[4]+1>UPPERMOST||
					 squareCoordinates[4]+1<DOWNARDSMOST||
					 squareCoordinates[2]-1>RIGHTMOST||
					 squareCoordinates[2]-1<LEFTMOST||
					 squareCoordinates[6]-1>UPPERMOST||
					 squareCoordinates[6]-1<DOWNARDSMOST||
					 squareCoordinates[7]-2>UPPERMOST||
					 squareCoordinates[7]-2<DOWNARDSMOST){
					return true;
				}		
			}
		}
		else if(tetrominoID==TETROMINO_ID::T){
			if(rotationState==0){
				if((board[squareCoordinates[4]-1][squareCoordinates[0]+1]&&isNotSamePiece(board,squareCoordinates[0]+1,squareCoordinates[4]-1))||
					 (board[squareCoordinates[6]-1][squareCoordinates[2]-1]&&isNotSamePiece(board,squareCoordinates[2]-1,squareCoordinates[6]-1))||
					 (board[squareCoordinates[7]+1][squareCoordinates[3]-1]&&isNotSamePiece(board,squareCoordinates[3]-1,squareCoordinates[7]+1))){
					return true;
				}
				if(squareCoordinates[0]+1>RIGHTMOST||
					 squareCoordinates[0]+1<LEFTMOST||
					 squareCoordinates[4]-1>UPPERMOST||
					 squareCoordinates[4]-1<DOWNARDSMOST||
					 squareCoordinates[2]-1>RIGHTMOST||
					 squareCoordinates[2]-1<LEFTMOST||
					 squareCoordinates[6]-1>UPPERMOST||
					 squareCoordinates[6]-1<DOWNARDSMOST||
					 squareCoordinates[3]-1>RIGHTMOST||
					 squareCoordinates[3]-1<LEFTMOST||
					 squareCoordinates[7]+1>UPPERMOST||
					 squareCoordinates[7]+1<DOWNARDSMOST){
					return true;
				}
			}
			else if(rotationState==1){
				if((board[squareCoordinates[4]-1][squareCoordinates[0]-1]&&isNotSamePiece(board,squareCoordinates[0]-1,squareCoordinates[4]-1))||
					 (board[squareCoordinates[6]+1][squareCoordinates[2]-1]&&isNotSamePiece(board,squareCoordinates[2]-1,squareCoordinates[6]+1))||
					 (board[squareCoordinates[7]+1][squareCoordinates[3]+1]&&isNotSamePiece(board,squareCoordinates[3]+1,squareCoordinates[7]+1))){
					return true;
				}
				if(squareCoordinates[0]-1>RIGHTMOST||
					 squareCoordinates[0]-1<LEFTMOST||
					 squareCoordinates[4]-1>UPPERMOST||
					 squareCoordinates[4]-1<DOWNARDSMOST||
					 squareCoordinates[2]-1>RIGHTMOST||
					 squareCoordinates[2]-1<LEFTMOST||
					 squareCoordinates[6]+1>UPPERMOST||
					 squareCoordinates[6]+1<DOWNARDSMOST||
					 squareCoordinates[3]+1>RIGHTMOST||
					 squareCoordinates[3]+1<LEFTMOST||
					 squareCoordinates[7]+1>UPPERMOST||
					 squareCoordinates[7]+1<DOWNARDSMOST){
					return true;
				}
			}
			else if(rotationState==2){
				if((board[squareCoordinates[4]+1][squareCoordinates[0]-1]&&isNotSamePiece(board,squareCoordinates[0]-1,squareCoordinates[4]+1))||
					 (board[squareCoordinates[6]+1][squareCoordinates[2]+1]&&isNotSamePiece(board,squareCoordinates[2]+1,squareCoordinates[6]+1))||
					 (board[squareCoordinates[7]-1][squareCoordinates[3]+1]&&isNotSamePiece(board,squareCoordinates[3]+1,squareCoordinates[7]-1))){
					return true;
				}
				if(squareCoordinates[0]-1>RIGHTMOST||
					 squareCoordinates[0]-1<LEFTMOST||
					 squareCoordinates[4]+1>UPPERMOST||
					 squareCoordinates[4]+1<DOWNARDSMOST||
					 squareCoordinates[2]+1>RIGHTMOST||
					 squareCoordinates[2]+1<LEFTMOST||
					 squareCoordinates[6]+1>UPPERMOST||
					 squareCoordinates[6]+1<DOWNARDSMOST||
					 squareCoordinates[3]+1>RIGHTMOST||
					 squareCoordinates[3]+1<LEFTMOST||
					 squareCoordinates[7]-1>UPPERMOST||
					 squareCoordinates[7]-1<DOWNARDSMOST){
					return true;
				}	
			}
			else if(rotationState==3){
				if((board[squareCoordinates[4]+1][squareCoordinates[0]+1]&&isNotSamePiece(board,squareCoordinates[0]+1,squareCoordinates[4]+1))||
					 (board[squareCoordinates[6]-1][squareCoordinates[2]+1]&&isNotSamePiece(board,squareCoordinates[2]+1,squareCoordinates[6]-1))||
					 (board[squareCoordinates[7]-1][squareCoordinates[3]-1]&&isNotSamePiece(board,squareCoordinates[3]-1,squareCoordinates[7]-1))){
					return true;
				}
				if(squareCoordinates[0]+1>RIGHTMOST||
					 squareCoordinates[0]+1<LEFTMOST||
					 squareCoordinates[4]+1>UPPERMOST||
					 squareCoordinates[4]+1<DOWNARDSMOST||
					 squareCoordinates[2]+1>RIGHTMOST||
					 squareCoordinates[2]+1<LEFTMOST||
					 squareCoordinates[6]-1>UPPERMOST||
					 squareCoordinates[6]-1<DOWNARDSMOST||
					 squareCoordinates[3]-1>RIGHTMOST||
					 squareCoordinates[3]-1<LEFTMOST||
					 squareCoordinates[7]-1>UPPERMOST||
					 squareCoordinates[7]-1<DOWNARDSMOST){
					return true;
				}	
			}
		}
		if(tetrominoID==TETROMINO_ID::S){
			if(rotationState==0){
				if((board[squareCoordinates[4]-1][squareCoordinates[0]+1]&&isNotSamePiece(board,squareCoordinates[0]+1,squareCoordinates[4]-1))||
					(board[squareCoordinates[6]-1][squareCoordinates[2]-1]&&isNotSamePiece(board,squareCoordinates[2]-1,squareCoordinates[6]-1))||
					(board[squareCoordinates[7]][squareCoordinates[3]-2]&&isNotSamePiece(board,squareCoordinates[3]-2,squareCoordinates[7]))){
					return true;
				}
				if(squareCoordinates[0]+1>RIGHTMOST||
					 squareCoordinates[0]+1<LEFTMOST||
					 squareCoordinates[4]-1>UPPERMOST||
					 squareCoordinates[4]-1<DOWNARDSMOST||
					 squareCoordinates[2]>RIGHTMOST||
					 squareCoordinates[2]<LEFTMOST||
					 squareCoordinates[6]>UPPERMOST||
					 squareCoordinates[6]<DOWNARDSMOST||
					 squareCoordinates[3]-2>RIGHTMOST||
					 squareCoordinates[3]-2<LEFTMOST||
					 squareCoordinates[7]>UPPERMOST||
					 squareCoordinates[7]<DOWNARDSMOST){
					return true;
				}
			}
			else if(rotationState==1){
				if((board[squareCoordinates[4]-1][squareCoordinates[0]-1]&&isNotSamePiece(board,squareCoordinates[0]-1,squareCoordinates[4]-1))||
					 (board[squareCoordinates[6]+1][squareCoordinates[2]-1]&&isNotSamePiece(board,squareCoordinates[2]-1,squareCoordinates[6]+1))||
					 (board[squareCoordinates[7]+2][squareCoordinates[3]]&&isNotSamePiece(board,squareCoordinates[3],squareCoordinates[7]+2))){
					return true;
				}
				if(squareCoordinates[0]-1>RIGHTMOST||
					 squareCoordinates[0]-1<LEFTMOST||
					 squareCoordinates[4]-1>UPPERMOST||
					 squareCoordinates[4]-1<DOWNARDSMOST||
					 squareCoordinates[2]-1>RIGHTMOST||
					 squareCoordinates[2]-1<LEFTMOST||
					 squareCoordinates[6]+1>UPPERMOST||
					 squareCoordinates[6]+1<DOWNARDSMOST||
					 squareCoordinates[3]>RIGHTMOST||
					 squareCoordinates[3]<LEFTMOST||
					 squareCoordinates[7]+2>UPPERMOST||
					 squareCoordinates[7]+2<DOWNARDSMOST){
					return true;
				}	
			}
			else if(rotationState==2){
				if((board[squareCoordinates[4]+1][squareCoordinates[0]-1]&&isNotSamePiece(board,squareCoordinates[0]-1,squareCoordinates[4]+1))||
					 (board[squareCoordinates[6]+1][squareCoordinates[2]+1]&&isNotSamePiece(board,squareCoordinates[2]+1,squareCoordinates[6]+1))||
					 (board[squareCoordinates[7]][squareCoordinates[3]+2]&&isNotSamePiece(board,squareCoordinates[3]+2,squareCoordinates[7]))){
					return true;
				}
				if(squareCoordinates[0]-1>RIGHTMOST||
					 squareCoordinates[0]-1<LEFTMOST||
					 squareCoordinates[4]+1>UPPERMOST||
					 squareCoordinates[4]+1<DOWNARDSMOST||
					 squareCoordinates[2]+1>RIGHTMOST||
					 squareCoordinates[2]+1<LEFTMOST||
					 squareCoordinates[6]+1>UPPERMOST||
					 squareCoordinates[6]+1<DOWNARDSMOST||
					 squareCoordinates[3]+2>RIGHTMOST||
					 squareCoordinates[3]+2<LEFTMOST||
					 squareCoordinates[7]>UPPERMOST||
					 squareCoordinates[7]<DOWNARDSMOST){
					return true;
				}		
			}
			else if(rotationState==3){
				if((board[squareCoordinates[4]+1][squareCoordinates[0]+1]&&isNotSamePiece(board,squareCoordinates[0]+1,squareCoordinates[4]+1))||
					 (board[squareCoordinates[6]-1][squareCoordinates[2]+1]&&isNotSamePiece(board,squareCoordinates[2]+1,squareCoordinates[6]-1))||
					 (board[squareCoordinates[7]-2][squareCoordinates[3]]&&isNotSamePiece(board,squareCoordinates[3],squareCoordinates[7]-2))){
					return true;
				}
				if(squareCoordinates[0]+1>RIGHTMOST||
					 squareCoordinates[0]+1<LEFTMOST||
					 squareCoordinates[4]+1>UPPERMOST||
					 squareCoordinates[4]+1<DOWNARDSMOST||
					 squareCoordinates[2]+1>RIGHTMOST||
					 squareCoordinates[2]+1<LEFTMOST||
					 squareCoordinates[6]-1>UPPERMOST||
					 squareCoordinates[6]-1<DOWNARDSMOST||
					 squareCoordinates[3]>RIGHTMOST||
					 squareCoordinates[3]<LEFTMOST||
					 squareCoordinates[7]-2>UPPERMOST||
					 squareCoordinates[7]-2<DOWNARDSMOST){
					return true;
				}			
			}
		}
		if(tetrominoID==TETROMINO_ID::Z){
			if(rotationState==0){
				if((board[squareCoordinates[4]-2][squareCoordinates[0]]&&isNotSamePiece(board,squareCoordinates[0],squareCoordinates[4]-2))||
					(board[squareCoordinates[5]-1][squareCoordinates[1]-1]&&isNotSamePiece(board,squareCoordinates[1]-1,squareCoordinates[5]-1))||
					(board[squareCoordinates[7]+1][squareCoordinates[3]-1]&&isNotSamePiece(board,squareCoordinates[3]-1,squareCoordinates[7]+1))){
					return true;
				}
				if(squareCoordinates[0]>RIGHTMOST||
					 squareCoordinates[0]<LEFTMOST||
					 squareCoordinates[4]-2>UPPERMOST||
					 squareCoordinates[4]-2<DOWNARDSMOST||
					 squareCoordinates[1]-1>RIGHTMOST||
					 squareCoordinates[1]-1<LEFTMOST||
					 squareCoordinates[5]-1>UPPERMOST||
					 squareCoordinates[5]-1<DOWNARDSMOST||
					 squareCoordinates[3]-1>RIGHTMOST||
					 squareCoordinates[3]-1<LEFTMOST||
					 squareCoordinates[7]+1>UPPERMOST||
					 squareCoordinates[7]+1<DOWNARDSMOST){
					return true;
				}
			}
			else if(rotationState==1){
				if((board[squareCoordinates[4]][squareCoordinates[0]-2]&&isNotSamePiece(board,squareCoordinates[0]-2,squareCoordinates[4]))||
					 (board[squareCoordinates[5]+1][squareCoordinates[1]-1]&&isNotSamePiece(board,squareCoordinates[1]-1,squareCoordinates[5]+1))||
					 (board[squareCoordinates[7]+1][squareCoordinates[3]+1]&&isNotSamePiece(board,squareCoordinates[3]+1,squareCoordinates[7]+1))){
					return true;
				}
				if(squareCoordinates[0]-2>RIGHTMOST||
					 squareCoordinates[0]-2<LEFTMOST||
					 squareCoordinates[4]>UPPERMOST||
					 squareCoordinates[4]<DOWNARDSMOST||
					 squareCoordinates[1]-1>RIGHTMOST||
					 squareCoordinates[1]-1<LEFTMOST||
					 squareCoordinates[5]+1>UPPERMOST||
					 squareCoordinates[5]+1<DOWNARDSMOST||
					 squareCoordinates[3]+1>RIGHTMOST||
					 squareCoordinates[3]+1<LEFTMOST||
					 squareCoordinates[7]+1>UPPERMOST||
					 squareCoordinates[7]+1<DOWNARDSMOST){
					return true;
				}	
			}
			else if(rotationState==2){
				if((board[squareCoordinates[4]+2][squareCoordinates[0]]&&isNotSamePiece(board,squareCoordinates[0],squareCoordinates[4]+2))||
					 (board[squareCoordinates[5]+1][squareCoordinates[1]+1]&&isNotSamePiece(board,squareCoordinates[1]+1,squareCoordinates[5]+1))||
					 (board[squareCoordinates[7]-1][squareCoordinates[3]+1]&&isNotSamePiece(board,squareCoordinates[3]+1,squareCoordinates[7]-1))){
					return true;
				}
				if(squareCoordinates[0]>RIGHTMOST||
					 squareCoordinates[0]<LEFTMOST||
					 squareCoordinates[4]+2>UPPERMOST||
					 squareCoordinates[4]+2<DOWNARDSMOST||
					 squareCoordinates[1]+1>RIGHTMOST||
					 squareCoordinates[1]+1<LEFTMOST||
					 squareCoordinates[5]+1>UPPERMOST||
					 squareCoordinates[5]+1<DOWNARDSMOST||
					 squareCoordinates[3]+1>RIGHTMOST||
					 squareCoordinates[3]+1<LEFTMOST||
					 squareCoordinates[7]-1>UPPERMOST||
					 squareCoordinates[7]-1<DOWNARDSMOST){
					return true;
				}		
			}
			else if(rotationState==3){
				if((board[squareCoordinates[4]][squareCoordinates[0]+2]&&isNotSamePiece(board,squareCoordinates[0]+2,squareCoordinates[4]))||
					 (board[squareCoordinates[5]-1][squareCoordinates[1]+1]&&isNotSamePiece(board,squareCoordinates[1]+1,squareCoordinates[5]-1))||
					 (board[squareCoordinates[7]-1][squareCoordinates[3]-1]&&isNotSamePiece(board,squareCoordinates[3]-1,squareCoordinates[7]-1))){
					return true;
				}
				if(squareCoordinates[0]+2>RIGHTMOST||
					 squareCoordinates[0]+2<LEFTMOST||
					 squareCoordinates[4]>UPPERMOST||
					 squareCoordinates[4]<DOWNARDSMOST||
					 squareCoordinates[1]+1>RIGHTMOST||
					 squareCoordinates[1]+1<LEFTMOST||
					 squareCoordinates[5]-1>UPPERMOST||
					 squareCoordinates[5]-1<DOWNARDSMOST||
					 squareCoordinates[3]-1>RIGHTMOST||
					 squareCoordinates[3]-1<LEFTMOST||
					 squareCoordinates[7]-1>UPPERMOST||
					 squareCoordinates[7]-1<DOWNARDSMOST){
					return true;
				}			
			}
		}
		return false;
	}
	
	bool isNotSamePiece(bool board[][10],int pieceX,int pieceY){
		if(board[pieceY][pieceX]!=board[squareCoordinates[4]][squareCoordinates[0]]&&
			 board[pieceY][pieceX]!=board[squareCoordinates[5]][squareCoordinates[1]]&&
			 board[pieceY][pieceX]!=board[squareCoordinates[6]][squareCoordinates[2]]&&
			 board[pieceY][pieceX]!=board[squareCoordinates[7]][squareCoordinates[3]]){
			return true;
		}
		else{
			return false;
		}
	}

	void updateValues(bool board[][10],bool isNewValues){
		board[squareCoordinates[4]][squareCoordinates[0]]=isNewValues;
		board[squareCoordinates[5]][squareCoordinates[1]]=isNewValues;
		board[squareCoordinates[6]][squareCoordinates[2]]=isNewValues;
		board[squareCoordinates[7]][squareCoordinates[3]]=isNewValues;
	}

	//static
	static TETROMINO_ID getInitialPiece(int *lastPiece){
		srand(time(NULL));
		int randomPiece=rand() % 7 + 1;
		switch(randomPiece){
		case 1:
			*lastPiece=1;
			return TETROMINO_ID::I;
		case 2:
			*lastPiece=2;
			return TETROMINO_ID::J;
		case 3:
			*lastPiece=3;
			return TETROMINO_ID::L;
		case 4:
			*lastPiece=4;
			return TETROMINO_ID::S;
		case 5:
			*lastPiece=5;
			return TETROMINO_ID::Z;
		case 6:
			*lastPiece=6;
			return TETROMINO_ID::O;
		case 7:
			*lastPiece=7;
			return TETROMINO_ID::T;
		}
	}

	static TETROMINO_ID getRandomPiece(int max, int *lastPiece){
		srand(time(NULL));
		int randomPiece=rand()%max+1;
		switch(randomPiece){
		case 1:
			if(*lastPiece==1){
				*lastPiece=0;
				return getRandomPiece(7,lastPiece);
			}
			else{
				*lastPiece=1;
				return TETROMINO_ID::I;
			}
		case 2:
			if(*lastPiece==2){
				*lastPiece=0;
				return getRandomPiece(7,lastPiece);
			}
			else{
				*lastPiece=2;
				return TETROMINO_ID::J;
			}
		case 3:
			if(*lastPiece==3){
				*lastPiece=0;
				return getRandomPiece(7,lastPiece);
			}
			else{
				*lastPiece=3;
				return TETROMINO_ID::L;
			}
		case 4:
			if(*lastPiece==4){
				*lastPiece=0;
				return getRandomPiece(7,lastPiece);
			}
			else{
				*lastPiece=4;
				return TETROMINO_ID::S;
			}
		case 5:
			if(*lastPiece==5){
				*lastPiece=0;
				return getRandomPiece(7,lastPiece);
			}
			else{
				*lastPiece=5;
				return TETROMINO_ID::Z;
			}
		case 6:
			if(*lastPiece==6){
				*lastPiece=0;
				return getRandomPiece(7,lastPiece);
			}
			else{
				*lastPiece=6;
				return TETROMINO_ID::O;
			}
		case 7:
			if(*lastPiece==7){
				*lastPiece=0;
				return getRandomPiece(7,lastPiece);
			}
			else{
				*lastPiece=7;
				return TETROMINO_ID::T;
			}
		case 8:
			*lastPiece=0;
			return getRandomPiece(7,lastPiece);
		}
	}
};