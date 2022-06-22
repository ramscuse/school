README - DO NOT TURN IN, USE CANVAS README QUIZ TO ANSWER QUESTIONS!
======

This package includes the following files.

|-- Coordinator.java [This is the driver program which will be used to create an instance of the Circular buffer, and create and wait for one thread of producer and one or more threads of and consumer.] (Skeleton Code provided)
|-- Producer.java [Each instance of a producer generates a single number between 0 and 99 (both inclusive) randomly and inserts into the buffer, and reports the location and the time the number was inserted into the buffer] (Skeleton Code provided)
|-- Consumer.java [Each instance of a consumer reads a number from the buffer and reports the location and the time the number was read from the buffer.]
|-- Buffer.java [Creates a circular buffer whose size is passed as an argument to it.]
|-- Makefile [For compiling, and cleaning]
|-- README.txt [This file]


NOTE:

Lab systems by default use Java 11 which supports nanosecond timestamp. If after logging in and running 'java -version', it doesn't output version 11, use the following two commands:

	$ export PATH=/usr/lib/jvm/jre-11-openjdk/bin/:$PATH

	$ export LD_LIBRARY_PATH=/usr/lib/jvm/jre-11-openjdk/lib/:$LD_LIBRARY_PATH

