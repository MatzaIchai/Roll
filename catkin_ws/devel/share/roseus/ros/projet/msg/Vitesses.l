;; Auto-generated. Do not edit!


(when (boundp 'projet::Vitesses)
  (if (not (find-package "PROJET"))
    (make-package "PROJET"))
  (shadow 'Vitesses (find-package "PROJET")))
(unless (find-package "PROJET::VITESSES")
  (make-package "PROJET::VITESSES"))

(in-package "ROS")
;;//! \htmlinclude Vitesses.msg.html


(defclass projet::Vitesses
  :super ros::object
  :slots (_VitesseDroite _VitesseGauche _TestSleep ))

(defmethod projet::Vitesses
  (:init
   (&key
    ((:VitesseDroite __VitesseDroite) 0.0)
    ((:VitesseGauche __VitesseGauche) 0.0)
    ((:TestSleep __TestSleep) nil)
    )
   (send-super :init)
   (setq _VitesseDroite (float __VitesseDroite))
   (setq _VitesseGauche (float __VitesseGauche))
   (setq _TestSleep __TestSleep)
   self)
  (:VitesseDroite
   (&optional __VitesseDroite)
   (if __VitesseDroite (setq _VitesseDroite __VitesseDroite)) _VitesseDroite)
  (:VitesseGauche
   (&optional __VitesseGauche)
   (if __VitesseGauche (setq _VitesseGauche __VitesseGauche)) _VitesseGauche)
  (:TestSleep
   (&optional __TestSleep)
   (if __TestSleep (setq _TestSleep __TestSleep)) _TestSleep)
  (:serialization-length
   ()
   (+
    ;; float32 _VitesseDroite
    4
    ;; float32 _VitesseGauche
    4
    ;; bool _TestSleep
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _VitesseDroite
       (sys::poke _VitesseDroite (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _VitesseGauche
       (sys::poke _VitesseGauche (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; bool _TestSleep
       (if _TestSleep (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _VitesseDroite
     (setq _VitesseDroite (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _VitesseGauche
     (setq _VitesseGauche (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; bool _TestSleep
     (setq _TestSleep (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get projet::Vitesses :md5sum-) "e88f4e7b2b13166de27ee260b4e34fa4")
(setf (get projet::Vitesses :datatype-) "projet/Vitesses")
(setf (get projet::Vitesses :definition-)
      "float32 VitesseDroite
float32 VitesseGauche
bool    TestSleep


")



(provide :projet/Vitesses "e88f4e7b2b13166de27ee260b4e34fa4")


