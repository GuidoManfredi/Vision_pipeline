/* Auto-generated by genmsg_cpp for file /home/gmanfred/devel/ros/Vision_pipeline/vision/reco/reco_3d/srv/OrientedBoundingBoxRecognition.srv */
#ifndef RECO_3D_SERVICE_ORIENTEDBOUNDINGBOXRECOGNITION_H
#define RECO_3D_SERVICE_ORIENTEDBOUNDINGBOXRECOGNITION_H
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

#include "ros/service_traits.h"

#include "sensor_msgs/PointCloud2.h"


#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/Vector3.h"

namespace reco_3d
{
template <class ContainerAllocator>
struct OrientedBoundingBoxRecognitionRequest_ {
  typedef OrientedBoundingBoxRecognitionRequest_<ContainerAllocator> Type;

  OrientedBoundingBoxRecognitionRequest_()
  : cluster()
  , names()
  {
  }

  OrientedBoundingBoxRecognitionRequest_(const ContainerAllocator& _alloc)
  : cluster(_alloc)
  , names(_alloc)
  {
  }

  typedef  ::sensor_msgs::PointCloud2_<ContainerAllocator>  _cluster_type;
   ::sensor_msgs::PointCloud2_<ContainerAllocator>  cluster;

  typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _names_type;
  std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  names;


  typedef boost::shared_ptr< ::reco_3d::OrientedBoundingBoxRecognitionRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::reco_3d::OrientedBoundingBoxRecognitionRequest_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct OrientedBoundingBoxRecognitionRequest
typedef  ::reco_3d::OrientedBoundingBoxRecognitionRequest_<std::allocator<void> > OrientedBoundingBoxRecognitionRequest;

typedef boost::shared_ptr< ::reco_3d::OrientedBoundingBoxRecognitionRequest> OrientedBoundingBoxRecognitionRequestPtr;
typedef boost::shared_ptr< ::reco_3d::OrientedBoundingBoxRecognitionRequest const> OrientedBoundingBoxRecognitionRequestConstPtr;


template <class ContainerAllocator>
struct OrientedBoundingBoxRecognitionResponse_ {
  typedef OrientedBoundingBoxRecognitionResponse_<ContainerAllocator> Type;

  OrientedBoundingBoxRecognitionResponse_()
  : pose()
  , box_dims()
  , names()
  , result(0)
  {
  }

  OrientedBoundingBoxRecognitionResponse_(const ContainerAllocator& _alloc)
  : pose(_alloc)
  , box_dims(_alloc)
  , names(_alloc)
  , result(0)
  {
  }

  typedef  ::geometry_msgs::PoseStamped_<ContainerAllocator>  _pose_type;
   ::geometry_msgs::PoseStamped_<ContainerAllocator>  pose;

  typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _box_dims_type;
   ::geometry_msgs::Vector3_<ContainerAllocator>  box_dims;

  typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _names_type;
  std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  names;

  typedef int32_t _result_type;
  int32_t result;

  enum { SUCCESS = 0 };
  enum { ERROR = 1 };

  typedef boost::shared_ptr< ::reco_3d::OrientedBoundingBoxRecognitionResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::reco_3d::OrientedBoundingBoxRecognitionResponse_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct OrientedBoundingBoxRecognitionResponse
typedef  ::reco_3d::OrientedBoundingBoxRecognitionResponse_<std::allocator<void> > OrientedBoundingBoxRecognitionResponse;

typedef boost::shared_ptr< ::reco_3d::OrientedBoundingBoxRecognitionResponse> OrientedBoundingBoxRecognitionResponsePtr;
typedef boost::shared_ptr< ::reco_3d::OrientedBoundingBoxRecognitionResponse const> OrientedBoundingBoxRecognitionResponseConstPtr;

struct OrientedBoundingBoxRecognition
{

typedef OrientedBoundingBoxRecognitionRequest Request;
typedef OrientedBoundingBoxRecognitionResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;
}; // struct OrientedBoundingBoxRecognition
} // namespace reco_3d

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::reco_3d::OrientedBoundingBoxRecognitionRequest_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::reco_3d::OrientedBoundingBoxRecognitionRequest_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::reco_3d::OrientedBoundingBoxRecognitionRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "a20c1ca225a936faa11b15fe52b8035a";
  }

  static const char* value(const  ::reco_3d::OrientedBoundingBoxRecognitionRequest_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xa20c1ca225a936faULL;
  static const uint64_t static_value2 = 0xa11b15fe52b8035aULL;
};

template<class ContainerAllocator>
struct DataType< ::reco_3d::OrientedBoundingBoxRecognitionRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "reco_3d/OrientedBoundingBoxRecognitionRequest";
  }

  static const char* value(const  ::reco_3d::OrientedBoundingBoxRecognitionRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::reco_3d::OrientedBoundingBoxRecognitionRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "sensor_msgs/PointCloud2 cluster\n\
string[] names\n\
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

  static const char* value(const  ::reco_3d::OrientedBoundingBoxRecognitionRequest_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros


namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::reco_3d::OrientedBoundingBoxRecognitionResponse_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::reco_3d::OrientedBoundingBoxRecognitionResponse_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::reco_3d::OrientedBoundingBoxRecognitionResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "09438245b2a6c9e0c6a5717a2df88a21";
  }

  static const char* value(const  ::reco_3d::OrientedBoundingBoxRecognitionResponse_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x09438245b2a6c9e0ULL;
  static const uint64_t static_value2 = 0xc6a5717a2df88a21ULL;
};

template<class ContainerAllocator>
struct DataType< ::reco_3d::OrientedBoundingBoxRecognitionResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "reco_3d/OrientedBoundingBoxRecognitionResponse";
  }

  static const char* value(const  ::reco_3d::OrientedBoundingBoxRecognitionResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::reco_3d::OrientedBoundingBoxRecognitionResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "\n\
int32 SUCCESS=0\n\
int32 ERROR=1\n\
\n\
\n\
geometry_msgs/PoseStamped pose\n\
\n\
geometry_msgs/Vector3 box_dims\n\
\n\
string[] names\n\
\n\
\n\
int32 result\n\
\n\
\n\
================================================================================\n\
MSG: geometry_msgs/PoseStamped\n\
# A Pose with reference coordinate frame and timestamp\n\
Header header\n\
Pose pose\n\
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
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of postion and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Vector3\n\
# This represents a vector in free space. \n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
";
  }

  static const char* value(const  ::reco_3d::OrientedBoundingBoxRecognitionResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::reco_3d::OrientedBoundingBoxRecognitionRequest_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.cluster);
    stream.next(m.names);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct OrientedBoundingBoxRecognitionRequest_
} // namespace serialization
} // namespace ros


namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::reco_3d::OrientedBoundingBoxRecognitionResponse_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.pose);
    stream.next(m.box_dims);
    stream.next(m.names);
    stream.next(m.result);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct OrientedBoundingBoxRecognitionResponse_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace service_traits
{
template<>
struct MD5Sum<reco_3d::OrientedBoundingBoxRecognition> {
  static const char* value() 
  {
    return "548454f15a44418037250e6b978bad35";
  }

  static const char* value(const reco_3d::OrientedBoundingBoxRecognition&) { return value(); } 
};

template<>
struct DataType<reco_3d::OrientedBoundingBoxRecognition> {
  static const char* value() 
  {
    return "reco_3d/OrientedBoundingBoxRecognition";
  }

  static const char* value(const reco_3d::OrientedBoundingBoxRecognition&) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<reco_3d::OrientedBoundingBoxRecognitionRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "548454f15a44418037250e6b978bad35";
  }

  static const char* value(const reco_3d::OrientedBoundingBoxRecognitionRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<reco_3d::OrientedBoundingBoxRecognitionRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "reco_3d/OrientedBoundingBoxRecognition";
  }

  static const char* value(const reco_3d::OrientedBoundingBoxRecognitionRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<reco_3d::OrientedBoundingBoxRecognitionResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "548454f15a44418037250e6b978bad35";
  }

  static const char* value(const reco_3d::OrientedBoundingBoxRecognitionResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<reco_3d::OrientedBoundingBoxRecognitionResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "reco_3d/OrientedBoundingBoxRecognition";
  }

  static const char* value(const reco_3d::OrientedBoundingBoxRecognitionResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace service_traits
} // namespace ros

#endif // RECO_3D_SERVICE_ORIENTEDBOUNDINGBOXRECOGNITION_H

