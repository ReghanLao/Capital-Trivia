#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <ctype.h>
#include <cstdlib>
#include "Player.h"
using namespace std;

void shuffle(vector<string> &vector) { //shuffles the answer choices
	srand(time(0));
	string temp;
	int randomSubscript = 0;

	for(int i = 0; i < vector.size(); i++) {
		randomSubscript = rand() % vector.size();
		temp = vector[i];
		vector[i] = vector[randomSubscript];
		vector[randomSubscript] = temp;
	}
}

//create a sub vector for the answer choices then set a variable 
void welcomeUser() 
{
	//displays a welcome message
	cout << endl;
	cout << "█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█" << endl;
	cout << "█░░╦─╦╔╗╦─╔╗╔╗╔╦╗╔╗░░█" << endl;
	cout << "█░░║║║╠─║─║─║║║║║╠─░░█" << endl;
	cout << "█░░╚╩╝╚╝╚╝╚╝╚╝╩─╩╚╝░░█" << endl;
	cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
	cout << endl;
}

void goodbyeUser() 
{
	//displays a good bye message
	cout << endl;
	cout << "★─▄█▀▀║░▄█▀▄║▄█▀▄║██▀▄║─★" << endl;
	cout << "★─██║▀█║██║█║██║█║██║█║─★" << endl;
	cout <<	"★─▀███▀║▀██▀║▀██▀║███▀║─★" << endl;
	cout << "★───────────────────────★" << endl;
	cout << "★───▐█▀▄─ ▀▄─▄▀ █▀▀──█───★" << endl;
	cout << "★───▐█▀▀▄ ──█── █▀▀──▀───★" << endl;
	cout << "★───▐█▄▄▀ ──▀── ▀▀▀──▄───★" << endl;
	cout << endl;
}

void displayMenu() 
{
	cout << endl;
	cout << "█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█" << endl;
	cout << "█░░HIGH SCORES('H')░░█" << endl;
	cout << "█░░   PLAY('G')    ░░█" << endl;
	cout << "█░░   EXIT('E')    ░░█" << endl;
	cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
	cout << endl;
}

//displays level options(easy/medium/hard)
void displayLevelOptions() 
{
	cout << endl;
	cout << "█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█" << endl;
	cout << "█░░    EASY('E')   ░░█" << endl;
	cout << "█░░   MEDIUM('M')  ░░█" << endl;
	cout << "█░░    HARD('H')   ░░█" << endl;
	cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
	cout << endl;
}

//fills vectors in main with question and answers from text files
void fillEasyMedHardQNA(ifstream &inputEasy, ifstream &inputMed, ifstream &inputHard, vector<string> &easyQNA, vector<string> &medQNA, vector<string> &hardQNA)
{
	inputEasy.open("Easy Questions.txt", ios::in); //opens file and activates read mode
	inputMed.open("Medium Questions.txt", ios::in); //opens file and activates read mode
	inputHard.open("Hard Questions.txt", ios::in); //opens file and activates read mode

	string qna;

	if(inputEasy.is_open()) 
	{
		while(getline(inputEasy, qna))
		{		
			easyQNA.push_back(qna);
		}	
	}
	else
	{
		cout << "Error opening 'Easy Quesions.txt'" << endl;	
	}

	if(inputMed.is_open()) 
	{
		while(getline(inputMed, qna))
		{		
			medQNA.push_back(qna);
		}	
	}
	else
	{
		cout << "Error opening 'Medium Quesions.txt'" << endl;	
	}

	if(inputHard.is_open()) 
	{
		while(getline(inputHard, qna))
		{		
			hardQNA.push_back(qna);
		}	
	}
	else
	{
		cout << "Error opening 'Hard Quesions.txt'" << endl;	
	}

	//closes files 
	inputEasy.close();
	inputMed.close();
	inputHard.close();
}

//displays an easy QNA set in the format: question, answer choice, answer choice, answer choice, answer choice
void displayEasyQNASet(vector<string> &easyQNA, int &startIndex, int &endIndex, string &correctAns, string &fiftyfiftyAns)
{
	char letter = 'a';
	correctAns = easyQNA[startIndex + 1];
	fiftyfiftyAns = easyQNA[startIndex + 2];
	vector<string> randomizedAns;

	for(int i = startIndex; i < endIndex; i++) 
	{
		if(i > startIndex)
		{
			randomizedAns.push_back(easyQNA[i]);
		}
	}

	shuffle(randomizedAns);

	cout << easyQNA[startIndex] << endl;//prints out question
  	for(int j = 0; j < randomizedAns.size(); j++)
	{
		cout << letter << ". " << randomizedAns[j] << endl;
		letter++;
	}
	cout << endl;
	
	startIndex = endIndex;
	endIndex += 5;
}

//displays a medium QNA set in the format: question, answer choice, answer choice, answer choice, answer choice
void displayMedQNASet(vector<string> &medQNA, int &startIndex, int &endIndex, string &correctAns, string &fiftyfiftyAns) 
{
	char letter = 'a';
	correctAns = medQNA[startIndex + 1];
	fiftyfiftyAns = medQNA[startIndex + 2];
	vector<string> randomizedAns;
	for(int i = startIndex; i < endIndex; i++) 
	{
		if(i > startIndex)
		{
			randomizedAns.push_back(medQNA[i]);
		}
	}

	shuffle(randomizedAns);

	cout << medQNA[startIndex] << endl;//prints out question
  	for(int j = 0; j < randomizedAns.size(); j++)
	{
		cout << letter << ". " << randomizedAns[j] << endl;
		letter++;
	}
	cout << endl;
	
	startIndex = endIndex;
	endIndex += 5;
}

//displays a hard QNA set in the format: question, answer choice, answer choice, answer choice, answer choice
void displayHardQNASet(vector<string> &hardQNA, int &startIndex, int &endIndex, string &correctAns, string &fiftyfiftyAns) 
{
	char letter = 'a';
	correctAns = hardQNA[startIndex + 1];
	fiftyfiftyAns = hardQNA[startIndex + 2];
	vector<string> randomizedAns;

	for(int i = startIndex; i < endIndex; i++) 
	{
		if(i > startIndex)
		{
			randomizedAns.push_back(hardQNA[i]);
		}
	}

	shuffle(randomizedAns);

	cout << hardQNA[startIndex] << endl;//prints out question
  	for(int j = 0; j < randomizedAns.size(); j++)
	{
		cout << letter << ". " << randomizedAns[j] << endl;
		letter++;
	}
	cout << endl;
	
	startIndex = endIndex;
	endIndex += 5;
}

bool rightAnsOrNot(string userAns, string correctAns) 
{
	bool correctOrNot;
	string userAnswer;
	string correctAnswer;

	//converts string into upper case
	for(int i = 0; i < userAns.length(); i++) {
		userAnswer += toupper(userAns[i]);
	}

	//converts string into upper case
	for(int j = 0; j < correctAns.length(); j++) {
		correctAnswer += toupper(correctAns[j]);
	}

	if(userAnswer == correctAnswer) 
	{
		correctOrNot = true;
	}
	else 
	{
		correctOrNot = false;
	}
	
	return correctOrNot;
}

void sendPlayerInfoOut(ofstream &sendOutUserInfo, int score, double time, string name, string fileName) {
	sendOutUserInfo.open("Player Info.txt", ios::out);
	sendOutUserInfo << score << " " << time << " " << name << " " << fileName << endl;
	sendOutUserInfo.close();
}

int main() 
{
	char gameModeSelect;
	char menuSelect;
	ifstream inputEasy, inputMedium, inputHard;
	ofstream sendOutEasy, sendOutMedium, sendOutHard;
	ifstream inputUserInfo;
	int easyCorrectPoints = 40, mediumCorrectPoints = 60, hardCorrectPoints = 80; //if user answers correctly on a certain level question they receive a set amount of points
	Player player; //player object initialization
	string userName; //will be sent out to 'Player(s) Info.txt'
	int userScore = 0;  //will be sent out to 'Player(s) Info.txt' 
	vector<string> easyQNA, mediumQNA, hardQNA; 
	int easyStartIndex = 0, medStartIndex = 0, hardStartIndex = 0, easyEndIndex = 5, medEndIndex = 5, hardEndIndex = 5;
	string easyAns = " ", easyFiftyFiftyAns = " ";
	string medAns = " ", medFiftyFiftyAns = " ";
	string hardAns = " ", hardFiftyFiftyAns = " ";
	string userAns;
	char fiftyfiftyOrNot;
	
	//GUI in the beginning for the game
	welcomeUser(); //welcomes user
  	cout << "US Geography: State Capitals Edition" << endl;
	cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
	cout << endl;
	displayMenu();
	cout << "Enter 'H' to view high scores, enter 'G' to play the game, or enter 'E' to exit the game: " << endl;
	cin >> menuSelect;

	switch(toupper(menuSelect)) 
	{
		case 'H':
		{
			string playerInfo;
			
			inputUserInfo.open("Player Info.txt", ios::in);
			if(inputUserInfo.is_open()) 
			{
				while(getline(inputUserInfo, playerInfo))
				{		
					cout << playerInfo << endl;
				}	
			}
			else
			{
				cout << "Error opening 'Player Info.txt'" << endl;	
			}
			break;
		}
		case 'G':
		{
			cout << "Please enter a username: " << endl; //prompts username
			cin.ignore();
			getline(cin, userName);
			player.setUsername(userName);

			cout << endl;
			displayLevelOptions();
			cout << endl;
			
			cout << "Which gamemode would you like to select? Options include easy, medium, and hard. Enter 'E' for easy, 'M' for medium, or 'H' for hard: " << endl;
			cin >> gameModeSelect;
			
			while(toupper(gameModeSelect) != 'E' && toupper(gameModeSelect) != 'M' && toupper(gameModeSelect) != 'H') 	
			{
				cout << "Please enter either 'E' for easy, 'M' for medium, or 'H' for hard: " << endl;
				cin >> gameModeSelect;
			}

			fillEasyMedHardQNA(inputEasy, inputMedium, inputHard, easyQNA, mediumQNA, hardQNA);
			
			switch(toupper(gameModeSelect)) //selects level of dificulty
			{
				case 'E':
				{
           			time_t start, end;
          			time(&start);
          			for(int i = 0; i < 10; i ++) 
					{
						displayEasyQNASet(easyQNA, easyStartIndex, easyEndIndex, easyAns, easyFiftyFiftyAns);
						cout << endl;
			
						cout << "Would you like to choose the fifty-fifty option? The amount of points you will earn for this question will be halved as a result if you choose the fifty-fifty option. Enter 'Y' for yes or 'N' for no: " << endl;	//50-50 option
						cin >> fiftyfiftyOrNot;
						cout << endl;
						
						if(toupper(fiftyfiftyOrNot) == 'Y') 
						{
							cout << "Fifty-fifty possible answer choices: " << endl;	
							cout << "a. " << easyAns << endl;
							cout << "b. " << easyFiftyFiftyAns << endl;
							cout << endl;
							cout << "Enter your answer(spell out the capital word for word): " << endl;
							cin.ignore();
							getline(cin, userAns);
							if(rightAnsOrNot(userAns, easyAns) == true)
							{
								cout << endl;
								cout << "█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█" << endl;
								cout << "█░░                ░░█" << endl;
								cout << "█░░    CORRECT     ░░█" << endl;
								cout << "█░░                ░░█" << endl;
								cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
								cout << endl;
								userScore += (easyCorrectPoints/2);
							}
							else 
							{
								cout << endl;
								cout << "█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█" << endl;
								cout << "█░░                ░░█" << endl;
								cout << "█░░    INCORRECT   ░░█" << endl;
								cout << "█░░                ░░█" << endl;
								cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
								cout << endl;
							}
						}
						else 
						{
							cout << "Enter your answer(spell out the capital word for word): " << endl;
							cin.ignore();
							getline(cin, userAns);
							if(rightAnsOrNot(userAns, easyAns) == true) //displays correct or incorrect
							{
								cout << endl;
								cout << "█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█" << endl;
								cout << "█░░                ░░█" << endl;
								cout << "█░░    CORRECT     ░░█" << endl;
								cout << "█░░                ░░█" << endl;
								cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
								cout << endl;
								userScore += easyCorrectPoints;
							}
							else 
							{
								cout << endl;
								cout << "█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█" << endl;
								cout << "█░░                ░░█" << endl;
								cout << "█░░    INCORRECT   ░░█" << endl;
								cout << "█░░                ░░█" << endl;
								cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
								cout << endl;
							}
						}
					}
					time(&end);
          			double elaspedTime = abs(start - end); //time elapsed
          			cout << "It took " << elaspedTime << " seconds." << endl;
					cout << userName << " you earned " << userScore << " points." << endl;
					sendPlayerInfoOut(sendOutEasy, userScore, elaspedTime, userName, "Easy Questions"); //high and previous scores
					break;
          		}	
				case 'M':
				{
					time_t start,end;
          			time(&start);
          			for(int i = 0; i < 10; i ++) 
					{
						displayMedQNASet(mediumQNA, medStartIndex, medEndIndex, medAns, medFiftyFiftyAns);
						cout << endl;
			
						cout << "Would you like to choose the fifty-fifty option? The amount of points you will earn for this question will be halved as a result if you choose the fifty-fifty option. Enter 'Y' for yes or 'N' for no: " << endl;	
						cin >> fiftyfiftyOrNot;
						cout << endl;
						
						if(toupper(fiftyfiftyOrNot) == 'Y') 
						{
							cout << "Fifty-fifty possible answer choices: " << endl;	
							cout << "a. " << medAns << endl;
							cout << "b. " << medFiftyFiftyAns << endl;
							cout << endl;
							cout << "Enter your answer(spell out the capital word for word): " << endl;
							cin.ignore();
							getline(cin, userAns);
							if(rightAnsOrNot(userAns, medAns) == true)
							{
								cout << endl;
								cout << "█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█" << endl;
								cout << "█░░                ░░█" << endl;
								cout << "█░░    CORRECT     ░░█" << endl;
								cout << "█░░                ░░█" << endl;
								cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
								cout << endl;
								userScore += (mediumCorrectPoints/2);
							}
							else 
							{
								cout << endl;
								cout << "█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█" << endl;
								cout << "█░░                ░░█" << endl;
								cout << "█░░    INCORRECT   ░░█" << endl;
								cout << "█░░                ░░█" << endl;
								cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
								cout << endl;
							}
						}
						else 
						{
							cout << "Enter your answer(spell out the capital word for word): " << endl;
							cin.ignore();
							getline(cin, userAns);
							if(rightAnsOrNot(userAns, medAns) == true)
							{
								cout << endl;
								cout << "█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█" << endl;
								cout << "█░░                ░░█" << endl;
								cout << "█░░    CORRECT     ░░█" << endl;
								cout << "█░░                ░░█" << endl;
								cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
								cout << endl;
								userScore += mediumCorrectPoints;
							}
							else 
							{
								cout << endl;
								cout << "█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█" << endl;
								cout << "█░░                ░░█" << endl;
								cout << "█░░    INCORRECT   ░░█" << endl;
								cout << "█░░                ░░█" << endl;
								cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
								cout << endl;
							}
						}
					}
					time(&end);
          			double elaspedTime = abs(start - end);
          			cout << "It took " << elaspedTime << " seconds." << endl;
					cout << userName << " you earned " << userScore << " points." << endl;
					sendPlayerInfoOut(sendOutEasy, userScore, elaspedTime, userName, "Easy Questions");
					break;
				}
				case 'H':
				{
					time_t start,end;
          			time(&start);
          			for(int i = 0; i < 10; i ++) 
					{
						displayHardQNASet(hardQNA, hardStartIndex, hardEndIndex, hardAns, hardFiftyFiftyAns);
						cout << endl;
			
						cout << "Would you like to choose the fifty-fifty option? The amount of points you will earn for this question will be halved as a result if you choose the fifty-fifty option. Enter 'Y' for yes or 'N' for no: " << endl;	
						cin >> fiftyfiftyOrNot;
						cout << endl;
						
						if(toupper(fiftyfiftyOrNot) == 'Y') 
						{
							cout << "Fifty-fifty possible answer choices: " << endl;	
							cout << "a. " << hardAns << endl;
							cout << "b. " << hardFiftyFiftyAns << endl;
							cout << endl;
							cout << "Enter your answer(spell out the capital word for word): " << endl;
							cin.ignore();
							getline(cin, userAns);
							if(rightAnsOrNot(userAns, hardAns) == true)
							{
								cout << endl;
								cout << "█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█" << endl;
								cout << "█░░                ░░█" << endl;
								cout << "█░░    CORRECT     ░░█" << endl;
								cout << "█░░                ░░█" << endl;
								cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
								cout << endl;
								userScore += (hardCorrectPoints/2);
							}
							else 
							{
								cout << endl;
								cout << "█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█" << endl;
								cout << "█░░                ░░█" << endl;
								cout << "█░░    INCORRECT   ░░█" << endl;
								cout << "█░░                ░░█" << endl;
								cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
								cout << endl;
							}
						}
						else 
						{
							cout << "Enter your answer(spell out the capital word for word): " << endl;
							cin.ignore();
							getline(cin, userAns);
							if(rightAnsOrNot(userAns, hardAns) == true)
							{
								cout << endl;
								cout << "█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█" << endl;
								cout << "█░░                ░░█" << endl;
								cout << "█░░    CORRECT     ░░█" << endl;
								cout << "█░░                ░░█" << endl;
								cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
								cout << endl;
								userScore += hardCorrectPoints;
							}
							else 
							{
								cout << endl;
								cout << "█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█" << endl;
								cout << "█░░                ░░█" << endl;
								cout << "█░░    INCORRECT   ░░█" << endl;
								cout << "█░░                ░░█" << endl;
								cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
								cout << endl;
							}
						}
					}
					time(&end);
          			double elaspedTime = abs(start - end);
          			cout << "It took " << elaspedTime << " seconds." << endl; //time it took
					cout << userName << " you earned " << userScore << " points." << endl;
					sendPlayerInfoOut(sendOutEasy, userScore, elaspedTime, userName, "Easy Questions"); //high and previous scores
					break;
				}
			}
		
			break;
		}
		case 'E':
		{
			goto exit;
			break;
		}
	}
	
	exit:
	goodbyeUser(); //says goodbye to user
	return 0;
}
