#ifndef CVOLUMEBUTTON_H
#define CVOLUMEBUTTON_H

#include <QObject>
#include <QPushButton>
#include "cvolumesliderdialog.h"

class CVolumeButton: public QPushButton
{
    Q_OBJECT
public:
    CVolumeButton(QWidget* parent = nullptr);
    ~CVolumeButton();

    bool getMute() const
    {
        return m_isMute;
    }

    void setMute(bool mute)
    {
        m_isMute = mute;
    }
signals:
    void sig_VolumeValue(int value);

protected:
    void paintEvent(QPaintEvent* event) override;
    void enterEvent(QEvent* event) override;
    void leaveEvent(QEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void timerEvent(QTimerEvent* event) override;

private:
    bool m_isMute = false;
    CVolumeSliderDialog* m_pVolumeSliderDlg = nullptr;
    int m_timerId = -1;
};

#endif // CVOLUMEBUTTON_H
