// Generated by gencpp from file geometry_msgs/Polygon.msg
// DO NOT EDIT!


#ifndef GEOMETRY_MSGS_MESSAGE_POLYGON_H
#define GEOMETRY_MSGS_MESSAGE_POLYGON_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Point32.h>

namespace geometry_msgs
{
template <class ContainerAllocator>
struct Polygon_
{
  typedef Polygon_<ContainerAllocator> Type;

  Polygon_()
    : points()  {
    }
  Polygon_(const ContainerAllocator& _alloc)
    : points(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector< ::geometry_msgs::Point32_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::geometry_msgs::Point32_<ContainerAllocator> >::other >  _points_type;
  _points_type points;




  typedef boost::shared_ptr< ::geometry_msgs::Polygon_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::geometry_msgs::Polygon_<ContainerAllocator> const> ConstPtr;

}; // struct Polygon_

typedef ::geometry_msgs::Polygon_<std::allocator<void> > Polygon;

typedef boost::shared_ptr< ::geometry_msgs::Polygon > PolygonPtr;
typedef boost::shared_ptr< ::geometry_msgs::Polygon const> PolygonConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::geometry_msgs::Polygon_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::geometry_msgs::Polygon_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace geometry_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/cloud9/ros_catkin_ws/src/std_msgs/msg'], 'geometry_msgs': ['/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/geometry_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::geometry_msgs::Polygon_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::geometry_msgs::Polygon_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::geometry_msgs::Polygon_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::geometry_msgs::Polygon_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::geometry_msgs::Polygon_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::geometry_msgs::Polygon_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::geometry_msgs::Polygon_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cd60a26494a087f577976f0329fa120e";
  }

  static const char* value(const ::geometry_msgs::Polygon_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xcd60a26494a087f5ULL;
  static const uint64_t static_value2 = 0x77976f0329fa120eULL;
};

template<class ContainerAllocator>
struct DataType< ::geometry_msgs::Polygon_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/Polygon";
  }

  static const char* value(const ::geometry_msgs::Polygon_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::geometry_msgs::Polygon_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#A specification of a polygon where the first and last points are assumed to be connected\n\
Point32[] points\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point32\n\
# This contains the position of a point in free space(with 32 bits of precision).\n\
# It is recommeded to use Point wherever possible instead of Point32.  \n\
# \n\
# This recommendation is to promote interoperability.  \n\
#\n\
# This message is designed to take up less space when sending\n\
# lots of points at once, as in the case of a PointCloud.  \n\
\n\
float32 x\n\
float32 y\n\
float32 z\n\
";
  }

  static const char* value(const ::geometry_msgs::Polygon_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::geometry_msgs::Polygon_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.points);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Polygon_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::geometry_msgs::Polygon_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::geometry_msgs::Polygon_<ContainerAllocator>& v)
  {
    s << indent << "points[]" << std::endl;
    for (size_t i = 0; i < v.points.size(); ++i)
    {
      s << indent << "  points[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::geometry_msgs::Point32_<ContainerAllocator> >::stream(s, indent + "    ", v.points[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // GEOMETRY_MSGS_MESSAGE_POLYGON_H
