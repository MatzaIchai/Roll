# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "projet: 2 messages, 0 services")

set(MSG_I_FLAGS "-Iprojet:/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/projet/msg;-Istd_msgs:/opt/cloud9/ros_catkin_ws/src/std_msgs/msg;-Igeometry_msgs:/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/geometry_msgs/msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(projet_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/projet/msg/Vitesses.msg" NAME_WE)
add_custom_target(_projet_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "projet" "/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/projet/msg/Vitesses.msg" ""
)

get_filename_component(_filename "/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/projet/msg/IMU.msg" NAME_WE)
add_custom_target(_projet_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "projet" "/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/projet/msg/IMU.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(projet
  "/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/projet/msg/Vitesses.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/projet
)
_generate_msg_cpp(projet
  "/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/projet/msg/IMU.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/projet
)

### Generating Services

### Generating Module File
_generate_module_cpp(projet
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/projet
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(projet_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(projet_generate_messages projet_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/projet/msg/Vitesses.msg" NAME_WE)
add_dependencies(projet_generate_messages_cpp _projet_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/projet/msg/IMU.msg" NAME_WE)
add_dependencies(projet_generate_messages_cpp _projet_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(projet_gencpp)
add_dependencies(projet_gencpp projet_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS projet_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(projet
  "/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/projet/msg/Vitesses.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/projet
)
_generate_msg_eus(projet
  "/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/projet/msg/IMU.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/projet
)

### Generating Services

### Generating Module File
_generate_module_eus(projet
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/projet
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(projet_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(projet_generate_messages projet_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/projet/msg/Vitesses.msg" NAME_WE)
add_dependencies(projet_generate_messages_eus _projet_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/projet/msg/IMU.msg" NAME_WE)
add_dependencies(projet_generate_messages_eus _projet_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(projet_geneus)
add_dependencies(projet_geneus projet_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS projet_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(projet
  "/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/projet/msg/Vitesses.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/projet
)
_generate_msg_lisp(projet
  "/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/projet/msg/IMU.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/projet
)

### Generating Services

### Generating Module File
_generate_module_lisp(projet
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/projet
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(projet_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(projet_generate_messages projet_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/projet/msg/Vitesses.msg" NAME_WE)
add_dependencies(projet_generate_messages_lisp _projet_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/projet/msg/IMU.msg" NAME_WE)
add_dependencies(projet_generate_messages_lisp _projet_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(projet_genlisp)
add_dependencies(projet_genlisp projet_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS projet_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(projet
  "/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/projet/msg/Vitesses.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/projet
)
_generate_msg_nodejs(projet
  "/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/projet/msg/IMU.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/projet
)

### Generating Services

### Generating Module File
_generate_module_nodejs(projet
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/projet
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(projet_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(projet_generate_messages projet_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/projet/msg/Vitesses.msg" NAME_WE)
add_dependencies(projet_generate_messages_nodejs _projet_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/projet/msg/IMU.msg" NAME_WE)
add_dependencies(projet_generate_messages_nodejs _projet_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(projet_gennodejs)
add_dependencies(projet_gennodejs projet_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS projet_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(projet
  "/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/projet/msg/Vitesses.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/projet
)
_generate_msg_py(projet
  "/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/projet/msg/IMU.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/projet
)

### Generating Services

### Generating Module File
_generate_module_py(projet
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/projet
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(projet_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(projet_generate_messages projet_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/projet/msg/Vitesses.msg" NAME_WE)
add_dependencies(projet_generate_messages_py _projet_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/src/projet/msg/IMU.msg" NAME_WE)
add_dependencies(projet_generate_messages_py _projet_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(projet_genpy)
add_dependencies(projet_genpy projet_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS projet_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/projet)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/projet
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(projet_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(projet_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/projet)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/projet
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(projet_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(projet_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/projet)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/projet
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(projet_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(projet_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/projet)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/projet
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(projet_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(projet_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/projet)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/projet\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/projet
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(projet_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(projet_generate_messages_py geometry_msgs_generate_messages_py)
endif()
