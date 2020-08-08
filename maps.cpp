#include <vector>
#include <iostream>
#include <ctime>
#include "perceptron.h"
#include "Layer.h"
#include "norm.h"
#include "outputLayer.h"
#include "gui.h"
#include <cmath>
#include "windows.h"
#include "neyralNetwork.h"
int main()
{
	Gui gui(800, 800);
	vector<vector<double>> kvadrat = { {0.1,0.1},{0.11,0.1},{0.12,0.1},{0.13,0.1},{0.14,0.1},{0.15,0.1},{0.16,0.1},{0.17,0.1},{0.18,0.1},{0.19,0.1},{0.2,0.1}/**/,{0.2,0.11},{0.2,0.12},{0.2,0.13},{0.2,0.14},{0.2,0.15},{0.2,0.16},{0.2,0.17},{0.2,0.18},{0.2,0.19},{0.2,0.2}/**/, {0.1,0.2},{0.11, 0.2},{0.12,0.2},{0.13,0.2},{0.14,0.2},{0.15,0.2},{0.16,0.2},{0.17,0.2},{0.18,0.2},{0.19,0.2},{0.2,0.2}/**/,{0.1,0.11},{0.1,0.12},{0.1,0.13},{0.1,0.14},{0.1,0.15},{0.1,0.16},{0.1,0.17},{0.1,0.18},{0.1,0.19},{0.1,0.2} };
	vector<vector<double>> treugolnik = { {0.75,0.75},{0.74,0.76},{0.76,0.76},{0.73,0.77},{0.77,0.77},{0.72,0.78},{0.78,0.78},{0.71,0.79},{0.79,0.79},{0.70,0.80},{0.80,0.80},{0.71,0.80} ,{0.72,0.80},{0.73,0.80},{0.74,0.80},{0.75,0.80},{0.76,0.80},{0.77,0.80},{0.78,0.80},{0.79,0.80} };
	/*while (gui.isOpen()) {
		if (gui.evnt() == Gui::EventType::CLOSE)
			return 0;
		gui.matrix_for_maps(treugolnik, 0);
		gui.matrix_for_maps(kvadrat, 1);
		gui.render();
	}*/
	srand(time(0));
	double n = 0.3 + (rand() % 10) / 100;
	vector<vector<double>> nn;
	for (int i = 0; i < kvadrat.size(); i++) {
		nn.push_back({ kvadrat[i][0] + n, kvadrat[i][1] + n });
	}

	n = 0.3 + (rand() % 10) / 100;
	vector<vector<double>> nnn;
	for (int i = 0; i < treugolnik.size(); i++) {
		nnn.push_back({ treugolnik[i][0] - n, treugolnik[i][1] });
	}

	Network net({ Network::LayerType::PERC,Network::LayerType::OUTPUTLAYER }, 2, 4, 250, 0.3, kvadrat.size()+treugolnik.size()+nn.size()+nnn.size());

	int counter = 0;

	while (gui.isOpen()) {
		cout << "#" << counter << endl;
		for (int i = 0; i < kvadrat.size(); i++) {
			net.process(kvadrat[i]);
			net.correct();
			//if (counter >= 300) {
				
				
			gui.matrix_for_maps(kvadrat, 1);
			gui.matrix_for_maps(treugolnik, 1);
			gui.matrix_for_maps(nn, 1);
			gui.matrix_for_maps(nnn, 1);
			vector<vector<double>> in(0);
			for (int i = 0; i < 4; i++) {
				in.push_back(net.get_w(0, i));
			}
			gui.matrix_for_maps(in, 0);
			gui.render();
			gui.clear();
			//Sleep(50);
			//}
			Sleep(250);
		}
		for (int i = 0; i < treugolnik.size(); i++) {
			net.process(treugolnik[i]);
			net.correct();
			//if (counter >= 300) {
			gui.clear();
			//Sleep(250);
			gui.matrix_for_maps(kvadrat, 1);
			gui.matrix_for_maps(treugolnik, 1);
			gui.matrix_for_maps(nn, 1);
			gui.matrix_for_maps(nnn, 1);
			vector<vector<double>> in(0);
			for (int i = 0; i < 4; i++) {
				in.push_back(net.get_w(0, i));
			}
			gui.matrix_for_maps(in, 0);
			gui.render();
			//Sleep(50);
			//}
			Sleep(250);
		}
		
		for (int i = 0; i < nn.size(); i++) {
			net.process(nn[i]);
			net.correct();
			//if (counter >= 300) {
			gui.clear();
			//Sleep(250);
			gui.matrix_for_maps(kvadrat, 1);
			gui.matrix_for_maps(treugolnik, 1);
			gui.matrix_for_maps(nn, 1);
			gui.matrix_for_maps(nnn, 1);
			vector<vector<double>> in(0);
			for (int i = 0; i < 4; i++) {
				in.push_back(net.get_w(0, i));
			}
			gui.matrix_for_maps(in, 0);
			gui.render();
			//Sleep(50);
			//}
			Sleep(250);
		}

		for (int i = 0; i < nnn.size(); i++) {
			net.process(nnn[i]);
			net.correct();
			//if (counter >= 300) {
			gui.clear();
			//Sleep(250);
			gui.matrix_for_maps(kvadrat, 1);
			gui.matrix_for_maps(treugolnik, 1);
			gui.matrix_for_maps(nn, 1);
			gui.matrix_for_maps(nnn, 1);
			vector<vector<double>> in(0);
			for (int i = 0; i < 4; i++) {
				in.push_back(net.get_w(0, i));
			}
			gui.matrix_for_maps(in, 0);
			gui.render();
			//Sleep(50);
			//}
			Sleep(250);
		}

		switch (gui.evnt())
		{
		case Gui::EventType::CLOSE:
			return 0;
			break;
		case Gui::EventType::PAUSE:
			cout << "Pause"<<endl;
			while (gui.evnt() != Gui::EventType::PAUSE) {
				Sleep(100);
			}
			cout << "!Pause" << endl;
			break;
		default:
			break;
		}
		counter++;
	}
	return 0;
}

