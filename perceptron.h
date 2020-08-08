#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <vector>
#include <iostream>	
#include <ctime>

using namespace std;

class Perc {
private:
	double sigmoid(double x);
	double dActivationFunction(double x);

	double summ;
	double out;
	vector <double> W;
	vector <double> input;
	double learningRate;
	double mOffset;

public:
	//Perc(int aCountOfW, double aLearningRate = 0.3);
	Perc(int aCountOfW, int count_of_neyro, double aLearningRate = 0.3);
	double process(vector<double> aInput);
	void changeWeights();
	double output();
	//void init(int aCountOfW, double aLearningRate);
	vector<double> ret_w();
};
#endif // !Perceptron