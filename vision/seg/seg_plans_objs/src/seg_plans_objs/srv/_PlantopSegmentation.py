"""autogenerated by genpy from seg_plans_objs/PlantopSegmentationRequest.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class PlantopSegmentationRequest(genpy.Message):
  _md5sum = "6c042850bdcce03549506f85b146e77b"
  _type = "seg_plans_objs/PlantopSegmentationRequest"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """int64 num_plans_requested

"""
  __slots__ = ['num_plans_requested']
  _slot_types = ['int64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       num_plans_requested

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(PlantopSegmentationRequest, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.num_plans_requested is None:
        self.num_plans_requested = 0
    else:
      self.num_plans_requested = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      buff.write(_struct_q.pack(self.num_plans_requested))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      start = end
      end += 8
      (self.num_plans_requested,) = _struct_q.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      buff.write(_struct_q.pack(self.num_plans_requested))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      start = end
      end += 8
      (self.num_plans_requested,) = _struct_q.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_q = struct.Struct("<q")
"""autogenerated by genpy from seg_plans_objs/PlantopSegmentationResponse.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import tabletop_object_detector.msg
import sensor_msgs.msg
import geometry_msgs.msg
import shape_msgs.msg
import std_msgs.msg

class PlantopSegmentationResponse(genpy.Message):
  _md5sum = "26ce45db91920805e7bcff3f22b1ca05"
  _type = "seg_plans_objs/PlantopSegmentationResponse"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """int32 NO_CLOUD_RECEIVED=1
int32 NO_TABLE=2
int32 OTHER_ERROR=3
int32 SUCCESS=4
tabletop_object_detector/Table table
sensor_msgs/PointCloud2[] clusters
sensor_msgs/Image[] cluster_images
int32 result


================================================================================
MSG: tabletop_object_detector/Table
# Informs that a planar table has been detected at a given location

# The pose gives you the transform that take you to the coordinate system
# of the table, with the origin somewhere in the table plane and the 
# z axis normal to the plane
geometry_msgs/PoseStamped pose

# These values give you the observed extents of the table, along x and y,
# in the table's own coordinate system (above)
# there is no guarantee that the origin of the table coordinate system is
# inside the boundary defined by these values. 
float32 x_min
float32 x_max
float32 y_min
float32 y_max

# There is no guarantee that the table does NOT extend further than these 
# values; this is just as far as we've observed it.


# Newer table definition as triangle mesh of convex hull (relative to pose)
shape_msgs/Mesh convex_hull

================================================================================
MSG: geometry_msgs/PoseStamped
# A Pose with reference coordinate frame and timestamp
Header header
Pose pose

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.secs: seconds (stamp_secs) since epoch
# * stamp.nsecs: nanoseconds since stamp_secs
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of postion and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

================================================================================
MSG: shape_msgs/Mesh
# Definition of a mesh

# list of triangles; the index values refer to positions in vertices[]
MeshTriangle[] triangles

# the actual vertices that make up the mesh
geometry_msgs/Point[] vertices

================================================================================
MSG: shape_msgs/MeshTriangle
# Definition of a triangle's vertices
uint32[3] vertex_indices

================================================================================
MSG: sensor_msgs/PointCloud2
# This message holds a collection of N-dimensional points, which may
# contain additional information such as normals, intensity, etc. The
# point data is stored as a binary blob, its layout described by the
# contents of the "fields" array.

# The point cloud data may be organized 2d (image-like) or 1d
# (unordered). Point clouds organized as 2d images may be produced by
# camera depth sensors such as stereo or time-of-flight.

# Time of sensor data acquisition, and the coordinate frame ID (for 3d
# points).
Header header

# 2D structure of the point cloud. If the cloud is unordered, height is
# 1 and width is the length of the point cloud.
uint32 height
uint32 width

# Describes the channels and their layout in the binary data blob.
PointField[] fields

bool    is_bigendian # Is this data bigendian?
uint32  point_step   # Length of a point in bytes
uint32  row_step     # Length of a row in bytes
uint8[] data         # Actual point data, size is (row_step*height)

bool is_dense        # True if there are no invalid points

================================================================================
MSG: sensor_msgs/PointField
# This message holds the description of one point entry in the
# PointCloud2 message format.
uint8 INT8    = 1
uint8 UINT8   = 2
uint8 INT16   = 3
uint8 UINT16  = 4
uint8 INT32   = 5
uint8 UINT32  = 6
uint8 FLOAT32 = 7
uint8 FLOAT64 = 8

string name      # Name of field
uint32 offset    # Offset from start of point struct
uint8  datatype  # Datatype enumeration, see above
uint32 count     # How many elements in the field

================================================================================
MSG: sensor_msgs/Image
# This message contains an uncompressed image
# (0, 0) is at top-left corner of image
#

Header header        # Header timestamp should be acquisition time of image
                     # Header frame_id should be optical frame of camera
                     # origin of frame should be optical center of cameara
                     # +x should point to the right in the image
                     # +y should point down in the image
                     # +z should point into to plane of the image
                     # If the frame_id here and the frame_id of the CameraInfo
                     # message associated with the image conflict
                     # the behavior is undefined

uint32 height         # image height, that is, number of rows
uint32 width          # image width, that is, number of columns

# The legal values for encoding are in file src/image_encodings.cpp
# If you want to standardize a new string format, join
# ros-users@lists.sourceforge.net and send an email proposing a new encoding.

string encoding       # Encoding of pixels -- channel meaning, ordering, size
                      # taken from the list of strings in include/sensor_msgs/image_encodings.h

uint8 is_bigendian    # is this data bigendian?
uint32 step           # Full row length in bytes
uint8[] data          # actual matrix data, size is (step * rows)

"""
  # Pseudo-constants
  NO_CLOUD_RECEIVED = 1
  NO_TABLE = 2
  OTHER_ERROR = 3
  SUCCESS = 4

  __slots__ = ['table','clusters','cluster_images','result']
  _slot_types = ['tabletop_object_detector/Table','sensor_msgs/PointCloud2[]','sensor_msgs/Image[]','int32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       table,clusters,cluster_images,result

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(PlantopSegmentationResponse, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.table is None:
        self.table = tabletop_object_detector.msg.Table()
      if self.clusters is None:
        self.clusters = []
      if self.cluster_images is None:
        self.cluster_images = []
      if self.result is None:
        self.result = 0
    else:
      self.table = tabletop_object_detector.msg.Table()
      self.clusters = []
      self.cluster_images = []
      self.result = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_3I.pack(_x.table.pose.header.seq, _x.table.pose.header.stamp.secs, _x.table.pose.header.stamp.nsecs))
      _x = self.table.pose.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_7d4f.pack(_x.table.pose.pose.position.x, _x.table.pose.pose.position.y, _x.table.pose.pose.position.z, _x.table.pose.pose.orientation.x, _x.table.pose.pose.orientation.y, _x.table.pose.pose.orientation.z, _x.table.pose.pose.orientation.w, _x.table.x_min, _x.table.x_max, _x.table.y_min, _x.table.y_max))
      length = len(self.table.convex_hull.triangles)
      buff.write(_struct_I.pack(length))
      for val1 in self.table.convex_hull.triangles:
        buff.write(_struct_3I.pack(*val1.vertex_indices))
      length = len(self.table.convex_hull.vertices)
      buff.write(_struct_I.pack(length))
      for val1 in self.table.convex_hull.vertices:
        _x = val1
        buff.write(_struct_3d.pack(_x.x, _x.y, _x.z))
      length = len(self.clusters)
      buff.write(_struct_I.pack(length))
      for val1 in self.clusters:
        _v1 = val1.header
        buff.write(_struct_I.pack(_v1.seq))
        _v2 = _v1.stamp
        _x = _v2
        buff.write(_struct_2I.pack(_x.secs, _x.nsecs))
        _x = _v1.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _x = val1
        buff.write(_struct_2I.pack(_x.height, _x.width))
        length = len(val1.fields)
        buff.write(_struct_I.pack(length))
        for val2 in val1.fields:
          _x = val2.name
          length = len(_x)
          if python3 or type(_x) == unicode:
            _x = _x.encode('utf-8')
            length = len(_x)
          buff.write(struct.pack('<I%ss'%length, length, _x))
          _x = val2
          buff.write(_struct_IBI.pack(_x.offset, _x.datatype, _x.count))
        _x = val1
        buff.write(_struct_B2I.pack(_x.is_bigendian, _x.point_step, _x.row_step))
        _x = val1.data
        length = len(_x)
        # - if encoded as a list instead, serialize as bytes instead of string
        if type(_x) in [list, tuple]:
          buff.write(struct.pack('<I%sB'%length, length, *_x))
        else:
          buff.write(struct.pack('<I%ss'%length, length, _x))
        buff.write(_struct_B.pack(val1.is_dense))
      length = len(self.cluster_images)
      buff.write(_struct_I.pack(length))
      for val1 in self.cluster_images:
        _v3 = val1.header
        buff.write(_struct_I.pack(_v3.seq))
        _v4 = _v3.stamp
        _x = _v4
        buff.write(_struct_2I.pack(_x.secs, _x.nsecs))
        _x = _v3.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _x = val1
        buff.write(_struct_2I.pack(_x.height, _x.width))
        _x = val1.encoding
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _x = val1
        buff.write(_struct_BI.pack(_x.is_bigendian, _x.step))
        _x = val1.data
        length = len(_x)
        # - if encoded as a list instead, serialize as bytes instead of string
        if type(_x) in [list, tuple]:
          buff.write(struct.pack('<I%sB'%length, length, *_x))
        else:
          buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(_struct_i.pack(self.result))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.table is None:
        self.table = tabletop_object_detector.msg.Table()
      if self.clusters is None:
        self.clusters = None
      if self.cluster_images is None:
        self.cluster_images = None
      end = 0
      _x = self
      start = end
      end += 12
      (_x.table.pose.header.seq, _x.table.pose.header.stamp.secs, _x.table.pose.header.stamp.nsecs,) = _struct_3I.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.table.pose.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.table.pose.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 72
      (_x.table.pose.pose.position.x, _x.table.pose.pose.position.y, _x.table.pose.pose.position.z, _x.table.pose.pose.orientation.x, _x.table.pose.pose.orientation.y, _x.table.pose.pose.orientation.z, _x.table.pose.pose.orientation.w, _x.table.x_min, _x.table.x_max, _x.table.y_min, _x.table.y_max,) = _struct_7d4f.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.table.convex_hull.triangles = []
      for i in range(0, length):
        val1 = shape_msgs.msg.MeshTriangle()
        start = end
        end += 12
        val1.vertex_indices = _struct_3I.unpack(str[start:end])
        self.table.convex_hull.triangles.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.table.convex_hull.vertices = []
      for i in range(0, length):
        val1 = geometry_msgs.msg.Point()
        _x = val1
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _struct_3d.unpack(str[start:end])
        self.table.convex_hull.vertices.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.clusters = []
      for i in range(0, length):
        val1 = sensor_msgs.msg.PointCloud2()
        _v5 = val1.header
        start = end
        end += 4
        (_v5.seq,) = _struct_I.unpack(str[start:end])
        _v6 = _v5.stamp
        _x = _v6
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _struct_2I.unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v5.frame_id = str[start:end].decode('utf-8')
        else:
          _v5.frame_id = str[start:end]
        _x = val1
        start = end
        end += 8
        (_x.height, _x.width,) = _struct_2I.unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        val1.fields = []
        for i in range(0, length):
          val2 = sensor_msgs.msg.PointField()
          start = end
          end += 4
          (length,) = _struct_I.unpack(str[start:end])
          start = end
          end += length
          if python3:
            val2.name = str[start:end].decode('utf-8')
          else:
            val2.name = str[start:end]
          _x = val2
          start = end
          end += 9
          (_x.offset, _x.datatype, _x.count,) = _struct_IBI.unpack(str[start:end])
          val1.fields.append(val2)
        _x = val1
        start = end
        end += 9
        (_x.is_bigendian, _x.point_step, _x.row_step,) = _struct_B2I.unpack(str[start:end])
        val1.is_bigendian = bool(val1.is_bigendian)
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.data = str[start:end].decode('utf-8')
        else:
          val1.data = str[start:end]
        start = end
        end += 1
        (val1.is_dense,) = _struct_B.unpack(str[start:end])
        val1.is_dense = bool(val1.is_dense)
        self.clusters.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.cluster_images = []
      for i in range(0, length):
        val1 = sensor_msgs.msg.Image()
        _v7 = val1.header
        start = end
        end += 4
        (_v7.seq,) = _struct_I.unpack(str[start:end])
        _v8 = _v7.stamp
        _x = _v8
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _struct_2I.unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v7.frame_id = str[start:end].decode('utf-8')
        else:
          _v7.frame_id = str[start:end]
        _x = val1
        start = end
        end += 8
        (_x.height, _x.width,) = _struct_2I.unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.encoding = str[start:end].decode('utf-8')
        else:
          val1.encoding = str[start:end]
        _x = val1
        start = end
        end += 5
        (_x.is_bigendian, _x.step,) = _struct_BI.unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.data = str[start:end].decode('utf-8')
        else:
          val1.data = str[start:end]
        self.cluster_images.append(val1)
      start = end
      end += 4
      (self.result,) = _struct_i.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_3I.pack(_x.table.pose.header.seq, _x.table.pose.header.stamp.secs, _x.table.pose.header.stamp.nsecs))
      _x = self.table.pose.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_7d4f.pack(_x.table.pose.pose.position.x, _x.table.pose.pose.position.y, _x.table.pose.pose.position.z, _x.table.pose.pose.orientation.x, _x.table.pose.pose.orientation.y, _x.table.pose.pose.orientation.z, _x.table.pose.pose.orientation.w, _x.table.x_min, _x.table.x_max, _x.table.y_min, _x.table.y_max))
      length = len(self.table.convex_hull.triangles)
      buff.write(_struct_I.pack(length))
      for val1 in self.table.convex_hull.triangles:
        buff.write(val1.vertex_indices.tostring())
      length = len(self.table.convex_hull.vertices)
      buff.write(_struct_I.pack(length))
      for val1 in self.table.convex_hull.vertices:
        _x = val1
        buff.write(_struct_3d.pack(_x.x, _x.y, _x.z))
      length = len(self.clusters)
      buff.write(_struct_I.pack(length))
      for val1 in self.clusters:
        _v9 = val1.header
        buff.write(_struct_I.pack(_v9.seq))
        _v10 = _v9.stamp
        _x = _v10
        buff.write(_struct_2I.pack(_x.secs, _x.nsecs))
        _x = _v9.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _x = val1
        buff.write(_struct_2I.pack(_x.height, _x.width))
        length = len(val1.fields)
        buff.write(_struct_I.pack(length))
        for val2 in val1.fields:
          _x = val2.name
          length = len(_x)
          if python3 or type(_x) == unicode:
            _x = _x.encode('utf-8')
            length = len(_x)
          buff.write(struct.pack('<I%ss'%length, length, _x))
          _x = val2
          buff.write(_struct_IBI.pack(_x.offset, _x.datatype, _x.count))
        _x = val1
        buff.write(_struct_B2I.pack(_x.is_bigendian, _x.point_step, _x.row_step))
        _x = val1.data
        length = len(_x)
        # - if encoded as a list instead, serialize as bytes instead of string
        if type(_x) in [list, tuple]:
          buff.write(struct.pack('<I%sB'%length, length, *_x))
        else:
          buff.write(struct.pack('<I%ss'%length, length, _x))
        buff.write(_struct_B.pack(val1.is_dense))
      length = len(self.cluster_images)
      buff.write(_struct_I.pack(length))
      for val1 in self.cluster_images:
        _v11 = val1.header
        buff.write(_struct_I.pack(_v11.seq))
        _v12 = _v11.stamp
        _x = _v12
        buff.write(_struct_2I.pack(_x.secs, _x.nsecs))
        _x = _v11.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _x = val1
        buff.write(_struct_2I.pack(_x.height, _x.width))
        _x = val1.encoding
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _x = val1
        buff.write(_struct_BI.pack(_x.is_bigendian, _x.step))
        _x = val1.data
        length = len(_x)
        # - if encoded as a list instead, serialize as bytes instead of string
        if type(_x) in [list, tuple]:
          buff.write(struct.pack('<I%sB'%length, length, *_x))
        else:
          buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(_struct_i.pack(self.result))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.table is None:
        self.table = tabletop_object_detector.msg.Table()
      if self.clusters is None:
        self.clusters = None
      if self.cluster_images is None:
        self.cluster_images = None
      end = 0
      _x = self
      start = end
      end += 12
      (_x.table.pose.header.seq, _x.table.pose.header.stamp.secs, _x.table.pose.header.stamp.nsecs,) = _struct_3I.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.table.pose.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.table.pose.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 72
      (_x.table.pose.pose.position.x, _x.table.pose.pose.position.y, _x.table.pose.pose.position.z, _x.table.pose.pose.orientation.x, _x.table.pose.pose.orientation.y, _x.table.pose.pose.orientation.z, _x.table.pose.pose.orientation.w, _x.table.x_min, _x.table.x_max, _x.table.y_min, _x.table.y_max,) = _struct_7d4f.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.table.convex_hull.triangles = []
      for i in range(0, length):
        val1 = shape_msgs.msg.MeshTriangle()
        start = end
        end += 12
        val1.vertex_indices = numpy.frombuffer(str[start:end], dtype=numpy.uint32, count=3)
        self.table.convex_hull.triangles.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.table.convex_hull.vertices = []
      for i in range(0, length):
        val1 = geometry_msgs.msg.Point()
        _x = val1
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _struct_3d.unpack(str[start:end])
        self.table.convex_hull.vertices.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.clusters = []
      for i in range(0, length):
        val1 = sensor_msgs.msg.PointCloud2()
        _v13 = val1.header
        start = end
        end += 4
        (_v13.seq,) = _struct_I.unpack(str[start:end])
        _v14 = _v13.stamp
        _x = _v14
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _struct_2I.unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v13.frame_id = str[start:end].decode('utf-8')
        else:
          _v13.frame_id = str[start:end]
        _x = val1
        start = end
        end += 8
        (_x.height, _x.width,) = _struct_2I.unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        val1.fields = []
        for i in range(0, length):
          val2 = sensor_msgs.msg.PointField()
          start = end
          end += 4
          (length,) = _struct_I.unpack(str[start:end])
          start = end
          end += length
          if python3:
            val2.name = str[start:end].decode('utf-8')
          else:
            val2.name = str[start:end]
          _x = val2
          start = end
          end += 9
          (_x.offset, _x.datatype, _x.count,) = _struct_IBI.unpack(str[start:end])
          val1.fields.append(val2)
        _x = val1
        start = end
        end += 9
        (_x.is_bigendian, _x.point_step, _x.row_step,) = _struct_B2I.unpack(str[start:end])
        val1.is_bigendian = bool(val1.is_bigendian)
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.data = str[start:end].decode('utf-8')
        else:
          val1.data = str[start:end]
        start = end
        end += 1
        (val1.is_dense,) = _struct_B.unpack(str[start:end])
        val1.is_dense = bool(val1.is_dense)
        self.clusters.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.cluster_images = []
      for i in range(0, length):
        val1 = sensor_msgs.msg.Image()
        _v15 = val1.header
        start = end
        end += 4
        (_v15.seq,) = _struct_I.unpack(str[start:end])
        _v16 = _v15.stamp
        _x = _v16
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _struct_2I.unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v15.frame_id = str[start:end].decode('utf-8')
        else:
          _v15.frame_id = str[start:end]
        _x = val1
        start = end
        end += 8
        (_x.height, _x.width,) = _struct_2I.unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.encoding = str[start:end].decode('utf-8')
        else:
          val1.encoding = str[start:end]
        _x = val1
        start = end
        end += 5
        (_x.is_bigendian, _x.step,) = _struct_BI.unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.data = str[start:end].decode('utf-8')
        else:
          val1.data = str[start:end]
        self.cluster_images.append(val1)
      start = end
      end += 4
      (self.result,) = _struct_i.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_IBI = struct.Struct("<IBI")
_struct_B = struct.Struct("<B")
_struct_7d4f = struct.Struct("<7d4f")
_struct_BI = struct.Struct("<BI")
_struct_i = struct.Struct("<i")
_struct_3I = struct.Struct("<3I")
_struct_B2I = struct.Struct("<B2I")
_struct_2I = struct.Struct("<2I")
_struct_3d = struct.Struct("<3d")
class PlantopSegmentation(object):
  _type          = 'seg_plans_objs/PlantopSegmentation'
  _md5sum = '1200a1dffca987703a9988258c174cc5'
  _request_class  = PlantopSegmentationRequest
  _response_class = PlantopSegmentationResponse