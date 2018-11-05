CC = /usr/bin/clang++
RM = /bin/rm
MAKE = /usr/bin/make
MKDIR = /bin/mkdir
TRASH = &>/dev/null

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


all: GLFW&GLAD $(OBJPATH) $(NAME)

GLFW&GLAD: $(LIBPATH) $(LIBGLFW3) $(LIBGLAD)

$(LIBPATH):
	@echo "\033[37mCreating ./lib directory\033[0m"
	@$(MKDIR) $(LIBPATH)
	@echo "\033[32mOK\033[0m"

$(LIBGLFW3):
	@echo "\033[37mDownloading and extracting glfw3 sources [...]\033[0m"
	@cd $(LIBPATH) && wget https://github.com/glfw/glfw/releases/download/3.2.1/glfw-3.2.1.zip $(TRASH) && unzip glfw-3.2.1.zip $(TRASH)
	@echo "\033[32mOK\033[0m"
	@echo "\033[37minstalling glfw3 [...] (hopefully few seconds)\033[0m"
	@cd $(LIBGLFW3) && Cmake ./ $(TRASH) && make -j8 $(TRASH)
	@echo "\033[32mOK\033[0m"

$(LIBGLAD):
	@$(MKDIR) $(LIBGLAD)
	@echo "\033[37mdownloading and extracting glad sources [...]\033[0m"
	@cd $(LIBPATH) && wget https://glad.dav1d.de/generated/tmp0_frFwglad/glad.zip $(TRASH) && unzip -d $(LIBGLAD) glad.zip $(TRASH)
	@echo "\033[32mOK\033[0m"
	@mv $(LIBGLAD)/src/glad.c $(LIBGLAD)/src/glad.cpp
 
$(OBJPATH):
	@echo "\033[37mCreating ./obj directory and *.obj files [...]\033[0m"
	@$(MKDIR) $@

SRCGLAD = $(LIBGLAD)/src/glad.cpp
OBJGLAD = $(LIBGLAD)/src/glad.opp
SRC = main.cpp\
		init.cpp\
		event.cpp\
		Shader.cpp\
		#Camera.cpp
OBJ = $(patsubst %.cpp, $(OBJPATH)/%.opp, $(SRC)) 

$(NAME): $(OBJGLAD) $(OBJ)
	@echo "\033[32mOK\033[0m"
	@echo "\033[37mBuilding $@ [...]\033[0m"
	@$(CC) -o $(NAME) $(OBJGLAD) $(OBJ) $(FLAGS) $(INCL) $(LIB)
	@echo "\033[36mAll is done!\033[0m"

$(OBJGLAD): $(SRCGLAD) 
	@$(CC) -c $< -o $@ $(FLAGS) $(INCL)

$(OBJPATH)/%.opp: $(SRCPATH)/%.cpp
	@$(CC) -c $< -o $@ $(FLAGS) $(INCL)

clean:
	@echo "\033[37mDeleting ./obj directory\033[0m"
	@$(RM) -rf $(OBJPATH)
	@echo "\033[32mOK\033[0m"

cleanLibs:
	@echo "\033[37mDeleting ./lib directory\033[0m"
	@$(RM) -rf $(LIBPATH)
	@echo "\033[32mOK\033[0m"

fclean : clean cleanLibs
	@echo "\033[37mDeleting HumanGL binary\033[0m"
	@$(RM) -f $(NAME)
	@echo "\033[32mOK\033[0m"

re : fclean all

# little memo
# $@ = rule's name
# $^ = all the rule dependencies
# $< = only the first dependence
# -j 8 => pour que la lib complie en multi thread ;)


# Color for c
#   reset	"\033[0m"
#   RED  	"\033[37m"
#   GRN  	"\033[32m"
#   YEL  	"\033[33m"
#   BLU  	"\033[32m"
#   MAG  	"\033[35m"
#   CYN  	"\033[36m"
#   WHT  	"\033[37m"
