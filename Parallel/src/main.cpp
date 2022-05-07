#include <stdio.h>
#include <stdlib.h>
#include "Board.hpp"

boost::barrier b(4);

void task1(){
	printf("task1\n");
	b.wait();
}

void task2(){
	printf("task2\n");
	b.wait();
}

int main(){
	boost::asio::thread_pool pool(4);
	//boost::asio::thread_pool::scheduler_type sch = pool.scheduler();
	//printf("running in thread %d\n", sch.running_in_this_thread());
	boost::asio::post(pool, task1);
	boost::asio::post(pool, task1);
	boost::asio::post(pool, task1);
	boost::asio::post(pool, task1);
	//while(!flags[0] && !flags[1] && !flags[2] && !flags[3]);
	boost::asio::post(pool, task2);
	boost::asio::post(pool, task2);
	boost::asio::post(pool, task2);
	boost::asio::post(pool, task2);
	boost::asio::post(pool, task1);
	boost::asio::post(pool, task1);
	boost::asio::post(pool, task1);
	boost::asio::post(pool, task1);
	boost::asio::post(pool, task2);
	boost::asio::post(pool, task2);
	boost::asio::post(pool, task2);
	boost::asio::post(pool, task2);
	pool.wait();
	return 0;
}
