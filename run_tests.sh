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
if [ "$mode" = "bonus" ]; then
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

tests=$(ls "$CMD_DIR/$path" | grep -E '^test[0-9]+\.sh$' | sort)

ok=0
fail=0

mkdir -p "$OUTPUT_DIR/$path"

for test_file in $tests; do
	echo "▶️  $test_file"

	bash "$CMD_DIR/$path$test_file"

	output_file="$OUTPUT_DIR/$path${test_file%.sh}.txt"
	expected_file="$EXPECTED_DIR/$path${test_file%.sh}.txt"

	if diff -q "$output_file" "$expected_file"; then
		echo -e "	${GREEN}✅ OK${NC}"
		((ok++))
	else
		echo -e "	${RED}❌ FAIL${NC}"
		echo "	→ Diferencias:"
		diff -u "$expected_file" "$output_file" | sed 's/^/      /'
        ((fail++))
	fi

	echo
done