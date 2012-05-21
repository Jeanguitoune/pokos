#Déclaration du projet
project(pokos)

#Déclaration de l'exécutable
add_executable(
	pokos
	src/Card.h
	src/Card.cpp
	src/Chipstack.h
	src/Chipstack.cpp	
	src/Player.h
	src/Player.cpp
	src/Table.h
	src/Table.cpp
	src/main.cpp
)