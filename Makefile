# Définition des variables
GPP = g++ -Wall
SRC = ./src
BIN = ./bin

all: start

# La cible "deleteAll" est exécutée en tapant la commande "make deleteAll"
deleteAll :
	@echo Suppression du contenu du répertoire $(BIN)
	rm -f $(BIN)/*.o $(BIN)/*.bin

# La cible "compilPoint" est exécutée en tapant la commande "make compilPoint"
compilPoint :
	@echo Compilation Point
	$(GPP) -c $(SRC)/Point.cpp -o $(BIN)/Point.o

# La cible "compilForme" est exécutée en tapant la commande "make compilForme"
compilForme : compilPoint
	@echo Compilation Forme
	$(GPP) -c $(SRC)/Forme.cpp -o $(BIN)/Forme.o

# La cible "compilCercle" est exécutée en tapant la commande "make compilCercle"
compilCercle : compilForme
	@echo Compilation Cercle
	$(GPP) -c $(SRC)/Cercle.cpp -o $(BIN)/Cercle.o

# La cible "compilRectangle" est exécutée en tapant la commande "make compilRectangle"
compilRectangle : compilForme
	@echo Compilation Rectangle
	$(GPP) -c $(SRC)/Rectangle.cpp -o $(BIN)/Rectangle.o

# La cible "compilCarre" est exécutée en tapant la commande "make compilCarre"
compilCarre : compilRectangle
	@echo Compilation Carré
	$(GPP) -c $(SRC)/Carre.cpp -o $(BIN)/Carre.o

compilListeFormes : compilForme
	@echo Compilation ListeFormes
	$(GPP) -c $(SRC)/ListeFormes.cpp -o $(BIN)/ListeFormes.o $(BIN)/Rectangle.o $(BIN)/Carre.o

# La cible "compilMain" est exécutée en tapant la commande "make compilMain"
compilMain : deleteAll compilCarre compilCercle compilListeFormes
	@echo Compilation de main
	$(GPP) ./main.cpp $(BIN)/ListeFormes.o $(BIN)/Cercle.o $(BIN)/Carre.o $(BIN)/Rectangle.o $(BIN)/Forme.o $(BIN)/Point.o -o $(BIN)/main.bin

# La cible "launchMain" est exécutée en tapant la commande "make launchMain"
launchMain :
	@echo Lancement de main
	$(BIN)/main.bin

# La cible "start" est exécutée en tapant la commande "make start"
start : compilMain launchMain
