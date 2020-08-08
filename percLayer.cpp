#include "percLayer.h"
//Layer::Layer(int aCountOfNeyrons, int aCountOfInputs, double aLearningRate) :
//	neyro(0)
//{
//	for (int i = 0; i < aCountOfNeyrons; ++i)
//	{
//		neyro.emplace_back(Perc());
//		neyro[i].init(aCountOfInputs, aLearningRate);
//	}
//}

PercLayer::PercLayer(int aCountOfNeyrons, int aCountOfInputs, double aLearningRate, double distance, int aCount_of_points)/* :
	neyro(aCountOfNeyrons, Perc(aCountOfInputs, rand()))*/
{
	for (int i = 0; i < aCountOfNeyrons; i++) {
		neyro.push_back(Perc(aCountOfInputs, i));
	}
	dist = distance;
	count_of_points = aCount_of_points;
}

vector <double> PercLayer::process(const vector <double> aInp) {
	vector <double> res;
	for (auto& i : neyro) {
		res.push_back(i.process(aInp));
	}
	return res;
}

vector<double> PercLayer::correct(const vector <double> aInp) {
	vector<double> sampleWeights = neyro[int(aInp[0])].ret_w();
	for (int i = 0; i < neyro.size(); i++){
		vector<double> weights = neyro[i].ret_w();
		double summ = 0;

		for (int j = 0; j < sampleWeights.size(); j++) {
			summ += (sampleWeights[j] - weights[j]) * (sampleWeights[j] - weights[j]);
		}
		if (sqrt(summ) <= (dist - (dist/(5000 * count_of_points))*counter)) {
			neyro[i].changeWeights();
		}
	}
	counter++;
	return{};
}

//void PercLayer::correct(double ans) {
//	for (int i = 0; i < neyro.size(); i++)
//	{
//		neyro[i].changeWeights(ans);
//	}
//}

int PercLayer::size() const {
	return neyro.size();
}

vector<double> PercLayer::get_w(int num_of_perc, bool flag) {
	vector<double> out;
	if (num_of_perc < 0) {
		out = { -1 };
		return out;
	}else if (flag) {
		for (int i = 0; i < neyro.size(); i++) {
			out.push_back(neyro[i].ret_w()[num_of_perc]);
		}
	}
	else {
		out = neyro[num_of_perc].ret_w();
	}
	return out;
}