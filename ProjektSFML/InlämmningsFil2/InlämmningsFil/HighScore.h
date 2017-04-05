#ifndef HIGH_SCORE_H
#define HIGH_SCORE_H
//#include"Game.h"
#include<fstream> 
#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

class HighScore
{
private:
	string highScoreString;
public:
	HighScore(/*int kills, float time*/);
	~HighScore();
	void save(int kills, float time);
	void load();

	void selectionSort(float *theArr, int nrOfElements);
	
	string getHighScore() const;
};


#endif // !HIGH_SCORE_H