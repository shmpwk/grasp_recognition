
# grasp_recognition

## Description
This is the package for robot recognition, s.t. grasping.

### record rosbag
```
roslaunch grasp_recognition rosbag_compressed_record.launch rosbag:=NAME.bag compress:=true
```
Currently, rosbag files are saved at /home/shumpeiwakabayashi/data/rosbags

### play rosbag
```
$ roslaunch grasp_recognition env.launch 
$ roslaunch grasp_recognition depth2pcl.launch 
$ rosbag play 202006270105.bag -l
```

### object detection
First, connect coral edge TPU.
```
$ roslaunch grasp_recognition env_bag.launch
$ roslaunch grasp_recognition depth2pcl.launch
$ roslaunch coral_usb edgetpu_obj_detector.launch INPUT_IMAGE:=/camera/rgb/image_raw
$ cd ~/data/rosbags
$ rosbag play 202006291015.bag -l
($  rosrun image_view image_view image:=/edgetpu_object_detector/output/image)
```
![Screenshot from 2020-06-29 10-56-32](https://user-images.githubusercontent.com/42209144/85966065-ac7ba100-b9f9-11ea-87ba-0691ccb81511.png)

### pose estimation

*************************************************************************************************
## xtionカメラでobject detection
### xtionを立ち上げる
```
source /opt/ros/melodic/setup.bash
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

### data collection server
See [here](https://jsk-common.readthedocs.io/en/latest/jsk_data/node_scripts/data_collection_server.html)
```
roslaunch grasp_recognition data_collection_server_test.launch
rosservice call /data_collection/save_request "{}"
```

### convert_to_gif.sh
shell script to convert video into gif file
```
./convert_to_gif.sh video.mp4
```
