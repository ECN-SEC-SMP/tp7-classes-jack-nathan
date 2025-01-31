GPP = g++ -Wall
SRC = ./src
BIN = ./bin

all: start

# La cible "deleteAll" est exécutée en tapant la commande "make deleteAll"
deleteAll :
	@echo suppression du contenu du répertoire ../bin
	rm -f $(BIN)/*.o $(BIN)/*.bin

# La cible "compilPoint" est exécutée en tapant la commande "make compilPoint"
compilPoint :
	@echo Compilation Point
	$(GPP) $(SRC)/Point.cpp -o $(BIN)/Point.o -c

# La cible "compilForme" est exécutée en tapant la commande "make compilForme"
compilForme : compilPoint
	@echo Compilation compilForme
	$(GPP) $(SRC)/Forme.cpp $(BIN)/Point.o -o $(BIN)/Forme.o -c

# La cible "compilCercle" est exécutée en tapant la commande "make compilCercle"
compilCercle : compilForme
	@echo Compilation compilCercle
	$(GPP) $(SRC)/Cercle.cpp $(BIN)/Forme.o -o $(BIN)/Cercle.o -c

# La cible "compilRectangle" est exécutée en tapant la commande "make compilRectangle"
compilRectangle : compilForme
	@echo Compilation compilRectangle
	$(GPP) $(SRC)/Rectangle.cpp $(BIN)/Forme.o -o $(BIN)/Rectangle.o -c

# La cible "compilCarre" est exécutée en tapant la commande "make compilCarre"
compilCarre : compilRectangle
	@echo Compilation compilCarre
	$(GPP) $(SRC)/Carre.cpp $(BIN)/Rectangle.o -o $(BIN)/Carre.o -c

# La cible "compilMain" est exécutée en tapant la commande "make compilMain"
compilMain : deleteAll compilCarre compilCercle
	@echo Compilation de main
	$(GPP) ./main.cpp $(BIN)/Forme.o $(BIN)/Point.o -o $(BIN)/main.bin

# La cible "launchMain" est exécutée en tapant la commande "make launchMain"
launchMain :
	@echo Lancement de main
	$(BIN)/main.bin

# La cible "start" est exécutée en tapant la commande "make start"
start : compilMain launchMain