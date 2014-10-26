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
#include <ctype.h>
#include "common.h"
#include "pcan_receive.h"
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

// DEFINES

#define DEFAULT_NODE "/dev/pcan32"
#define CURRENT_RELEASE "Release_20090203_n"

// GLOBALS

HANDLE h;
const char *current_release;


int main(int argc, char** argv)
{
	/*!
			 *\brief The main() function only initiates a ROS node, creates and initializes a pcan_receive object instance, sets two signal handlers and starts to loop.
			 *
			 *
			 *
			 * */
	ros::init(argc, argv, "pcan_receive");
	pcan_receive pcan_receive_1;
	pcan_receive_1.init(argc, argv);
	signal(SIGTERM, signal_handler);
	signal(SIGINT, signal_handler);
	// Enter read loop in which Can data is published on /can_in
	while(ros::ok)
	{
		pcan_receive_1.receive();
	}
}





