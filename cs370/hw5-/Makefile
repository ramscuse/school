JFLAGS = -g
JC = javac
.SUFFIXES: .java .class

.java.class:
		$(JC) $(JFLAGS) $*.java

CLASSES = Coordinator.java Buffer.java Producer.java Consumer.java

default: classes

classes: $(CLASSES:.java=.class)

package: 
		tar -cvzf HW5.tar *.java *.txt Makefile

clean:
		$(RM) *.class