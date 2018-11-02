CC = /usr/bin/clang++
RM = /bin/rm
MAKE = /usr/bin/make
MKDIR = /bin/mkdir

NAME = HumanGL 

ROOT = 		$(shell /bin/pwd)
SRCPATH = 	$(ROOT)/src
OBJPATH = 	$(ROOT)/obj
INCLPATH = 	$(ROOT)/include
LIBPATH =	$(ROOT)/lib

FLAGS = -Wall -Wextra -Werror
INCL = -I lib/glfw-3.2.1/include/GLFW -I lib/glad/include/KHR -I lib/glad/include/glad -I $(INCLPATH)
LIB = -L $(LIBPATH)/glfw-3.2.1/src -lglfw3 -framework AppKit -framework IOKit -framework CoreVideo

GLADSRC = $(LIBPATH)/glad/src/glad.cpp\
SRC = glad.cpp\
		main.cpp\
		init.cpp\
		#event.cpp\
		#Shader.cpp\
		#Camera.cpp\

OBJ = $(patsubst %.cpp, $(OBJPATH)/%.opp, $(SRC))


all: GLFW&GLAD $(OBJPATH) $(NAME)

GLFW&GLAD:
	@echo "Creating lib Dir"
	@$(MKDIR) $(LIBPATH)
 
	@echo "downloading and extracting glfw3 sources [...]"
	@cd $(LIBPATH) && wget https://github.com/glfw/glfw/releases/download/3.2.1/glfw-3.2.1.zip && unzip glfw-3.2.1.zip && rm glfw-3.2.1.zip
	@echo "installing glfw3 [...]"
	@cd $(LIBPATH)/glfw-3.2.1 && Cmake ./ && make -j8
	@echo "done!"

	@echo "Creating glad directory"
	@$(MKDIR) $(LIBPATH)/glad
	@echo "downloading and extracting glad sources [...]"
	@cd $(LIBPATH)/glad && wget https://glad.dav1d.de/generated/tmpT1teK5glad/glad.zip && unzip glad.zip && rm glad.zip
	@echo "done!"
	echo "mouving glad.cpp in src folder"
	@mv $(LIBPATH)/glad/src/glad.c src/glad.cpp
	

 
$(OBJPATH):
	@echo "Creating OBJ directory"
	@$(MKDIR) $@

$(NAME): $(OBJ)
	@echo "Creating OBJ files"
	@echo "Building $@"
	@$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(INCL) $(LIB)
	@echo "\033[36mAll is done!\033[0m"

$(OBJPATH)/%.opp: $(SRCPATH)/%.cpp
	@$(CC) -c $< -o $@ $(FLAGS) $(INCL)

clean:
	@echo "Deleting OBJ files"
	@$(RM) -rf $(OBJPATH)

cleanLibs:
	@echo "Deleting libs"
	@$(RM) -rf $(LIBPATH)

fclean : clean cleanLibs
	@echo "Deleting HumanGL binary"
	@$(RM) -f $(NAME)

re : fclean all

# little memo
# $@ = rule's name
# $^ = all the rule dependecies
# $< = only the first dependence
# -j 8 => pour que la lib complie en multi thread ;)


# Color for c
#   reset	"\033[0m"
#   RED  	"\033[31m"
#   GRN  	"\033[32m"
#   YEL  	"\033[33m"
#   BLU  	"\033[34m"
#   MAG  	"\033[35m"
#   CYN  	"\033[36m"
#   WHT  	"\033[37m"

#assimp:
#	@echo "\033[35mdownloading assimp [...]\033[0m"
#	@wget https://github.com/assimp/assimp/archive/v4.1.0.tar.gz -O ./lib/assimp.tar.gz
#	@echo "\033[37mdone\033[0m"
#	@echo "\033[35mdecompressing and installing assimp [...]\033[0m"
#	@cd lib && tar xzf assimp.tar.gz && rm assimp.tar.gz && cd assimp-4.1.0 && cmake ./ && make
#	@echo "\033[37mdone\033[0m"
