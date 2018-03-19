
#include "send_consigne_vitesse.h"
#include <vector>
#include <iostream>

float  get_vitesseA;
float  get_vitesseL;


ros::Duration d(0.01);
class Listener
{
	
public:


	void Vitesse_Lin_Ang_CallBack(const geometry_msgs::Twist::ConstPtr& Vitesse_Lin_Ang)
	{
	//	ROS_INFO_STREAM("Angulaire: [" <<  Vitesse_Lin_Ang->angular.z << "] ");
	//	ROS_INFO_STREAM("Lineaire: [" <<  Vitesse_Lin_Ang->linear.x << "] ");
    get_vitesseA = Vitesse_Lin_Ang->angular.z;
    get_vitesseL =  Vitesse_Lin_Ang->linear.x;
    
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
  ros::init(argc, argv, "send_consigne_vitesse");
  std::vector<float> bufferVG;
  std::vector<float> bufferVD;
  

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
   
  ros::NodeHandle node_consigne_vitesse;

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
  ros::Publisher pub = node_consigne_vitesse.advertise<projet::Vitesses>("consigne_vitesse", 1);

  ros::Rate loop_rate(10);

  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */
  projet::Vitesses  VitesseConsigne;
  VitesseConsigne.TestSleep = false;
  
  Listener l;
	ros::Subscriber sub1 = node_consigne_vitesse.subscribe("Twist", 10, &Listener::Vitesse_Lin_Ang_CallBack, &l);
  ros::AsyncSpinner s(1);
	s.start();
	ros::Rate r(5);
	
  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
     
   //uint8_t
  VitesseConsigne.VitesseGauche = get_vitesseL - get_vitesseA * 0.56;
  VitesseConsigne.VitesseDroite = get_vitesseL + get_vitesseA * 0.56;
  
   // ROS_INFO("%f", VitesseConsigne.VitesseGauche);
  //ROS_INFO("%f", VitesseConsigne.VitesseDroite);
    /**
     * The publish() function is how you send messages. The parameter
     * is the message object. The type of this object must agree with the type
     * given as a template parameter to the advertise<>() call, as was done
     * in the constructor above.
     */

    if (- 1 < VitesseConsigne.VitesseDroite && VitesseConsigne.VitesseDroite < 1)
    {
      bufferVD.push_back(VitesseConsigne.VitesseDroite);
    }
    else
    {
      bufferVD.clear();
      VitesseConsigne.TestSleep = false;
    }
    
    if (- 1 < VitesseConsigne.VitesseGauche && VitesseConsigne.VitesseGauche < 1)
    {
      bufferVG.push_back(VitesseConsigne.VitesseGauche);
    }
    else
    {
      bufferVG.clear();
      VitesseConsigne.TestSleep = false;
    }
    
    if(bufferVD.size() == 30) 
    {
        bufferVD.pop_back();
        if( bufferVG.size() == 30)
        {
            VitesseConsigne.TestSleep = true;
            bufferVG.pop_back();
        }
        else
        {
            VitesseConsigne.TestSleep = false;
        }

    }
    else
    {
        VitesseConsigne.TestSleep = false;
    }
    
    
    
    pub.publish(VitesseConsigne);

    ros::spinOnce();

    loop_rate.sleep();
  }


  return 0;
}