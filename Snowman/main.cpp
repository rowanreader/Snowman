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
