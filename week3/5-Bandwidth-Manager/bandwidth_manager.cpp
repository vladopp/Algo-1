#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <map>

using namespace std;

map<string, int> Protocol = {{"ICMP", 1}, {"UDP", 2}, {"RTM", 3}, {"IGMP", 4}, {"DNS", 5}, {"TCP", 6}};

bool Comp(pair<string, string> a, pair<string, string> b)
{
	return true;
}

class BandwidthManager {
public:

	//receives a packet with specified protocol and payload
	void rcv(string protocol, string payload)
	{
		q.push(make_pair(protocol, payload));
	}
	
	//returns the payload of the packet which should be sent
	string send()
	{
		if(q.empty())
		{
			return "Nothing to send!";
		}
		else
		{
			string res = q.top().second;
			q.pop();
			return res;
		}
	}
private:
	struct CompareProtocol
	{
		bool operator() (const pair<string,string> &a, const pair<string,string> &b)
		{
			return Protocol[a.first] > Protocol[b.first];
		}
	};

	priority_queue< pair<string, string>, vector< pair<string,string> >, CompareProtocol > q;
};


int main()
{
	BandwidthManager BM;

	BM.rcv("UDP","zxchzrkljhklzrjlkhklzr");
	BM.rcv("TCP","ghljkajklhgjklare");
	BM.rcv("ICMP","ping87.129.54.123");
	cout << BM.send() << endl;
	cout << BM.send() << endl;

	BM.rcv("DNS","maps.google.com");
	cout << BM.send() << endl;

	BM.rcv("TCP","aejkgjkaegaegae");
	cout << BM.send() << endl;
	cout << BM.send() << endl;
	cout << BM.send() << endl;

	return 0;
}