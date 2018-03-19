#include "Fuse.h"

geometry_msgs::Vector3 data_imu_intern;
geometry_msgs::Vector3 data_imu_extern;


ros::Duration d(0.01);
class Listener
{
	
public:


	void get_IMU1_Callback(const geometry_msgs::Vector3::ConstPtr& data_1)
	{
	    data_imu_extern.x = data_1->x; //// EXTERN DATA 1 !!!!
	    data_imu_extern.y = data_1->y;
	    data_imu_extern.z = data_1->z;
		d.sleep();
	}
	
	void get_IMU2_Callback(const geometry_msgs::Vector3::ConstPtr& data_2)
	{
		data_imu_intern.x = data_2->x;
		data_imu_intern.y = data_2->y;
		data_imu_intern.z = data_2->z;
		d.sleep();
	}
};

int main(int argc, char **argv)
{
  

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
  ros::init(argc, argv, "Fuse");
  
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
  ros::Publisher pub = node_Fuse.advertise<geometry_msgs::Vector3>("euler_angles", 1);

  ros::Rate loop_rate(10);

  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */

  
  
  
  geometry_msgs::Vector3 euler_angles;
  euler_angles.x = 0;
  euler_angles.y = 0;
  euler_angles.z = 0;

  Listener l;
  ros::Subscriber sub1 = node_Fuse.subscribe("imu_data_1", 10, &Listener::get_IMU1_Callback, &l);
  ros::Subscriber sub2 = node_Fuse.subscribe("imu_data_2", 10, &Listener::get_IMU2_Callback, &l);
  
  ros::AsyncSpinner s(2);
  s.start();
  ros::Rate r(5);
    
  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
//ROS_INFO_STREAM("Intern x : [" <<  data_imu_intern.x << "] Extern x : [" <<  data_imu_extern.x << "] Difference x : [" <<  euler_angles.x << "] ");


    euler_angles.x = data_imu_intern.x  - data_imu_extern.x;

    euler_angles.y = data_imu_intern.y  - data_imu_extern.y;
    
    euler_angles.z = data_imu_intern.z  - data_imu_extern.z;
    pub.publish(euler_angles);

    ros::spinOnce();
   
    loop_rate.sleep();
  }


  return 0;
}

