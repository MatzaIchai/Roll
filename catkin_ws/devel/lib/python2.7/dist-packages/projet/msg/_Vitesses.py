# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from projet/Vitesses.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class Vitesses(genpy.Message):
  _md5sum = "e88f4e7b2b13166de27ee260b4e34fa4"
  _type = "projet/Vitesses"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """float32 VitesseDroite
float32 VitesseGauche
bool    TestSleep

"""
  __slots__ = ['VitesseDroite','VitesseGauche','TestSleep']
  _slot_types = ['float32','float32','bool']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       VitesseDroite,VitesseGauche,TestSleep

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(Vitesses, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.VitesseDroite is None:
        self.VitesseDroite = 0.
      if self.VitesseGauche is None:
        self.VitesseGauche = 0.
      if self.TestSleep is None:
        self.TestSleep = False
    else:
      self.VitesseDroite = 0.
      self.VitesseGauche = 0.
      self.TestSleep = False

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
      buff.write(_get_struct_2fB().pack(_x.VitesseDroite, _x.VitesseGauche, _x.TestSleep))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 9
      (_x.VitesseDroite, _x.VitesseGauche, _x.TestSleep,) = _get_struct_2fB().unpack(str[start:end])
      self.TestSleep = bool(self.TestSleep)
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
      buff.write(_get_struct_2fB().pack(_x.VitesseDroite, _x.VitesseGauche, _x.TestSleep))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 9
      (_x.VitesseDroite, _x.VitesseGauche, _x.TestSleep,) = _get_struct_2fB().unpack(str[start:end])
      self.TestSleep = bool(self.TestSleep)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_2fB = None
def _get_struct_2fB():
    global _struct_2fB
    if _struct_2fB is None:
        _struct_2fB = struct.Struct("<2fB")
    return _struct_2fB
