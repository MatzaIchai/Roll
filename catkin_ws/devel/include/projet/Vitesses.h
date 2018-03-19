// Generated by gencpp from file projet/Vitesses.msg
// DO NOT EDIT!


#ifndef PROJET_MESSAGE_VITESSES_H
#define PROJET_MESSAGE_VITESSES_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace projet
{
template <class ContainerAllocator>
struct Vitesses_
{
  typedef Vitesses_<ContainerAllocator> Type;

  Vitesses_()
    : VitesseDroite(0.0)
    , VitesseGauche(0.0)
    , TestSleep(false)  {
    }
  Vitesses_(const ContainerAllocator& _alloc)
    : VitesseDroite(0.0)
    , VitesseGauche(0.0)
    , TestSleep(false)  {
  (void)_alloc;
    }



   typedef float _VitesseDroite_type;
  _VitesseDroite_type VitesseDroite;

   typedef float _VitesseGauche_type;
  _VitesseGauche_type VitesseGauche;

   typedef uint8_t _TestSleep_type;
  _TestSleep_type TestSleep;




  typedef boost::shared_ptr< ::projet::Vitesses_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::projet::Vitesses_<ContainerAllocator> const> ConstPtr;

}; // struct Vitesses_

typedef ::projet::Vitesses_<std::allocator<void> > Vitesses;

typedef boost::shared_ptr< ::projet::Vitesses > VitessesPtr;
typedef boost::shared_ptr< ::projet::Vitesses const> VitessesConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::projet::Vitesses_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::projet::Vitesses_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace projet

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'projet': ['/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/projet/msg'], 'geometry_msgs': ['/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/geometry_msgs/msg'], 'std_msgs': ['/opt/cloud9/ros_catkin_ws/src/std_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::projet::Vitesses_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::projet::Vitesses_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::projet::Vitesses_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::projet::Vitesses_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::projet::Vitesses_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::projet::Vitesses_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::projet::Vitesses_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e88f4e7b2b13166de27ee260b4e34fa4";
  }

  static const char* value(const ::projet::Vitesses_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe88f4e7b2b13166dULL;
  static const uint64_t static_value2 = 0xe27ee260b4e34fa4ULL;
};

template<class ContainerAllocator>
struct DataType< ::projet::Vitesses_<ContainerAllocator> >
{
  static const char* value()
  {
    return "projet/Vitesses";
  }

  static const char* value(const ::projet::Vitesses_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::projet::Vitesses_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 VitesseDroite\n\
float32 VitesseGauche\n\
bool    TestSleep\n\
\n\
";
  }

  static const char* value(const ::projet::Vitesses_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::projet::Vitesses_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.VitesseDroite);
      stream.next(m.VitesseGauche);
      stream.next(m.TestSleep);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Vitesses_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::projet::Vitesses_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::projet::Vitesses_<ContainerAllocator>& v)
  {
    s << indent << "VitesseDroite: ";
    Printer<float>::stream(s, indent + "  ", v.VitesseDroite);
    s << indent << "VitesseGauche: ";
    Printer<float>::stream(s, indent + "  ", v.VitesseGauche);
    s << indent << "TestSleep: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.TestSleep);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PROJET_MESSAGE_VITESSES_H