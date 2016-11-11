#pragma once
#ifndef EVENT_H
#define EVENT_H
struct Event
{
	int sender;
	int receiver;
	double time;

	Event(int sndr, int rcvr, double t)
	{
		sender = sndr;
		receiver = rcvr;
		time = t;
	}
};

#endif

