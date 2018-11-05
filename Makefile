CC = /usr/bin/clang++
RM = /bin/rm
MAKE = /usr/bin/make
MKDIR = /bin/mkdir

TRASH = &> /dev/null
#https://medium.freecodecamp.org/sh-silence-your-bash-scripts-by-coding-your-own-silent-flag-c7e9f8b668a4

NAME = HumanGL 

ROOT = 		$(shell /bin/pwd)
SRCPATH = 	$(ROOT)/src
OBJPATH = 	$(ROOT)/obj
INCLPATH = 	$(ROOT)/include
LIBPATH =	$(ROOT)/lib
LIBGLFW3 =  $(LIBPATH)/glfw-3.2.1
LIBGLAD =  $(LIBPATH)/glad

FLAGS = -Wall -Wextra -Werror
INCL = -I $(LIBGLFW3)/include/GLFW -I $(LIBGLAD)/include -I $(INCLPATH)
LIB = -L $(LIBGLFW3)/src -lglfw3 -framework AppKit -framework IOKit -framework CoreVideo

SRC = glad.cpp\
		main.cpp\
		init.cpp\
		event.cpp\
		Shader.cpp\
		#Camera.cpp\

OBJ = $(patsubst %.cpp, $(OBJPATH)/%.opp, $(SRC))


all: GLFW&GLAD $(OBJPATH) $(NAME)

$(LIBPATH):
	@echo "\033[31mCreating lib Dir\033[0m"
	@$(MKDIR) $(LIBPATH)
	@echo "\033[34mdone!\033[0m"

$(LIBGLFW3):
	@echo "\033[31mDownloading and unziping glfw3 sources [...]\033[0m"
	@cd $(LIBPATH) && wget https://github.com/glfw/glfw/releases/download/3.2.1/glfw-3.2.1.zip $(TRASH) && unzip glfw-3.2.1.zip $(TRASH)
	@echo "\033[34mdone!\033[0m"
	@echo "installing glfw3 [...]"
	@cd $(LIBGLFW3) && Cmake ./ $(TRASH) && make -j8 $(TRASH)
	@echo "\033[34mdone!\033[0m"

$(LIBGLAD):
	@echo "\033[31mCreating glad directory\033[0m"
	@$(MKDIR) $(LIBGLAD)
	@echo "\033[34mdone!\033[0m"
	@echo "\033[31mdownloading and extracting glad sources [...]\033[0m"
	@cd $(LIBGLAD) && wget https://glad.dav1d.de/generated/tmp0_frFwglad/glad.zip $(TRASH) && unzip glad.zip $(TRASH)
	@echo "\033[34mdone!\033[0m"
	@echo "mouving glad.cpp in src folder"
	@mv $(LIBGLAD)/src/glad.c src/glad.cpp


GLFW&GLAD: $(LIBPATH) $(LIBGLFW3) $(LIBGLAD)
	@echo "\033[33mAll libs installed\033[0m"

	

 
$(OBJPATH):
	@echo "\033[33mCreating OBJ directory\033[0m"
	@$(MKDIR) $@

$(NAME): $(OBJ)
	@echo "\033[33mCreating OBJ files\033[0m"
	@echo "Building $@"
	@$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(INCL) $(LIB)
	@echo "\033[36mAll is done!\033[0m"

$(OBJPATH)/%.opp: $(SRCPATH)/%.cpp
	@$(CC) -c $< -o $@ $(FLAGS) $(INCL)

clean:
	@echo "\033[31mDeleting OBJ files\033[0m"
	@$(RM) -rf $(OBJPATH)
	@echo "\033[34mdone!\033[0m"

cleanLibs:
	@echo "\033[31mDeleting libs\033[0m"
	@$(RM) -rf $(LIBPATH)
	@echo "\033[34mdone!\033[0m"

fclean : clean cleanLibs
	@echo "\033[31mDeleting HumanGL binary\033[0m"
	@$(RM) -f $(NAME)
	@echo "\033[34mdone!\033[0m"

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
