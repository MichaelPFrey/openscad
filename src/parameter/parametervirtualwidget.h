#pragma once

#include "value.h"
#include "qtgettext.h"
#include "ui_ParameterEntryWidget.h"
#include "parameterobject.h"

enum descLoD {ShowDetails,Inline,HideDetails,DescOnly};

class ParameterVirtualWidget : public QWidget, public Ui::ParameterEntryWidget
{
	Q_OBJECT

protected:
	ParameterObject *object;

public:
	ParameterVirtualWidget(QWidget *parent,ParameterObject *parameterobject, int descriptionLoD);
	~ParameterVirtualWidget();
	virtual void setParameterFocus() = 0;
	virtual void setValue() = 0;
	void resizeEvent(QResizeEvent * event) override;

signals:
	void changed();

protected:
	int decimalPrecision;
	virtual void setPrecision(double number);
	void setName(QString name);
	void setDescription(const QString& description);
	void addInline(QString txt);
};
