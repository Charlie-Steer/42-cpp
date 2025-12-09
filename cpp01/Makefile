NAME = phonebook

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

BUILD = build
RM = rm -rf

SRCS = \
	main.cpp

OBJS = $(SRCS:%.cpp=$(BUILD)/%.o)

default: all

$(BUILD)/%.o: %.cpp
	@mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

info:
	@echo "INFO:"
	@echo NAME = $(NAME)
	@echo CXX = $(CXX)
	@echo CXXFLAGS = $(CXXFLAGS)
	@echo

dev: CXXFLAGS := $(filter-out -Werror,$(CXXFLAGS))
dev: all

clean:
	@$(RM) $(BUILD)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: default all dev re info bonus clean fclean
