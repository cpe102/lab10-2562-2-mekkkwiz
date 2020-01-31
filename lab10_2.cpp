#include<iostream>
#include<string>
#include<ctime>

using namespace std;

string cardNames[] = {"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int cardScores[] = {0,1,2,3,4,5,6,7,8,9,10,10,10,10};

int drawCard(void){
	double ran_draw;
	ran_draw = rand()%13+1;
	

	return ran_draw;
}

int calScore(int x,int y,int z){
	int Sum_Score = x+y+z;
	int New_Score = Sum_Score%10;
	return New_Score;
}

int findYugiAction(int s){	
	if(s == 9) return 2; // Yugi will definitely stay (2) when current score (s) is equal to 9
	else if(s < 6) return 1; // Yugi will definitely draw (1) when current score (s) is less than 6
	else{
		int pbb;
		// If current score is 6,7,8, Yugi will draw with probability 69% and will stay with probability 31% 
		// Write conditions here using random number
		if (s >= 6 && s <= 8)
		{
			pbb = rand()%100+1;
			if (pbb < 31)
			{
				return 0;
			}
			else
			{
				return 1;
			}
			
			
			
		}
		
	}
}

void checkWinner(int p, int y){
	// Write condition for cout in this function
	cout << "\n---------------------------------\n";
	if (p == y)
	cout <<   "|             Draw!!!           |";
	if (p > y)
	cout <<   "|         Player wins!!!        |"; // when p is greater than y
	if (p < y)
	cout <<   "|          Yugi wins!!!         |"; // when p is less than y
	cout << "\n---------------------------------\n";
}

int main(){
	srand(time(0));
	int playerScore, yugiScore, playerAction, yugiAction;
	int playerCards[3] = {drawCard(), drawCard(), 0};
	int yugiCards[3] = {drawCard(),drawCard(),0}; //This line of code is not completed. You need to initialize value of yugiCards[].
	
	
	cout << "---------ORE NO TURN, DRAW!!!------------\n";
	cout << "Your cards: " << cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
	playerScore = calScore(cardScores[playerCards[0]],cardScores[playerCards[1]],cardScores[playerCards[2]]);
	cout << "Your score: " << playerScore << "\n";
	do{
		cout << "(1) Destiny draw (2) Stay, SELECT: ";
		cin >> playerAction;
	}while(playerAction != 1 && playerAction != 2);


	if(playerAction == 1){
		cout << "Player draws the 3rd card!!!" << "\n";
		int playercard3rd = drawCard();
		playerCards[2] = playercard3rd;
		cout << "Your 3rd card: "<< cardNames[playercard3rd] << "\n";
		
		cout << "Your new score: " << calScore(cardScores[playerCards[0]],cardScores[playerCards[1]],cardScores[playerCards[2]]) << "\n";
		playerScore = calScore(cardScores[playerCards[0]],cardScores[playerCards[1]],cardScores[playerCards[2]]);
	}
	cout << "------------ Turn end -------------------\n\n";
	

	cout << "---------YUGI'S TURN, DRAW!!!------------\n";
	cout << "Yugi's cards: " << cardNames[yugiCards[0]] << " " << cardNames[yugiCards[1]] << "\n";
	yugiScore = calScore(cardScores[yugiCards[0]],cardScores[yugiCards[1]],cardScores[yugiCards[2]]);
	cout << "Yugi's score: " << yugiScore << "\n";

	yugiAction = findYugiAction(yugiScore);
	if(yugiAction == 1){
		cout << "Yugi draws the 3rd card!!!" << "\n";
		int yugicard3rd = drawCard();
		yugiCards[2] = yugicard3rd;
		cout << "Yugi's 3rd card: "<< cardNames[yugicard3rd] << "\n";
		
		cout << "Yugi's new score: " << calScore(cardScores[yugiCards[0]],cardScores[yugiCards[1]],cardScores[yugiCards[2]]) << "\n";
		yugiScore = calScore(cardScores[yugiCards[0]],cardScores[yugiCards[1]],cardScores[yugiCards[2]]);
	}
	cout << "------------ Turn end -------------------\n";


	
	
	checkWinner(playerScore,yugiScore);
}
