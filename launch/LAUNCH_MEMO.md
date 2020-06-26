# memo

### env.launch
- 一番基本の環境
- INPUTを/camera/depth_registered/decompress/pointsにするか，/camera/depth_registered/pointsにするか
- tabletop_object_detector.launchをssd用に書き換えていきたい．


### env_bag.launch
- env.launchを修正
- 2d food coords to 3d coordsを理解していない．


## xtion_test
- xtion関係のlaunch

### depth2pcl.launch
- depthをpoint cloudに変換
- image_transport パッケージを用いてdecompressしている．詳細は，[wiki](https://github.com/shmpwk/grasp_recognition/wiki/%E3%82%AB%E3%83%A1%E3%83%A9%E7%94%BB%E5%83%8F%E3%81%AE%E5%9C%A7%E7%B8%AE%E3%81%AB%E3%81%A4%E3%81%84%E3%81%A6)



