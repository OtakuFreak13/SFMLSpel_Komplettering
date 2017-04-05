#include "HighScore.h"


void HighScore::selectionSort(float *theArr, int nrOfElements)
{
	float tempS;
	for (int i = 0; i < nrOfElements - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < nrOfElements; j++)
		{
			tempS = theArr[i];
			if (theArr[j] > theArr[minIndex])
			{
				minIndex = j;
			}

		}
		tempS = theArr[i];
		theArr[i] = theArr[minIndex];
		theArr[minIndex] = tempS;
	}
}

//void HighScore::selectionSort(string theArr[], int nrOfElements)
//{
//	string::size_type mySizeType;
//	float tempS;
//	for (int i = 0; i < nrOfElements - 1; i++)
//	{
//		int minIndex = i;
//		for (int j = i + 1; j < nrOfElements; j++)
//		{
//			tempS = stof(theArr[i]);
//
//			if (theArr[j] < theArr[minIndex])
//			{
//				minIndex = j;
//			}
//
//		}
//		tempS = stof(theArr[i]);
//		theArr[i] = theArr[minIndex];
//		theArr[minIndex] = to_string(tempS);
//	}
//}

string HighScore::getHighScore() const
{
	return this->highScoreString;
}

//string HighScore::highScoreString = this->load();
//{
//	return this->load();
//}

void HighScore::save(int kills, float time)
{
	float highSoreFloat = kills*time / 5;

	//int numLines = 0;
	//ifstream in("HighScore.txt");
	//if (in)
	//{
	//	std::string unused;
	//	while (std::getline(in, unused))
	//	{
	//		numLines++;
	//	}
	//}
	//else
	//{

	//}
	ofstream out;
	out.open("HighScore.txt", ios::out | ios::app);

	out << endl << highSoreFloat << endl;

	//out << kills << endl;
	//out << time << endl;
	//out << endl;
	//out << "HighScore: " + to_string(highSoreFloat) + " Confirmed Kills: " + to_string(kills) + " Time Survived: " + to_string(time) << endl;

	out.close();
}

void HighScore::load()
{

	string *highScore;
	string HighScore1;
	ifstream in;
	if (!in)
	{
		//no highScore
	}
	else
	{
		in.open("HighScore.txt");
		int numLines = 0;
		std::string unused;
		while (getline(in, unused))
		{
			numLines++;
		}
		//int *killsTemp = new int[numLines / 3];
		//float *timeTemp = new float[numLines / 3];
		//float *highScoreTemp = new float[numLines / 3];
		//for (int i = 0; i < numLines - 2; i + 3)
		//{
		//	in >> killsTemp[i];//TODO rekrusiv kallese på highScore, eller en string här som sedan plusass på på highScore
		//	//highScore += highScoreTemp[i];
		//	in >> timeTemp[i + 1];
		//	highScoreTemp[i] = killsTemp[i] * timeTemp[i + 1] / 5;
		//}

		//selectionSort(highScoreTemp, numLines / 3);
		//highScore = new string[numLines / 3];
		//for (int i = 0; i < numLines / 3; i++)
		//{
		//	highScore[i] = "HighScore: " + to_string(highScoreTemp[i]);
		//}
		//for (int i = 0; i < 0; i++)
		//{
		//	HighScore1 += "Current " + highScore[i];
		//}
		//for (int i = 1; i < numLines / 3; i++)
		//{
		//	HighScore1 += highScore[i];
		//}
		//string::size_type mySizeType;
		//string trash;
		in.clear();
		in.seekg(0, ios::beg);

		float *highScoreTemp1 = new float[numLines / 2]; //used if save just inputs highscore
		string *highScoreTempString = new string[numLines];
		//for (int i = 0; i < numLines - 1; i++)
		//{
		//		//getline(in, (highScoreTempString[i]));
		//		in>>highScoreTemp1[i];
		//}
		if (in.is_open())
		{
			//string myArray[5];

			for (int i = 0; i < numLines-1; ++i)
			{
				in >> highScoreTempString[i];
			}
		}

		for (int i = 0; i < numLines/2; i++)
		{
			int j = i ;
 			highScoreTemp1[i] = stof(highScoreTempString[j]);
		}
		selectionSort(highScoreTemp1, numLines /2);/////fuckar upp och blir 0.0000!!! förstår inte varför
		highScore = new string[5];
		for (int i = 0; i < 5; i++)
		{
			highScore[i] = "HighScore: " + to_string(highScoreTemp1[i]);
		}

		HighScore1 = "Current " + highScore[0];

		for (int i = 1; i < 5; i++)
		{
			HighScore1 += "\n" + highScore[i];
		}
		delete[] highScore;
		delete[] highScoreTemp1;
		delete[] highScoreTempString;
	}
	this->highScoreString = HighScore1;
	in.close();
	
}



HighScore::HighScore(/*int kills, float time*/)
{
	//save(kills, time);
	//load();
}


HighScore::~HighScore()
{
}
