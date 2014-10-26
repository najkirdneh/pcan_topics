// INCLUDE

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>   // exit
#include <signal.h>
#include <string.h>
#include <stdlib.h>   // strtoul
#include <fcntl.h>    // O_RDWR
#include <libpcan.h>
#include "common.h"
#include <ctype.h>

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

// DEFINES

#define DEFAULT_NODE "/dev/pcan32"
#define CURRENT_RELEASE "Release_20090203_n"


class pcan_receive
{
protected:
	HANDLE h;
	const char *current_release;
	ros::NodeHandle n;
	ros::Publisher pcan_pub;
	char *ptr;
	int i;
	int nType;
	__u32 dwPort;
	__u16 wIrq;
	__u16 wBTR0BTR1;
	const char  *szDevNode;
	bool bDevNodeGiven;
	bool bTypeGiven;
	char txt[VERSIONSTRING_LEN];
	std_msgs::String msg;
	std::stringstream ss;
	char *result;
public:
	pcan_receive();
	void hlpMsg();
	void init(int argc, char **argv);
	void receive();
	std_msgs::String TPCANRdMsgToString(TPCANRdMsg m);


};
