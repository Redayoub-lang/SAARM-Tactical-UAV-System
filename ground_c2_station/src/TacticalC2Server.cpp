#include "TacticalC2Server.h"

TacticalC2Server::TacticalC2Server(QObject *parent) : QObject(parent)
{
    m_systemStatus = "SYSTEM_ARMED_LINK_ACTIVE";
}

QString TacticalC2Server::systemStatus() const
{
    return m_systemStatus;
}