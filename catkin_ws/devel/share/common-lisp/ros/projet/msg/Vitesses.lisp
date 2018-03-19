; Auto-generated. Do not edit!


(cl:in-package projet-msg)


;//! \htmlinclude Vitesses.msg.html

(cl:defclass <Vitesses> (roslisp-msg-protocol:ros-message)
  ((VitesseDroite
    :reader VitesseDroite
    :initarg :VitesseDroite
    :type cl:float
    :initform 0.0)
   (VitesseGauche
    :reader VitesseGauche
    :initarg :VitesseGauche
    :type cl:float
    :initform 0.0)
   (TestSleep
    :reader TestSleep
    :initarg :TestSleep
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass Vitesses (<Vitesses>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Vitesses>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Vitesses)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name projet-msg:<Vitesses> is deprecated: use projet-msg:Vitesses instead.")))

(cl:ensure-generic-function 'VitesseDroite-val :lambda-list '(m))
(cl:defmethod VitesseDroite-val ((m <Vitesses>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projet-msg:VitesseDroite-val is deprecated.  Use projet-msg:VitesseDroite instead.")
  (VitesseDroite m))

(cl:ensure-generic-function 'VitesseGauche-val :lambda-list '(m))
(cl:defmethod VitesseGauche-val ((m <Vitesses>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projet-msg:VitesseGauche-val is deprecated.  Use projet-msg:VitesseGauche instead.")
  (VitesseGauche m))

(cl:ensure-generic-function 'TestSleep-val :lambda-list '(m))
(cl:defmethod TestSleep-val ((m <Vitesses>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projet-msg:TestSleep-val is deprecated.  Use projet-msg:TestSleep instead.")
  (TestSleep m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Vitesses>) ostream)
  "Serializes a message object of type '<Vitesses>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'VitesseDroite))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'VitesseGauche))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'TestSleep) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Vitesses>) istream)
  "Deserializes a message object of type '<Vitesses>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'VitesseDroite) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'VitesseGauche) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:slot-value msg 'TestSleep) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Vitesses>)))
  "Returns string type for a message object of type '<Vitesses>"
  "projet/Vitesses")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Vitesses)))
  "Returns string type for a message object of type 'Vitesses"
  "projet/Vitesses")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Vitesses>)))
  "Returns md5sum for a message object of type '<Vitesses>"
  "e88f4e7b2b13166de27ee260b4e34fa4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Vitesses)))
  "Returns md5sum for a message object of type 'Vitesses"
  "e88f4e7b2b13166de27ee260b4e34fa4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Vitesses>)))
  "Returns full string definition for message of type '<Vitesses>"
  (cl:format cl:nil "float32 VitesseDroite~%float32 VitesseGauche~%bool    TestSleep~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Vitesses)))
  "Returns full string definition for message of type 'Vitesses"
  (cl:format cl:nil "float32 VitesseDroite~%float32 VitesseGauche~%bool    TestSleep~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Vitesses>))
  (cl:+ 0
     4
     4
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Vitesses>))
  "Converts a ROS message object to a list"
  (cl:list 'Vitesses
    (cl:cons ':VitesseDroite (VitesseDroite msg))
    (cl:cons ':VitesseGauche (VitesseGauche msg))
    (cl:cons ':TestSleep (TestSleep msg))
))
