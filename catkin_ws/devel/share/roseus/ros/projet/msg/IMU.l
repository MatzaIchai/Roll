;; Auto-generated. Do not edit!


(when (boundp 'projet::IMU)
  (if (not (find-package "PROJET"))
    (make-package "PROJET"))
  (shadow 'IMU (find-package "PROJET")))
(unless (find-package "PROJET::IMU")
  (make-package "PROJET::IMU"))

(in-package "ROS")
;;//! \htmlinclude IMU.msg.html


(defclass projet::IMU
  :super ros::object
  :slots (_YAW _PITCH _ROLL ))

(defmethod projet::IMU
  (:init
   (&key
    ((:YAW __YAW) 0.0)
    ((:PITCH __PITCH) 0.0)
    ((:ROLL __ROLL) 0.0)
    )
   (send-super :init)
   (setq _YAW (float __YAW))
   (setq _PITCH (float __PITCH))
   (setq _ROLL (float __ROLL))
   self)
  (:YAW
   (&optional __YAW)
   (if __YAW (setq _YAW __YAW)) _YAW)
  (:PITCH
   (&optional __PITCH)
   (if __PITCH (setq _PITCH __PITCH)) _PITCH)
  (:ROLL
   (&optional __ROLL)
   (if __ROLL (setq _ROLL __ROLL)) _ROLL)
  (:serialization-length
   ()
   (+
    ;; float32 _YAW
    4
    ;; float32 _PITCH
    4
    ;; float32 _ROLL
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _YAW
       (sys::poke _YAW (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _PITCH
       (sys::poke _PITCH (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _ROLL
       (sys::poke _ROLL (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _YAW
     (setq _YAW (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _PITCH
     (setq _PITCH (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _ROLL
     (setq _ROLL (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get projet::IMU :md5sum-) "f112f250a60522c693be80ef8484ac2c")
(setf (get projet::IMU :datatype-) "projet/IMU")
(setf (get projet::IMU :definition-)
      "float32 YAW
float32 PITCH
float32 ROLL

")



(provide :projet/IMU "f112f250a60522c693be80ef8484ac2c")


