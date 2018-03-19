
(cl:in-package :asdf)

(defsystem "projet-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "IMU" :depends-on ("_package_IMU"))
    (:file "_package_IMU" :depends-on ("_package"))
    (:file "Vitesses" :depends-on ("_package_Vitesses"))
    (:file "_package_Vitesses" :depends-on ("_package"))
  ))