#include "timespace.h"


geometry_msgs::Vector3 data_imu_intern;


ros::Duration d(0.01);
class Listener
{
	
public:



	
	void get_IMU2_Callback(const geometry_msgs::Vector3::ConstPtr& data_2)
	{
		data_imu_intern.x = data_2->x;
		data_imu_intern.y = data_2->y;
		data_imu_intern.z = data_2->z;
		d.sleep();
	}
};
/*******************************************************************************
* int main() 
*
* This template main function contains these critical components
* - call to rc_initialize() at the beginning
* - main while loop that checks for EXITING condition
* - rc_cleanup() at the end
*******************************************************************************/
int main(int argc, char **argv)
{
	// always initialize cape library first
	if(rc_initialize()){
		fprintf(stderr,"ERROR: failed to initialize rc_initialize(), are you root?\n");
		return -1;
	}

	// do your own initialization here
	printf("\nHello BeagleBone\n");

  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   * For programmatic remappings you can use a different version of init() which takes
   * remappings directly, but for most command-line programs, passing argc and argv is
   * the easiest way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "timespace");
  
  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
   
  ros::NodeHandle node_Fuse;

  /**
   * The advertise() function is how you tell ROS that you want to
   * publish on a given topic name. This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing. After this advertise() call is made, the master
   * node will notify anyone who is trying to subscribe to this topic name,
   * and they will in turn negotiate a peer-to-peer connection with this
   * node.  advertise() returns a Publisher object which allows you to
   * publish messages on that topic through a call to publish().  Once
   * all copies of the returned Publisher object are destroyed, the topic
   * will be automatically unadvertised.
   *
   * The second parameter to advertise() is the size of the message queue
   * used for publishing messages.  If messages are published more quickly
   * than we can send them, the number here specifies how many messages to
   * buffer up before throwing some away.
   */

  ros::Rate loop_rate(10);

  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */

  
  
  

  Listener l;
  ros::Subscriber sub2 = node_Fuse.subscribe("imu_data_2", 10, &Listener::get_IMU2_Callback, &l);
  
  ros::AsyncSpinner s(1);
  s.start();
  ros::Rate r(5);
    
  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
//ROS_INFO_STREAM("Intern x : [" <<  data_imu_intern.x << "] Extern x : [" <<  data_imu_extern.x << "] Difference x : [" <<  euler_angles.x << "] ");


    
     data_imu_intern.y = data_imu_intern.y+ 20 + 100;
    usleep(data_imu_intern.y*100);

    rc_set_led(GREEN, ON);
	usleep(data_imu_intern.y*100);
    rc_set_led(GREEN, OFF);


    ros::spinOnce();
   
    
  }
	
	// exit cleanly
	rc_cleanup(); 
	return 0;
}


