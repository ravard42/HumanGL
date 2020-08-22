# NOTE CONCERNANT LES REPETITIONS DES '#'
# À Travers un exemple :
#	ici on a 4 rubriques --> #### [0] pour la rubrique 0 de l'intro/défintions/axiomes ( >####< indique le nombre de rubrique total avec inclusion du 0)
				# 1] pour la rubrique 1
				#
				## 2] pour la rubrique 2
				##
				### 3]  pour la rubrique 3
				###

																					
#### [0] Définitions & Construction:

CC = /usr/bin/g++
RM = /bin/rm
MAKE = /usr/bin/make
MKDIR = /bin/mkdir
TRASH = > /dev/null 2>&1

NAME = HumanGL 

ROOT = 		$(shell /bin/pwd)
SRCPATH = 	$(ROOT)/src
SRCMATHPATH = $(ROOT)/src/mathStuff
OBJPATH = 	$(ROOT)/obj
OBJMATHPATH = $(ROOT)/obj/mathStuff
INCLPATH = 	$(ROOT)/include
INCLMATHPATH = $(ROOT)/include/mathStuff
LIBPATH =	$(ROOT)/lib

LIBGLFW3 =  $(LIBPATH)/glfw-3.2.1
LIBGLAD =  $(LIBPATH)/glad

DLGLFW3 = https://github.com/glfw/glfw/releases/download/3.2.1/glfw-3.2.1.zip
# DLGLAD link need to be refresh regularly
# 1] go to the webservice https://glad.dav1d.de/
# 2] set API_gl : 4.1 and Profile : Core
# 3] click on Generate
# 4] right click on glad.zip + copy link address
# 5] refresh DLGLAD with it
DLGLAD = https://glad.dav1d.de/generated/tmpOf7MIAglad/glad.zip


FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
#FLAGS = -Wall -Wextra -Werror
INCL = -I $(LIBGLFW3)/include/GLFW -I $(LIBGLAD)/include -I $(INCLPATH) -I $(INCLMATHPATH)
LIB = -L $(LIBGLFW3)/src -lglfw3 -lX11 -lpthread -lXrandr -ldl -lXxf86vm -lXinerama -lXcursor
#LIB = -L $(LIBGLFW3)/src -lglfw3 -framework AppKit -framework IOKit -framework CoreVideo


Construction: GLFW&GLAD $(OBJPATH) $(OBJMATHPATH) $(NAME)
####



# 1] Récupération, configuration et construction des librairies

GLFW&GLAD: $(LIBPATH) $(LIBGLFW3) $(LIBGLAD)

$(LIBPATH):
	@echo -e "\033[37mCreating ./lib directory\033[0m"
	@$(MKDIR) $(LIBPATH)
	@echo -e "\033[32mOK\033[0m"

$(LIBGLFW3):
	@echo -e "\033[37mDownloading and extracting glfw3 sources [...]\033[0m"
	@cd $(LIBPATH) && wget $(DLGLFW3) $(TRASH) && unzip glfw-3.2.1.zip $(TRASH)
	@echo -e "\033[32mOK\033[0m"
	@echo -e "\033[37minstalling glfw3 [...] (hopefully few seconds)\033[0m"
	@cd $(LIBGLFW3) && cmake ./ $(TRASH) && make -j8 $(TRASH)
	#@cd $(LIBGLFW3) && Cmake ./ $(TRASH) && make -j8 $(TRASH)
	@echo -e "\033[32mOK\033[0m"

$(LIBGLAD):
	@$(MKDIR) $(LIBGLAD)
	@echo -e "\033[37mdownloading and extracting glad sources [...]\033[0m"
	@cd $(LIBPATH) && wget $(DLGLAD) $(TRASH) && unzip -d $(LIBGLAD) glad.zip $(TRASH)
	@echo -e "\033[32mOK\033[0m"
	@mv $(LIBGLAD)/src/glad.c $(LIBGLAD)/src/glad.cpp
#


## 2] Compilation des sources en briques .obj suivi de la  compilation du binaire/executable

$(OBJPATH):
	@echo -e "\033[37mCreating ./obj directory and *.obj files [...]\033[0m"
	@$(MKDIR) $@

$(OBJMATHPATH):
	@echo -e "\033[37mCreating ./obj/mathStuff directory and mathStuff/*.obj [...]\033[0m"
	@$(MKDIR) $@

## 2.a]
SRCGLAD = $(LIBGLAD)/src/glad.cpp
OBJGLAD = $(LIBGLAD)/src/glad.opp
$(OBJGLAD): $(SRCGLAD) 
	@$(CC) -c $< -o $@ $(FLAGS) $(INCL)

## 2.b]
SRCMATH = Vec2.cpp\
					Vec3.cpp\
					Vec4.cpp\
					Mat3.cpp\
					Mat4.cpp
OBJMATH = $(patsubst %.cpp, $(OBJMATHPATH)/%.opp, $(SRCMATH))
$(OBJMATHPATH)/%.opp: $(SRCMATHPATH)/%.cpp 
	@$(CC) -c $< -o $@ $(FLAGS) $(INCL)

## 2.c]
SRC = main.cpp\
		init.cpp\
		event.cpp\
		Shader.cpp\
		Camera.cpp\
		Square.cpp\
		Cube.cpp\
		CubeTree.cpp\
		Human.cpp\

OBJ = $(patsubst %.cpp, $(OBJPATH)/%.opp, $(SRC)) 
$(OBJPATH)/%.opp: $(SRCPATH)/%.cpp
	@$(CC) -c $< -o $@ $(FLAGS) $(INCL)

## 2.d]
$(NAME): $(OBJGLAD) $(OBJ) $(OBJMATH)
	@echo -e "\033[32mOK\033[0m"
	@echo -e "\033[37mBuilding $@ [...]\033[0m"
	@$(CC) -o $(NAME) $(OBJGLAD) $(OBJMATH) $(OBJ) $(FLAGS) $(INCL) $(LIB)
	@echo -e "\033[36mConstruction OKKK!\033[0m"

##

### 3] Un peu de rangement

clean:
	@echo -e "\033[37mDeleting ./obj directory\033[0m"
	@$(RM) -rf $(OBJPATH)
	@echo -e "\033[32mOK\033[0m"

cleanLibs:
	@echo -e "\033[37mDeleting ./lib directory\033[0m"
	@$(RM) -rf $(LIBPATH)
	@echo -e "\033[32mOK\033[0m"

fclean: clean cleanLibs
	@echo -e "\033[37mDeleting HumanGL binary\033[0m"
	@$(RM) -f $(NAME)
	@echo -e "\033[32mOK\033[0m"

re: fclean Construction
###


# little memo
# $@ = rule's name
# $^ = all the rule dependencies
# $< = only the first dependence
# -j$(sysctl -n hw.physicalcpu)  => pour que la lib complie en multi thread ;)

# Color for c
#   reset	"\033[0m"
#   RED  	"\033[31m"
#   GRN  	"\033[32m"
#   YEL  	"\033[33m"
#   BLU  	"\033[34m"
#   MAG  	"\033[35m"
#   CYN  	"\033[36m"
#   WHT  	"\033[37m"
