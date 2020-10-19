#include "ros/ros.h"
#include "grasp_recognition/adder.h"

// Subscribeする対象のトピックが更新されたら呼び出されるコールバック関数
// 引数にはトピックにPublishされるメッセージの型と同じ型を定義する
void chatterCallback(const grasp_recognition::adder msg)
{
    int result;
    result = msg.a + msg.b;
    printf("a:%d + b:%d = %d\n",msg.a , msg.b, result );
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "adder");
  ros::NodeHandle n;

  // Subscriberとしてpara_inputというトピックがSubscribeし、トピックが更新されたときは
  // chatterCallbackという名前のコールバック関数を実行する
  ros::Subscriber sub = n.subscribe("para_input", 1000, chatterCallback);

  // トピック更新の待ちうけを行うAPI
  ros::spin();

  return 0;
}
