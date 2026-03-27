SRC = src
BUILD = build
BIN = bin
TEST = test

defaut : $(BIN)/test


help :
	@echo "Cible disponible :"
	@echo "	 - messStacker : génère le programme final (défaut)"
	@echo "	 - clean : nettoyage des .o"
	@echo "	 - help : affichage de l'aide"

#alias pour simplifier l'accès à la cible util_string.o
#lib_util : $(LIB_DIR)/util_string.o


# compilation de la librairie messStacker
$(BUILD)/messStacker.o : $(SRC)/messStacker.c
	@echo "### compilation .o de messStacker"
	gcc -c -Wall $(SRC)/messStacker.c -o $(BUILD)/messStacker.o

# compilation intérmédiaire de test
$(BUILD)/test.o : $(TEST)/test.c
	@echo "### compilation .o de test"
	gcc -c -Wall $(TEST)/test.c -o $(BUILD)/test.o

# génération de l'exécutable test
$(BIN)/test : $(BUILD)/test.o $(BUILD)/messStacker.o
	@echo "=== compilation finale de test"
	gcc -Wall $(BUILD)/test.o $(BUILD)/messStacker.o -o $(BIN)/test

# nettoyage du projet
clean :
	@echo "... suppression de tous les .o ..."
	rm -r *.o



#run : $(BIN)/messStacker
#	@$(BIN)/messStacker
