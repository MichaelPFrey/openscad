#include "parametercheckbox.h"

ParameterCheckBox::ParameterCheckBox(QWidget *parent, ParameterObject *parameterobject, int descriptionLoD)
	: ParameterVirtualWidget(parent, parameterobject, descriptionLoD)
{
	setValue();
	connect(checkBox, SIGNAL(clicked()), this, SLOT(onChanged()));

	if (descriptionLoD == descLoD::ShowDetails){
		//large checkbox, when we have the space
		checkBox->setStyleSheet("QCheckBox::indicator {\nwidth: 20px;\nheight: 20px;\n}");
	}
}

void ParameterCheckBox::onChanged()
{
	if(!suppressUpdate){
		object->focus = true;
		object->value = ValuePtr(checkBox->isChecked());
		emit changed();
	}
}

void ParameterCheckBox::setParameterFocus()
{
	this->checkBox->setFocus();
	object->focus = false;
}

void ParameterCheckBox::setValue() {
	suppressUpdate=true;
	this->stackedWidgetRight->setCurrentWidget(this->pageCheckBox);
	this->pageCheckBox->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Expanding);
	this->stackedWidgetBelow->hide();
	this->checkBox->setChecked(object->value->toBool());
	suppressUpdate=false;
}
