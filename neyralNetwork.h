#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include "percLayer.h"
#include "norm.h"
#include "outputLayer.h"
#include "layer.h"


class Network {
private:
	vector<Layer*> layers;
	double answered = 0;
public:
	enum LayerType { NORM, PERC, OUTPUTLAYER };
	Network(std::vector<LayerType> aLayersType, int aInpNeuronsCol, int aNeyronsCount, int aMaxInpSize = 250, double aLerningRate = 0.1, int count_of_points = 1);//TODO: aColOfLayers
	~Network();
	double process(vector<double> aInp);
	void correct();
	vector<double> get_w(int aLayer, int aNeuron);
};


#endif