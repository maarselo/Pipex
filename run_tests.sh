#!/bin/bash

#Rutas de archvios
CMD_DIR="tests/cmds"
INFILE_DIR="tests/infile"
EXPECTED_DIR="tests/expected"
OUTPUT_DIR="tests/output"

# Colores
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

mode=$1
if [$mode = "bonus"]; then
	echo -e "${GREEN}Compilando pipex bonus...${NC}"
	make bonus
	pipex="./pipex_bonus"
	path="bonus/"
else
	echo -e "${GREEN}Compilando pipex...${NC}"
	make
	pipex="./pipex"
	path=""
fi

echo
echo -e "${GREEN} 🧪 Ejecutando tests...${NC}"
echo
 
