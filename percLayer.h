#ifndef PERC_LAYER_H
#define PERC_LAYER_H

#include <vector>
#include <iostream>
#include <ctime>
#include "perceptron.h"
#include "layer.h"

using namespace std;

class PercLayer : public Layer {
private:
	vector <Perc> neyro;
	double dist;
	int counter = 0;
	int count_of_points = 1;
public:
	PercLayer(int aCountOfNeyrons, int aCountOfInputs, double aLearningRate, double distance, int aCount_of_points);
	virtual vector<double> process(const vector <double> aInp);
	virtual vector<double> correct(const vector <double> aInp);
	//virtual void correct(double ans);
	virtual int size() const;
	virtual vector<double> get_w(int num_of_perc, bool flag);
};

#endif // !LAYER_