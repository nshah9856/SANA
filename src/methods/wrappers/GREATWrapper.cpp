#include <vector>
#include <iostream>
#include <sstream>
#include "GREATWrapper.hpp"

using namespace std;

const string CONVERTER = "bio-graph";
const string GHOSTBinary = "GHOST";
const string scripts[4] = {
			"run_G_G.sh",
			"run_G_H.sh",
			"run_H_G.sh",
			"run_H_H.sh",};

GREATWrapper::GREATWrapper(Graph* G1, Graph* G2, string args): WrappedMethod(G1, G2, "GREAT", args) {
	wrappedDir = "wrappedAlgorithms/GREAT";
}

void GREATWrapper::loadDefaultParameters() {
	parameters = "0 10";
}

string GREATWrapper::convertAndSaveGraph(Graph* graph, string name) {
	graph->saveInGWFormat(name + ".gw");
	return name + ".gw";
}

string GREATWrapper::generateAlignment() {
	exec("cd " + wrappedDir + "; mv *.gw networks/.");


	exec("cd " + wrappedDir + "; chmod +x *.sh");
	exec("cd " + wrappedDir + "/src; chmod +x *");

	exec("cd " + wrappedDir + "; count.sh " + g1FileName);
	exec("cd " + wrappedDir + "; count.sh " + g2FileName);

	string script = scripts[atoi(parameters.substr(0, 1).c_str())];
	string alpha = parameters.substr(2, 2);

	string options = "echo \"" + g1FileName + "\n" + g2FileName + "\n" + alpha + "\n" + "\" | ";


	return " ";
}

Alignment GREATWrapper::loadAlignment(Graph* G1, Graph* G2, string fileName) {
	//TODO replace
	exit(-1);
    vector<ushort> mapping(G1->getNumNodes(), G2->getNumNodes());
    return Alignment(mapping);
}

void GREATWrapper::deleteAuxFiles() {
    exec("cd " + wrappedDir + "; rm " + g1File + " " + g2File);
}