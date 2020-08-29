#!/usr/bin/env python
# -*- coding: utf-8 -*-

import rospy
import math
import numpy as np
from sensor_msgs.msg import Image

def depthcallback(msg):
    depths = np.zeros((10))
    for i in range(10):
        print(msg.data[i])
    print(depths)    


rospy.init_node('depth_cd')
rospy.Subscriber('/camera/depth/image_rect', Image, depthcallback)
#pub = rospy.Publisher('/depth_cd', )
rospy.spin()
