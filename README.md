<<<<<<< HEAD
# grasp_recognition

## Description
This is the package for robot recognition

### record rosbag
```
roslaunch grasp_recognition rosbag_compressed_record.launch rosbag:=NAME.bag
```
Currently, rosbag files are saved at /home/shumpeiwakabayashi/data/rosbags

***************************************************************************************:::
## xtionカメラでobject detection
### xtionを立ち上げる
```
source /opt/ros/melodic/setup.bas
roslaunch openni2_launch openni2.launch 
```
### Coralの認識ノードを立ち上げる
```
source /opt/ros/melodic/setup.bash
source ~/coral_ws/devel/setup.bash
roslaunch coral_usb edgetpu_object_detector.launch INPUT_IMAGE:=/camera/rgb/image_raw
```

### 結果を表示
```
source /opt/ros/melodic/setup.bash
rosrun image_view2 image_view2 image_view image:=/edgetpu_object_detector/output/image
```

### 学習について
`edgetpu_object_detector.launch`のmodel_fileとlabel_fileを置き換える．
具体的には，dlboxで学習させたラベルと.tfliteを持ってくればよいだろう．

