#Déclaration du projet
project(pokos)

#Déclaration de l'exécutable
add_executable(
	pokos
	src/Card.h
	src/Card.cpp
	src/Environnement.h
	src/Environnement.cpp
	src/main.cpp
)
