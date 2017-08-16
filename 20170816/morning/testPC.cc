#include "taskqueue.h"
#include "producer.h"
#include "consumer.h"

#include <stdlib.h>
#include <unistd.h>

#include <iostream>
#include <memory>
 
using std::cout;
using std::endl;
using std::unique_ptr;

int main(void)
{
	wd::TaskQueue queue(10);
	unique_ptr<wd::Thread> pProducer(new wd::Producer(queue));
	unique_ptr<wd::Thread> pConsumer(new wd::Consumer(queue));
	
	pProducer->start();
	pConsumer->start();

	pProducer->join();
	pConsumer->join();

	return 0;
}
