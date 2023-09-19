FIFO := fifo
SJF := sjf
RR := rr

FIFO_DIR 	 := ./$(FIFO)_files
SJF_DIR := ./$(SJF)_files
RR_DIR := ./$(RR)_files

.default: all
all: fifo sjf rr

clean:
	rm -rf $(FIFO) $(SJF) $(RR) $(FIFO_DIR)/*o $(SJF_DIR)/*o $(RR_DIR)/*o *.o

fifo: $(FIFO_DIR)/$(FIFO).o loader.o simulator.o pcb.o
	g++ -Wall -Werror -std=c++20 -o $@ $^

sjf: $(SJF_DIR)/$(SJF).o loader.o simulator.o pcb.o
	g++ -Wall -Werror -std=c++20 -o $@ $^

rr: $(RR_DIR)/$(RR).o loader.o simulator.o pcb.o
	g++ -Wall -Werror -std=c++20 -o $@ $^

$(FIFO_DIR)/%.o: %.cpp
	g++ -Wall -Werror -std=c++20 -c $^

$(SJF_DIR)/%.o: %.cpp
	g++ -Wall -Werror -std=c++20 -c $^

$(RR_DIR)/%.o: %.cpp
	g++ -Wall -Werror -std=c++20 -c $^