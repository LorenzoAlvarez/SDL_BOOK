#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/src/Enemy.o \
	${OBJECTDIR}/src/Game.o \
	${OBJECTDIR}/src/GameObject.o \
	${OBJECTDIR}/src/GameState.o \
	${OBJECTDIR}/src/GameStateMachine.o \
	${OBJECTDIR}/src/InputHandler.o \
	${OBJECTDIR}/src/LoaderParams.o \
	${OBJECTDIR}/src/MenuState.o \
	${OBJECTDIR}/src/PlayState.o \
	${OBJECTDIR}/src/Player.o \
	${OBJECTDIR}/src/SDLGameObject.o \
	${OBJECTDIR}/src/TextureManager.o \
	${OBJECTDIR}/src/Vector2D.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=`pkg-config --libs sdl2` `pkg-config --libs SDL2_image`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sdl_gamecpp11

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sdl_gamecpp11: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sdl_gamecpp11 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_image` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/src/Enemy.o: src/Enemy.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_image` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Enemy.o src/Enemy.cpp

${OBJECTDIR}/src/Game.o: src/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_image` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Game.o src/Game.cpp

${OBJECTDIR}/src/GameObject.o: src/GameObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_image` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GameObject.o src/GameObject.cpp

${OBJECTDIR}/src/GameState.o: src/GameState.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_image` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GameState.o src/GameState.cpp

${OBJECTDIR}/src/GameStateMachine.o: src/GameStateMachine.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_image` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GameStateMachine.o src/GameStateMachine.cpp

${OBJECTDIR}/src/InputHandler.o: src/InputHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_image` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/InputHandler.o src/InputHandler.cpp

${OBJECTDIR}/src/LoaderParams.o: src/LoaderParams.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_image` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/LoaderParams.o src/LoaderParams.cpp

${OBJECTDIR}/src/MenuState.o: src/MenuState.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_image` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/MenuState.o src/MenuState.cpp

${OBJECTDIR}/src/PlayState.o: src/PlayState.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_image` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/PlayState.o src/PlayState.cpp

${OBJECTDIR}/src/Player.o: src/Player.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_image` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Player.o src/Player.cpp

${OBJECTDIR}/src/SDLGameObject.o: src/SDLGameObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_image` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/SDLGameObject.o src/SDLGameObject.cpp

${OBJECTDIR}/src/TextureManager.o: src/TextureManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_image` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TextureManager.o src/TextureManager.cpp

${OBJECTDIR}/src/Vector2D.o: src/Vector2D.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iinclude `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_image` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Vector2D.o src/Vector2D.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sdl_gamecpp11

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
