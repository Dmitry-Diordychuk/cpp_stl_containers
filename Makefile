# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/20 14:55:41 by marvin            #+#    #+#              #
#    Updated: 2021/04/20 14:55:41 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := test

CXX := clang++

CXXFLAGS := -Wall -Wextra -Werror
CXXFLAGS += -std=c++98 -pedantic -glldb

BUILD_DIR := ./build
SRC_DIR := ./source

SRCS := main.cpp test_list.cpp test_vector.cpp test_map.cpp test_stack.cpp test_queue.cpp Test.cpp TestMiscellanea.cpp
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

INC_DIR := ./include
INC_FLAGS := $(addprefix -I,$(INC_DIR))

CXXFLAGS += $(INC_FLAGS)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.cpp.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f valgrind-out.txt

re: fclean all

valgrind: re
	valgrind --leak-check=full \
			 --show-leak-kinds=all \
			 --track-origins=yes \
			 --verbose \
			 --log-file=valgrind-out.txt \
			 ./$(NAME)

.PHONY: all clean fclean re
