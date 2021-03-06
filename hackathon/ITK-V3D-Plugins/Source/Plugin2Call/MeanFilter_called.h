/* MeanFilter.h
 * 2010-06-03: create this program by Lei Qu
 */

#ifndef __MEANFILTER_H__
#define __MEANFILTER_H__

#include <QtGui>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <v3d_interface.h>

class ITKMeanFilterPlugin: public QObject, public V3DPluginInterface2
{
	Q_OBJECT
	Q_INTERFACES(V3DPluginInterface2)

public:
	ITKMeanFilterPlugin() {}
  	QStringList menulist() const;
	QStringList funclist() const;

	void domenu(const QString & menu_name, V3DPluginCallback2 & callback, QWidget * parent);

	bool dofunc(const QString & func_name, const V3DPluginArgList & input, V3DPluginArgList & output,
				 V3DPluginCallback2 & v3d,  QWidget * parent);

};

class ITKMeanFilterDialog: public QDialog
{
Q_OBJECT

public:
	ITKMeanFilterDialog(Image4DSimple *p4DImage, QWidget *parent)
	{
		if (!p4DImage)
			return;

		printf("Passing data to data1d\n");

		ok = new QPushButton("OK");
		cancel = new QPushButton("Cancel");

		gridLayout = new QGridLayout();

		gridLayout->addWidget(cancel, 0, 0);
		gridLayout->addWidget(ok, 0, 1);
		setLayout( gridLayout);
		setWindowTitle(QString("Mean Filter"));

		connect(ok, SIGNAL(clicked()), this, SLOT(accept()));
		connect(cancel, SIGNAL(clicked()), this, SLOT(reject()));
	}

	~ITKMeanFilterDialog()
	{
	}

public slots:

public:
	QGridLayout *gridLayout;

	QPushButton* ok;
	QPushButton* cancel;
};

#endif

