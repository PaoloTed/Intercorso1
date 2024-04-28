
cc = g++
cflags = -Wall -pedantic -O3 -std=c++20 -fsanitize=address

objects = main.o test.o mytest.o container.o exc1as.o exc1af.o exc1bs.o exc1bf.o exc1asMy.o exc1bsMy.o

libcon = container/container.hpp container/testable.hpp container/traversable.cpp container/traversable.hpp container/mappable.cpp container/mappable.hpp container/dictionary.cpp container/dictionary.hpp container/linear.cpp container/linear.hpp

libexc = $(libcon) zlasdtest/container/container.hpp zlasdtest/container/testable.hpp zlasdtest/container/traversable.hpp zlasdtest/container/mappable.hpp zlasdtest/container/dictionary.hpp zlasdtest/container/linear.hpp
libexcMy = $(libcon) zmytest/container/container.hpp zmytest/container/testable.hpp zmytest/container/traversable.hpp zmytest/container/mappable.hpp zmytest/container/dictionary.hpp zmytest/container/linear.hpp

libexc1a = $(libexc) vector/vector.cpp vector/vector.hpp list/list.cpp list/list.hpp
libexc1aMy = $(libexcMy) vector/vector.cpp vector/vector.hpp list/list.cpp list/list.hpp

libexc1b = $(libexc1a) stack/stack.hpp stack/lst/stacklst.cpp stack/lst/stacklst.hpp stack/vec/stackvec.cpp stack/vec/stackvec.hpp queue/queue.hpp queue/lst/queuelst.cpp queue/lst/queuelst.hpp queue/vec/queuevec.cpp queue/vec/queuevec.hpp

main: $(objects)
	$(cc) $(cflags) $(objects) -o main

clean:
	clear; rm -rfv *.o; rm -fv main

main.o: main.cpp
	$(cc) $(cflags) -c main.cpp

test.o: zlasdtest/test.cpp zlasdtest/test.hpp
	$(cc) $(cflags) -c zlasdtest/test.cpp -o test.o

mytest.o: zmytest/test.cpp zmytest/test.hpp
	$(cc) $(cflags) -c zmytest/test.cpp -o mytest.o

container.o: $(libcon) zlasdtest/container/container.cpp zlasdtest/container/container.hpp
	$(cc) $(cflags) -c zlasdtest/container/container.cpp -o container.o

exc1as.o: $(libexc1a) zlasdtest/exercise1a/simpletest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise1a/simpletest.cpp -o exc1as.o

exc1af.o: $(libexc1a) zlasdtest/exercise1a/fulltest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise1a/fulltest.cpp -o exc1af.o

exc1bs.o: $(libexc1b) zlasdtest/exercise1b/simpletest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise1b/simpletest.cpp -o exc1bs.o

exc1bf.o: $(libexc1b) zlasdtest/exercise1b/fulltest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise1b/fulltest.cpp -o exc1bf.o



exc1asMy.o: $(libexc1a) zmytest/exercise1a/simpletest.cpp
	$(cc) $(cflags) -c zmytest/exercise1a/simpletest.cpp -o exc1asMy.o

exc1bsMy.o: $(libexc1b) zmytest/exercise1b/simpletest.cpp
	$(cc) $(cflags) -c zmytest/exercise1b/simpletest.cpp -o exc1bsMy.o


