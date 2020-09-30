#! /usr/bin/env python
# sample.py
from absl import app
from absl import flags

FLAGS = flags.FLAGS

flags.DEFINE_string(
    'foo', 'default value', 'help message of this argument.')
flags.DEFINE_integer(
    'hoge', 1, 'ex) --hoge 10')


def main(argv):
    # print('FLAGS.foo is {}'.format(FLAGS.foo))
  print('hoge is {}'.format(FLAGS.hoge))


if __name__ == '__main__':
  print("============================ started !!")
  app.run(main)
