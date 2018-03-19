#include "conversion.h"
#include <vector>
#include <iostream>

#define KA 0.3
#define KL 0.5
#define limite 20

float pitch, roll, yaw;


// ajout
ros::Duration d(0.01);
class Listener
{
	
public:


	void Angles_euler_CallBack(const geometry_msgs::Vector3::ConstPtr& euler_angles)
	{
	//	ROS_INFO_STREAM("Pitch : [" << euler_angles->x << "] Roll : [" <<  euler_angles->y << "] Yaw : [" <<  euler_angles->z << "] ");
		//ROS_INFO_STREAM("Roll : [" <<  euler_angles->y << "] ");
		//ROS_INFO_STREAM("Yaw : [" <<  euler_angles->z << "] ");

        pitch = euler_angles->x;
        roll =  euler_angles->y;
        yaw = euler_angles->z;
    
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
  ros::init(argc, argv, "conversion");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
   
  ros::NodeHandle node_coversion;

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
  ros::Publisher pub = node_coversion.advertise<geometry_msgs::Twist>("Twist", 1);

  ros::Rate loop_rate(10);

  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */
  float  get_vitesseA = 0;
  float  get_vitesseL = 0;

  geometry_msgs::Twist  Vitesse_Lin_Ang_Consigne;
  
  Vitesse_Lin_Ang_Consigne.linear.x = 0;
  Vitesse_Lin_Ang_Consigne.angular.z = 0;

  // ajout
  Listener l;
  ros::Subscriber sub1 = node_coversion.subscribe("euler_angles", 10, &Listener::Angles_euler_CallBack, &l);
  ros::AsyncSpinner s(1);
  s.start();
  ros::Rate r(5);
	


  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
     
      geometry_msgs::Twist  Vitesse_Lin_Ang_Consigne;
    
      //modif
      

     
     if (pitch >= -limite && pitch <= limite)
     {
       if (roll >= -limite && roll <= limite)
       {
         get_vitesseA = 0;
         get_vitesseL = 0;
       }
       else 
       {
         get_vitesseA = KA * roll;
         get_vitesseL = 0;
       }
     }
     else if (pitch < -limite)
     {
       get_vitesseA = 0;
       get_vitesseL = KL * pitch;
     }
     
     else if (pitch > limite )
     {
       if (roll >= -limite && roll <= limite)
       {
         get_vitesseA = 0;
         get_vitesseL = KL * pitch;
       }
       else 
       {
         get_vitesseA = KA * roll;
         get_vitesseL = KL * pitch;
       }
    }
 
    //modif
    
    Vitesse_Lin_Ang_Consigne.linear.x = get_vitesseL;
    Vitesse_Lin_Ang_Consigne.angular.z =  get_vitesseA;
    
    
   // ROS_INFO("Lin %f | Ang %f", Vitesse_Lin_Ang_Consigne.linear.x, Vitesse_Lin_Ang_Consigne.angular.z);

    /**
     * The publish() function is how you send messages. The parameter
     * is the message object. The type of this object must agree with the type
     * given as a template parameter to the advertise<>() call, as was done
     * in the constructor above.
     */
     
     
    pub.publish(Vitesse_Lin_Ang_Consigne);

    ros::spinOnce();

    loop_rate.sleep();
  }


  return 0;
}

