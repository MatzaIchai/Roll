#include "send_IMU.h"

Angles angles_calibrate;

rc_imu_data_t data; 

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
  ros::init(argc, argv, "send_IMU");
  
  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
   
  ros::NodeHandle node_IMU_data;

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
  ros::Publisher pub = node_IMU_data.advertise<geometry_msgs::Vector3>("imu_data_2", 1);

  ros::Rate loop_rate(10);

  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */
  angles_calibrate.data_PITCH = 0; 
  angles_calibrate.data_ROLL = 0;
  angles_calibrate.data_YAW = 0;
  
  init_IMU();
  
  calibrate();
  geometry_msgs::Vector3 data_imu;
    
  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
     
    data_imu.x = (data.dmp_TaitBryan[TB_PITCH_X]-angles_calibrate.data_PITCH)*RAD_TO_DEG;
    data_imu.y = (data.dmp_TaitBryan[TB_ROLL_Y]-angles_calibrate.data_ROLL)*RAD_TO_DEG;
    data_imu.z = (data.dmp_TaitBryan[TB_YAW_Z]-angles_calibrate.data_YAW)*RAD_TO_DEG;

    pub.publish(data_imu);

    ros::spinOnce();
    loop_rate.sleep();
  }


  return 0;
}

