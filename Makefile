FIFO_DIR 	 := ./fifo_files
SJF_DIR := ./sjr_files
RR_DIR := ./rr_files

.default: all

all: fifo sjf rr

clean:
	rm -rf copier mtcopier $(FIFO_DIR)/*.o $(SJF_DIR)/*.o *.o $(RR_DIR)/*.o *.o

# copier: $(COPIER_DIR)/main.o $(COPIER_DIR)/reader.o $(COPIER_DIR)/writer.o
# 	g++ -Wall -Werror -std=c++20 -o $@ $^

# mtcopier: $(MTCOPIER_DIR)/main.o $(MTCOPIER_DIR)/reader.o $(MTCOPIER_DIR)/writer.o
# 	g++ -Wall -Werror -std=c++20 -lpthread -o $@ $^

fifo:
	g++ ?

sjf:
	g++ ?

rr:
	g++ ?

# $(COPIER_DIR)/%.o: %.cpp
# 	g++ -Wall -Werror -std=c++20 -c $^

# $(MTCOPIER_DIR)/%.o: %.cpp
# 	g++ -Wall -Werror -std=c++20 -c $^