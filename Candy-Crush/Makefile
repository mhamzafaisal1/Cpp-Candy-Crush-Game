CXXFLAGS =	-g3 -Wall -fmessage-length=0 #-Werror

OBJS =		 util.o  CanvasSizing.o GameBoard.o Gem.o AllGems.o  Coordinates.o Player.o  Menu.o game.o NormalMode.o TimeMode.o ProgressBar.o Variable.o

LIBS = -L/usr/X11R6/lib -L/sw/lib -L/usr/sww/lib -L/usr/sww/bin -L/usr/sww/pkg/Mesa/lib -lglut -lGLU -lGL -lX11 -lfreeimage -pthread



TARGET =	game


$(TARGET):	$(OBJS) 
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
