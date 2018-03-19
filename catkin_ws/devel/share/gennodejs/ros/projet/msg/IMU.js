// Auto-generated. Do not edit!

// (in-package projet.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class IMU {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.YAW = null;
      this.PITCH = null;
      this.ROLL = null;
    }
    else {
      if (initObj.hasOwnProperty('YAW')) {
        this.YAW = initObj.YAW
      }
      else {
        this.YAW = 0.0;
      }
      if (initObj.hasOwnProperty('PITCH')) {
        this.PITCH = initObj.PITCH
      }
      else {
        this.PITCH = 0.0;
      }
      if (initObj.hasOwnProperty('ROLL')) {
        this.ROLL = initObj.ROLL
      }
      else {
        this.ROLL = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type IMU
    // Serialize message field [YAW]
    bufferOffset = _serializer.float32(obj.YAW, buffer, bufferOffset);
    // Serialize message field [PITCH]
    bufferOffset = _serializer.float32(obj.PITCH, buffer, bufferOffset);
    // Serialize message field [ROLL]
    bufferOffset = _serializer.float32(obj.ROLL, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type IMU
    let len;
    let data = new IMU(null);
    // Deserialize message field [YAW]
    data.YAW = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [PITCH]
    data.PITCH = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [ROLL]
    data.ROLL = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'projet/IMU';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'f112f250a60522c693be80ef8484ac2c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 YAW
    float32 PITCH
    float32 ROLL
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new IMU(null);
    if (msg.YAW !== undefined) {
      resolved.YAW = msg.YAW;
    }
    else {
      resolved.YAW = 0.0
    }

    if (msg.PITCH !== undefined) {
      resolved.PITCH = msg.PITCH;
    }
    else {
      resolved.PITCH = 0.0
    }

    if (msg.ROLL !== undefined) {
      resolved.ROLL = msg.ROLL;
    }
    else {
      resolved.ROLL = 0.0
    }

    return resolved;
    }
};

module.exports = IMU;
