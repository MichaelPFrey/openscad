#pragma once

#include <QMainWindow>
#include <QSettings>

#include "qtgettext.h"
#include "ui_Preferences.h"
#include "settings.h"

class Preferences : public QMainWindow, public Ui::Preferences
{
	Q_OBJECT;

public:
	~Preferences();
	
	static void create(QStringList colorSchemes);
	static Preferences *inst();
	
	QVariant getValue(const QString &key) const;
	void init();
	void apply() const;
	void fireEditorConfigChanged() const;
	void updateButtonState(int,bool) const;
	void AxesChanged(int,double) const;

public slots:
	void actionTriggered(class QAction *);
	void featuresCheckBoxToggled(bool);
	void on_colorSchemeChooser_itemSelectionChanged();
	void on_fontChooser_activated(const QString &);
	void on_fontSize_currentIndexChanged(const QString &);
	void on_syntaxHighlight_activated(const QString &);
	void on_openCSGWarningBox_toggled(bool);
	void on_enableOpenCSGBox_toggled(bool);
	void on_cgalCacheSizeEdit_textChanged(const QString &);
	void on_polysetCacheSizeEdit_textChanged(const QString &);
	void on_opencsgLimitEdit_textChanged(const QString &);
	void on_forceGoldfeatherBox_toggled(bool);
	void on_mouseWheelZoomBox_toggled(bool);
	void on_localizationCheckBox_toggled(bool);
	void on_updateCheckBox_toggled(bool);
	void on_snapshotCheckBox_toggled(bool);
	void on_mdiCheckBox_toggled(bool);
	void on_reorderCheckBox_toggled(bool);
	void on_undockCheckBox_toggled(bool);
	void on_checkNowButton_clicked();
	void on_launcherBox_toggled(bool);
	void on_editorType_currentIndexChanged(const QString &);

	void on_checkBoxShowWarningsIn3dView_toggled(bool);
	
	void on_AxisTrimm();
	void on_AxisTrimmReset();
  //
	// editor settings
  //

	// Indentation
	void on_checkBoxAutoIndent_toggled(bool);
	void on_checkBoxBackspaceUnindents_toggled(bool);
	void on_comboBoxIndentUsing_activated(int);
	void on_spinBoxIndentationWidth_valueChanged(int);
	void on_spinBoxTabWidth_valueChanged(int);
	void on_comboBoxTabKeyFunction_activated(int);
	void on_comboBoxShowWhitespace_activated(int);
	void on_spinBoxShowWhitespaceSize_valueChanged(int);
	
	// Line wrap
	void on_comboBoxLineWrap_activated(int);
	void on_comboBoxLineWrapIndentationStyle_activated(int);
	void on_spinBoxLineWrapIndentationIndent_valueChanged(int);
	void on_comboBoxLineWrapVisualizationStart_activated(int);
	void on_comboBoxLineWrapVisualizationEnd_activated(int);

	// Display
	void on_checkBoxHighlightCurrentLine_toggled(bool);
	void on_checkBoxEnableBraceMatching_toggled(bool);
	void on_checkBoxEnableLineNumbers_toggled(bool);

	// Input Driver
        void on_comboBoxTranslationX_activated(int val);
        void on_comboBoxTranslationY_activated(int val);
        void on_comboBoxTranslationZ_activated(int val);
        void on_comboBoxTranslationXVPRel_activated(int val);
        void on_comboBoxTranslationYVPRel_activated(int val);
        void on_comboBoxTranslationZVPRel_activated(int val);
        void on_comboBoxRotationX_activated(int val);
        void on_comboBoxRotationY_activated(int val);
        void on_comboBoxRotationZ_activated(int val);
        void on_comboBoxZoom_activated(int val);
        void on_comboBoxButton0_activated(int val);
        void on_comboBoxButton1_activated(int val);
        void on_comboBoxButton2_activated(int val);
        void on_comboBoxButton3_activated(int val);
        void on_comboBoxButton4_activated(int val);
        void on_comboBoxButton5_activated(int val);
        void on_comboBoxButton6_activated(int val);
        void on_comboBoxButton7_activated(int val);
        void on_comboBoxButton8_activated(int val);
        void on_comboBoxButton9_activated(int val);

	void on_doubleSpinBoxDeadzone0_valueChanged(double);        
	void on_doubleSpinBoxDeadzone1_valueChanged(double);
	void on_doubleSpinBoxDeadzone2_valueChanged(double);
	void on_doubleSpinBoxDeadzone3_valueChanged(double);        
	void on_doubleSpinBoxDeadzone4_valueChanged(double);
	void on_doubleSpinBoxDeadzone5_valueChanged(double);
	void on_doubleSpinBoxDeadzone6_valueChanged(double);        
	void on_doubleSpinBoxDeadzone7_valueChanged(double);
	void on_doubleSpinBoxDeadzone8_valueChanged(double);
	
	void on_doubleSpinBoxTrimm0_valueChanged(double);
	void on_doubleSpinBoxTrimm1_valueChanged(double);
	void on_doubleSpinBoxTrimm2_valueChanged(double);	
	void on_doubleSpinBoxTrimm3_valueChanged(double);
	void on_doubleSpinBoxTrimm4_valueChanged(double);
	void on_doubleSpinBoxTrimm5_valueChanged(double);	
	void on_doubleSpinBoxTrimm6_valueChanged(double);
	void on_doubleSpinBoxTrimm7_valueChanged(double);
	void on_doubleSpinBoxTrimm8_valueChanged(double);	
		
signals:
	void requestRedraw() const;
	void updateMdiMode(bool mdi) const;
	void updateUndockMode(bool undockMode) const;
	void updateReorderMode(bool undockMode) const;
	void fontChanged(const QString &family, uint size) const;
	void colorSchemeChanged(const QString &scheme) const;
	void openCSGSettingsChanged() const;
	void syntaxHighlightChanged(const QString &s) const;
	void editorTypeChanged(const QString &type);
	void editorConfigChanged() const;
	void ExperimentalChanged() const ;
        void inputMappingChanged() const;
        void inputCalibrationChanged() const;

private:
    Preferences(QWidget *parent = nullptr);
	void keyPressEvent(QKeyEvent *e);
	void updateGUI();
	void removeDefaultSettings();
	void setupFeaturesPage();
	void writeSettings();
	void addPrefPage(QActionGroup *group, QAction *action, QWidget *widget);

	/** Initialize combobox list values from the settings range values */
	void initComboBox(QComboBox *comboBox, const Settings::SettingsEntry& entry);
	/** Initialize spinbox min/max values from the settings range values */
	void initSpinBox(QSpinBox *spinBox, const Settings::SettingsEntry& entry);
	void initDoubleSpinBox(QDoubleSpinBox *spinBox, const Settings::SettingsEntry& entry);
	/** Update combobox from current settings */
	void updateComboBox(QComboBox *comboBox, const Settings::SettingsEntry& entry);
	/** Set value from combobox to settings */
	void applyComboBox(QComboBox *comboBox, int val, Settings::SettingsEntry& entry);

	QSettings::SettingsMap defaultmap;
	QHash<const QAction *, QWidget *> prefPages;

	static Preferences *instance;
	static const char *featurePropertyName;

	const QString EmptyString= QString("");
	const QString ActiveStyleString= QString("font-weight: bold; color: red");
};
