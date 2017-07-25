#include <pthread.h>
#include <iostream> 
 
using std::cin;
using std::cout;
using std::endl;

class MutexLock
{
public:
	MutexLock();
	~MutexLock();
	void lock();
	void unlock();
private:
	pthread_mutex_t _lock;
	bool _islock;
	friend class Condition;
};

MutexLock::MutexLock()	
{
	pthread_mutex_init(&_lock,NULL);
}

MutexLock::~MutexLock()
{
	pthread_mutex_destroy(&_lock);
}

void MutexLock::lock()
{
	pthread_mutex_lock(&_lock);
}

void MutexLock::unlock()
{
	pthread_mutex_unlock(&_lock);
}

class Condition
{
public:
	Condition(MutexLock &mutelock);
	~Condition();
	void wait();
	void notify();
	void notifyall();
private:
	pthread_cond_t _cond;
	MutexLock &mutex;
};

Condition::Condition(MutexLock &mutelock)
	:mutex(mutelock)
{
	pthread_cond_init(&_cond,NULL);
}

Condition::~Condition()
{
	pthread_cond_destroy(&_cond);
}

void Condition::wait()
{
	pthread_cond_wait(&_cond,&mutex._lock);
}

void Condition::notify()
{
	pthread_cond_signal(&_cond);
}

void Condition::notifyall()
{
	pthread_cond_broadcast(&_cond);
}

int main(void)
{
	MutexLock mutex;
	Condition cond(mutex);
}
