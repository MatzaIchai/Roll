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

class Vitesses {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.VitesseDroite = null;
      this.VitesseGauche = null;
      this.TestSleep = null;
    }
    else {
      if (initObj.hasOwnProperty('VitesseDroite')) {
        this.VitesseDroite = initObj.VitesseDroite
      }
      else {
        this.VitesseDroite = 0.0;
      }
      if (initObj.hasOwnProperty('VitesseGauche')) {
        this.VitesseGauche = initObj.VitesseGauche
      }
      else {
        this.VitesseGauche = 0.0;
      }
      if (initObj.hasOwnProperty('TestSleep')) {
        this.TestSleep = initObj.TestSleep
      }
      else {
        this.TestSleep = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Vitesses
    // Serialize message field [VitesseDroite]
    bufferOffset = _serializer.float32(obj.VitesseDroite, buffer, bufferOffset);
    // Serialize message field [VitesseGauche]
    bufferOffset = _serializer.float32(obj.VitesseGauche, buffer, bufferOffset);
    // Serialize message field [TestSleep]
    bufferOffset = _serializer.bool(obj.TestSleep, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Vitesses
    let len;
    let data = new Vitesses(null);
    // Deserialize message field [VitesseDroite]
    data.VitesseDroite = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [VitesseGauche]
    data.VitesseGauche = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [TestSleep]
    data.TestSleep = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 9;
  }

  static datatype() {
    // Returns string type for a message object
    return 'projet/Vitesses';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e88f4e7b2b13166de27ee260b4e34fa4';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 VitesseDroite
    float32 VitesseGauche
    bool    TestSleep
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Vitesses(null);
    if (msg.VitesseDroite !== undefined) {
      resolved.VitesseDroite = msg.VitesseDroite;
    }
    else {
      resolved.VitesseDroite = 0.0
    }

    if (msg.VitesseGauche !== undefined) {
      resolved.VitesseGauche = msg.VitesseGauche;
    }
    else {
      resolved.VitesseGauche = 0.0
    }

    if (msg.TestSleep !== undefined) {
      resolved.TestSleep = msg.TestSleep;
    }
    else {
      resolved.TestSleep = false
    }

    return resolved;
    }
};

module.exports = Vitesses;
