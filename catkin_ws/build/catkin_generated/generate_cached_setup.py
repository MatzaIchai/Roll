# -*- coding: utf-8 -*-
from __future__ import print_function
import argparse
import os
import stat
import sys

# find the import for catkin's python package - either from source space or from an installed underlay
if os.path.exists(os.path.join('/opt/cloud9/ros_catkin_ws/src/catkin/cmake', 'catkinConfig.cmake.in')):
    sys.path.insert(0, os.path.join('/opt/cloud9/ros_catkin_ws/src/catkin/cmake', '..', 'python'))
try:
    from catkin.environment_cache import generate_environment_script
except ImportError:
    # search for catkin package in all workspaces and prepend to path
    for workspace in "/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/devel;/opt/cloud9/ros_catkin_ws/devel;/opt/cloud9/ros_catkin_ws/devel_isolated/ros;/opt/cloud9/ros_catkin_ws/devel_isolated/mk;/opt/cloud9/ros_catkin_ws/devel_isolated/message_runtime;/opt/cloud9/ros_catkin_ws/devel_isolated/message_generation;/opt/cloud9/ros_catkin_ws/devel_isolated/cpp_common;/opt/cloud9/ros_catkin_ws/devel_isolated/cmake_modules;/opt/cloud9/ros_catkin_ws/devel_isolated/genpy;/opt/cloud9/ros_catkin_ws/devel_isolated/gennodejs;/opt/cloud9/ros_catkin_ws/devel_isolated/genlisp;/opt/cloud9/ros_catkin_ws/devel_isolated/geneus;/opt/cloud9/ros_catkin_ws/devel_isolated/gencpp;/opt/cloud9/ros_catkin_ws/devel_isolated/genmsg;/opt/cloud9/ros_catkin_ws/devel_isolated/catkin".split(';'):
        python_path = os.path.join(workspace, 'lib/python2.7/dist-packages')
        if os.path.isdir(os.path.join(python_path, 'catkin')):
            sys.path.insert(0, python_path)
            break
    from catkin.environment_cache import generate_environment_script

code = generate_environment_script('/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/devel/env.sh')

output_filename = '/var/lib/cloud9/Robotics_Cape_Installer/catkin_ws/build/catkin_generated/setup_cached.sh'
with open(output_filename, 'w') as f:
    #print('Generate script for cached setup "%s"' % output_filename)
    f.write('\n'.join(code))

mode = os.stat(output_filename).st_mode
os.chmod(output_filename, mode | stat.S_IXUSR)
