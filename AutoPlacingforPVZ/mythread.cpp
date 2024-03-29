#include "mythread.h"

MyThread::MyThread():m_function(nullptr),m_mutex(),m_waitCondition(),m_isPaused(false),m_stopRequested(false)
{

}

void MyThread::run()
{
    m_function();
}

void MyThread::Pause()
{
    QMutexLocker locker(&m_mutex);
    m_isPaused=false;
    m_waitCondition.wakeAll();
}

void MyThread::Resume()
{
    QMutexLocker locker(&m_mutex);
    m_isPaused = false;
    m_waitCondition.wakeAll();
}

void MyThread::Stop()
{
    QMutexLocker locker(&m_mutex);
    m_stopRequested = true;
    m_isPaused = false;
    m_waitCondition.wakeAll();
}

bool MyThread::isStop()
{
    return m_stopRequested;
}

bool MyThread::isPaused()
{
    return m_isPaused;
}

