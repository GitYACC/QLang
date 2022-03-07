FILE := test.qx

build: build.o 
	./build.o <$(FILE)

build.o:
	gcc src/main.c src/builtin/exts/token.c src/builtin/classes/integer.c -o build.o

clean:
	rm -f build.o