/*

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QFile>
#include <Inventor/nodes/SoBaseColor.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoSphere.h>
#include <Inventor/nodes/SoCylinder.h>
#include <Inventor/nodes/SoCone.h>
#include <Inventor/nodes/SoRotation.h>
#include <Inventor/nodes/SoBaseColor.h>
#include <Inventor/nodes/SoMaterial.h>
#include <Inventor/nodes/SoTransform.h>
#include <Quarter/Quarter.h>
#include <Quarter/QuarterWidget.h>
#include <Quarter/eventhandlers/DragDropHandler.h>
#include <ui_QuarterViewer.h>

using namespace SIM::Coin3D::Quarter;
int main(int argc, char *argv[])
{
	// start application
	QApplication a(argc, argv);
	Quarter::init();

	// widget = screen we see
	QWidget * viewer = new QWidget;
	// style?
	Ui::QuarterViewer ui; // I'm assuming this is a bunch of formatting stuff
	ui.setupUi(viewer);
	viewer->resize(600, 800); // change size of window
	//viewer->setStyleSheet("background-color:blue;"); // only makes border blue
	SoSeparator * root = new SoSeparator;
	//SoMaterial * l = new SoMaterial;
	//l->diffuseColor.setValue(0.2, 0.5, 0.2);
	//root->addChild(l);
	root->ref();

	// BASE
	// new thing/material
	SoSeparator * base = new SoSeparator;
	root->addChild(base);
	SoMaterial* m = new SoMaterial();
	SoSphere * sphereBase = new SoSphere();
	SoTransform * baseT = new SoTransform();
	baseT->translation.setValue(0, -.7, 0);
	base->addChild(m);
	// m->transparency = 0.6;
	m->diffuseColor.setValue(1, 1, 1); // make white
	base->addChild(baseT);
	base->addChild(sphereBase); // add sphere to root


	// for all buttons
	SoMaterial * t = new SoMaterial;
	t->diffuseColor.setValue(0.5, 0, 0.5);

	// button 3
	SoSeparator * button3 = new SoSeparator;
	SoSphere * sphereB3 = new SoSphere;
	SoTransform * b3T = new SoTransform;
	sphereB3->radius = 0.1;
	b3T->translation.setValue(0, 0.75, 0.6);
	button3->addChild(b3T);
	button3->addChild(t);
	button3->addChild(sphereB3);
	base->addChild(button3);



	// MIDDLE
	SoSeparator * middle = new SoSeparator;
	root->addChild(middle);
	SoMaterial* n = new SoMaterial();
	n->diffuseColor.setValue(1, 1, 1);
	SoSphere * sphereMid = new SoSphere();
	SoTransform * middleT = new SoTransform();
	middleT->translation.setValue(0, 1, 0);
	sphereMid->radius = .7;
	middle->addChild(n);
	middle->addChild(middleT);
	middle->addChild(sphereMid);

	// button 1 and 2
	SoSeparator * button1 = new SoSeparator;
	SoSeparator * button2 = new SoSeparator;
	SoSphere * sphereB1 = new SoSphere;
	SoSphere * sphereB2 = new SoSphere;
	SoTransform * b1T = new SoTransform;
	SoTransform * b2T = new SoTransform;
	sphereB1->radius = 0.1;
	sphereB2->radius = 0.1;
	b1T->translation.setValue(0,0.2,0.6);
	b2T->translation.setValue(0, -0.2, 0.6);

	button1->addChild(t);
	button1->addChild(b1T);
	button1->addChild(sphereB1);
	
	button2->addChild(t);
	button2->addChild(b2T);
	button2->addChild(sphereB2);

	middle->addChild(button1);
	middle->addChild(button2);

	// HEAD
	SoSeparator * head = new SoSeparator;
	root->addChild(head);
	SoMaterial * o = new SoMaterial();
	o->diffuseColor.setValue(1, 1, 1);
	SoSphere * sphereHead = new SoSphere();
	SoTransform * headT = new SoTransform();
	sphereHead->radius = 0.5;
	headT->translation.setValue(0, 2.2, 0); // 1.9 + rad
	head->addChild(o);
	head->addChild(headT);
	head->addChild(sphereHead);

	// nose
	SoSeparator * nose = new SoSeparator;
	head->addChild(nose);
	SoMaterial * r = new SoMaterial();
	r->diffuseColor.setValue(1, 0.2, 0);
	SoCone * coneNose = new SoCone;
	SoTransform * noseT = new SoTransform;
	SoRotation * noseR = new SoRotation;
	noseT->translation.setValue(0,0,0.7);
	noseR->rotation.setValue(SbVec3f(1,0,0),1.57);
	coneNose->bottomRadius = 0.1;
	coneNose->height = 0.45;
	nose->addChild(r);
	nose->addChild(noseT);
	nose->addChild(noseR);
	nose->addChild(coneNose);
	head->addChild(nose);

	// eyes
	
	SoSeparator * eye1 = new SoSeparator;
	SoMaterial * s = new SoMaterial();
	s->diffuseColor.setValue(0, 0, 1);
	SoSphere * sphereEye1 = new SoSphere;
	SoTransform * eye1T = new SoTransform;

	SoSeparator * eye2 = new SoSeparator;
	SoSphere * sphereEye2 = new SoSphere;
	SoTransform * eye2T = new SoTransform;

	eye1T->translation.setValue(-.15, .18, 0.4);
	eye2T->translation.setValue(.15, .18, 0.4);

	sphereEye1->radius = 0.08;
	sphereEye2->radius = 0.08;

	eye1->addChild(s);
	eye2->addChild(s);
	eye1->addChild(eye1T);
	eye2->addChild(eye2T);
	eye1->addChild(sphereEye1);
	eye2->addChild(sphereEye2);
	head->addChild(eye1);
	head->addChild(eye2);

	// HAT
	SoSeparator * hat = new SoSeparator;
	root->addChild(hat);
	SoMaterial * p = new SoMaterial();
	p->diffuseColor.setValue(0, 1, 0);
	hat->addChild(p);

	// bucket
	SoCylinder * bucket = new SoCylinder();
	SoTransform * bucketT = new SoTransform();
	bucket->radius = 0.45;
	bucket->height = .8;
	bucketT->translation.setValue(0, 3, 0);	
	hat->addChild(bucketT);
	hat->addChild(bucket);

	// rim
	SoCylinder * rim = new SoCylinder();
	SoTransform * rimT = new SoTransform;
	rim->radius = 0.6;
	rim->height = 0.05;
	rimT->translation.setValue(0, -.4, 0);
	hat->addChild(rimT);
	hat->addChild(rim);

	// ribbon
	SoMaterial * q = new SoMaterial(); // need to change color	
	q->diffuseColor.setValue(1, 0, 0);
	SoCylinder * ribbon = new SoCylinder();
	SoTransform * ribbonT = new SoTransform();
	ribbon->radius = 0.46;
	ribbon->height = 0.2;
	ribbonT->translation.setValue(0, 0.2, 0);
	hat->addChild(q);
	hat->addChild(ribbonT);
	hat->addChild(ribbon);
	

	
	

	ui.QuarterWidget->setSceneGraph(root); // format?? add root to widget?

	viewer->show(); // show widget
	return a.exec();
}

*/




#include <QtCore/QCoreApplication>
#include <QtWidgets/QApplication>

#include <QtWidgets/QWidget>
#include <QFile>

//#include <QTextStream>
#include <Inventor/nodes/SoBaseColor.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoSphere.h>
#include <Inventor/nodes/SoCylinder.h>
#include <Inventor/nodes/SoCone.h>
#include <Inventor/nodes/SoLineSet.h>
#include <Inventor/nodes/SoCoordinate3.h>
#include <Inventor/nodes/SoRotation.h>
#include <Inventor/nodes/SoBaseColor.h>
#include <Inventor/nodes/SoMaterial.h>
#include <Inventor/nodes/SoTransform.h>
#include <Inventor/fields/SoMFVec3f.h>
#include <Inventor/SbVec3f.h>
#include <Inventor/nodes/SoCube.h>

#include <Quarter/Quarter.h>
#include <Quarter/QuarterWidget.h>
#include <Quarter/eventhandlers/DragDropHandler.h>
#include <Quarter/ui_QuarterViewer.h>


#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>

using namespace System;
using namespace std;
using namespace SIM::Coin3D::Quarter;
int main(int argc, char *argv[])
{
	
	QApplication a(argc, argv);
	Quarter::init();

	QWidget * viewer = new QWidget;
	Ui::QuarterViewer ui;

	
	ui.setupUi(viewer);
	viewer->resize(600, 800);
	
	SoSeparator * root = new SoSeparator;
	root->ref();
	// display breast
	SoInput in;
	in.openFile("S1.iv");
	SoSeparator* file_root = SoDB::readAll(&in);
	
	root->addChild(file_root);
	
	// display points
	ifstream areola("C:\\Users\\Jacqueline\\Documents\\MATLAB\\Jacqueline\\Deluany Distance\\output2.txt");
	
	string hold;
	string num = "";
	int k;
	int found;
	float coords[3] = { 0,0,0 };
	//cout << "Hello World" << endl;
	while (getline(areola, hold)) {
		k = 0;
		found = 0; // we know there are only 2 white spaces (but must add last num)
		while (found < 3) {
			if (hold[k] != ' ') {
				num += hold[k];
			}
			else {
				coords[found] = stof(num);
				found++;
				num = "";
			}
			k++;
		}
		SoSeparator * pt = new SoSeparator;
		//root->addChild(pt);
		SoMaterial * o = new SoMaterial();
		o->diffuseColor.setValue(1, 1, 1);
		SoSphere * sphere = new SoSphere();
		SoTransform * trans = new SoTransform();
		sphere->radius = 1;
		trans->translation.setValue(coords[0], coords[1], coords[2]);
		pt->addChild(o);
		pt->addChild(trans);
		pt->addChild(sphere);
		root->addChild(pt);
		
	}

	ifstream normal("C:\\Users\\Jacqueline\\Documents\\MATLAB\\Jacqueline\\Deluany Distance\\normals.txt");
	vector<vector<float>> normals;
	// first in normals will be index value (face id)
	vector<float> temp;
	int count = 0;
	num = "";
	
	while (getline(normal, hold)) {
		k = 0;
		found = 0; // we know there are only 3 white spaces (but must add last num, exclude 1st num)
		
		while (found < 4) {
			if (hold[k] != ' ') {
				num += hold[k];
			}
			else {				
				if (found > 0) {
					temp.push_back(stof(num));					
				}
				num = "";
				found++;
			}
			k++;
		}
		normals.push_back(temp);
		temp.clear();
	}

	///// get all angles
	ifstream ang("C:\\Users\\Jacqueline\\Documents\\MATLAB\\Jacqueline\\Deluany Distance\\angles.txt");
	vector<float> angles;
	while (getline(ang, hold)) {
		angles.push_back(stof(hold));
	}
	
	vector<vector<float>> allCoords;
	///////////////////
	// display surface points and vectors
	ifstream spts("C:\\Users\\Jacqueline\\Documents\\MATLAB\\Jacqueline\\Deluany Distance\\surface points.txt");
	num = "";

	count = 0;
	while (getline(spts, hold)) {
		k = 0;
		found = 0; // we know there are only 2 white spaces (but must add last num)
		while (found < 3) {
			if (hold[k] != ' ') {
				num += hold[k];
			}
			else {
				coords[found] = stof(num);
				temp.push_back(coords[found]);
				found++;
				num = "";
			}
			k++;
		}
		SoSeparator * pt = new SoSeparator;
		root->addChild(pt);
		SoMaterial * o = new SoMaterial();
		o->diffuseColor.setValue(0, 1, 0);
		//SoCylinder * cyl = new SoCylinder();
		SoSphere * cyl = new SoSphere();
		SoTransform * trans = new SoTransform();
		cyl->radius = 1;
		//cyl->height = 3;
		trans->translation.setValue(coords[0], coords[1], coords[2]);
		allCoords.push_back(temp);
		temp.clear();
		pt->addChild(o);
		pt->addChild(trans);
		pt->addChild(cyl);
		root->addChild(pt);
		count++;
	}
	int dirNum =49; // from matlab (actual-1 cuz 0 based index) WILL NEED TO CHANGE HERE IF CHANGES IN MATLAB
	int ptCount = 0; // what line we are on
	int j = 0; // where we are in the line
	int thresh = 20; // THIS IS WHAT YOU NEED TO CHANGE IN FITPLANE TO MATCH
	/*
	SoSeparator * zAxis = new SoSeparator;
	root->addChild(zAxis);
	SoMaterial * p = new SoMaterial;
	p->diffuseColor.setValue(1, 1, 1);
	SoCoordinate3 *pt1 = new SoCoordinate3;
	SbVec3f vec1(0,1,0);
	SbVec3f vec2(0,100,0);
	pt1->point.setValue(vec1);
	pt1->point.setValue(vec2);

	SoLineSet * ln = new SoLineSet;
	ln->numVertices.setValue(2);
	zAxis->addChild(p);
	zAxis->addChild(pt1);
	zAxis->addChild(ln);
	*/


	for (int i = 0; i < count; i++) {
		SoSeparator * line = new SoSeparator;
		root->addChild(line);
		SoMaterial * p = new SoMaterial();
		p->diffuseColor.setValue(0, 0, 1);
		if (angles[ptCount] > thresh && j != dirNum - 1 && j != 0){ // THRESHOLD IS HERE
			p->diffuseColor.setValue(1, 0, 0);
		}
		if (j == dirNum - 1){
			j = 0;
			ptCount--; // cuz we're moving to the next line, must undo increment
		}
		j++;
		ptCount++;
		SoCoordinate3 *pt1 = new SoCoordinate3;
		SbVec3f vec1(allCoords[i][0], allCoords[i][1], allCoords[i][2]);
		SbVec3f vec2(50*normals[i][0], 50*normals[i][1], 50*normals[i][2]);
		SoTransform * trans = new SoTransform;
		trans->translation.setValue(allCoords[i][0], allCoords[i][1], allCoords[i][2]);
		pt1->point.setValue(vec1);
		pt1->point.setValue(vec2);

		SoLineSet * ln = new SoLineSet;
		ln->numVertices.setValue(2);
		line->addChild(p);
		line->addChild(trans);
		line->addChild(pt1);
		line->addChild(ln);
	}

	// use plane.txt to fit a plane
	ifstream planeFile("C:\\Users\\Jacqueline\\Documents\\MATLAB\\Jacqueline\\Deluany Distance2\\plane.txt");
	vector<vector<float>> plane;
	while (getline(planeFile, hold)) { // should be exactly 4 rows
		k = 0;
		found = 0; // we know there are only 2 white spaces (but must add last num)
		while (found < 3) {
			if (hold[k] != ' ') {
				num += hold[k];
			}
			else {
				coords[found] = stof(num);
				temp.push_back(coords[found]);
				found++;
				num = "";
			}
			k++;
		}
		plane.push_back(temp); // center, dir, dir, dir

	}
	SoSeparator * drawplane = new SoSeparator;
	root->addChild(drawplane);
	SoMaterial * q = new SoMaterial;
	q->diffuseColor.setValue(0, 1, 0);
	SoCube * cube = new SoCube;
	cube->width.setValue(5);
	cube->height.setValue(500);
	cube->depth.setValue(200);
	SoRotation * rotateX = new SoRotation;
	SoRotation * rotateY = new SoRotation;
	SoRotation * rotate = new SoRotation;
	//float mag1 = sqrt(pow(plane[1][0],2) + pow(plane[1][1],2) + pow(plane[1][2],2)); // axis of rotation
	float mag2 = sqrt(pow(plane[2][0], 2) + pow(plane[2][1], 2) + pow(plane[2][2], 2)); // normal
	float dot =  plane[2][1]; // dot with y axis is just middle element of normal
	float angleC = 1.57 - acos(dot/(mag2));
	rotate->rotation.setValue(SbVec3f(plane[1][0], plane[1][1], plane[1][2]), angleC);

	SoTransform * move = new SoTransform;
	move->translation.setValue(plane[0][0], plane[0][1], plane[0][2]);
	drawplane->addChild(q);
	drawplane->addChild(move);

	drawplane->addChild(rotate);
	
	drawplane->addChild(cube);

	ui.QuarterWidget->setSceneGraph(root); // format?? add root to widget?
	viewer->show(); // show widget
	return a.exec();
}
