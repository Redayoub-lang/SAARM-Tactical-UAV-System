#pragma once
#include <QObject>
#include <QString>

class TacticalC2Server : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString systemStatus READ systemStatus NOTIFY statusChanged)

private:
    QString m_systemStatus;

public:
    explicit TacticalC2Server(QObject *parent = nullptr);
    QString systemStatus() const;

signals:
    void statusChanged();
};