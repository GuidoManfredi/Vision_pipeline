/* Auto-generated by genmsg_cpp for file /home/gmanfred/devel/ros/packs/vision/seg/seg_plans_objs/msg/Clusters.msg */
#ifndef SEG_PLANS_OBJS_MESSAGE_CLUSTERS_H
#define SEG_PLANS_OBJS_MESSAGE_CLUSTERS_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "sensor_msgs/PointCloud2.h"

namespace seg_plans_objs
{
template <class ContainerAllocator>
struct Clusters_ {
  typedef Clusters_<ContainerAllocator> Type;

  Clusters_()
  : clusters()
  {
  }

  Clusters_(const ContainerAllocator& _alloc)
  : clusters(_alloc)
  {
  }

  typedef std::vector< ::sensor_msgs::PointCloud2_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::sensor_msgs::PointCloud2_<ContainerAllocator> >::other >  _clusters_type;
  std::vector< ::sensor_msgs::PointCloud2_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::sensor_msgs::PointCloud2_<ContainerAllocator> >::other >  clusters;


  typedef boost::shared_ptr< ::seg_plans_objs::Clusters_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::seg_plans_objs::Clusters_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct Clusters
typedef  ::seg_plans_objs::Clusters_<std::allocator<void> > Clusters;

typedef boost::shared_ptr< ::seg_plans_objs::Clusters> ClustersPtr;
typedef boost::shared_ptr< ::seg_plans_objs::Clusters const> ClustersConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::seg_plans_objs::Clusters_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::seg_plans_objs::Clusters_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace seg_plans_objs

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::seg_plans_objs::Clusters_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::seg_plans_objs::Clusters_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::seg_plans_objs::Clusters_<ContainerAllocator> > {
  static const char* value() 
  {
    return "f94e5e56fc7ff419809a40b3ff371b4c";
  }

  static const char* value(const  ::seg_plans_objs::Clusters_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xf94e5e56fc7ff419ULL;
  static const uint64_t static_value2 = 0x809a40b3ff371b4cULL;
};

template<class ContainerAllocator>
struct DataType< ::seg_plans_objs::Clusters_<ContainerAllocator> > {
  static const char* value() 
  {
    return "seg_plans_objs/Clusters";
  }

  static const char* value(const  ::seg_plans_objs::Clusters_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::seg_plans_objs::Clusters_<ContainerAllocator> > {
  static const char* value() 
  {
    return "sensor_msgs/PointCloud2[] clusters\n\
\n\
================================================================================\n\
MSG: sensor_msgs/PointCloud2\n\
# This message holds a collection of N-dimensional points, which may\n\
# contain additional information such as normals, intensity, etc. The\n\
# point data is stored as a binary blob, its layout described by the\n\
# contents of the \"fields\" array.\n\
\n\
# The point cloud data may be organized 2d (image-like) or 1d\n\
# (unordered). Point clouds organized as 2d images may be produced by\n\
# camera depth sensors such as stereo or time-of-flight.\n\
\n\
# Time of sensor data acquisition, and the coordinate frame ID (for 3d\n\
# points).\n\
Header header\n\
\n\
# 2D structure of the point cloud. If the cloud is unordered, height is\n\
# 1 and width is the length of the point cloud.\n\
uint32 height\n\
uint32 width\n\
\n\
# Describes the channels and their layout in the binary data blob.\n\
PointField[] fields\n\
\n\
bool    is_bigendian # Is this data bigendian?\n\
uint32  point_step   # Length of a point in bytes\n\
uint32  row_step     # Length of a row in bytes\n\
uint8[] data         # Actual point data, size is (row_step*height)\n\
\n\
bool is_dense        # True if there are no invalid points\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: sensor_msgs/PointField\n\
# This message holds the description of one point entry in the\n\
# PointCloud2 message format.\n\
uint8 INT8    = 1\n\
uint8 UINT8   = 2\n\
uint8 INT16   = 3\n\
uint8 UINT16  = 4\n\
uint8 INT32   = 5\n\
uint8 UINT32  = 6\n\
uint8 FLOAT32 = 7\n\
uint8 FLOAT64 = 8\n\
\n\
string name      # Name of field\n\
uint32 offset    # Offset from start of point struct\n\
uint8  datatype  # Datatype enumeration, see above\n\
uint32 count     # How many elements in the field\n\
\n\
";
  }

  static const char* value(const  ::seg_plans_objs::Clusters_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::seg_plans_objs::Clusters_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.clusters);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct Clusters_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::seg_plans_objs::Clusters_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::seg_plans_objs::Clusters_<ContainerAllocator> & v) 
  {
    s << indent << "clusters[]" << std::endl;
    for (size_t i = 0; i < v.clusters.size(); ++i)
    {
      s << indent << "  clusters[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::sensor_msgs::PointCloud2_<ContainerAllocator> >::stream(s, indent + "    ", v.clusters[i]);
    }
  }
};


} // namespace message_operations
} // namespace ros

#endif // SEG_PLANS_OBJS_MESSAGE_CLUSTERS_H

