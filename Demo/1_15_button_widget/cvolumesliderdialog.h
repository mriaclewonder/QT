#ifndef CVOLUMESLIDERDIALOG_H
#define CVOLUMESLIDERDIALOG_H

#include <QDialog>
#include <QSlider>
#include <QWidget>
class CVolumeSliderDialog : public QDialog
{
    Q_OBJECT
public:
    CVolumeSliderDialog(QWidget *parent = Q_NULLPTR);
    ~CVolumeSliderDialog();
    void setsliderValue(int value)
    {
        m_pSlider->setValue(value);
    }
public:
    bool event(QEvent* event) override;

signals:
    void sig_SliderValueChanged(int value);

private:
    QSlider* m_pSlider = nullptr;
};

#endif // CVOLUMESLIDERDIALOG_H
